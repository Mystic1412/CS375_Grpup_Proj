#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#define EMPTY -1
#define ITEMS 10
using namespace std;

struct Bin
{
	int num;
	int items[ITEMS]={EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY};//0-9
	Bin(const int&n):num(n){}
	void addItem(const int&item)
	{
		items[item%ITEMS]=item;
	}
	void clearBin()
	{
		for(int i=0;i<ITEMS;i++)items[i]=EMPTY;
	}
	friend ostream&operator<<(ostream&os,const Bin&bin)
	{
		int binNum=bin.num;
		if(binNum==-1)return os;
		os<<"Bin "<<bin.num<<":[";
		for(int i=0;i<ITEMS;i++)
		{
			int it=bin.items[i];
			os<<(it==EMPTY?"--":(it+""))<<(i==ITEMS-1?"":", ");
		}
		return os<<"]"<<endl;
	}
};
class Warehouse {
	public:
		Warehouse();
		void setBins(const int&);
		void setCosts(const float&,const float&);
		void addItem(const int&);//fetch/return if necessary
		friend ostream&operator<<(ostream&,const Warehouse&);
		
		int maxBins;
		float fetchCost;
		float returnCost;
		vector<Bin>bins;
};


#endif
