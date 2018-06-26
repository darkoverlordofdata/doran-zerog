/**
 * Null methods
 * All methods do nothing
 * Have no side effects
 * Return input parameters without trasformation
 * 
 */

#include <config.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <locale.h>
#include <errno.h>
#include <ctype.h>              /* For tolower() */

// #include <glib/gstring.h>
#include <glib/gstrfuncs.h>
// #include <glib/gmessages.h>
// #include <glib/gmem.h>
// #include <glib/gwakeup.h>

/**
 * These can't be defined where glib/thread.h is included
 */

#define g_once_init_enter_impl(x) ((*(x) == 0) ? TRUE : FALSE)
#define g_once_init_leave_impl(x,y) (*(x) = y)

gboolean
g_once_init_enter(gsize *initialised)
{
    return g_once_init_enter_impl(initialised);
}

gboolean
g_once_init_leave(  
    gsize  *location,
    gsize   result)
{
    return g_once_init_leave_impl(location, result);
}

