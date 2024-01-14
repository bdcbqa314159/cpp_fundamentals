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