/**
 * Initialize both GLib and GObject since they are not each in their own dll
 * 
 */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <glib/glib-init.h>

void gobject_init (void);

static void zerog_init_ctor() __attribute__((constructor));
static void 
zerog_init_ctor()
{
    glib_init ();
    gobject_init ();
}
