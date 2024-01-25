# C Programming Cheat Sheet

## Basic Structure

```c
#include <stdio.h> // Standard input/output header

// Function prototypes (if any)

int main() {
    // Program code goes here
    return 0; // Return statement
}
```
# Data Types 🔢
C supports several data types including integers, floating-point numbers, characters, and Booleans.
```c
int myInt;         // Integer
float myFloat;     // Floating-point number
double myDouble;   // Double-precision floating-point number
char myChar;       // Character
_Bool myBool;      // Boolean (C99)

#include <stdint.h>
int32_t myInt32;   // 32-bit integer
uint8_t myUint8;   // 8-bit unsigned integer
```
# Operators
Operators in C include arithmetic, relational, logical, and bitwise operators.
```c
// Arithmetic Operators
+   // Addition
-   // Subtraction
*   // Multiplication
/   // Division
%   // Modulus (remainder)

// Relational Operators
==  // Equal to
!=  // Not equal to
>   // Greater than
<   // Less than
>=  // Greater than or equal to
<=  // Less than or equal to

// Logical Operators
&&  // Logical AND
||  // Logical OR
!   // Logical NOT

// Bitwise Operators
&   // Bitwise AND
|   // Bitwise OR
^   // Bitwise XOR
~   // Bitwise NOT
<<  // Left shift
>>  // Right shift
```
# Control Structures 🔁
Control structures in C manage the flow of execution.
```c
// Conditional statements: if, if-else
// Loops: while, for, do-while
// Switch statement for multi-way branching

// If statement
if (condition) {
    // Code if condition is true
}

// If-Else statement
if (condition) {
    // Code if condition is true
} else {
    // Code if condition is false
}

// While loop
while (condition) {
    // Code as long as condition is true
}

// For loop
for (init; condition; increment) {
    // Code until condition is false
}

// Do-While loop
do {
    // Code to execute
} while (condition);

// Switch statement
switch (expression) {
    case constant1:
        // Code for constant1
        break;
    case constant2:
        // Code for constant2
        break;
    //...
    default:
        // Default code
}
```
# Functions 🛠️
Functions are blocks of code that perform specific tasks and can return values.
```c
// Define and implement functions with return types and parameters.

// Example: A function to add two integers.

// Function definition
returnType functionName(parameters) {
    // Function code
    return value; // if returnType is not void
}

// Example: Function that adds two integers
int add(int a, int b) {
    return a + b;
}
```
# Pointers 👉
Pointers hold the memory address of variables and are powerful tools in C.
```c
// Declare and use pointers to reference and dereference memory locations.

// Pointer arithmetic to navigate through memory.

int* ptr;  // Pointer to an int
ptr = &myInt;  // Assign address of myInt to ptr
*ptr = 10;  // Set value at ptr

// Pointer arithmetic
ptr++; // Next int position
ptr--; // Previous int position
```
# Arrays 🗃️
Arrays are collections of elements of the same type, stored in contiguous memory locations.
```c
// Declare and initialize single and multidimensional arrays.

int myArray[10]; // Array of 10 integers
myArray[0] = 5;  // Set first element to 5

// Multidimensional array
int my2DArray[5][5]; // 5x5 array
```
# Structures 🏗️
Structures group together different types of variables under a single name.
```c
// Define structures with different data types.

// Create instances (variables) of these structures and access their members.

// Define a structure
struct MyStruct {
    int myInt;
    char myChar;
};

// Structure instance
struct MyStruct myInstance;

// Access structure members
myInstance.myInt = 10;
myInstance.myChar = 'A';
```
# Input/Output 📥📤
Input and output operations are performed primarily using printf and scanf.
```c
// Use printf for formatted output and scanf for input.

printf("Hello, World!"); // Print to stdout
printf("Value: %d", myInt); // Formatted output

int x;
scanf("%d", &x); // Read formatted input
```
# Memory Managment
Dynamic memory allocation and deallocation are crucial in C for efficient memory use.
```c
// Use malloc and free for dynamic memory management.

#include <stdlib.h> // Memory management functions

int* ptr = malloc(10 * sizeof(int)); // Allocate array
if (ptr != NULL) {
    // Allocation succeeded
}

free(ptr); // Free memory
ptr = NULL; // Nullify pointer
```
# Preprocessor Directives
Preprocessor directives are used for macros, file inclusion, and conditional compilation.
```c
// Define macros, include headers, and use conditional compilation directives.

#define PI 3.14 // Define a constant
#ifdef DEBUG // If DEBUG is defined
// Debug code
#endif

#include "myheader.h" // Include a header file
```