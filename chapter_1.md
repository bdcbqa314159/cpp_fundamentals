# Chapter 1

## Compilation Model
We saw the importance of include guards, the process of compilation and how to write a simple executable and compile it.
The first exercise was not done as I use Makefile and CMake commands to compile c++ code.

## Built-in Data Types
We saw the basics of primitive data types, the data types modifiers and variable definition with some naming conventions.
Two new types of initialisation has been covered:
```
auto variable_name = value;

type variable1;
decltype(variable1) variable2;
```

Note that the auto keyword needs an initialisation.

## Pointers and References
We saw pointers, references, const qualifier (+constexpr) and scope of variables.

```
#include <iostream>

int global = 10;

int main(){

    int global = 20;

    std::cout<<"global: "<<::global<<std::endl; //10
    std::cout<<"local: "<<global<<std::endl; //20

    return 0;
}
```

## Control Flow Statements

We saw selection statements: if else, else if logic, the swith usage.
We saw iteration statements: for, while and do while loops.
We saw jump statements: break, continue.

## The try-catch Block

We saw the mere basic in order to understand how it does work.

## Arrays

...

