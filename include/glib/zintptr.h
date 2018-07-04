#ifndef _ZINTPTR_H_
#define _ZINTPTR_H_

#include <glib/gtypes.h>

G_BEGIN_DECLS

typedef struct ZIntPtr
{
    gconstpointer m_value;

} ZIntPtr;

GLIB_AVAILABLE_IN_ALL
ZIntPtr* z_int_ptr_new              (const void* ptr);

// GLIB_AVAILABLE_IN_ALL
// ZIntPtr* z_int_ptr_ULong            (const gulong ptr);

GLIB_AVAILABLE_IN_ALL
gpointer z_int_ptr_ToPointer        (const ZIntPtr* this);

GLIB_AVAILABLE_IN_ALL
gboolean z_int_ptr_IsNull           (const ZIntPtr* this);

GLIB_AVAILABLE_IN_ALL
gboolean z_int_ptr_Equals           (const ZIntPtr* this, const ZIntPtr* that);

GLIB_AVAILABLE_IN_ALL
gint z_int_ptr_GetHashCode          (const ZIntPtr* this);

GLIB_AVAILABLE_IN_ALL
ZIntPtr* z_int_ptr_Add              (const ZIntPtr* ptr, const gint offset);

GLIB_AVAILABLE_IN_ALL
ZIntPtr* z_int_ptr_Subtract         (const ZIntPtr* ptr, const gint offset);

GLIB_VAR
ZIntPtr* z_int_ptr_Zero;

GLIB_VAR 
gint z_int_ptr_Size;

G_END_DECLS

#endif /* _ZINTPTR_H_ */
