# Chapter 5 - Standard Library Containers and Algorithms

## Introduction

The core of C++ is its Standard Template Library (STL), which represents a set of important data structures and algorithms that facilitates the programmer's task and improves code efficiency.
The components of the STL are parametric so that they can be reused and combined in different ways. The STL is mainly made up of container classes, iterators, and algorithms.

## Sequence Containers

Sequence containers, sometimes referred to as sequential containers, are a particular class of containers where the order in which their elements are stored is decided by the programmer rather than by the values of the elements. Every element has a certain position that is independent of its value.

### Array
The array container is a fixed-size data structure of contiguous elements.
An array's size needs to be specified at compile time. Once defined, the size of the array
cannot be changed.
When an array is created, the size elements it contains are initialized next to each other in memory. While elements cannot be added or removed, their values can be modified.
Arrays can be randomly accessed using the access operator with the corresponding element's index. To access an element at a given position, we can use the operator [] or the at() member function. The former does not perform any range checks, while the latter throws an exception if the index is out of range. Moreover, the first and the last element can be accessed using the front() and back() member functions.
These operations are fast: since the elements are contiguous, we can compute the position in memory of an element given its position in the array, and access that directly.
The size of the array can be obtained using the size() member function. Whether the container is empty can be checked using the empty() function, which returns true if size() is zero.
The array class is defined in the ```cpp <array>``` header file, which has to be included before usage.

### Vector
The vector container is a data structure of contiguous elements whose size can be dynamically modified.
The vector class is defined in the ```cpp <vector>``` header file.
A vector stores the elements it contains in a single section of memory. Usually, the section of memory has enough space for more elements than the number of elements stored in the vector. When a new element is added to the vector, if there is enough space in the section of memory, the element is added after the last element in the vector. If there isn't enough space, the vector gets a new, bigger section of memory and copies all the existing elements into the new section of memory, then it deletes the old section of memory. 
When the vector is created, it is empty.
Most of the interface is similar to the array's, but with a few differences.
Elements can be appended using the push_back() function or inserted at a generic position using the insert() function. The last element can be removed using pop_back() or at a generic position using the erase() function.
Appending or deleting the last element is fast, while inserting or removing other elements of the vector is considered slow, as it requires moving all the elements to make space for the new element or to keep all the elements contiguous.
Vectors, just like arrays, allow efficient access of elements at random positions. A vector's size is also retrieved with the size() member function, but this should not be confused with capacity(). The former is the actual number of elements in the vector, and the latter returns the maximum number of elements that can be inserted in the current section of memory.
The operation of getting a new section of memory is called reallocation. Since reallocation is considered an expensive operation, it is possible to reserve enough memory for a given number of elements by enlarging a vector's capacity using the reserve() member function. The vector's capacity can also be reduced to fit the number of elements using the shrink_to_fit() function in order to release memory that is not needed anymore.

Note: Vector is the most commonly used container for a sequence of elements and is often the best one performance-wise.

### Deque

The deque container (pronounced deck) is short for "double-ended queue." Like vector, it allows for fast, direct access of deque elements and fast insertion and deletion at the back. Unlike vector, it also allows for fast insertion and deletion at the front of the deque.
The deque class is defined in the ```cpp <deque>``` header file.
Deque generally requires more memory than vector, and vector is more performant for accessing the elements and push_back, so unless it is required to insert at the front, vector is usually preferred.

### List

The list container is a data structure of nonadjacent elements that can be dynamically grown.

The list class is defined in the ```cpp <list>``` header file.
Each element in the list has its memory segment and a link to its predecessor and its successor. The structure containing the element, which is the link to its predecessor and to its successor, is called a node.
When an element is inserted in a list, the predecessor node needs to be updated so that its successor link points to the new element. Similarly, the successor node needs to be updated so that its predecessor link points to the new element.
When an element is removed from the list, we need to update the successor link of
the predecessor node to point to the successor of the removed node. Similarly, the predecessor link of the successor node needs to be updated to point to the predecessor of the removed node.
Unlike vectors, lists do not provide random access. Elements are accessed by linearly following the chain of elements: starting from the first, we can follow the successor link to find the next node, or from the last node we can follow the predecessor link to find the previous node, until we reach the element we are interested into.
The advantage of list is that insertion and removal are fast at any position, if we already know the node at which we want to insert or remove. The disadvantage of this is that getting to a specific node is slow.
The interface is similar to a vector, except that lists don't provide operator[].

### Forward-List

The forward_list container is similar to the list container, with the difference that its nodes only have the link to the successor. For this reason, it is not possible to iterate over a forward_list in backward order.
As usual, the forward_list class is defined in the ```cpp <forward_list>``` header file.
The forward_list class does not even provide push_back() or size(). Inserting an element is done using insert_after(), which is a variation of the insert() function, where the new element is inserted after the provided position. The same idea applies to element removal, which is done through erase_after(), which removes the element after the provided position.


### Providing Initial Values to Sequence Containers

All the sequence containers we have looked at are empty when they are first created. When we want to create a container containing some elements, it can be repetitive to
call the push_back() or insert() functions repeatedly for each element.
Fortunately, all the containers can be initialized with a sequence of elements when they are created.
The sequence must be provided in curly brackets, and the elements need to be comma-
separated. This is called an initializer list.
This works for any of the containers we have seen in this chapter.

## Associative Containers

Associative containers are containers that allow for the fast lookup of elements. Additionally, the elements are always kept in a sorted order. The order is determined by the value of the element and a comparison function. The comparison function is called a comparator, and by default this is the operator<, although the user can supply a Functor (function object) as a parameter to specify how the elements should be compared. The ```cpp <functional>``` header contains many such objects that can be used to sort the associative containers, like std::greater or std::less.

### Set and Multiset

A Set is a container that contains a unique group of sorted elements. A Multiset is similar to Set, but it allows duplicate elements.
Set and multiset have size() and empty() function members to check how many elements are contained and whether any elements are contained.
Insertion and removal is done through the insert() and erase() functions. Because the order of the elements is determined by the comparator, they do not take a position argument like they do for sequential containers. Both insertion and removal are fast.
Since sets are optimized for element lookup, they provide special search functions. The find() function returns the position of the first element equal to the provided value, or the position past the end of the set when the element is not found. When we look for an element with find, we should always compare it with the result of calling end() on the container to check whether the element was found.
Finally, count() returns the number of elements equal to the value provided.
The set and multiset classes are defined in the ```cpp <set>``` header file.

### Map and Multimap

Map and multimap are containers that manage key/value pairs as elements. The elements are sorted automatically according to the provided comparator and applied to the key: the value does not influence the order of the elements.
Map allows you to associate a single value to a key, while multimap allows you to associate multiple values to the same key.
The map and multimap classes are defined in the ```cpp <map>``` header file.
To insert values into a map, we can call insert(), providing a pair containing the key and the value. Later in this chapter, we will see more about pairs. The function also returns a pair, containing the position at which the element was inserted, and a Boolean set to true if the element was inserted, or false if an element with the same key already exists.
Once values are inserted into the map, there are several ways to look up a key/value pair in a map.
Similar to set, map provides a find() function, which looks for a key in the map and returns the position of the key/value pair if it exists, or the same result of calling end().
From the position, we can access the key with position->first and the value with position->second.
An alternative to accessing a value from a key is to use at(), which takes a key and returns the associated value.
If there is no associated value, at() will throw an exception.
A last alternative to get the value associated with a key is to use operator[].
The operator[] returns the value associated with a key, and if the key is not present, it inserts a new key/value pair with the provided key, and a default value for the value. Because operator[] could modify the map by inserting into it, it cannot be used on a const map.

## Unordered Containers

Unordered associative containers differ from associative containers in that the elements have no defined order. Visually, unordered containers are often imagined as bags of elements. Because the elements are not sorted, unordered containers do not accept a comparator object to provide an order to the elements. On the other hand, all the unordered containers depend on a hash function.
The user can provide a Functor (function object) as a parameter to specify how the keys should be hashed.

Typically, unordered containers are implemented as hash tables. The position in the array is determined using the hash function, which given a value returns the position at which it should be stored. Ideally, most of the elements will be mapped into different positions, but the hash function can potentially return the same position for different elements. This is called a collision. This problem is solved by using linked lists to chain elements that map into the same position, so that multiple elements can be stored in the same position. Because there might be multiple elements at the same position, the position is often called bucket.
Implementing unordered containers using a hash table allows us to find an element with a specific value in constant time complexity, which translates to an even faster lookup when compared to associative containers.

### Unordered Set/Multiset -  Unordered Map/Multimap
Unordered associative containers and ordered associative containers provide the same functionalities, and the explanations in the previous section apply to the unordered associative containers as well. Unordered associative containers can be used to get better performances when the order of the elements is not important.

## Containers Adaptors
Additional container classes that are provided by the STL library are container adaptors. Container adaptors provide constrained access policies on top of the containers we have looked at in this chapter.

### Stack

The stack container implements the LIFO access policy, where the elements are virtually stacked one on the top of the other so that the last inserted element is always on top. Elements can only be read or removed from the top, so the last inserted element is the first that gets removed. A stack is implemented using a sequence container class internally, which is used to store all the elements and emulate the stack behavior.
The access pattern of the stack data structure happens mainly through three core member functions: push(), top(), and pop(). The push() function is used to insert an element into the stack, top() used to access the element on top of the stack, and pop() is used to remove the top element.
The stack class is defined in the ```cpp <stack>``` header file.

### Queue

The queue class implements the FIFO access policy, where the elements are enqueued one after the other, so that elements inserted before are ahead of elements inserted after. Elements are inserted at the end of the queue and removed at the start.
The interface of the queue data structure is composed of the push(), front(), back(), and pop() member functions.
The push() function is used to insert an element into the queue(); front() and back() return the next and last elements of the queue, respectively; the pop() is used to remove the next element from the queue.
The queue class is defined in the ```cpp <queue>``` header file.

### Priority Queue

Finally, the priority queue is a queue where the elements are accessed according to
their priority, in descending order (highest priority first).
The interface is similar to the normal queue, where push() inserts a new element and top() and pop() access and remove the next element. The difference is in the way the next element is determined. Rather than being the first inserted element, it is the element that has the highest priority.
By default, the priority of the elements is computed by comparing the elements with the operator<, so that an element that is less than another comes after it. A user- defined sorting criterion can be provided to specify how to sort the elements by priority in regard to their priority in the queue.
The priority queue class is also defined in the ```cpp <queue>``` header file.

## Unconventional Containers

The C++ standard defines some other types that can contain types but offer a different set of functionalities from the containers we saw previously.

### Strings

A string is a data structure that's used to manipulate mutable sequences of contiguous characters. The C++ string classes are STL containers: they behave similarly to vectors, but provide additional functionalities that ease the programmer to perform common operations of sequences of characters easily.

There exist several string implementations in the standard library that are useful for different lengths of character sets, such as string, wstring, u16string, and u32string. All of them are a specialization of the basic_string base class and they all have the same interface.
The most commonly used type is std::string.
All types and functions for strings are defined in the ```cpp <string>``` header file.
A string can be converted into a null-terminating string, which is an array of characters that terminate with the special null character (represented with '\0') via the use of the data() or c_str() functions. Null-terminating strings, also called C-strings, are the way to represent sequences of character in the C language and they are often used when the program needs to interoperate with a C library; they are represented with the const char * type and are the type of the literal strings in our programs.

As for vectors, strings have size(), empty(), and capacity() member functions, but there is an additional function called length(), which is just an alias for size().
Strings can be accessed in a character-by-character fashion using operator[] or the at(), front(), and back() member functions.

The usual comparison operators are provided for strings, thus simplifying the way two string objects can be compared.
Since strings are like vectors, we can add and remove characters from them. Strings can be made empty by assigning an empty string, by calling the clear(), or
erase() functions.
Let's look at the following code to understand the usage of the clear() and erase()
functions.

C++ also provides many convenience functions to convert a string into numeric values or vice versa. For example, the stoi() and stod() functions (which stand for string- to-int and string-to-double) are used to convert string to int and double, respectively. Instead, to convert a value into a string, it is possible to use the overloaded function to_string().

### Pairs and Tuples

The pair and tuple classes are similar to some extent, in the way they can store a collection of heterogeneous elements.
The pair class can store the values of two types, while the tuple class extended this concept to any length.
Pair is defined in the ```cpp <utility>``` header, while tuple is in the ```cpp <tuple>``` header.
The pair constructor takes two types as template parameters, used to specify the types for the first and second values. Those elements are accessed directly using the first and second data. Equivalently, these members can be accessed with the get<0>() and get<1>() functions.
The make_pair() convenience function is used to create a value pair without explicitly specifying the types.
Pairs are used by unordered map, unordered multimap, map, and multimap containers to manage their key/value elements.
Tuples are similar to pairs. The constructor allows you to provide a variable number of template arguments. Elements are accessed with the get<N>() function only, which returns the nth element inside the tuple, and there is a convenience function to create them similar to that for pair, named make_tuple().
Additionally, tuples have another convenience function that's used to extract values from them. The tie() function allows for the creation of a tuple of references, which is useful in assigning selected elements from a tuple to specific variables.

### std::optional

optional<T> is a that's used to contain a value that might be present or not.
The class takes a template parameter, T, which represents the type that the std::optional template class might contain. Value type means that the instance of the class contains the value. Copying optional will create a new copy of the contained data.
At any point in the execution of the program, optional<T> either contains nothing, when it's empty, or contains a value of type T.
Optional is defined in the ```cpp <optional>``` header.
Let's imagine our application is using a class named User for managing registered users. We would like to have a function that gets us the information of a user from their email: 
```cpp
User getUserByEmail(Email email);
```
But what happens when a user is not registered? That is, when we can determine that our system does not have the associated User instance?
Some would suggest throwing an exception. In C++, exceptions are used for exceptional situations, ones that should almost never happen. A user not being registered on our website is a perfectly normal situation.

In these situations, we can use the optional template class to represent the fact that we
might not have the data:
```cpp
std::optional<User> tryGetUserByEmail(Email email);
```

The optional template provides two easy methods to work with:

- has_value(): This returns true if optional is currently holding a value, and false if
the variant is empty.

- value(): This function returns the value currently held by optional, or throws an exception if it's not present.

- Additionally, optional can be used as a condition in an if statement: it will evaluate to true if it contains a value, or false otherwise.

Let's look at the following example to understand how the has_value() and value() functions work:

```cpp
#include <iostream>
#include <optional>

int main() {
    // We might not know the hour. But if we know it, it's an integer
    std::optional<int> currentHour;
    if (not currentHour.has_value()) {
      std::cout << "We don't know the time" << std::endl;
    }
    currentHour = 18;
    if (currentHour) {
      std::cout << "Current hour is: " << currentHour.value() << std::endl;
    }
  }
```

The optional template comes with additional convenience features. We can assign the std::nullopt value to optional to make it explicit when we want it empty, and we can use the make_optional value to create an optional from a value. Additionally, we can use the dereference operator, *, to access the value of optional without throwing an exception if the value is not present. In such cases, we will access invalid data, so we need to be sure that optional contains a value when we use *:

```cpp
std::optional<std::string> maybeUser = std::nullopt;
if (not maybeUser) {
    std::cout << "The user is not present" << std::endl;
}
maybeUser = std::make_optional<std::string>("email@example.com");
if (maybeUser) {
    std::cout << "The user is: " << *maybeUser  << std::endl;
}
```

Another handy method is value_or(defaultValue). This function takes a default value and returns the value contained by optional if it currently holds a value, otherwise it returns the default value. Let's explore the following example:

```cpp
#include <iostream>
#include <optional>
int main() {
    std::optional<int> x;
    std::cout << x.value_or(10) << std::endl;
    //Will return value of x as 10
    x = 15;
    std::cout << x.value_or(10)<< std::endl;
    //Will return value of x as 15
}
```
In addition to return values, optional is useful when accepting it as an argument to
represent arguments that can be present or not.
Let's recall our User class that's composed of an email address, a phone number, and a physical address. Sometimes, users don't have a phone number and don't want to provide a physical address, so the only required field we have in User is the email address:

```cpp
User::User(Email email, std::optional<PhoneNumber> phoneNumber =std::nullopt,std::optional<Address> address = std::nullopt){
...
}
```
This constructor allows us to pass in all the information we have on the user. If, instead of using optional, we used multiple overloads, we would have had four overloads:

- Only email
- Email and phone number
- Email and address
- Email with phone number and address

You can see that the number of overloads grows quickly when there are more arguments that we might not want to pass.

### std::variant

variant is a value type that's used to represent a choice of types. The class takes a list of types, and the variant will be able to contain one value of any of those types.
It is often referred to as tagged union, because similar to a union, it can store multiple types, with only one present at a time. It also keeps track of which type is currently stored.
During the execution of a program, variant will contain exactly one of the possible types at a time.
Like optional, variant is a value type: when we create a copy of variant, the element that is currently stored is copied into the new variant.

To interact with std::variant, the C++ standard library gives us two main functions:
- ```cpp holds_alternative<Type>(variant)```: It returns true if the variant is currently holding the provided type, if not then false.
- get(variant): There are two versions: ```cpp get<Type>(variant)``` and ```cpp get<Index>(variant)```.

```cpp get<Type>(variant)``` gets the value of the type that's currently stored inside the variant. Before calling this function, the caller needs to be sure that ```cpp holds_ alternative<Type>(variant)``` returns true.
```cpp get<Type>(variant)``` gets the value of the index type that's currently stored inside variant. Like before, the caller needs to be sure that variant is holding the correct type.
For example, with ```cpp std::variant<string, float>``` variant, calling ```cpp get<0>(variant)``` will give us the string value, but we need to be sure that variant is currently storing a string at the moment. Usually, it is preferable to access the elements with ```cpp get<Type>()``` so that we are explicit on the type that we expect and that if the order of the types in the variant changes, we will still get the same result.

An alternative way to get the content of variant is to use std::visit(visitor, variant), which takes variant and a callable object. The callable objects need to support an overload of operator(), taking a type for each of the possible types stored inside variant. Then, visit will make sure to call the function that accepts the current type that's stored inside variant.

std::variant is incredibly valuable when we want to represent a set of values of different types. Typical examples are as follows:
- A function returning different types depending on the current state of the program
- A class that represents several states

Thanks to optional, we could now write the function in a clear way, showing that sometimes we would not retrieve the user. It is likely that if the user is not registered, we might ask them whether they want to register.
Let's imagine we have struct UserRegistrationForm, which contains the information that's needed to let the user register.
Our function can now return ```cpp std::variant<User, UserRegistrationForm> tryGetUserByEmail()```. When the user is registered, we return User, but if the user is not registered, we can return the registration form.
Additionally, what should we do when there is an error? With variant, we could have struct GetUserError storing all the information we have so that our application will be able to recover from the error and add it to the return type: ```cpp std::variant<User, UserRegistrationForm, GetUserError>```, or tryGetUserByEmail().
Now we can have the complete picture of what is going to happen when we call getUserByEmail() by just looking at the function signature, and the compiler will help us make sure that we handle all the cases.
Alternatively, variant can also be used to represent the various states in which a class can be. Each state contains the data that's required for that state, and the class only manages the transitions from one state to another.

## Iterators

Iterators are the way in which the position of an element in a container is represented.
An iterator always belongs to a range. The iterator representing the start of the range, can be accessed by the begin() function, while the iterator representing the end of the range, non-inclusive, can be obtained with the end() function. The range where the first element is included, but where the last one is excluded, is referred to as half-open.

- Input iterators: can step forward and allow you to read the element it is pointing to. The iterator can be copied, but when one copy is incremented or dereferenced to access the element, all the other copies are invalidated and cannot be incremented or dereferenced anymore. Conceptually, it means that elements in a sequence that are accessed through an input iterator can only be read once at most.
Typically, input iterators are used to access elements from a stream of elements, where the whole sequence is not stored in memory, but we are obtaining one element at a time.

- Forward iterators: are very similar to input iterators but provide additional guarantees.
The same iterator can be dereferenced several times to access the element it points to.
Additionally, when we increment or dereference a forward iterator, the other copies are not invalidated: if we make a copy of a forward iterator, we can advance the first one, and the second can still be used to access the previous element.
Two iterators that refer to the same element are guaranteed to be equal.

- Bidirectional iterators: are also forward iterators with the additional ability to iterate backward over the elements using the operator-- (position decrement) member function.

- Random-access iterators: are also bidirectional iterators with the additional ability to directly access any position without the need of a linear scan, in constant time. Random-access iterators are provided by the operator[] member function to access elements at generic indexes and the binary operator+ and operator- to step forward and backward of any quantity.

### Reverse Iterators

A reverse iterator wraps a bidirectional iterator and swaps the operation increment with the operation of decrement, and vice versa.
Because of this, when we are iterating a reverse iterator in the forward direction, we are visiting the elements in a range in backward order.

### Insert Iterators

Insert iterators, also called inserters, are used to insert new values into a container rather than overwrite them.

### Stream Iterators

Stream iterators allow us to use streams as a source to read elements from or as a destination to write elements to.
Because we don't have a container in this case, we cannot call the end() method to get the end iterator. A default constructed stream iterator counts as the end of any stream range.

### Iterator Invalidation

As we said, iterators represent the position of elements in a container.
This means that they are tightly tied with the container, and changes to the container might move the elements: this means that iterators pointing to such an element can no longer be used – they are invalidated.

It is extremely important to always check the invalidation contract when using iterators with containers, as it is not specified what happens when using an invalidated iterator. More commonly, invalid data is accessed or the program crashes, leading to bugs that are hard to find.
If we keep in mind how the containers are implemented, as we saw earlier in this chapter, we can more easily remember when an iterator is invalidated.
For example, we said that when we insert an element in a vector, we might have to
get more memory to store the element, in which case all the previous elements are moved to the newly obtained memory. This means that all the iterators pointing to the elements are now pointing to the old location of the elements: they are invalidated.
On the other hand, we saw that when we insert an element into the list, we only have to update the predecessor and successor nodes, but the elements are not moved. This means that the iterators to the elements remain valid.

## Algorithms Provided by the C++ Standard Template Library

Algorithms are a way to operate on containers in an abstract way.
The C++ standard library provides a wide range of algorithms for all the common operations that can be performed on ranges of elements.
Because algorithms accept iterators, they can operate on any container, even user- defined containers, as long as they provide iterators.

### Lambda

Most of the algorithms accept a unary or binary predicate: a Functor (function object), which accepts either one or two parameters. These predicates allow the user to specify some of the actions that the algorithm requires. What the actions are vary from algorithm to algorithm.

This can be very verbose, especially when the functor should perform a simple operation.
To overcome this with C++, the user has to write a lambda expression, also called just a lambda.

A lambda expression creates a special function object, with a type known only by the compiler, that behaves like a function but can access the variables in the scope in which it is created.
It is defined with a syntax very similar to the one of functions:

```cpp
[captured variables] (arguments) { body }
```

Arguments is the list of arguments the function accepts, and body is the sequence of statements to execute when the function is invoked.

```cpp

auto sum_numbers = [](int a, int b){return a+b;}

std::cout<<sum_numbers(1,2)<<std::endl; // -> we see 3

```

Additionally, lambdas can capture a variable in the local scope, and use it in their body.
Captured variables entail a list of variable names that can be referenced in the body of the lambda.
When a variable is captured, it is stored inside the created function object, and it can be referenced in the body.

```cpp

int addend = 1;
auto sum_numbers = [addend](int b){return addend+b;}

addend = 2;

std::cout<<sum_numbers(2)<<std::endl; // -> we see 2 because the copie is equal to 1

```

In some situations, we want to be able to modify the value of a variable in the scope in which the lambda is created, or we want to access the actual value, not the value that the variable had when the lambda was created.
In that case, we can capture by reference by prepending & to the variable name.

```cpp

int addend = 1;
auto sum_numbers = [&addend](int b){return addend+b;}

addend = 2;

std::cout<<sum_numbers(2)<<std::endl; // -> we see 4 because the reference updates to 2

```

A lambda can capture multiple variables, and each one can be either captured by value or by reference, independently one from the other.

### Read-Only Algorithms

Read-only algorithms are algorithms that inspect the elements stored inside a container but do not modify the order of the elements of the container.

The following are the most common operations that inspect the elements of a range:

- all_of, any_of, none_of
- for_each
- count, count_if
- find, find_if, find_if_not

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> vector = {1, 2, 3, 4};
    bool allLessThen10 = std::all_of(vector.begin(), vector.end(), [](int value) { return value < 10; });
    std::cout << "All are less than 10: " << allLessThen10 << std::endl;
    bool someAreEven = std::any_of(vector.begin(), vector.end(), [](int value) { return value % 2 == 0; });
    std::cout << "Some are even: " << someAreEven << std::endl;
    bool noneIsNegative = std::none_of(vector.begin(), vector.end(), [](int value) { return value < 0; });
    std::cout << "None is negative: " << noneIsNegative << std::endl;
    std::cout << "Odd numbers: " << std::count_if(vector.begin(), vector.
  end(), [](int value) { return value % 2 == 1; }) << std::endl;
    auto position = std::find(vector.begin(), vector.end(), 6);
    std::cout << "6 was found: " << (position != vector.end()) << std::endl;
}

/*
Output:
All are less than 10: 1
Some are even: 1
None is negative: 1
Odd numbers: 2
6 was found: 0
*/
```

### Modifying Algorithms

Modifying algorithms are algorithms that modify the collections they iterate on:
- copy, copy_if
- transform
- remove, remove_if

```cpp
#include <iostream>
  #include <vector>
  #include <algorithm>
  #include <iterator>
int main() {
      std::vector<std::string> vector = {"Hello", "C++", "Morning",
  "Learning"};
      std::vector<std::string> longWords;
      std::copy_if(vector.begin(), vector.end(), std::back_inserter(longWords),
  [](const std::string& s) { return s.length() > 3; });
      std::cout << "Number of longWords: " << longWords.size() << std::endl;
      std::vector<int> lengths;
      std::transform(longWords.begin(), longWords.end(), std::back_
  inserter(lengths), [](const std::string& s) { return s.length(); });
      std::cout << "Lengths: ";
      std::for_each(lengths.begin(), lengths.end(), [](int length) { std::cout
  << length << " "; });
      std::cout << std::endl;
      auto newLast = std::remove_if(lengths.begin(), lengths.end(), [](int
  length) { return length < 7; });
      std::cout << "No element removed yet: " << lengths.size() << std::endl;
      // erase all the elements between the two iterators
      lengths.erase(newLast, lengths.end());
      std::cout << "Elements are removed now. Content: ";
      std::for_each(lengths.begin(), lengths.end(), [](int length) { std::cout<< length << " "; });
      std::cout << std::endl;
}
/*
Output:
Number of longWords: 3
Lengths: 5 7 8
No element removed yet: 3
Elements are removed now. Content: 7 8
*/
```

### Mutating Algorithms

Mutating algorithms are algorithms that change the order of elements:
- reverse, reverse_copy
- shuffle

```cpp
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
      std::vector<int> vector = {1, 2, 3, 4, 5, 6};
      std::random_device randomDevice;
      std::mt19937 randomNumberGenerator(randomDevice());
      std::shuffle(vector.begin(), vector.end(), randomNumberGenerator);
      std::cout << "Values: ";
      std::for_each(vector.begin(), vector.end(), [](int value) { std::cout <<
  value << " "; });
      std::cout << std::endl;
  }

/*
Output:
Values: 5 2 6 4 3 1
*/
```

### Sorting Algorithms

This class of algorithms rearranges the order of elements within a container in a specific order:
- sort

```cpp
#include <iostream>
  #include <vector>
  #include <algorithm>
int main() {
      std::vector<int> vector = {5, 2, 6, 4, 3, 1};
      std::sort(vector.begin(), vector.end());
      std::cout << "Values: ";
      std::for_each(vector.begin(), vector.end(), [](int value) { std::cout <<
  value << " "; });
      std::cout << std::endl;
}

/*
Output:
Values: 1 2 3 4 5 6
*/
```

### Binary Search

Name for the algorithm:
- binary_search

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
      std::vector<int> vector = {1, 2, 3, 4, 5, 6};
      bool found = std::binary_search(vector.begin(), vector.end(), 2);
      std::cout << "Found: " << found << std::endl;
}
/*
Output:
Found: 1
*/
```

### Numeric Algorithms

This class of algorithms combines numeric elements using a linear operation in different ways:
- accumulate

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
      std::vector<int> costs = {1, 2, 3};
      int budget = 10;
      int margin = std::accumulate(costs.begin(), costs.end(), budget, [](int
  a, int b) { return a - b; });
      std::cout << "Margin: " << margin << std::endl;
}

/*
Output:
Margin: 4
*/
```

## Summary

In this chapter, we introduced sequential containers – containers whose elements can be accessed in sequence. We looked at the array, vector, deque, list, and forward_list sequential containers.
We saw what functionality they offer and how we can operate on them, and we saw how they are implemented and how storage works for vector and list.
We followed this up with associative containers, containers that allow the fast lookup of their elements, always kept in order. Set, multiset, map, and multimap are part of this category.
We looked at the operations they support and how map and multimap are used to associate a value to a key. We also saw their unordered version, which does not keep elements in order but provides higher performance. Unordered_set and unordered_map are in this category.







