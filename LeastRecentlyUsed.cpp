/*
Victor is slacking
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

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
    // bin N = 2 -> 20-22
    // log10(1000) = 3 size

    // item = 999. bin index = 999/10 = 99
    // item = 999999. bin index = 999999/10 = 99999
    vector<int> onTable; // num times bin was used
    vector<int> freq; // holds size which means bin at the index holds size

    // Temphardcode
    //vector<int> items = {1, 40, 402, 20, 16, 2, 8, 30, 44, 27, 9};

    int maxTableSize = binSize;
    int tableSize = 0;
    float totalCosts = 0;


    for (int i = 0; i < (int)items.size(); i++) {
        // Sets current items binSize
        bool placed = false;
        int binIndex = floor(items[i]/10);
        int currBinSize = floor(log10(items[i]));

        if (currBinSize < 1) {
            currBinSize = 1;
        }

        for (int tableItems = 0; tableItems < (int)onTable.size(); tableItems++) {
            if (binIndex == onTable[tableItems]) {
                placed = true;
                freq[binIndex]++;
                break;

            }
        }

        if (!placed) {

            if (tableSize > 0) {

                // Theres space on table
                if (tableSize + currBinSize <= maxTableSize) {
                    if (binIndex >= (int)freq.size()) {
                    freq.resize(binIndex + 1, 0);
                    }

                    freq[binIndex]++;
                    onTable.push_back(binIndex);
                    tableSize = tableSize + currBinSize*fetchCost;

                // No space so keep removing lowest freq until theres space e
                } else if (tableSize + currBinSize > maxTableSize) {

                    while (tableSize + currBinSize > maxTableSize) {
                        int minFreqBin = onTable[0];
                        int index = 0;
                        for (int j = 0; j < (int)onTable.size(); j++) {
                            if (freq[onTable[j]] < freq[minFreqBin]) {
                                minFreqBin = onTable[j];
                                index = j;
                            }
                        }

                        int minFreqBinSize = floor(log10(minFreqBin * 10));

                        if (minFreqBinSize < 1) {
                            minFreqBinSize = 1;
                        }

                        tableSize = tableSize - minFreqBinSize;
                        totalCosts = totalCosts + minFreqBinSize*returnCost;
                        output << " -REMOVED: Bin " << minFreqBin << " (size " << minFreqBinSize << ")" << endl;

                        onTable.erase(onTable.begin() + index);
                    }

                }

                if (binIndex >= (int)freq.size()) {
                    freq.resize(binIndex + 1, 0);
                    }

                    freq[binIndex]++;
                    onTable.push_back(binIndex);
                    tableSize = tableSize + currBinSize;
                    totalCosts = totalCosts + currBinSize*fetchCost;

            } else {

                // If table was empty
                if (binIndex >= (int)freq.size()) {
                    freq.resize(binIndex + 1, 0);
                }

                freq[binIndex]++;
                onTable.push_back(binIndex);
                tableSize = tableSize + currBinSize;
                totalCosts = totalCosts + currBinSize * fetchCost;
            }

        }

        // Debug output
        output << "Item: " << items[i] << " | Bin Index: " << binIndex << " | Size: " << currBinSize;
        output << " | Table size: " << tableSize << " | Total cost: " << totalCosts << endl;
    }

    output << "Final total cost: " << totalCosts << endl;
}
