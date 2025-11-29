#ifndef __WAREHOUSE___
#define __WAREHOUSE___
#include <iostream>
#include <iomanip>
#include <vector>
#define Bin vector<vector<int>>
using namespace std;
class Warehouse
{
private:
	int numBins;
	int itemsPerBin;
	float fetchCost;
	float returnCost;
	Bin bins;
public:
	Warehouse();
	void setBinsAndItems(const int&,const int&);
	void setCosts(const float&,const float&);
	void addItem(const int&);
	friend ostream&operator<<(ostream&,const Warehouse&);
};

#endif
