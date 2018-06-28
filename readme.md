# ZeroG


        __________                    ________ 
        \____    /___________  ____  /  _____/ 
          /     // __ \_  __ \/  _ \/   \  ___ 
         /     /\  ___/|  | \(  <_> )    \_\  \
        /_______ \___  >__|   \____/ \______  /
                \/   \/                     \/ 


    Compact replacement for Vala runtime GLib


Based on the Gnome's GLib and GObject. Valauses GLib as it's runtime, but there is much of GLib that is does not use at all. This implementation uses even less.

Just support for the oop syntax. Currently being co-developed with  https://github.com/darkoverlordofdata/doran-xna.framework


No threading, no marshalling, no notifications.
No custom gobject constructor or properties.
No Variant data type, nothing that relies on Variant, such as 
        
        GLib.Object(Mode: 420);
        
If you declare something not supported:

        public Thread t2;

you'll get a link error due to undefined references.

## Old Demos - using prototype version (Compact ZeroG)

### [<del>ShmupWarz II</del> Better Than Shmup](https://darkoverlordofdata.com/zerog-shmupwarz/)
[The old standby](https://github.com/darkoverlordofdata/zerog-shmupwarz)

### [Match3](https://darkoverlordofdata.com/zerog-match3/)
[wip](https://github.com/darkoverlordofdata/zerog-match3)

### [Platformer](https://darkoverlordofdata.com/zerog-platformer/)
[wip](https://github.com/darkoverlordofdata/zerog-platformer)




## License
Various licences apply. 

The ZeroG library and Adriac: GPL2

Application libraries:
* entitas - MIT
* sdx - Apache2
* mt19937 - see code 