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