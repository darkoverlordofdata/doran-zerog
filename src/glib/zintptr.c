#include <config.h>

#include <glib/gslice.h>
#include <glib/zintptr.h>

ZIntPtr* 
z_int_ptr_new(const gint ptr)
{
    ZIntPtr *int_ptr;

    int_ptr = g_slice_new (ZIntPtr);
    int_ptr->m_value = ptr;
    return int_ptr;
}

ZIntPtr* z_int_ptr_Zero = { 0 };

gint z_int_ptr_Size = sizeof(ZIntPtr);

gpointer 
z_int_ptr_ToPointer(const ZIntPtr* this)
{
    return this->m_value;
}

gboolean 
z_int_ptr_Equals(const ZIntPtr* this, const ZIntPtr* that)
{
    return this->m_value == that->m_value;
}

gboolean 
z_int_ptr_IsNull(const ZIntPtr* this)
{
    return this->m_value == NULL;
}

gint 
z_int_ptr_GetHashCode(const ZIntPtr* this)
{
    return (gint)this->m_value;
}

ZIntPtr* 
z_int_ptr_Add(const ZIntPtr* ptr, const gint offset)
{
    return z_int_ptr_new(ptr->m_value + offset);
}

ZIntPtr* 
z_int_ptr_Subtract(const ZIntPtr* ptr, const gint offset)
{
    return z_int_ptr_new(ptr->m_value - offset);
}
