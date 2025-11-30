#include "Warehouse.h"

Warehouse::Warehouse():maxBins(0),fetchCost(0),returnCost(0),bins(){}

void Warehouse::setBins(const int&binCount)
{
	maxBins=binCount;
	bins=vector<Bin>(maxBins,Bin(-1));
}
//base implementation (ig)
void Warehouse::addItem(const int&it)
{
	int binModifyIndex=-1;
	int index=it/10;
	//first find existing bin, if none add
	for(int i=0;i<maxBins;i++)
	{
		if(bins[i].num==index)
		{
			binModifyIndex=i;
			goto setBin;
		}
	}
	//not found
	for(int i=0;i<maxBins;i++)
	{
		if(bins[i].num==EMPTY)
		{
			//fetch
			binModifyIndex=i;
			goto setBin;
		}
	}
	//no empty space
	//assume return first bin for now
	//return
	
	binModifyIndex=0;
	bins[binModifyIndex].clearBin();
setBin:
	bins[binModifyIndex].num=index;
	bins[binModifyIndex].addItem(it);
}

void Warehouse::setCosts(const float&fetch,const float&returnC)
{
	fetchCost=fetch;
	returnCost=returnC;
}

ostream&operator<<(ostream&os,const Warehouse&warhouse)
{
	int n=warhouse.maxBins;
	os<<"FetchCost: $"<<fixed<<setw(3)<<setprecision(2)<<warhouse.fetchCost<<
			fixed<<endl<<"ReturnCost: $"<<fixed<<setw(3)<<setprecision(2)<<warhouse.returnCost<<endl;
	cout<<"Bins:["<<endl;
	for(int i=0;i<n;i++)os<<warhouse.bins[i];
	cout<<"]"<<endl;
	return os;
}
