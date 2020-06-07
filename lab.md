# lab0x: Using GDB to debug a linked list

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
$ gdb ./list 1

GNU gdb (GDB) Fedora 8.2-7.fc29
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./list...done.
```
We're now using GDB! Let's try putting a *break point* at line 28 in `main.cpp`. This means that the program will run until line 28.

```
(gdb) break 28

Breakpoint 1 at 0x4012c0: file main.cpp, line 24.
```

Then start running the program. The 1 is the command line argument.

```
(gdb) run 1

Starting program: /cs/student/sophiegroenwold/cs190j/sophiegroenwold_proj03/list 1
Breakpoint 1, test_1 () at main.cpp:28
28          int max = list2.max();
```

If you're not very familiar with the code, it might help to check where we are. Run *list*:

```
(gdb) list

23          int arr2 [] = {-4, -3, -1, -11};
24          for (int i = 0; i < 4; i++)
25              list2.append(arr2[i]);
26          cout << "list2: ";
27          list2.print();
28          int max = list2.max();
29          cout << " max: " << max << endl;
30      }
31
32      void test_2()
```

Alright, so we should be able to view the values of `arr1`. Let's check them out:

```
(gdb) print arr2

$1 = {-4, -3, -1, -11}
```

This looks fine. Now we want to go into the `max()` function, so we use *step*:

```
(gdb) step

IntList::max (this=0x7fffffffd0a8) at intlist.cpp:65
65          Node* ptr = first;
```

Cool! So now we're inside `intlist.cpp`, specifically within `max()`. If you need convincing, run *list* again. 

```
(gdb) list

60          return false;
61      }
62
63      // returns maximum value in list, or 0 if empty list
64      int IntList::max() const {
65          Node* ptr = first;
66
67          if (!ptr)
68              return 0;
```

So this is definitely inside `IntList::max()`. Now we investigate our suspicion that this function is going wrong. Let's set a break points at line 72, and *continue* until then. 

``` 
(gdb) break 72

Breakpoint 3 at 0x401654: file intlist.cpp, line 72.

(gdb) continue

Continuing.

Breakpoint 3, IntList::max (this=0x7fffffffd0a8) at intlist.cpp:72
72          while (ptr)
```

Let's check the value of `ptr -> info`:

```
(gdb) print ptr -> info

$2 = -4
```

This is as expected. But we can also use *print* to evaluate boolean statements. Maybe we should check to see what the following if statement will execute:

```
(gdb) print ptr -> info > max

$3 = false
```

Think about this -- does this tell us anything about what our bug might be?

### Step 3: Find the other bugs

The starter code contains the bug you just found plus 3 other bugs, for a total of four. For the rest of this lab, you'll use GDB to find them. 

#### GDB commands:

*file*: "file executable" specifies which program you want to debug.

*run*: "run" starts the program running under GDB. The program is the one that you have previously selected with the file command, or on the unix command line when you started gdb. You can give command line arguments to your program on the gdb command line. You can do this the same way you would on the unix command line, except that you are saying run instead of the program name. For example,

```
run 5 20 40 60
```

You can even do input/output redirection: `run > outfile.txt`.

*list*: "list linenumber" prints out some lines from the source code around linenumber. If you give it the argument function it will print out lines from the beginning of that function.

Just *list* without any arguments will print out the lines just after the lines that you printed out with the previous list command.

*break*: "break" sets a breakpoint in your program.

A breakpoint is a spot in your program where you would like to temporarily stop execution in order to check the values of variables, or to try to find out where the program is crashing, etc.

"break function" sets the breakpoint at the beginning of function. If your code is in multiple files, you might need to specify filename:function.

"break linenumber" or "break filename:linenumber" sets the breakpoint to the given line number in the source file. Execution will stop before that line has been executed.

delete "delete" deletes all breakpoints that you have set. "delete number" deletes breakpoint numbered number. You can find out what number each breakpoint is by doing info breakpoints. (The command info can also be used to find out a lot of other stuff. Do help info for more information.)

clear "clear function" deletes the breakpoint set at that function. Similarly for linenumber, filename:function, and filename:linenumber.

*step*: "step" goes ahead and execute the current source line, and then stop execution again before the next source line.

*next*: "next" continues until the next source line in the current function (actually, the current innermost stack frame, to be precise). This is similar to step, except that if the line about to be executed is a function call, then that function call will be completely executed before execution stops again, whereas with step execution will stop at the first line of the function that is called.

*until*: "until" is like *next*, except that if you are at the end of a loop, *until* will continue execution until the loop is exited, whereas *next* will just take you back up to the beginning of the loop. This is convenient if you want to see what happens after the loop, but don’t want to step through every iteration.

*print*: "print expression" prints out the value of the expression, which could be just a variable name. To print out the first 25 (for example) values in an array called list, you would do print `list[0]@25`

*quit*: "quit" is used to exit the gdb debugger.