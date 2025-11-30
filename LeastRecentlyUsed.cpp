/*
Victor is slacking
*/

#include "Warehouse.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;
class LRUWarehouse : public Warehouse
{
    public:
    void addItem(const int&it)
    {
        //
    }
};
inline void LeastRecentlyUsed(ofstream&output,const vector<int>&items,const int&binSize,const float&fetchCost,const float&returnCost){

    // Items = my inputs
        // Bin sizes are basedd on log10, log10(item = 10) = 1

        // go through our items and find largest item set as table size? --> maybe later

    // while table <= binsize
        // check if item is in a bin thats already on the tables
            // if it is add 1 in array at that index, use counting sort
            // keep track somewhere in another array that will hold the areas of the array that will hold the bin its at
        // every new bin added += fetchCost

    // If table == binSize,
        // look at our array to see which bin is being used, do quick comparison between them to find the smallest and remove that
        // cost += returnSize    

    vector<int> frequecy;
    unordered_set<int> table; // holds size which means bin at the index holds size
    int tableSize = 0;

    for (int i = 0; i < (int)items.size(); i++) {
        int itemBinSize = floor(log10(items[i]));

        for(int j = 0; j < (int) frequecy.size();j++) {
            items[i];
        }
    }




}
