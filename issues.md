# issues

## In g_object, my_object_class_init gets an error:

Invalid function pointer called with signature 'vii'.

Workaround - EMULATE_FUNCTION_POINTER_CASTS=1


## Interfaces

    Invalid function pointer called with signature 'X'.

```c
	if (node_real_GetName != INODE_GET_INTERFACE ((INode*)self)->GetName)
		node_inode_interface_init (INODE_GET_INTERFACE ((INode*)self));
```


Asuming a class with an interface INode:

```c
static void node_instance_init (Node * self) {
	static int k = 0;
	if (k++ == 0)
		node_inode_interface_init (INODE_GET_INTERFACE ((INode*)self));

}
```

Only works with 1 interface...    
# Underlying problem:

https://kripken.github.io/emscripten-site/docs/porting/guidelines/function_pointer_issues.html

https://wiki.sei.cmu.edu/confluence/display/c/EXP37-C.+Call+functions+with+the+correct+number+and+type+of+arguments

GLib defines extra trailing parameters, like userdata pointers. Then, when using function pointers, they will define call backs that since they don't use the parameter, they don't define it in the argument list. (This does raise a compiler warning, but there a zillions of warnings when compiling gnome products...). xxx_class_init, xxx_class_finalize, and many other functions work this way. This is also undefined behavior. It doesn't crash on x86 architecture, so the developer doesn't care. But you can't port stuff like this...


