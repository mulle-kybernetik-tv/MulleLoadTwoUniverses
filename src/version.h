#ifndef mulle_load_two_universes_version_h__
#define mulle_load_two_universes_version_h__

/*
 *  version:  major, minor, patch
 */
#define MULLE_LOAD_TWO_UNIVERSES_VERSION  ((0 << 20) | (7 << 8) | 56)


static inline unsigned int   Mulle_Load_Two_Universes_get_version_major( void)
{
   return( MULLE_LOAD_TWO_UNIVERSES_VERSION >> 20);
}


static inline unsigned int   Mulle_Load_Two_Universes_get_version_minor( void)
{
   return( (MULLE_LOAD_TWO_UNIVERSES_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   Mulle_Load_Two_Universes_get_version_patch( void)
{
   return( MULLE_LOAD_TWO_UNIVERSES_VERSION & 0xFF);
}

#endif
