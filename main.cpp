#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <chrono>

#include "FIFO.cpp"
#include "LeastFrequentlyUsed.cpp"
#include "RandomlyUsed.cpp"
using namespace std;
using namespace chrono;
#define GetTime high_resolution_clock::now()
#define AlgorithmParameters (ofstream&,const vector<int>&,const int&,const float&,const float&)
void evaluate(const string&prefix,void(*function)AlgorithmParameters,const string&suffix,ofstream&output,const vector<int>&items,const int&binNum,const float&fetchCost,const float&returnCost)
{
	auto start=GetTime;
	function(output,items,binNum,fetchCost,returnCost);
	auto end=GetTime;
	output<<prefix<<duration_cast<microseconds>(end-start).count()<<suffix<<endl;
}
int main(int argv,char**argc)
{
	//1 input file | 3 outputs
	if(argv<4)return -1;
	ifstream input(argc[1]);
	if(input.is_open())
	{
		string line;
		bool firstLine=true;
		vector<int>items;
		int binNum;
		float fetchCost,returnCost;
		while(getline(input,line))
		{
			if(firstLine)
			{
				firstLine=false;
				vector<float>nums;
				stringstream ss(line);
				float n;
				while(ss>>n)nums.push_back(n);
				if(nums.size()>=3)
				{
					//[# of bins] [fetch cost] [return cost]
					binNum=nums[0];
					fetchCost=nums[1];
					returnCost=nums[2];
				}
				else return -1;
			}
			else items.push_back(stoi(line));
		}
		input.close();
		//outputs go here
		ofstream fifo(argc[2]),lru(argc[3]),rand(argc[4]);
		if(!fifo.is_open()||!lru.is_open()||!rand.is_open())return -1;
		//FIFO
		evaluate("Time: ",FIFO," ms",fifo,items,binNum,fetchCost,returnCost);
		//LRU
		evaluate("Time: ",LeastRecentlyUsed," ms",lru,items,binNum,fetchCost,returnCost);
 		//cout<<"RNADN"<<endl;
		//Random
		evaluate("Time: ",RandomlyUsed," ms",rand,items,binNum,fetchCost,returnCost);
		fifo.close();
		lru.close();
		rand.close();
	}
	return 0;
}
