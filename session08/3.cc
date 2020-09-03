In the lecture it was stated several times that initialization differs from assignment. Explain how they differ (or not) for the following:

a) variables of primitive type (e.g. int).
b) objects
c) constants
d) references



answers:

a) primative types are not initialized; they contain junk; assignment copies values into the variables.
b) objects are initialized by using a constructor such as copy or default or paramaterised ctors. Assignments invoke te assignment operator on the class which copies the other class and modifies the current class ie the target. This is not initialization.
c) constant cannot change once assigned(primatives) or initialized(objects).
d) references are aliases that refer to the originating object the reference was set to. Only assignment can occur from a object to a reference.

