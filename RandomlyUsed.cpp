/*
	Andrew
	addItem(int)
		get #bins for item (floor(log10(item))
		search through bins for existing index
		if found add item to that bin (no fetching / returning needed)
		else
  	  	  if no space for new bin, remove random bin until able to fetch new bin
  	  	  else fetch new bin
 */
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
using namespace std;
inline void RandomlyUsed(ofstream&output,const vector<int>&items,const int&binSize,const float&fetchCost,const float&returnCost){
	float totalCost=0;
	vector<int>bins;//sum of elements have to be <= binSize
	int currBinSum=0;
	srand(time(0));
	for(int i=0;i<(int)items.size();i++)
	{
		int item=items[i];
		int numBins=floor(log10(item))+1;
		if(numBins>binSize)continue;//cannot fit item wompwomp
		int currNumBins=(int)bins.size();
		for(int i=0;i<currNumBins;i++)
			if(bins[i]==numBins)continue;//found bin
		//specified bin size not found
		//remainder from total
		while(currBinSum+numBins>binSize)//while no space left for new slots, remove random
		{
			//randomly remove bins
			int index=rand()%currNumBins;
			int removeBinVal=bins[index];
			currBinSum-=removeBinVal;
			bins.erase(bins.begin()+index);
			totalCost+=returnCost*removeBinVal;
		}
		//push bin
		bins.push_back(numBins);
		currBinSum+=numBins;
		totalCost+=fetchCost;
		output<<"Current Table: ";for(auto x:bins)output<< x<<" ";output<<endl;
	}
	output<<"TotalCost: "<<totalCost<<endl;
}
