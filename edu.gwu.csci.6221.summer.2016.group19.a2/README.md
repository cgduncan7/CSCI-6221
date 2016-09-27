##### Class: 		CSCI 6221 - Advanced Software Paradigms
##### Assignment: 	Homework #2 - A2
##### Group:		19
##### Authors:		Collin Duncan, Mason Molesky, Anderson Thomas
##### Date:		2016.09.20

This folder contains group 19's solution to the A2 homework assignment. There are 4 class files in the project:
- A2
- Program
- P1 
- P2

A2, is the main program and launches either P1 or P2 as a result. To run the program in Eclipse, change the run configurations to have two parameters. The first parameter being `P1` or `P2` and the second being either: an integer number specifying the size of a randomly generated array, or the path to a file containing a set of numbers separated by a non-digit character (e.g. a space). The JUnit4 test files included in test/ also test P1 and P2 for correctness.
NOTE: You can simply run A2 with no parameters and it will run both P1 and P2 with two random arrays of 1000 integers.

Program, is an abstract class which is extended by P1 and P2. It has a variety of helper methods and, more importantly, the partition method which is used by both the iterative and recursive implementation of quicksort. The most notable method in Program would be sort. Sort is what is implemented by the classes to perform each of their versions of quicksort.

P1, is the recursive implementation of quicksort. It implements Program.

P2, is the iterative implementation of quicksort (using a stack). It implements Program.
