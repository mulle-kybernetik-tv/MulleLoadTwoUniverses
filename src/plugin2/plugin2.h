#import "import.h"

#include <stdint.h>

/*
 *  (c) 2018 mulle_kybernetik_tv 
 *
 *  version:  major, minor, patch
 */
#define PLUGIN2_VERSION  ((0 << 20) | (7 << 8) | 56)


static inline unsigned int   plugin2_get_version_major( void)
{
   return( PLUGIN2_VERSION >> 20);
}


static inline unsigned int   plugin2_get_version_minor( void)
{
   return( (PLUGIN2_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   plugin2_get_version_patch( void)
{
   return( PLUGIN2_VERSION & 0xFF);
}


extern uint32_t   plugin2_get_version( void);

/*
   Add other library headers here like so, for exposure to library
   consumers.

   # include "foo.h"
*/
