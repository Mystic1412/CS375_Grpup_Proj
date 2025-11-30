//Nichole
#include "Warehouse.h"
#include <queue>
#include <unordered_map>

/*
class FIFOWarehouse : public Warehouse
{
    public:
    void addItem(const int&it)
    {
        //
    }
};
*/
inline void FIFO(ofstream&output,const vector<int>&items,const int&binSize,const float&fetchCost,const float&returnCost){
    int totalslotused = 0;
    float totalCost=0;
    int Maxslot = binSize;
    
    unordered_map<int, int> Ontable;
    queue<int> BinQueue;
    //for each item
    for(int i=0;i<items.size();i++){
        int needbin=items[i]/10;
        int slotsize = floor(log10(items[i])+1);

        if(Ontable.find(needbin) == Ontable.end()){
            if(slotsize> Maxslot){
                continue; //item is too big
            }


            while(slotsize +totalslotused >  Maxslot && !BinQueue.empty()){ //getting rid of bins till the current bin size can fit on the table
                int removedBin = BinQueue.front(); //gets the first item that was in it
                int removedSize = Ontable[removedBin]; //gets the slot size of the bin we're getting rid of
                BinQueue.pop();
                Ontable.erase(removedBin); 
                totalslotused -= removedSize; //freeing up room on the table
                totalCost += returnCost*removedSize; //return cost * bin size 
                
            }

            BinQueue.push(needbin); 
            Ontable[needbin] = slotsize; //maps the number to how much slots it takes
            totalslotused += slotsize; //keeping track of how much room on the table is used
            totalCost += fetchCost*slotsize;
        }
        output<<"Current Table: ";
        for(auto x = Ontable.begin(); x != Ontable.end(); x++){
            output<< x->first;output<<" ";
        }
        output<<endl;
    }
    
    output<<"\nTotal Cost: "<<totalCost<<endl;
}
