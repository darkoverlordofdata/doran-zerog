# ZeroG


        __________                    ________ 
        \____    /___________  ____  /  _____/ 
          /     // __ \_  __ \/  _ \/   \  ___ 
         /     /\  ___/|  | \(  <_> )    \_\  \
        /_______ \___  >__|   \____/ \______  /
                \/   \/                     \/ 


                Replacement Vala runtime


Based on the Gnome's GLib and GObject. Vala uses GLib as it's runtime, but there is much of GLib that is does not use at all. This implementation uses even less. Designed to target environments with no GLib distro, such as WASM and Android.

Just support for the oop syntax and regex. Currently being co-developed with  https://github.com/darkoverlordofdata/doran-xna.framework


No threading, no boxing, no closure, no marshalling, no notifications.
No custom gobject constructor or properties.
No RegEx. Not portable, as it depends on an external lib not available in emscripten.
No Variant data type, nothing that relies on Variant, such as 
        
        GLib.Object(Mode: 420);
        
If you declare something not supported:

        public Thread t2;

you'll get a link error due to undefined references.


Vala 'boxing' is supported - this is not the same as GObject boxing:

        var x = new HashTable<int, Date?>();

Vala closures are also supported. Again, not the same thing as GObject closures.