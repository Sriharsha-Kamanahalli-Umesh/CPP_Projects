// RAII in C++ — “Resource Acquisition Is Initialization”
// RAII is a core C++ idiom that ties the lifetime of a resource (like memory, file handles, sockets, mutexes, etc.) to the lifetime of an object. In simple terms:

// Acquire the resource in the object’s constructor.
// Release the resource in the object’s destructor.
// Let scope control the lifetime—when the object goes out of scope (including due to exceptions), the destructor runs and the resource is safely released.

// This provides deterministic cleanup, strong exception safety, and makes code easier to reason about.