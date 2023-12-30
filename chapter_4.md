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