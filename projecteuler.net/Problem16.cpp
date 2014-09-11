/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cmath>
using namespace std; 

int solution() {
	int num = 1000, sum=0, carry = 1; 	// 2^1000
	int size = floor(num * (log(2)/log(10)) + 1);	// num of digits in 2^1000
	int *myDigits = new int[size]; 
	myDigits[0] = 1; 

	for(int i=0; i<num; i++) {
		for(int j=0; j<size; j++) {
			myDigits[j] <<= 1;  
			
			while(myDigits[j] >= 10) {
				myDigits[j] = myDigits[j]%10; 
				myDigits[j+1] <<= 1; 
				myDigits[j+1] += carry; 
				j++; 
			}			
		}
	}
	for(int i=0; i<size; i++) sum += myDigits[i]; 
	delete [] myDigits; 
	return sum; 
}

int main() {
	cout << "Calculating solution...\n"; 
	cout << solution() << endl;  
	return 0; 
}
