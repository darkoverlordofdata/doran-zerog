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
        

So far, inheritence, abstracts and delegates work. Interfaces do not. They don't initialize correctly, it appears the vtable gets overwritten.

I could re-write framework code to use abstract instead of interface. I'm not sure that is the right direction - wasm supports real function pointers, and when emscripten supports them also, this entire issue may go away.