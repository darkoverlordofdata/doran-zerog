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


## Emscripten:
GObject Requires:
        -s EMULATE_FUNCTION_POINTER_CASTS=1
        

So far, inheritence and abstracts work. Interfaces do not. I can support 1 interface with a manual workaround. The underlying issue is function pointers. GLib recasts function pointers with differring args. There is signature abuse, arity abuse and memory abuse. This all leads to undefined behavior, the last thing you want when trying to port. Exploiting platform specific undefined behavior. Shame on Gnome. It makes me want to re-write glib. It'd probably take me about a long time - 6 months. Not sure it I want to do that.