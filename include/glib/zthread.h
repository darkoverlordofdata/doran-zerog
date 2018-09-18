#ifndef _ZTHREAD_H_
#define _ZTHREAD_H_

#include <glib/gtypes.h>

GLIB_AVAILABLE_IN_ALL
gboolean        (g_once_init_enter)               (volatile void  *location);
GLIB_AVAILABLE_IN_ALL
void            (g_once_init_leave)               (volatile void  *location,
                                                 gsize           result);

#endif //_ZTHREAD_H_
