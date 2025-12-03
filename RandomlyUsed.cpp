/*
	Andrew
	addItem(int)
		get #bins for item (floor(log10(item))
		search through bins for existing index
		if found add item to that bin (no fetching / returning needed)
		else
  	  	  if no space for new bin, remove random bin and fetch new bin
  	  	  else fetch bin
 */
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
using namespace std;
inline void RandomlyUsed(ofstream&output,const vector<int>&items,const int&binSize,const float&fetchCost,const float&returnCost){
	float totalCost=0;
	vector<int>table;
	int currBinSum=0;
	srand(time(0));//sets seed based on current time (always changing)
	for(int i=0;i<(int)items.size();i++)
	{
		int item=items[i];
		int binWeight=floor(log10(item))+1;
		if(binWeight>binSize)continue;//cannot fit item wompwomp
		int binIndex=item/10;
		bool binFound=false;
		for(int b:table)
			if(b==binIndex)
			{
				binFound=true;
				break;
			}
		if(binFound)continue;//found bin
		//specified bin size not found
		//remainder from total
		while(currBinSum+binWeight>binSize)//while no space left for new slot, remove random
		{
			int currNumBins=(int)table.size();
			//randomly remove bins
			int index=rand()%currNumBins;//0-currNumBins-1
			//cout<<"Remove: "<<index<<endl;
			int removeBinIndex=table[index];
			int removeBinWeight=removeBinIndex==0?1:(floor(log10(10*removeBinIndex))+1);
			currBinSum-=removeBinWeight;
			table.erase(table.begin()+index);
			totalCost+=returnCost*removeBinWeight;
			//output<<"Removed: "<<removeBinIndex<<endl;
		}
		//output<<"Fetched: "<<binIndex<<endl;
		//push bin
		table.push_back(binIndex);
		currBinSum+=binWeight;
		totalCost+=fetchCost*binWeight;
		//output<<"Current Table: ";for(auto x:bins)output<< x<<" ";output<<endl;
	}
	output<<"TotalCost: "<<totalCost<<endl;
}