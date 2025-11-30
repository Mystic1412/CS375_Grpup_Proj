#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <chrono>

#include "FIFO.cpp"
#include "LeastRecentlyUsed.cpp"
#include "RandomlySelected.cpp"
using namespace std;
using namespace chrono;
#define GetTime high_resolution_clock::now()
#define AlgorithmParameters (ofstream&,const vector<int>&,const int&,const float&,const float&)

struct Algorithm
{
	void(*function)AlgorithmParameters;
	Algorithm(void(*function)AlgorithmParameters):function(function){}
	void evaluate(const string&prefix,const string&suffix,ofstream&output,const vector<int>&items,const int&binNum,const float&fetchCost,const float&returnCost)
	{
		auto start=GetTime;
		function(output,items,binNum,fetchCost,returnCost);
		auto end=GetTime;
		cout<<prefix<<duration_cast<microseconds>(end-start).count()<<suffix<<endl;
	}
};

using namespace std;
using namespace chrono;
int main(int argv,char**argc)
{
	//1 input file | 3 outputs
	if(argv<4)return -1;
	ifstream input(argc[1]);
	if(input.is_open())
	{
		string line;
		bool firstLine=true;
		int binNum;
		float fetchCost,returnCost;
		vector<int>items;
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
		Algorithm firstinfirstout(FIFO);
		firstinfirstout.evaluate("Time: "," ms",fifo,items,binNum,fetchCost,returnCost);

		//LRU
		Algorithm leastrecentlyused(LeastRecentlyUsed);
			// lru - outputstream, items - inputs, binNum, fetchCost, returnCosts - firstInput
		leastrecentlyused.evaluate("Time: "," ms", lru, items, binNum, fetchCost, returnCost);

		//Random
		Algorithm random(RandomlyUsed);
		random.evaluate("Time: "," ms",rand,items,binNum,fetchCost,returnCost);

		fifo.close();
		lru.close();
		rand.close();
	}
	return 0;
}
