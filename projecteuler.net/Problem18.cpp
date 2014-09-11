/*
	Maximum path sum
*/
#include <iostream>
#include <cmath>

#define HEIGHT 15

using namespace std; 

int maxSum(int pyramid[][HEIGHT] ) {

	const int pathLength 	= HEIGHT-1; 
	int path[pathLength]	= {0}; 
	double temp 		= pow(2, HEIGHT-1); 
	int limit 		= (int)temp; 
	int index1		= 0;
	int index2		= 0;
	int max			= 0;
	int sum			= pyramid[0][0]; 
	
	// path[j]==0 --> go down and right
	// path[j]==1 --> go down and left
	for(int i=0; i<limit; i++) {
		for(int j=0; j<pathLength; j++) {
			if(path[j]==0)
				sum += pyramid[++index1][++index2]; 
			else if(path[j]==1)
				sum += pyramid[++index1][index2]; 
		}
		if(sum>max)
			max=sum;

		if(i+1==limit)
			return max; 

		sum=pyramid[0][0];
		index1=0; index2=0; 
  
		//generate new path
		path[pathLength-1]++; 
		for(int j=pathLength-1; j>=0; j--) {
			if(path[j] > 1) {
				path[j]=0; 
				path[j-1]++; 
			}
		}
	}
}

int main() {
	int pyramid[][HEIGHT] = { {75}, {95, 64}, {17, 47, 82}, {18, 35, 87, 18}, {20, 04, 82, 47, 65},
				{19, 01, 23, 75, 03, 34}, {88, 02, 77, 73, 07, 63, 67}, {99, 65, 04, 28, 06, 16, 70, 92},
				{41, 41, 26, 56, 83, 40, 80, 70, 33}, {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
				{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14}, {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
				{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48}, {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31}, 
				{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23} }; 
	
	cout << "Calculating solution...\n"; 
	cout << maxSum(pyramid) << endl; 

	return 0;  
}
