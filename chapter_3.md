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

## Resource Acquisition Is Initialization (RAII)

RAII is a programming idiom that is used to manage the life cycle of a resource automatically by binding it to the lifetime of an object.

## Nested Class Declarations

Inside the scope of a class, we can declare more than just data members and member functions; we can declare a class inside another class. These classes are called nested classes.

Since a nested class declaration happens inside the outer class, it has access to all the declared names as if it were part of the outer class: it can access even private declarations.


```cpp

// Declaration
  class Coordinate {
  ...
    struct CoordinateDistance {
      float x = 0;
      float y = 0;
      static float walkingDistance(CoordinateDistance distance);
} };
  // Create an instance of the nested class CoordinateDistance
  Coordinate::CoordinateDistance distance;
  /* Invoke the static method walkingDistance declared inside the nested class
  CoordinateDistance */
  Coordinate::CoordinateDistance::walkingDistance(distance);

```

Nested classes are useful for two main reasons:

- When implementing a class, we need an object that manages some of the logic of the class. In such cases, the nested class is usually private, and is not exposed through the public interface of the class. It is mostly used to ease the implementation of the class.

- When designing the functionality of a class, we want to provide a different class, closely related to the original one, which provides part of that functionality. In that case, the class is accessible by the users of the class and is usually an important part of the interaction with the class.

An example of nested class is the iterator for a list of items.

## Friend Specifier

As we know, private and protected members of a class are not accessible from within other functions and classes. A class can declare another function or class as a friend: this function or class will have access to the private and protected members of the class which declares the friend relationship.

### Friend Functions

Friend functions are non-member functions that are entitled to access the private and protected members of a class.

```cpp

class theClass{

  private:
  int a;

  public:
  friend void show_a(const theClass& obj);

};

void show_a(const theClass &obj){
  std::cout<<obj.a<<std::endl;
}

```

### Friend Classes

Similarly, like a friend function, a class can also be made a friend of another class by using the friend keyword.

Note: Friendship is not mutual. If a class is a friend of another, then the opposite is not automatically true.

```cpp

class A{
  friend class B;
  int a = 0;
};

class B{
  friend class C;
  int b = 0;
};

class C{
  int c = 0;
  public:
  void access_a(const A& obj){
    std::cout<<obj.a<<std::endl; // Big error - friendship is not transitive.
  }
};

```

## Copy Constructor And Assignment Operators

One special type of constructor is the copy constructor. It initializes the data members of one object to another object. The object that's used to copy the member's value is passed as an argument to the copy constructor, typically of type reference to the class itself, and possibly const qualified.

```cpp

class class_name{

  public:
  class_name(const class_name& other): member(other.member){

  }
  private:
  int member;
};

```

Note: When a pointer is copied, we are not copying the object pointed to, but simply the address at which the object is located.
This means that when a class contains a pointer as a data member, the implicit copy constructor only copies the pointer and not the pointed object, so the copied object and the original one will share the object that's pointed to by the pointer. This is sometimes called a shallow copy.

## The copy Assignment Operator

An alternative way to copy an object is by using the copy assignment operator, which, contrary to the construct operator, is called when the object has been already initialized.

```cpp

class class_name{

  public:
  class_name& operator=(const class_name& other){
    member = other.member;
  }
  private:
  int member;
};

```

## The move-constructor and move-assignment Operator

Like copying, moving also allows you to set the data members of an object to be equal to those of another data member. The only difference with copying lies in the fact that the content is transferred from one object to another, removing it from the source.

The move-constructor and move-assignment are members that take a parameter of type rvalue reference to the class itself:

```cpp

class_name(const class_name &&other);

class_name&& operator=(const class_name &&other);

```

Note: For clarity, we can briefly describe an rvalue reference (formed by placing an && operator after the type of the function argument) as a value that does not have a memory address and does not persist beyond a single expression, for example, a temporary object.

A move constructor and a move assignment operator enable the resources owned by an rvalue object to be moved into an lvalue without copying.
When we move a construct or assign a source object to a destination object, we transfer the content of the source object into the destination object, but the source object needs to remain valid. To do so, when implementing such methods, it is fundamental to reset the data members of the source object to a valid value. This is necessary to prevent the destructor from freeing the resources (such as memory) of the class multiple times.

## Preventing Implicit Constructors and Assignment Operators

The compiler will implicitly generate the copy constructor, copy assignment, move constructor, and move assignment if our class respects all the required conditions.
For cases in which our class should not be copied or moved, we can prevent that.
To prevent the generation of implicit constructors and operators, we can write the declaration of the constructor or operator and add = delete; at the end of the declaration.

```cpp

class Rectangle {
    int length;
    int width;
    // Prevent generating the implicit move constructor
    Rectangle(Rectangle&& other) = delete;
    // Prevent generating the implicit move assignment
    Rectangle& operator=(Rectangle&& other) = delete;
  };

```

## Operator Overloading

C++ classes represent user-defined types. So, the need arises to be able to operate with these types in a different way. Some operator functions may have a different meaning when operating on different types. Operator overloading lets you define the meaning of an operator when applied to a class type object.

Note: Operator overloading is possible in two ways: either as a member function or as a non-member function. The two end up producing the same effect.

## Introducing Functors

A Functor (function object) is similar to a class. The class that overloads the operator() function is also known as the function call operator.

```cpp
class class_name {
    public:
      type operator()(type arg) {}
};
```

## Summary

In this chapter, we saw how the concept of classes can be used in C++. We started by delineating the advantages of using classes, describing how they can help us to create powerful abstractions.
We outlined the access modifiers a class can use to control who has access to class fields and methods.
We continued by exploring the conceptual differences between a class and its instances, along with the implications this has when implementing static fields and static methods.
We saw how constructors are used to initialize classes and their members, while destructors are used to clean up the resources that are managed by a class.
We then explored how constructors and destructors can be combined to implement the fundamental paradigm C++ is famous for: RAII. We showed how RAII makes it easy to create classes that handle resources and make programs safer and easier to work with.
Finally, we introduced the concept of operator overloading and how it can be used to create classes that are as easy to use as built-in types.
In the next chapter, we'll focus on templates. We'll primarily look at how to implement template functions and classes, and write code that works for multiple types.