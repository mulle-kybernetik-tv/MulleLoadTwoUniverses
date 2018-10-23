#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


int  load_plugin( char *filename, int dlmode)
{
   void       *handle;
   void       *universe;
   char       *pwd;
   void       *adr;
   void       *(*p_get_universe)( uint32_t);
   uint32_t   (*p_get_version)( void);
   uint32_t   version;

   if( ! filename)
      exit( -1);

   dlmode |= RTLD_NOW;

   if( getenv( "VERBOSE"))
      fprintf( stderr, "Loading  \"%s\"...\n", filename);

   handle = dlopen( filename, dlmode);
   if( ! handle)
   {
      char   *pwd;

      pwd = getenv( "PWD");
      fprintf( stderr, "failed to open \"%s\" (%s) %s\n",
                  filename,
                  pwd ? pwd : "???",
                  dlerror());
      return( 1);
   }

   adr = dlsym( handle, "get_version");
   if( adr)
   {
      p_get_version = adr;
      version       = (*p_get_version)();
      printf( "Version of \"%s\" is %lu\n", filename, (long) version);
   }  
   else
   {
      fprintf( stderr, "Did not find \"get_version\" function in \"%s\"\n", 
                       filename);
      return( 1); 
   }

   adr = dlsym( handle, "mulle_objc_global_get_universe");
   if( adr)
   {
      p_get_universe = adr;
      universe       = (*p_get_universe)( 0);
      printf( "Universe of \"%s\" is %p\n", filename, universe);
   }  
   else
   {
      fprintf( stderr, "Did not find \"mulle_objc_global_get_universe\" function in \"%s\"\n", 
                       filename);
      return( 1); 
   }
 
   return( 0);
}

static int   tokenize( char **p_s, int *value)
{
   char   *s;
   char   *memo;
   int    c;

   s = *p_s;
   while( c = *s)
   {
      switch( c)
      {
      case '|' :
      case '+' :
         *p_s = ++s;
         return( '+');

      case ' ' :
         break;

      default :
         if( ! strncmp( s, "RTLD_LOCAL", 10))
         {
            *p_s   = &s[ 10];
            *value = RTLD_LOCAL;
            return( 'v');
         }
         if( ! strncmp( s, "RTLD_GLOBAL", 11))
         {
            *p_s   = &s[ 11];
            *value = RTLD_GLOBAL;
            return( 'v');
         }
         if( ! strncmp( s, "RTLD_DEEPBIND", 13))
         {
            *p_s   = &s[ 13];
            *value = RTLD_DEEPBIND;
            return( 'v');
         }

         fprintf( stderr, "unknown token \"%s\"\n", s);
         exit( 1);         
      }
      ++s;
   }
   *p_s = s;
   return( 0);
}


static int   parse_dlmode_flags( char *s)
{
   int  token;
   int  dlmode;
   int  value;

   dlmode = 0;
   while( token = tokenize( &s, &value))
   {
      // fprintf( stderr, "token: %x value: %d (%s)\n", token, value, s);
      if( token == '+')
         continue;
      dlmode += value;
   }
   return( dlmode);
}


/* 
 * Loader is C only:
 * 
 * libplugin1.so | libplugin2.so | Universes | Description
 * --------------|---------------|---------------------------------------
 * RTLD_LOCAL    | RTLD_LOCAL    | 1         | works
 * RTLD_LOCAL    | RTLD_GLOBAL   | 1         | works
 * RTLD_GLOBAL   | RTLD_LOCAL    | 1         | plugin2 crashes on load (duplicate class)
 * RTLD_GLOBAL   | RTLD_GLOBAL   | 1         | plugin2 crashes on load (duplicate class)
 * RTLD_LOCAL    | RTLD_LOCAL    | 1         | works
 * RTLD_LOCAL+RTLD_DEEPBIND  | RTLD_LOCAL+RTLD_DEEPBIND  | 2 | works
 * RTLD_LOCAL+RTLD_DEEPBIND  | RTLD_GLOBAL+RTLD_DEEPBIND | 2 | works
 * RTLD_GLOBAL+RTLD_DEEPBIND | RTLD_LOCAL+RTLD_DEEPBIND  | 2 | works, dual global variable universes
 * RTLD_GLOBAL+RTLD_DEEPBIND | RTLD_GLOBAL+RTLD_DEEPBIND | 2 | works
 */ 

int  main( int argc, char *argv[])
{
   load_plugin( argv[ 1], parse_dlmode_flags( argv[ 2]));
   load_plugin( argv[ 3], parse_dlmode_flags( argv[ 4]));
   return( 0);
}
