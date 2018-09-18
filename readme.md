# ZeroG


        __________                    ________ 
        \____    /___________  ____  /  _____/ 
          /     // __ \_  __ \/  _ \/   \  ___ 
         /     /\  ___/|  | \(  <_> )    \_\  \
        /_______ \___  >__|   \____/ \______  /
                \/   \/                     \/ 


                Replacement Vala runtime


Based on the Gnome's GLib and GObject. Vala uses GLib as it's runtime, but there is much of GLib that it does not use at all. This implementation uses even less. Designed to target environments with no GLib distro, such as WASM and Android.

No threading, no boxing, no closure, no marshalling, no notifications.
No custom gobject constructor or properties.
No RegEx, its not portable, depending on an external lib.
No Variant data type, nothing that relies on Variant.
No dependencies, just support for Vala's oop syntax 

GObject Requires:

        -s EMULATE_FUNCTION_POINTER_CASTS=1
        
