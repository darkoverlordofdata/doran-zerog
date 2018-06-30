
# Reason

GLib and GObject are a mess. There is no separation of concern, everything is twisted together. It can't be used modularly. I can't just leave threading out. I can't even get it to compile as is. The only reasons for using it is that other projects depend on it.

[why glib is a bad idea](http://repo.hu/cgi-bin/pool.cgi?cmd=show&node=glib)

I want to use Vala. But that ties me to a morass of dependency issues that are not very portable - I can't use it for example in Emscripten and Android among other enbedded environments. 

### Compatability

GLib.Object is customised to include some virtual methods copied from CSharp:
ToString, GatHashCode, and Equals, along with static methods: InstanceEquals and ReferenceEquals. This is to make it easier to port from CSharp, such as the Xna port.



### pcre

try using this to replace the static library dependencies?

    https://github.com/benekastah/empcre