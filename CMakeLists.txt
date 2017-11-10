cmake_minimum_required ( VERSION 3.1 )
#########################################################################################
#
#   Library: ZeroG
#
#########################################################################################
project ( zerog VERSION 0.1.0 )

set ( INCLUDES "${INCLUDES}; .lib/zerog/src" PARENT_SCOPE )
set ( VALAC_OPTIONS "${VALAC_OPTIONS};--define=NOGOBJECT" PARENT_SCOPE )

