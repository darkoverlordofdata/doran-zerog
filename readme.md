# ZeroG


        __________                    ________ 
        \____    /___________  ____  /  _____/ 
          /     // __ \_  __ \/  _ \/   \  ___ 
         /     /\  ___/|  | \(  <_> )    \_\  \
        /_______ \___  >__|   \____/ \______  /
                \/   \/                     \/ 


    Compact replacement for Vala runtime GLib


Based on the Gnome's GLib and GObject. Valauses GLib as it's runtime, but there is much of GLib that is does not use at all. This implementation uses even less.

No threading, no marshalling, no notifications.
No custom gobject constructor or properties.
Just support for the oop syntax.

### status: 
This is being rewriten. The original prototype is a header only static inline library.
The rewrite does not modify the glib headers, its only an alternate implementation.

At this point it just sort of works. But if you declare something not supported:

        public Thread t2;

you'll get a link error due to undefined references.

## Demos - using prototype version

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