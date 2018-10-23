#import "import.h"

#include <stdint.h>

/*
 *  (c) 2018 nat 
 *
 *  version:  major, minor, patch
 */
#define PLUGIN1_VERSION  ((0 << 20) | (7 << 8) | 56)


static inline unsigned int   plugin1_get_version_major( void)
{
   return( PLUGIN1_VERSION >> 20);
}


static inline unsigned int   plugin1_get_version_minor( void)
{
   return( (PLUGIN1_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   plugin1_get_version_patch( void)
{
   return( PLUGIN1_VERSION & 0xFF);
}


extern uint32_t   plugin1_get_version( void);

/*
   Add other library headers here like so, for exposure to library
   consumers.

   # include "foo.h"
*/
