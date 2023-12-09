# Chapter 2 - Classes

## Introduction
We will be covering how to define and declare classes and how to access member functions of a class. We will explore what member and friend functions are and how to use each in a program. Later in the chapter, we will look at how constructors and destructors work. At the end of the chapter, we will explore functors and how you can we them.

## Declaring and Defining Class
A class is a way to combine data and operations together to create new types that can be used to represent complex concepts.

### The Advantages of Using Classes
Classes provide several benefits, such as abstraction, information hiding, and encapsulation.

### C++ Data Members and Access Specifiers
Inside the body of a class we have the class members such as: data memebers (fields) and member functions (methods).
We also have the access specifiers: private, public and protected.

### Static members

However, sometimes, we want to share the same value across all instances. In those cases, we can associate the field with the class instead of the instance by creating a static field. Let's examine the following syntax:

```cpp
class ClassName {
    static Type memberName;
};
```

It is important to define the values of the static variables in the .cpp file.
Always use const when declaring a static field.

In addition to static fields, classes can also have static methods.
A static method is associated with a class; it can be invoked without an instance. Since the fields and members of a class are associated with an instance, while static methods are not, static methods cannot invoke them. Static methods can be invoked using the scope resolution operator: ClassName::staticMethodName();.

Static methods can only call other static methods and static fields inside a class.

## Member Functions