#
# The following includes include definitions generated
# during `mulle-sde update`. Don't edit those files. They are
# overwritten frequently.
#
# === MULLE-SDE START ===

include( _Headers)
include( _Sources)

# === MULLE-SDE END ===
#

# add ignored headers back in


# add ignored headers back in so that the generators pick them up
set( PUBLIC_HEADERS
"src/_MulleLoadTwoUniverses-include.h"
"src/_MulleLoadTwoUniverses-import.h"
${PUBLIC_HEADERS}
)

# keep headers to install separate to make last minute changes
set( INSTALL_PUBLIC_HEADERS ${PUBLIC_HEADERS})


#
# Do not install generated private headers and include-private.h
# which aren't valid outside of the project scope.
#
set( INSTALL_PRIVATE_HEADERS ${PRIVATE_HEADERS})
list( REMOVE_ITEM INSTALL_PRIVATE_HEADERS "include-private.h")
list( REMOVE_ITEM INSTALL_PRIVATE_HEADERS "import-private.h")

# add ignored headers back in so that the generators pick them up
set( PRIVATE_HEADERS
"src/_MulleLoadTwoUniverses-import-private.h"
"src/_MulleLoadTwoUniverses-include-private.h"
${PRIVATE_HEADERS}
)


#
# You can put more source and resource file definitions here.
#
