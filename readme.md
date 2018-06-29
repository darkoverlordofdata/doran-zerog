# ZeroG


        __________                    ________ 
        \____    /___________  ____  /  _____/ 
          /     // __ \_  __ \/  _ \/   \  ___ 
         /     /\  ___/|  | \(  <_> )    \_\  \
        /_______ \___  >__|   \____/ \______  /
                \/   \/                     \/ 


                Replacement Vala runtime


Based on the Gnome's GLib and GObject. Vala uses GLib as it's runtime, but there is much of GLib that is does not use at all. This implementation uses even less. Designed to target environments with no GLib distro, such as WASM and Android.

Just support for the oop syntax. Currently being co-developed with  https://github.com/darkoverlordofdata/doran-xna.framework


No threading, no marshalling, no notifications.
No custom gobject constructor or properties.
No Variant data type, nothing that relies on Variant, such as 
        
        GLib.Object(Mode: 420);
        
If you declare something not supported:

        public Thread t2;

you'll get a link error due to undefined references.

### todo
RegEx

