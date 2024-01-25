# 📁 Standalone C Project Structure

A typical C project may include directories for source files (`src`), headers (`include`), libraries (`lib`), binaries (`bin`), object files (`obj`), tests (`test`), and documentation (`doc`). Below is a structured representation:

## 🌲 Project Tree

/YourCProject
├── /src 🧾                 Source files and main application logic
│ ├── main.c                Entry point of the application
│ ├── /module1               
│ │ ├── module1.c           Source code for module 1
│ │ └── module1.h           Header file for module 1
│ ├── /module2              
│ │ ├── module2.c           Source code for module 2
│ │ └── module2.h           Header file for module 2
│ └── ...                  
├── /include                Directory for all header files
│ ├── /module1
│ │ └── module1.h           Public header for module 1
│ ├── /module2
│ │ └── module2.h           Public header for module 2
│ └── ...                  
├── /lib  Libraries         (e.g., third-party or external)
│ └── /third_party_lib
├── /bin                    Compiled binaries/executables
├── /obj                    Intermediate object files
├── /test                   Tests for the application's functionality
│ ├── test_main.c           Main test file
│ ├── /module1
│ │ └── test_module1.c      Test file for module 1
│ ├── /module2
│ │ └── test_module2.c       Test file for module 2
│ └── ...  Other tests
├── /doc                    Documentation for the project
├── Makefile                Build script for compiling the project
└── README.md               Basic project information

## 🛠️ Building the Project
- Use the `Makefile` to define the build process for compiling source files into executables.
- The `Makefile` typically includes targets for building the `bin` and `obj`, as well as cleaning up build artifacts.

## 📝 Documentation
- Keep your project's `README.md` updated with instructions on how to build and use your project.
- Use the `/doc` directory to store additional documentation like API guides, development notes, or usage manuals.
The /src directory contains all the source .c files, organized by module or functionality. 
Headers that are part of your public API might be in /include to make them easily accessible to other projects or modules. The /lib directory could contain any third-party or external libraries that your project uses. The /bin directory is the typical location for the output executables after compilation, 
and /obj for the intermediary object files. The /test directory contains your unit tests, and /doc is for documentation.


# Notes on Header files:

In C programming, a .h file is a header file. It typically contains function prototypes, which declare the names, return types, and parameters of functions so that other files (source files) can call those functions. Header files can also contain definitions for types, macros, and constants used throughout your program.

Here's an example of what might be in a header file:

```c
// math_operations.h

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

// Function prototype for adding two integers
int add(int x, int y);

// Function prototype for subtracting two integers
int subtract(int x, int y);

// A macro for calculating the square of a number
#define SQUARE(x) ((x) * (x))

// A constant for the value of pi
const double PI = 3.14159;

#endif // MATH_OPERATIONS_H
```
The #ifndef, #define, and #endif preprocessor directives at the top and bottom of the file are called "include guards." They prevent the contents of the header file from being included multiple times in the same file, which can happen when multiple files include the same header, either directly or indirectly. This could lead to errors such as redefinition of functions or variables.

The .h header files are included in .c source files using the #include preprocessor directive. This tells the compiler to replace that line with the entire contents of the specified header file. For example:

```c
// main.c

#include "math_operations.h"

int main() {
    int result = add(5, 3);
    int squared = SQUARE(4);

    return 0;
}
```
The source file main.c includes math_operations.h, so it can use the add function, the SQUARE macro, and the PI constant defined in the header. The implementation (definition) of the functions declared in math_operations.h would be in a corresponding .c file, typically with the same name as the header (e.g., math_operations.c).


## Makefile using Clang

Sure, I'd be happy to explain each line of the `Makefile`:

```makefile
# Variables
CC = clang
```
This line sets the variable `CC` to `clang`, which is the compiler that will be used.

```makefile
CFLAGS = -Iinclude
```
This line sets the variable `CFLAGS` to `-Iinclude`. The `-I` option tells the compiler to look in the `include` directory for header files.

```makefile
DEPS = $(wildcard include/*.h)
```
This line sets the variable `DEPS` to the result of `$(wildcard include/*.h)`, which is a list of all `.h` files in the `include` directory. These are the dependencies for the object files.

```makefile
OBJ = $(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))
```
This line sets the variable `OBJ` to the result of `$(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))`. This command finds all `.c` files in the `src` directory, and then replaces `src/%.c` with `obj/%.o` to generate a list of object file names.

```makefile
# Rules
all: bin/main
```
This line defines a rule for the target `all`. The target `all` depends on `bin/main`, so `make all` (or simply `make`, since `all` is the first target) will build `bin/main`.

```makefile
bin/main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
```
This rule says that `bin/main` depends on the files in `$(OBJ)`. If any of those files change, `bin/main` will be rebuilt. The command `$(CC) -o $@ $^ $(CFLAGS)` is run to build `bin/main`. Here, `$@` is the target (`bin/main`), `$^` is the dependencies (`$(OBJ)`), and `$(CFLAGS)` are the flags passed to the compiler.

```makefile
obj/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
```
This is a pattern rule that applies to all object files. It says that an object file `obj/%.o` depends on the corresponding source file `src/%.c` and the header files `$(DEPS)`. If any of the dependencies change, the object file will be rebuilt. The command `$(CC) -c -o $@ $< $(CFLAGS)` is run to build the object file. Here, `$@` is the target (the object file), `$<` is the first dependency (the source file), and `$(CFLAGS)` are the flags passed to the compiler.

```makefile
.PHONY: clean
```
This line declares `clean` as a phony target. A phony target is one that is not associated with a file. It's always out-of-date, so its recipe is always executed if the target is requested.

```makefile
clean:
	rm -f obj/*.o bin/main
```
This rule is for the target `clean`. It doesn't have any dependencies, so it always runs when requested. The command `rm -f obj/*.o bin/main` is run, which removes the object files and the `main` executable.

I hope this helps! Let me know if you have any other questions. 😊