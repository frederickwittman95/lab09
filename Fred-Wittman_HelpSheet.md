Frederick Wittman

Dr. Hill

COSC 2030-01

23 April 2019

### 1.  To comment C++ code:

Inserting "//" will identify everything after this symbol as a comment on a single line.  To add a block comment that can span multiple lines, insert the desired comment between the asterisks of the "/* */" symbol.
    
### 2.  To comment Python code:

The "#" symbol is used to comment out a single line.  To identify a block of code as a comment, insert the code between three
double quotation marks, literally: """comment""".
    
### 3.  What kind of file has extension ".md"?

Markdown files have extension ".md".  Markdown languages control the styling of webpages and other computer interfaces using
plain text.  The primary example of a markdown language is HTML.
    

### 4.  How to strip whitespace from the end of a string in C++:
    One way to strip the whitespace from the end of a string in C++ is to use the algorithm provided by the pixel compressor file:
    
#include <string>
    
string whitespace(" \t\f\v\n\r");  // Define whitespace characters
    
sampleString.substr(0, sampleString.find_last_not_of(whitespace));

sThis returns a substring beginning at the zeroth element of sampleString and ending at the last character in sampleString that is not the parameter, which in this case is whitespace, of the the find_last_not_of function.  Note that this function will not strip whitespace inside the string, but only whitespace
that trails the last character.

### 5.  How to create an object of type T and its pointer:

Generically, without formatting and in connection to a function or class you need the following:

template <class T>
T object;
T * objectPtr = &object;
    
### 6.  List the Python modules that you have imported in your Python experience, and what they contain. And answer this question: What is the class of the ops variable? (Review Ch. 5 of the Tutorial.) And what are the other general-purpose built-in container data structures in Python?
    
I have imported the math and operations modules.  The ops variable is a set.  In addition to sets, Python supports tuples,
sequences, and lists. Additionally, lists can be used as the substrate for stacks and queues.

### 7.  How to declare a record structure in C++:

Records are linear, direct access data structures with heterogenous components.  In C++, they are declared as structs:

struct {

type1 field1; 

type2 field2;

...}

### 8.  How to declare a binary tree in C++ and Python:

##### C++
```
struct Node{
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * root = new Node;
root->value = 5;
```
##### Python
```
class Node:

    def __init__(self, value):

    	self.left = None
    	self.right = None
    	self.value = value

root = Node(5)
```

### 9. How do you declare a class in python?

The simplest possible class declaration for python is the following:
```
class ClassName:
    <statement-1>
    .
    .
    .
    <statement-N>
```

### 10. What is the drawback for the great speed of the bit-array data structure?

One drawback is that bit-arrays are inefficient at storing sparse sets (sets that do not have many elements compared with their range).Another drawback is that accessing individual elements can be time consuming and difficult to code in some languages.

### 11. What is the name of the functionality that allows the .append function in Python. Do you think it is useful?

The .append functionality is enabled by the fact that Python lists support dynamic memory allocation.  I prefer Python lists over the staticly sized arrays of C++.  I am sure there is a trade off, however.  

### 12. What are the differences between open addressing and linked hashtables?

In open addressing hashtables, values that share the same hash are stored in a linked list, the head of which is located at the relevant hash.  The benefits of this implementation of the ADT include ease of implementation, less sensitivity to the hash function, and an unlimited capacity to store key:value pairs.  

In open addressing hashtables, values are stored in the hashtable itself.  When a collision occurs, the value is stored in the next available slot.  This type of hashtable is best used when the number and frequency of key:value pairs is known in advance.  Other benefits include better cache performance (since all the data stored in one spot in memory) and the fact that a slot can be used even if the hash function does not map a value to it.  Drawbacks include inefficiency when the hash function is not well formulated and the fact that the this type of hash table has a maximum capacity.  

