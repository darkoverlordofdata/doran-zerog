cmake_minimum_required ( VERSION 3.1 )
#########################################################################################
#
#   Library: ZeroG
#
#########################################################################################
project ( zerog VERSION 0.1.0 )

list ( APPEND INCLUDE "${INCLUDE}; .lib/zerog/include" )
list ( APPEND INCLUDE "${INCLUDE}; C:/msys64/mingw64/include/glib-2.0" )
list ( APPEND INCLUDE "${INCLUDE}; C:/msys64/mingw64/include" )

list ( APPEND CSOURCE .lib/zerog/src/glib/garray.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gatomic.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gbase64.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gbytes.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gchecksum.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gdate.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/ghash.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/ghmac.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/glist.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gdatetime.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gerror.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gmain.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gmem.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gmessages.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gnode.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gprimes.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gprintf.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gqsort.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gquark.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gqueue.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/grand.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gsequence.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gslice.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gslist.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gstring.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gstrfuncs.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtestutils.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtimer.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtimezone.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtree.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gutils.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/guuid.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gversion.c )

#include <glib/gdate.h> - needs testing

## Export to the parent scope:

set ( ZEROG true PARENT_SCOPE )
set ( INCLUDES "${INCLUDES};${INCLUDE}" PARENT_SCOPE )
set ( C_SOURCES "${C_SOURCES};${CSOURCE}" PARENT_SCOPE )
set ( VALAC_OPTIONS "${VALAC_OPTIONS};--define=NOGOBJECT" PARENT_SCOPE )

