Summary of Educational Goals
Sophie Groenwold // CS190J, Spring 20

CS24 currently has a lab to introduce students to GDB. However, I believe that the current version of 
the lab does not demonstrate why using GDB is helpful in the long term. 

This is because: 
- the file to debug is only 70 lines long, and thus the problem can be found without the use of GDB; 
- the problem they are debugging is not immediately applicable to the other work they are doing with 
linked lists and BSTs; and
- the other half of the lab is about make & Makefiles, instead of GDB. 

This lab addresses these issues by:
1. having the code to debug be an implementation of a linked list. Thus this lab is intended to be 
introduced after their lab02 (which is their own implementation of a linked list) is completed. 
2. connecting the subject matter of the code to the current material of the class. 
3. demonstrating how the use of GDB can help their debugging workflows in later labs and projects.
4. concentrating on GDB, instead of containing two different subjects. 

This lab does not have instructions on how to pull starter code, instructions on pair programming, or
instructions for submission, as these all differ by quarter. This lab also does not have the walkthrough
on make and Makefiles present in the current GDB lab; since this is an important topic, I imagine it would 
be important to move to a different lab or assignment.

Other notes:
- I used the same GDB commands summary as is already present in lab03, since it's a great resource.
- It's possible that the code from this lab can be used dishonestly, if students give their debugged code
to students in future quarters. However, I think the benefits outweigh this problem, since I've had students 
come to ask about how to finish their linked list lab after the due date. It's also helpful for their pa01, 
which utilizes a linkedlist.

