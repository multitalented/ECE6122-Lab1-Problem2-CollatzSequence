/*
Author: Deanna Gierzak
Class: ECE 6122
Last Date Modified: 9/14/2020

Description:

Sum of Collatz Sequence:

This program takes one command line input and calculates the sum of the terms in its Collatz sequence
		Even numbers: n--> n/2			Odd numbers: n--> 3*n + 1
For example, an input of 13 will generate the sequence 13 40 20 10 5 16 8 4 2 1 and a sum of 119
The resulting sum is output to a file calling Output2.txt

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// prototype functions declared
bool isEven(unsigned long lNum);				// function to determine if a number is even
bool isOdd(unsigned long lNum);					// function to determine if a number is odd
unsigned long calcEven(unsigned long lNum);		// function to calculate the next number in sequence for even numbers, n --> n/2
unsigned long calcOdd(unsigned long lNum);		// function to calculate the next number in sequence for odd numbers, n --> 3*n + 1

// takes one command-line argument variable of type unsigned long
int main(int argc, char* argv[])
{
	unsigned long sum = 0;
	unsigned long num = 0;
	unsigned long numSeq = 0;
	// unsigned long fullSeq[]; // would need to make a dynamic array, don't need to do this

	stringstream convert(argv[1]);  // take the second argument (first is the program executable path), any other arguments would get ignored
	convert >> num;					// convert this argument to the unsigned long

	//cout << "Your number is: " << num << endl;	// debugging checks
	//cout << "Enter a number: ";					// debugging checks
	//cin >> num;									// debugging checks

	sum = num;		// set the sum to the first/input number in sequence
	numSeq = num;	// set the first number in sequence to the input number

	do
	{
		if (isEven(numSeq) == true)		// if the current number in the sequence is even
		{
			numSeq = calcEven(numSeq);	// calculate the next number in the Collatz sequence for even numbers
			goto SumSequence;			// skip the next if statement to avoid error, since next number in sequence gets set here
		}
		if (isOdd(numSeq) == true)		// if the current number in the sequence is odd
		{
			numSeq = calcOdd(numSeq);	// calculate the next number in the Collatz sequence for odd numbers
			goto SumSequence;			// skip to SumSequence to avoid error, since next number in sequence gets set here
		}

		SumSequence:
		sum = sum + numSeq;				// update the sum with the latest number in sequence

	} while (numSeq > 1);				// once the number in sequence = 1, the sequence ends

	//cout << endl;
	//cout << "The sum of the sequence is: " << sum << endl; 

	ofstream ofs;						// define an ofstream object
	ofs.open("Output2.txt");			// use to open (creates) a text file 
	ofs << sum;							// put the sum value into file
	ofs.close();						// close text file
	//system("pause");					// debugging check

	return 0;
}

// there was a good cplusplus tutorial using these exact functions, find it again
// i think i could make this more efficient with some recursive calling, but not sure how yet

bool isEven(unsigned long lNum)
{
	if (lNum % 2 == 0)		// if number is even
	{
		return true;		// therefore it is true that it is even
	}
	return false;
}
bool isOdd(unsigned long lNum) 
{
	if (lNum % 2 == 0)		// is number is even
	{
		return false;		// therefore it is false that it is odd
	}
	return true;
}
unsigned long calcEven(unsigned long lNum)
{
	return lNum / 2;		// next number in Collatz sequence if it is even
}
unsigned long calcOdd(unsigned long lNum) 
{
	return 3 * lNum + 1;	// next number in Collatz sequence if it is odd
}
