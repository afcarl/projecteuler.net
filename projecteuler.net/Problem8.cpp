/*
 * Project8.cpp
 *
 *  Created on: Jun 23, 2013
 *      Author: Patrick
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int ctr=0;

	char a[] = "73167176531330624919225119674426574742355349194934969835203127745063262395783180169848018694788518438586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772390713810515859307960866701724271218839987979087922749219016997208880937766572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397536978179778461740649551492908625693219784686224828397224137565705605749026140797296865241453510047482166370484403199890008895243450658541227588666881";

	for(int z=0; z<600; z++)
	{

		int i=z;

		if( a[z]== '0' || a[z+1]== '0' || a[z+2]== '0' || a[z+3]== '0' || a[z+4]== '0')
			continue;
		else
		{
			for(int y=0; y<5; y++)
			{
				if(a[i]== '9')
				{
					ctr++;
				}
				i++;
			}

			if(ctr>=3)
			{
				cout << a[z] << a[z+1] << a[z+2] << a[z+3] << a[z+4];
				cout << endl;
			}
			ctr=0;
		}

	}

}

