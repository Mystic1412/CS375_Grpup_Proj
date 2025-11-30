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
		int remainder=binSize-currBinSum;
		//cout<<"Add:"<<numBins<<",OldRemainder:"<<remainder<<endl;
		if(remainder<=0)//if no space left for new bin
		{
			int removeSum=0;
			while(removeSum<numBins)
			{
				//randomly remove bins
				int index=rand()%currNumBins;
				int removeBinVal=bins[index];
				currBinSum-=removeBinVal;
				removeSum+=removeBinVal;
				bins.erase(bins.begin()+index);
				totalCost+=returnCost;
				//cout<<"CurrBinSum: "<<currBinSum<<",::Remainder:"<<remainder<<endl;
			}
		}
		bins.push_back(numBins);
		currBinSum+=numBins;
		//cout<<"NewRemainder:"<<(binSize-currBinSum)<<endl;
		totalCost+=fetchCost;
		cout<<"Current Table: ";for(auto x:bins)cout<< x<<" ";cout<<endl;
	}
	cout<<"TotalCost: "<<totalCost<<endl;
}
