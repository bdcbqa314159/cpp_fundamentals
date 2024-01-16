# Chapter 6 - Object Oriented Programming

## Introduction

We learned about templates that are used to create functions and classes that work with arbitrary types. This avoids duplication of work. However, using templates is not applicable in all cases, or may not be the best approach. The limitation of templates is that their types need to be known when the code is compiled.
In real-world cases, this is not always possible. A typical example would be a program that determines what logging infrastructure to use depending on the value of a configuration file.
We can solve these problems using the concept of inheritance in C++.

## Inheritance

Inheritance allows the combination of one or more classes.

```cpp
class Vehicle {
    public:
      TankLevel getTankLevel() const;
      void turnOn();
  };
  class Car : public Vehicle {
    public:
      bool isTrunkOpen();
  };
```

Here Vehicle is the base class and Car is the derived class.
When specifying the list of classes to derive from, we can also specify the visibility of the inheritance – private, protected, or public.
The visibility modifier specifies who can know about the inheritance relationship between the classes.
