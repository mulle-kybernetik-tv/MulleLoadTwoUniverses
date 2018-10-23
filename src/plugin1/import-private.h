/* DO:    #import this files in sources

   DONT:  #import this files in headers
          #include this file anywhere
 */

/* This is a central include file to not expose includes to consumers of
   this library. It must not be imported by .h files, but by .m and
   .aam files only.
*/

/*
   Include C first
*/
#import "include-private.h"


/*
   Now the public interfaces
*/
#import "import.h"

/* Include the header file automatically generated by c-sourcetree-update.
   Here the prefix is harmless and serves disambiguation. If you have no
   sourcetree, then you don't need it.
 */
#import "_plugin1-import-private.h"

/* You can add some more include statements here */
