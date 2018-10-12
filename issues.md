# issues

## In g_object, my_object_class_init gets an error:

#### Invalid function pointer called with signature 'vii'.

Workaround - EMULATE_FUNCTION_POINTER_CASTS=1


## Interfaces

#### Interface vtable gets klobbered. 

Asumming a class Dummy : Object, IDummy, IOther:

Workaround - 
```c
static void dummy_instance_init (Dummy * self) {
    static int k = 0;
    if (k++ == 0) {

        /** Reset vTables */
        
        IDummyIface * idummy = IDUMMY_GET_INTERFACE ((IDummyIface*)self);
        IOtherIface * iother = IOTHER_GET_INTERFACE ((IOtherIface*)self);

        iother->Test = (void (*) (IOther *)) dummy_real_Test;
        idummy->Jello = (void (*) (IDummy *)) dummy_real_Jello;

    }
}
```

#### And there's more...
There are several issues. Problem is, fix them and then there are integration issues

* different objects cannot share the same interface, it calls the wong object.
* 'is' operator doesn't work

# Underlying problem:

https://kripken.github.io/emscripten-site/docs/porting/guidelines/function_pointer_issues.html

https://wiki.sei.cmu.edu/confluence/display/c/EXP37-C.+Call+functions+with+the+correct+number+and+type+of+arguments

GLib defines extra trailing parameters, like userdata pointers. Then, when using function pointers, they will define call backs that since they don't use the parameter, they don't define it in the argument list. (This does raise a compiler warning, but there a zillions of warnings when compiling gnome products...). xxx_class_init, xxx_class_finalize, and many other functions work this way. This is also undefined behavior. It doesn't crash on x86 architecture, so the developer doesn't care.

In emscripten, function pointers are handled very differently, and this causes errors. Vala seems stable as long as I stay on the happy path. I can work with it this way for now, since this seems to be an area that is still evolving:
https://brionv.com/log/2018/05/06/emscripten-fun-porting-libffi-to-webassembly-part-1/

Interestingly - I'm also including libffi headers ... maybe that is where the issue is?