/*
	Patrick Emami
	projecteuler.net - Problem 10
	
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#include <iostream>
#include "math.h"

using namespace std; 

int main() {

  const long long int max = 2000000; 
  bool primes[max];
  long long int count = 0; 
  
  //mark all primes as true, all non primes as false
  for(long long int i=2; i <= max; i++) 
    primes[i] = true; 

  for(long long int j = 2; j <= max; ) {
    for(long long int k = 2; j*k <= max; k++) {

      if( primes[j*k] ) 
	primes[j*k] = false;
    }
    j++; 
    while( primes[j] == false ) {
      j++; 
    }
  }

  for(long long int i = 2; i < max; i++) {
    if(primes[i])
      count += i; 
  }
  
  cout<< "Sum of primes from [0:2000000] is : " << count << endl; 

  return 0;
}
