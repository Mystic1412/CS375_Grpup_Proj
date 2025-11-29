#include "Warehouse.h"

Warehouse::Warehouse():numBins(0),itemsPerBin(0),fetchCost(0),returnCost(0),bins(){}

void Warehouse::setBinsAndItems(const int&binCount,const int&items)
{
	numBins=binCount;
	itemsPerBin=items;
	bins=vector(binCount,vector(items,-1));
}
void Warehouse::addItem(const int&it)
{
	int binNum=it/itemsPerBin;
	int itemIndex=it%itemsPerBin;
	bins[binNum][itemIndex]=it;
}
void Warehouse::setCosts(const float&fetch,const float&returnC)
{
	fetchCost=fetch;
	returnCost=returnC;
}
ostream&operator<<(ostream&os,const Warehouse&warhouse)
{
	int n=warhouse.numBins;
	int nI=warhouse.itemsPerBin;
	os<<"FetchCost: $"<<fixed<<setw(3)<<setprecision(2)<<warhouse.fetchCost<<
			fixed<<endl<<"ReturnCost: $"<<fixed<<setw(3)<<setprecision(2)<<warhouse.returnCost<<endl;
	for(int i=0;i<n;i++)
	{
		os<<"Bin "<<i<<": [";
		for(int j=0;j<nI;j++)
		{
			os<<warhouse.bins[i][j]<<(j==n-1?"":", ");
		}
		os<<"]"<<endl;
	}
	return os;
}
