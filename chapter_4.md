# Chapter 4 - Generic Program4ming and Templates

If, for example, between two elements we want to implement operator<, then it is possible to find the greater of the two numbers, and the algorithm does not change. In these situations, C++ offers an effective tool—templates.

## Templates

Templates are a way to define functions or classes that can work for many different types, while still writing them only once.
They do so by having special kinds of parameters—type parameters.

```cpp
template<typename T>
T max(T a, T b){
  if (a>b) return a;
  else return b;
}
```

Note: You can also use the class keyword in place of typename, since there is no difference between them.

## Compiling the Template Code

When a template is instantiated, the compiler looks at the definition of the template and uses it to generate a new instance of the code, where all the references to the type parameters are replaced by the types that are provided when instantiating it.

Note: Since the compiler generates the code from the template definition, it means that the full definitions need to be visible to the calling code, not only the declaration, as was the case for functions and classes.

The template can still be forward declared, but the compiler must also see the definition. Because of this, when writing templates that should be accessed by several files, both the definition and the declaration of the templates must be in the header file.
This restriction does not apply if the template is used only in one file.

## Using Template Type Parameters

The compiler uses the template as a guide to generate a template instance with some concrete type when the template is used.
This means that we can use the type as a concrete type, including applying type modifiers to it.
A type can be modified by making it constant with the const modifier, and we can also take a reference to an object of a specific type by using the reference modifier:

```cpp

template<typename T>
  T createFrom(const T& other) {
      return T(other);
  }

```

Similarly, we have a lot of freedom in where we can use the template arguments.
Let's see two templates with a multiple template type argument:

```cpp
template<typename A, typename B>
  A transform(const B& b) {
      return A(b);
  }

template<typename A, typename B>
  A createFrom() {
    B factory;
    return factory.getA();
  }

```

We can see that we can use the template argument in the function parameter, in the return type, or instantiate it directly in the function body.

## Requirements of Template Parameter Types

When working with templates the compiler checks most of the errors, but only when we instantiate the template.
It is also very important to clearly document the requirements of the template so that the user does not have to read complicated error messages to understand which requirement is not respected.

Note: To make it easy to use our templates with many types, we should try to set the least requirements we can on the types.

# Defining Function and Class Templates

## Function Template

The decltype is a keyword that accepts an expression and returns the type of that expression. Let's examine the following code:

```cpp
int x;
decltype(x) y;

```

Other feature: trailing return types. Starting from C++11, it is possible to use a trailing return type: specifying the return type at the end of the function signature. The syntax to declare a function with a trailing return type is to use the keyword auto, followed by the name of the function and the parameters, and then by an arrow and the return type.

```cpp
template<typename User>
auto getAccount(User user) -> decltype(user.getAccount());

```

More recently, C++14 introduced the ability to simply specify auto in the function declaration, without the need for the trailing return type:

```cpp
auto max(int a, int b)

```
The return type is automatically deduced by the compiler, and to do so, the compiler needs to see the definition of the function—we cannot forward declare functions that return auto.
Additionally, auto always returns a value—it never returns a reference: this is something to be aware of when using it, as we could unintentionally create copies of the returned value.

A template is just a blueprint for a function, and the real function is going to be created only when the template is instantiated. C++ allows us to instantiate the template function even without calling it. We can do this by specifying the name of the template function, followed by the template parameters, without adding the parameters for the call.

```cpp
template<typename T>
void sort(std::array<T, 5> array, bool (*function)(const T&, const T&));

template<typename T>
  bool less(const T& a, const T& b) {
  return a < b; }

int main() {
    std::array<int, 5> array = {4,3,5,1,2};
    sort(array, &less<int>);
}

```

## Class Templates

The syntax for class templates is equivalent to the one for functions: first, there is the template declaration, followed by the declaration of the class:


```cpp
template<typename T>
  class MyArray {
// As usual
};
```

Like functions, class template code gets generated when the template is instantiated, and the same restrictions apply: the definition needs to be available to the compiler and some of the error-checking is executed when the template is instantiated.

When writing a class template, the name of the class can be used directly, and it will refer to the specific template instance being created:

```cpp
template<typename T>
  class MyArray {
    /* There is no need to use MyArray<T> to refer to the class, MyArray
  automatically refers to the current template instantiation*/

    MyArray(); //<-Define the constructor for the current template T
    MyArray<T>(); //<-This is not a valid constructor.
  };

```

Like regular classes, template classes can have fields and methods. The field can depend on the type declared by the template. Let's review the following code example:

```cpp
template<typename T>
  class MyArray {
    T[] internal_array;
  };

```

Classes can also have templated methods. Templated methods are similar to template functions, but they can access the class instance data.
Let's review the following example:

```cpp
template<typename T>
  class MyArray {
    template<typename Comparator>
    void sort (const Comparator & element);
  };

```
The sort method will accept any type and will compile if the type satisfies all the requirements that the method imposes on the type.

```cpp
MyArray<int> array;
MyComparator comparator;
array.sort<MyComparator>(comparator);
```

We need to remember that the template is a guide on the code that will be generated for the specific types. This means that when a template class declares a static member, the member is shared only between the instantiations of the template with the same template parameters:

```cpp
template<typename T>
  class MyArray {
    const Static int element_size = sizeof(T);
  };

MyArray<int> int_array1;
MyArray<int> int_array2;
MyArray<std::string> string_array;

```
int_array1 and int_array2 will share the same static variable, element_size, since
they are both of the same type: MyArray<int>. On the other hand, string_array has
a different one, because its class type is MyArray<std::string>. MyArray<int> and MyArray<std::string>, even if generated from the same class template, are two different classes, and thus do not share static fields.

## Dependent Types

It's fairly common, especially for code that interacts with templates, to define some public aliases to types.
A typical example would be the value_type type alias for containers, which specifies the type contained:

```cpp
template<typename T>
class MyArray {
public:
  using value_type = T;
};

```

Since we know the type of the vector, we could write this kind of code:

```cpp
void createOneAndAppend(std::vector<int>& container) {
  int new_element{}; // We know the vector contains int
  container.push_back(new_element);
}
```

But the problem arises when we accept any container which accepts the push_back method:

```cpp
template<typename Container>
void createOneAndAppend(Container& container) {
    // what type should new_element be?
  container.push_back(new_element);
}
```

We can access the type alias declared inside the container, which specifies which kind
of values it contains, and we use it to instantiate a new value:

```cpp
template<typename Container>
void createOneAndAppend(Container& container) {
  Container::value_type new_element;
  container.push_back(new_element);
}

```
This code, unfortunately, does not compile.
The reason for this is that value_type is a dependent type. A dependent type is a type that is derived from one of the template parameters.
To solve this issue, we can tell the compiler that we are accessing a type in the class, and we do so by prepending the typename keyword to the type we are accessing:

```cpp
template<typename Container>
void createOneAndAppend(Container& container) {
  typename Container::value_type new_element{};
  container.push_back(new_element);
}

```

## Non-Type Template Parameters

Templates in C++ have an additional feature—non-type template parameters.
The declaration of a non-type template parameter is in the parameter list of the template, but instead of starting with a typename keyword such as the type parameters, it starts with the type of the value, followed by the identifier.
There are strict restrictions on the types that are supported as non-type template parameters: they must be of integral type.
Let's examine the following example of the declaration of a non-type template parameter:

```cpp
template<typename T, unsigned int size>
  Array {
    // Implementation
  };
```

What is the difference between template and non-template parameters? Why would we use a non-type template parameter instead of a regular parameter?
The main difference is when the parameter is known to the program. Like all the template parameters and unlike the non-template parameters, the value must be known at compile time.
This is useful when we want to use the parameters in expressions that need to be evaluated at compile time, as we do when declaring the size of an array.
The other advantage is that the compiler has access to the value when compiling the code, so it can perform some computations during compilation, reducing the amount of instruction to execute at runtime, thus making the program faster.
Additionally, knowing some values at compile time allows our program to perform additional checks so that we can identify problems when we compile the program instead of when the program is executed.

## Default Template Arguments

The syntax for default template arguments is to add after the template identifier the equal, followed by the value:

```cpp
template<typename MyType = int>
void foo();
```

Correct way to doing things: A has a default value, and no other template parameter without default value comes after it. It also references T, which is declared before the template parameter A.

```cpp
template<typename T, typename A = T >
void foo();
```

The reason to use the default arguments is to provide a sensible option for the
template, but still allowing the user to provide their own type or value when needed.

## Template Argument Deduction

Template argument deduction refers to the ability of the compiler to automatically understand some of the types that are used to instantiate the template, without the user having to explicitly type them.

## Parameter and Argument Types

The compiler cannot deduce a type for any of the following reasons:
- The type is not used in the parameters. For example: the compiler cannot deduce a type if it is only used in the return type, or only used inside the body of the function.
- The type in the parameter is a derived type.

Knowing these rules, we can derive a best practice for the order of the template parameters when writing templates: the types that we expect the user to provide need to come before the types that are deduced.

If we use:
```cpp
template<typename A, typename B, typename C>
C foo(A, B);
```

We will need to call
```cpp
foo<int, double, float>(1,2.23);
```

But if we use:
```cpp
template<typename C,typename A, typename B>
C foo(A, B);
```

And for this we can call:
```cpp
foo<float>(1,2.3);
```

## Being Generic Templates

We have learned how the compiler can make our templated functions easier to use by automatically deducing the types used. The template code decides whether to accept a parameter as a value or a reference, and the compiler finds the type for us. But what do we do if we want to be agnostic regarding whether an argument is a value or a reference, and we want to work with it regardless?

An example would be std::invoke in C++17. std::invoke is a function that takes a function as the first argument, followed by a list of arguments, and calls the function with the arguments.

How can we write a function such as std::invoke that works regardless of the kind of reference (colloquially referred to as "ref-ness", similarly to how "const-ness" is used to talk about whether a type is const qualified) of the parameters?
The answer to that is forwarding references.

Forwarding references look like r-value references, but they only apply where the type
is deduced by the compiler:

```cpp
void do_action(PrintOnCopyOrMove&&) // not deduced: r-value reference
  
template<typename T>
void do_action(T&&) // deduced by the compiler: forwarding reference
```

In Chapter 3, Classes, we learned that std::move can make our code more efficient when we need to use an object that we are not going to access after the call happens.
But we saw that we should never move objects we receive as an l-value reference parameter, since the code that called us might still use the object after we return.
When we are writing templates using a forwarding reference, we are in front of a dilemma: our type might be a value or a reference, so how do we decide whether we can use std::move?

```cpp
template<typename T>
void do_action(T&& obj) {
    do_something_with_obj(???);
  // We are not using obj after this call.
  }
```

Should we use move or not in this case?
The answer is yes: we should move if T is a value, and, no, we should not move if T is a
reference.
C++ provides us with a tool to do exactly this: std::forward.
std::forward is a function template that always takes an explicit template parameter and a function parameter: std::forward<T>(obj).

Forward looks at the type of T, and if it's an l-value reference, then it simply returns a reference to the obj, but if it's not, then it is equivalent to calling std::move on the object.

```cpp
template<typename T>
void do_action(T&& obj) {
  use_printoncopyormove_obj(std::forward<T>(obj));
}
```

Note: A template can have many type parameters. Forwarding references can apply to any of the type parameters independently.


