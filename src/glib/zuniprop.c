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
#include <glib/gmessages.h>
#include <glib/gmem.h>
#include <glib/gwakeup.h>
#include <glib/gthread.h>
#include <glib/gwin32.h>
#include <glib/gtrashstack.h>
#include <glib/gspawn.h>
#include <glib/gstdio.h>

#define TRACE(x) printf(x)

static gchar *
strdup_len (const gchar *string,
	    gssize       len,
	    gsize       *bytes_read,
	    gsize       *bytes_written,
	    GError     **error)
{
    // TRACE("trace: strdup_len\n");
    gchar *new_str;
    gsize length;

    if (string)
    {
        length = strlen (string) + 1;
        new_str = g_new (char, length);
        memcpy (new_str, string, length);
    }
    else new_str = NULL;

    if (bytes_read) *bytes_read = length;
    if (bytes_written) *bytes_written = length;
    if (error) *error = "\0";

    return new_str;

}
/**
 * Replace utf conversion with string copy,
 * so it's essentially doing nothing.
 * Every one of these g_utf8_?? functions are in a different file. 
 * Gnome - you're worse than M$
 */
gchar *
g_utf8_casefold (const gchar *str,
		 gssize       len)
{
    // TRACE("trace: g_utf8_casefold\n");
    g_return_val_if_fail (str != NULL, NULL);
    // result = g_strdup(str);}
    return strdup_len (str, len, NULL, NULL, NULL);

}

gchar *
g_utf8_normalize (const gchar    *str,
		  gssize          len,
		  GNormalizeMode  mode)
{
    // TRACE("trace: g_utf8_normalize\n");
    g_return_val_if_fail (str != NULL, NULL);
    // result = g_strdup(str);
    return strdup_len (str, len, NULL, NULL, NULL);
}

gchar *
g_utf8_strup (const gchar *str,
	      gssize       len)
{
    // TRACE("trace: g_utf8_strup\n");
    g_return_val_if_fail (str  != NULL, 0);

    int l = strlen(str);
    int i = 0;

    gchar *s = g_new (char, l);
    gchar *result = s;
    gint n = len;
    
    while ((len < 0 && *s) || i < l) 
    {
        *s = toupper(*(str+i));
        s += 1;
        i += 1;
    } 
    return result;
}

gchar *
g_utf8_strdown (const gchar *str,
	      gssize       len)
{
    // TRACE("trace: g_utf8_strdown\n");
    g_return_val_if_fail (str  != NULL, 0);

    int l = strlen(str);
    int i = 0;

    gchar *s = g_new (char, l);
    gchar *result = s;
    gint n = len;
    
    while ((len < 0 && *s) || i < l) 
    {
        *s = tolower(*(str+i));
        s += 1;
        i += 1;
    } 
    return result;
}


gboolean
g_get_charset (const char **charset)
{
    // TRACE("trace: g_get_charset\n");
    gchar *result;
    result = g_strdup("CP1252");

    return TRUE;
}

gchar *
g_locale_to_utf8 (const gchar  *opsysstring,
		  gssize        len,            
		  gsize        *bytes_read,    
		  gsize        *bytes_written,
		  GError      **error)
{
    // TRACE("trace: g_locale_to_utf8\n");
    return strdup_len (opsysstring, len, bytes_read, bytes_written, error);
}

gchar *
g_locale_from_utf8 (const gchar *utf8string,
		    gssize       len,            
		    gsize       *bytes_read,    
		    gsize       *bytes_written,
		    GError     **error)
{
    // TRACE("trace: g_locale_from_utf8\n");
    return strdup_len (utf8string, len, bytes_read, bytes_written, error);
}


gchar *
g_win32_error_message (gint error)
{
    // TRACE("trace: g_win32_error_message\n");
    return g_strdup_printf("Error %i", error);
}

void
g_wakeup_free (GWakeup *wakeup)
{
    // TRACE("trace: g_wakeup_free\n");
}

void
g_wakeup_signal (GWakeup *wakeup)
{
    // TRACE("trace: g_wakeup_signal\n");
}


gint
g_poll (GPollFD *fds,
	guint    nfds,
	gint     timeout)
{
    // TRACE("trace: g_poll\n");
    return 0; //poll ((struct pollfd *)fds, nfds, timeout);
}

GWakeup *
g_wakeup_new (void)
{
    // TRACE("trace: g_wakeup_new\n");
}

void
g_wakeup_get_pollfd (GWakeup *wakeup,
                     GPollFD *poll_fd)
{
    // TRACE("trace: g_wakeup_get_pollfd\n");
}


GThread*
g_thread_self (void)
{
    // TRACE("trace: g_thread_self\n");
    return NULL;
}

void
g_wakeup_acknowledge (GWakeup *wakeup)
{
    // TRACE("trace: g_wakeup_acknowledge\n");
}

// const gchar *
// g_getenv (const gchar *variable)
// {
//     // TRACE("trace: g_getenv\n");
//     g_return_val_if_fail (variable != NULL, NULL);
//     return g_strdup (variable);
// }

GThread *
g_thread_new (const gchar *name,
              GThreadFunc  func,
              gpointer     data)
{
    // TRACE("trace: g_thread_new\n");
    return NULL;
}

gsize
g_variant_iter_init (GVariantIter *iter,
                     GVariant     *value)
{
    // TRACE("trace: g_variant_iter_init\n");
    return 0;
}

gboolean
g_variant_iter_next (GVariantIter *iter,
                     const gchar  *format_string,
                     ...)
{
    // TRACE("trace: g_variant_iter_next\n");
    return FALSE;
}

gboolean
g_variant_is_of_type (GVariant           *value,
                      const GVariantType *type)
{
    // TRACE("trace: g_variant_is_of_type\n");
    return FALSE;
}

gconstpointer
g_variant_get_fixed_array (GVariant *value,
                           gsize    *n_elements,
                           gsize     element_size)
{
    // TRACE("trace: g_variant_get_fixed_array\n");
    return NULL;
}

gchar *
g_variant_print (GVariant *value,
                 gboolean  type_annotate)
{
    // TRACE("trace: g_variant_print\n");
    return "\0";
}

void
g_variant_unref (GVariant *value)
{
    // TRACE("trace: g_variant_unref\n");
}

const gchar *
g_variant_get_string (GVariant *value,
                      gsize    *length)
{
    // TRACE("trace: g_variant_get_string\n");
    return "\0";
}


gboolean
g_win32_check_windows_version (const gint major,
                               const gint minor,
                               const gint spver,
                               const GWin32OSType os_type)
{
    // TRACE("trace: g_win32_check_windows_version\n");
    return FALSE;
}

gchar*
g_convert_with_fallback (const gchar *str,
			 gssize       len,    
			 const gchar *to_codeset,
			 const gchar *from_codeset,
			 const gchar *fallback,
			 gsize       *bytes_read,
			 gsize       *bytes_written,
			 GError     **error)
{
    // TRACE("trace: g_convert_with_fallback\n");
    return "\0";
}

void
g_trash_stack_push (GTrashStack **stack_p,
                    gpointer      data_p)
{
    // TRACE("trace: g_trash_stack_push\n");
}

gpointer
g_trash_stack_pop (GTrashStack **stack_p)
{
    // TRACE("trace: g_trash_stack_pop\n");
    return NULL;
}

gboolean
g_unichar_isalnum (gunichar c)
{
    // TRACE("trace: g_unichar_isalnum\n");
    return isalnum(c);
}

gboolean
g_unichar_ismark (gunichar c)
{
    // TRACE("trace: g_unichar_ismark\n");
    return FALSE;
}

gchar *
g_str_to_ascii (const gchar *str,
                const gchar *from_locale)
{
    // TRACE("trace: g_str_to_ascii\n");
    return g_strdup(str);
}

gchar* 
glib_gettext(gchar *str)
{
    // TRACE("trace: glib_gettext\n");
    return g_strdup(str);
}

GQuark 
g_thread_error_quark (void)
{
    // TRACE("trace: g_thread_error_quark\n");
}

gchar *
g_get_current_dir (void)
{
    // TRACE("trace: g_get_current_dir\n");
    return "\0";
}

gchar *
g_path_get_dirname (const gchar *file_name)
{
    // TRACE("trace: g_path_get_dirname\n");
    return "\0";
}

gchar *
g_build_path (const gchar *separator,
	      const gchar *first_element,
	      ...)
{
    // TRACE("trace: g_build_path\n");
    return "\0";
}

gboolean
g_spawn_async_with_pipes (const gchar          *working_directory,
                          gchar               **argv,
                          gchar               **envp,
                          GSpawnFlags           flags,
                          GSpawnChildSetupFunc  child_setup,
                          gpointer              user_data,
                          GPid                 *child_handle,
                          gint                 *standard_input,
                          gint                 *standard_output,
                          gint                 *standard_error,
                          GError              **error)
{
    // TRACE("trace: g_spawn_async_with_pipes\n");
    return FALSE;
}

GIOChannel *
g_io_channel_unix_new (gint fd)
{
    // TRACE("trace: g_io_channel_unix_new\n");
    return NULL;
}

void
g_io_channel_set_close_on_unref	(GIOChannel *channel,
				 gboolean    do_close)
{
    // TRACE("trace: g_io_channel_set_close_on_unref\n");
}

GIOStatus
g_io_channel_set_encoding (GIOChannel	*channel,
                           const gchar	*encoding,
			   GError      **error)
{
    // TRACE("trace: g_io_channel_set_encoding\n");
    return NULL;
}

void
g_io_channel_set_buffered (GIOChannel *channel,
                           gboolean    buffered)
{
    // TRACE("trace: g_io_channel_set_buffered\n");
}

GSource *
g_io_create_watch (GIOChannel   *channel,
		   GIOCondition  condition)
{
    // TRACE("trace: g_io_create_watch\n");
    return NULL;
}

void 
g_io_channel_unref (GIOChannel *channel)
{
    // TRACE("trace: g_io_channel_unref\n");
}

gchar *
g_build_filenamev (gchar **args)
{
    // TRACE("trace: g_build_filenamev\n");
    return "\0";
}

GIOStatus
g_io_channel_read_chars (GIOChannel  *channel,
                         gchar       *buf,
                         gsize        count,
                         gsize       *bytes_read,
                         GError     **error)
{
    // TRACE("trace: g_io_channel_read_chars\n");
    return 0;
}

GQuark g_convert_error_quark (void)
{
    // TRACE("trace: g_convert_error_quark\n");
    return NULL;
}

gboolean
g_path_is_absolute (const gchar *file_name)
{
    // TRACE("trace: g_path_is_absolute\n");
    return FALSE;
}

gboolean
g_file_test (const gchar *filename,
             GFileTest    test)
{
    // TRACE("trace: g_file_test\n");
    return FALSE;
}

const gchar *
g_path_skip_root (const gchar *file_name)
{
    // TRACE("trace: g_path_skip_root\n");
    return g_strdup(file_name);
}

gchar *
g_path_get_basename (const gchar *file_name)
{
    // TRACE("trace: g_path_get_basename\n");
    return g_strdup(file_name);
}

gchar *
g_build_filename (const gchar *first_element, 
		  ...)
{
    // TRACE("trace: g_build_filename\n");
    return g_strdup(first_element);
}

// int
// g_mkdir (const gchar *filename,
// 	 int          mode)
// {
//     // TRACE("trace: g_mkdir\n");
//     return -1;
// }

gchar *
g_win32_get_package_installation_directory_of_module (gpointer hmodule)
{
    // TRACE("trace: g_win32_get_package_installation_directory_of_module\n");
    return NULL;
}

const gchar *
g_dngettext (const gchar *domain,
             const gchar *msgid,
             const gchar *msgid_plural,
             gulong       n)
{
    // TRACE("trace: g_dngettext\n");
    return g_strdup(msgid);
}
