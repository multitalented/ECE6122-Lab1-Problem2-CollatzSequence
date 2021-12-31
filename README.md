# ECE6122-Lab1-Problem2-CollatzSequence

Last Date Modified: 9/14/2020

Sum of Collatz Sequence:

This program takes one command line input and calculates the sum of the terms in its Collatz sequence
		Even numbers: n--> n/2			Odd numbers: n--> 3*n + 1
For example, an input of 13 will generate the sequence 13 40 20 10 5 16 8 4 2 1 and a sum of 119
The resulting sum is output to a file calling Output2.txt

Example execution in command line:

~$  g++ .\*.cpp a.exe

~$  a.exe 13

~$ cat Output1.txt

119
