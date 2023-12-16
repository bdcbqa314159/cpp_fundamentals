# Chapter 3 - Classes

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

Member Functions are functions that are used to manipulate the data members of a class, and they define the properties and behavior of the objects of the class.

### Declaring a Member Function

Member functions, like data members, must be declared inside the class. However, a member function's implementation can be placed either inside or outside the class, body.

### Using const Member Functions

The member functions of a class can be qualified as const, which means that the function limits its access to be read-only. Moreover, a member function is required to be const when it accesses const member data. So, const member functions are not allowed to modify the state of an object or call another function that does so.

Example of declaration of such kind of function:

```cpp
const std::string& getColor() const{

  // Function body

}
```

Three versions of const functions:

- The first one is a const member function
- The second returns a const reference
- The third one is a const function that returns a const reference

```cpp

type& function() const {}
const type& function() {}
const type& function() const {}

```

### The this Keyword

When the this keyword is used in the class context, it represents a pointer whose value is the address of the object on which the member function is called. It can appear within the body of any non-static member function.

Example:

```cpp

class Car{

  std::string color = "";

  void setColorBlue(){
    this->color = "Blue";
  }

};


```

Note: pointer->member is a convenient way to access the member of the struct pointed by pointer. It is equivalent to (*pointer).member.

### Non-Member Class-Related Functions

Defined as functions or operations that conceptually belong to the interface of a class, non-member class-related functions are not part of a class itself. 

```cpp
(...)
class Circle{
  public:
    int radius;
};

ostream& print(ostream& os, const Circle& circle){
  os<<"Circle has a radius of "<<circle.radius;
  return os;
}

```

## Constructors and Destructors

The way to initialize data members is by using a constructor. A constructor is a special member function that has the same name as the class and no return type, and it is called automatically by the compiler when a new object of the class is created.

The implementation of a class in private enforces the concept of class invariant.

A class invariant is a property or a set of properties of a class that should be true for any given instance of the class, at any point. It is called invariant because the set of properties do not vary; they are always true.

The constructor does not only initialize the data members but also ensure that the class
respects the invariant. After the constructor is executed, the invariant must be true.

## Overloading Constructors

Similar to other functions, we can overload the constructor by accepting different parameters. This is useful when an object can be created in several ways, since the user can create the object by providing the expected parameter, and the correct constructor is going to be called.

```cpp

class Rectangle{
  public:
  Rectangle();
  Rectangle(Square square);
};

void use_rectangle(Rectangle rectangle);

int main(){

  Square square;

  use_rectangle(square); //possible because the converting constructor

  return 0;
}

```

If we don't want these kind of implicit conversions we should use eplicit.

```cpp

class ExplicitRectangle{
  public:
  ExplicitRectangle();
  explicit ExplicitRectangle(Square square);
};

void use_explicit_rectangle(ExplicitRectangle rectangle);

int main(){

  Square square;

  use_explicit_rectangle(square); //error

  return 0;
}

```

## Constructor Member Initialization

Initializer lists are the recommended way to initialize member variables in C++, and they are necessary when a data member is const.

When using an initializer list, the order in which the members are constructed is the one in which they are declared inside the class; not the one in which they appear in the initializer list. Let's look at the following example:

```cpp

class Example(){

  Example(int x, int y):y_(y), x_(x){

  }

  private:
  int x_, y_;

};

```

Here even if y_ is setup first in the constructor it will be set after x_ because the order in the private section.

### Aggregate Classes Initialization

Classes or structs with no user-declared constructors, no private or protected specifiers non-static data members, no base classes, and no virtual functions are considered aggregate.

```cpp

struct Rectangle{
  int l,L;
};

int main(){

  Rectangle example = {10, 90};

  //this will put example.l = 10 and example.L = 90

  return 0;
}

```

### Destructors

A destructor function is called automatically when the object goes out of scope and is used to destroy objects of its class type.

```cpp

class Example(){

  public:
  Example();
  ~Example(); //destructor

};

```

### Default Constructor and Destructor
All the classes needs constructor and destructor functions. When the programmer does not define these, the compiler automatically creates an implicitly defined constructor and destructor.

Note: The default constructor might not initialize data members. Classes that have members of a built-in or compound type should ordinarily either initialize those members inside the class or define their version of the default constructor.
