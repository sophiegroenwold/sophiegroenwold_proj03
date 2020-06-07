# lab0x: Using gdb to debug a linked list

## Goals for this lab:
- Use g++ from the command line
- Learn the basic tools and general workflow of gdb
- Debug a linked list

## Step by step instructions

### Step 1: Review the starter code

The starter code is a finished implementation of lab02, but with some bugs. It consists of four files: `intlist.cpp`, `intlist.h`, `main.cpp`, and a `Makefile`. To run the program, use `make list`. 

These files implement a linked list that stores ints, and has the following functions:

- `IntList()`: constructor
- `IntList(const IntList& source)`: copy constructor
- `~IntList()`: destructor
- `operator=(const IntList& source)`: overloaded assignment operator
- `append(int value)`: appends new value to end of the list
- `void insertFirst(int value)`: inserts new value at the front of the list
- `bool contains(int value) const`: true if value is in list
- `int count() const`: counts number of values
- `int sum() const`: sum of values in list
- `void print() const`: prints list
- `int max() const`: returns maximum value
- `double average() const`: returns max of values

Some of these functions may have implementations that are new to you. Take the time to look over them before continuing. 

### Step 2: What is GDB?
GDB is a debugger that allows you to step through the execution of your code. There are four bugs in `intlist.cpp`. Together we'll find the first one, using GDB. 

Go ahead and run `make list` and then `./list 1`. This runs our first buggy case in the code. This case is looking at the `max()` function of our linked list, so the correct output should be:

```
list: [5 2 15 30 4] max: 30
list2: [-4 -3 -1 -11] max: -1
```

We instead get this output:

```
list: [5 2 15 30 4] max: 30
list2: [-4 -3 -1 -11] max: 0
```

You could look at the max function and trace through the logic to find the bug. However, for more complicated projects, it's helpful to take a look with GDB instead, which we'll practice now. To compile the code for use with GDB, we use the `-g` flag. This is already included in the `Makefile`, so all we have to do is run

```
gdb ./list 1
```

