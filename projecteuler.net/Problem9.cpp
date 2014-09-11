/*
	Patrick Emami
	Problem 9:
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a2 + b2 = c2
	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include <iostream>
using namespace std; 

int main() {

  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if( (((2000*i + 2000*j) - (2*i*j)) == 1000000) ) {
	cout << "a is : " << i << endl; 
	cout << "b is : " << j << endl;

	int c = 1000 - i - j; 
	cout << "a*b*c is : " << i * j * c << endl; 
	return 0; 
      }
    } 
  }

  cout << "search failed\n"; 
  return 0; 
}
