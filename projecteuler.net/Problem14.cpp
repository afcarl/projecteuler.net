/* 
 *	ProjectEuler.net - Problem 14 - Collatz Sequences
 *      Problem Statement: The following iterative sequence is defined for the set of positive integers:
 *				n → n/2 (n is even)
 *				n → 3n + 1 (n is odd)
 *		Using the rule above and starting with 13, we generate the following sequence:
 *				13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *		It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
 *		Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *		Which starting number, under one million, produces the longest chain?
 *
 *		NOTE: Once the chain starts the terms are allowed to go above one million.
 *	
 *      Language: C++	
 *	This is the work of Patrick Emami
 *	Date Completed: 12/31/13
 */
 
#include <iostream>
using namespace std; 

/*
	The purpose of this function is to generate the Collatz sequence starting at the integer n. 
	A pointer to the array "a" has been passed so that changes can be made to the array from this function. 
	The integer "size" is set to 1,000,000.
*/
void collatz(int n, int* a, int size) {

	//A counter is used to keep track of the length of the current sequence
	int counter=0; 	
	
	//The variable "temp" is declared as having type "long long int", since some numbers
	//in the Collatz sequences of very large integers will cause problems for variables of type int
	long long int temp=n; 
	
	while(true) {
	
		//If the current integer, "temp", in the Collatz sequence of n is less than 1,000,000 and if the Collatz sequence
	        //for this integer has already been found, store the length of the sequence at n, a[n], as the sum of the current
		//value of counter and the value stored in a[temp]
		//This prevents the algorithm from calculating the Collatz sequence for the same integer more than once
		if( temp<size ) {
			if( a[temp]!=0 ) {
				int newEntry=counter+a[temp]; 
				a[n]=newEntry; 
				counter=0; 
				return; 
			}
		}
		
		if( temp%2==0 ) { 
			temp/=2;
			counter+=1; 
		}
		else { 
			temp=(3*temp)+1;
			counter+=1; 
		} 		 
	}
}

/*
	This is the driver for the algorithm. After initializing a[1] to 1 
	and the rest of the array a[] to 0, the algorithm iterates from 1 to 1,000,000. 
	Since the function "collatz()" does not calculate a sequence for a specific 
	integer more than once, the algorithm finds the solution in less than a second
*/
int main(void) {
	int size=1000000; 
	int theMax=0, theNumber=0; 
	int* a=new int[size]; 
	for( int i=0; i<size; i++ ) 	
		a[i] = 0; 
	a[1]=1; 

	for(int n=1; n<size; n++) {
		collatz(n, a, size); 
		if( a[n] > theMax ) {
			theMax = a[n]; 
			theNumber = n; 
		}
	}
	delete [] a;
	cout << "The Collatz sequence starting at " << theNumber << " has the longest chain, of length:  " << theMax << endl; 
	return 0;  
}