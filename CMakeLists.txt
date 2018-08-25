cmake_minimum_required ( VERSION 3.1 )
###################################################################################
#
#   Library: zerog
#
###################################################################################
project ( zerog VERSION 0.0.1 )

# Includes: 
list ( APPEND INCLUDE .lib/zerog/include )
list ( APPEND INCLUDE C:/Users/darko/Documents/GitHub/glib/ )
list ( APPEND INCLUDE C:/Users/darko/Documents/GitHub/glib/glib )
list ( APPEND INCLUDE C:/Users/darko/Documents/GitHub/glib/gobject )
list ( APPEND INCLUDE C:/msys64/mingw64/lib/libffi-3.2.1/include )

# C Sources: 
list ( APPEND CSOURCE .lib/zerog/src/zerog.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gbinding.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gatomicarray.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gboxed.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gclosure.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gobject.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/genums.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gparam.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gparamspecs.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gsignal.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gsourceclosure.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gtype.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gvalue.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gtypemodule.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gtypeplugin.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gvaluetypes.c )
list ( APPEND CSOURCE .lib/zerog/src/gobject/gvaluearray.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/garray.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gbase64.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gatomic.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gbytes.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gchecksum.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gdate.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gdatetime.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gerror.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/genviron.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/ghash.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/ghmac.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/glib-init.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/glist.c )
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
list ( APPEND CSOURCE .lib/zerog/src/glib/gstrfuncs.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gstring.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtestutils.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtimezone.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtimer.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gtree.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gutils.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gunidecomp.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/guniprop.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gutf8.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/guuid.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/gversion.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/zthread.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/zintptr.c )
list ( APPEND CSOURCE .lib/zerog/src/glib/zuniprop.c )

# Vala Sources: 

# Vapis: 

# Vapidir: 

## Export to the parent scope:
set ( ZEROG true PARENT_SCOPE )
set ( INCLUDES "${INCLUDES};${INCLUDE}" PARENT_SCOPE )
set ( C_SOURCES "${C_SOURCES};${CSOURCE}" PARENT_SCOPE )






# (generated from template: package. Do not modify. )
