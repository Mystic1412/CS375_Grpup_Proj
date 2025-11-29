#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Warehouse.h"
using namespace std;
int main(int argv,char**argc)
{
	ifstream input("inputs/order1.txt");
	if(input.is_open())
	{
		Warehouse warehouse;
		string line;
		bool firstLine=true;
		while(getline(input,line))
		{
			if(firstLine)
			{
				firstLine=false;
				vector<float>nums;
				stringstream ss(line);
				float n;
				while(ss>>n)nums.push_back(n);
				if(nums.size()>=4)
				{
					//[# of bins] [# of slo1ts] [fetch cost] [return cost]
					warehouse.setBinsAndItems(nums[0],nums[1]);
					warehouse.setCosts(nums[2],nums[3]);
					cout<<warehouse<<endl;
				}
				else return -1;
			}
			else
			{
				warehouse.addItem(stoi(line));
			}
		}
		cout<<warehouse<<endl;
	}
	return 0;
}
