# Chapter 2 - Functions

## Introduction
We introduce the concept of function within the creation of a software.

## Function Declaration and Definition

```cpp
// Declaration: function without body
return_type function_name( parameter list );
```

## Defining a Function

```cpp
// Definition: function with body
  return_type function_name( parameter_list ) {
    statement1;
    statement2;
  ...
    last statement;
}
```

## Local and Global Variables
We saw two types of variables and we have some experience on how to use them.
Note that const must go along a global variable.

## Working with Variable objects
We saw how the scope of a variable tied up with its lifetime during the execution of the program and the order of declaration has an impact on the order of destruction of every single data created within the scope of the whole program.

## Passing Arguments and Returning Values
We saw how we call functions, the difference between parameters and arguments.
We also saw how we do pass the arguments, passing by value (a copy is created within the scope of the function this could be very memory greedy) and passing by reference (an alias of the variable is called and we modify it inside the function and the changes remain after the stack of the function)

## Working with const References or r-value References
A temporary object cannot be passed as an argument for a reference parameter.
The r-value references are references that are identified by two ampersands (&&) and can only refer to temporary values.

### Returning Values from Functions
We saw the importance of return something if the function is not void type.

### Returning by Value
A function whose return type is a value type is said to return by value.

### Returning by Reference
A function whose return type is a reference is said to return by reference.

## Const Parameters and Default Arguments
Let's see how const is used in the various scenarios we investigated when looking at how functions can accept parameters.

### Passing by const Value
In pass by value, the function parameter is a value type: when invoked, the argument is copied into the parameter.
The only reason to use const in the function signature is to document to the
implementation that it cannot modify such a value.
There is an exception, though: when the function accepts a pointer.

### Passing by const Reference
Const is extremely important in pass by reference, and any time you use a reference in the parameters of a function, you should also add const to it (if the function is not designed to modify it).

### Returning by const Value
There is no widespread reason to return by const value since the calling code often assigns the value to a variable, in which case the const-ness of the variables is going to be the deciding factor, or passes the value to a next expression, and it is rare for an expression to expect a const value.

### Returning by const Reference
A function should always return by const reference when the returned reference is meant to only be read and not be modified by the calling code.

## Default Arguments
Default arguments are added to a function declaration. The syntax is to add an = sign and supply the value of the default argument after the identifier of the parameter of the function.
It is a best practice to set the default arguments in the function signature declaration,
and not declare them in the definition.

## Namespaces
A namespace starts a scope in which all the names declared inside are part of the namespace.
To access an identifier inside a namespace, you prepend the name of the identifier with the name of the namespace in which it is declared, followed by ::.