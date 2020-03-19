#ifndef HSORT_H
#define HSORT_H
#include <vector>

template<typename T, class Comparator>
void heapify(std::vector<T>& data, int loc, Comparator& comp)
{
	// RECREATE THE LECTURE SLIDE HEAPIFY FUNCTION

	// if(idx == leafnode){ return; } 
    if((2 * loc) >= data.size() && (2 * loc + 1) >= data.size())
    {
    	return;
    }

    // int smallerChild = 2 * idx;
    int smallerChild = 2 * loc; 

    // if(right child exists)
    if((smallerChild + 1) < data.size()) 
    {
		// int rChild = smallerChild+1;
		// if(items_[rChild] < items_[smallerChild]){
		//	smallerChild = rChild;}

        int rChild = smallerChild + 1;
        if(comp(data.at(rChild - 1), data.at(smallerChild - 1)))
        {
            smallerChild = rChild;
        } 
    }

    // if(items_[smallerChild] < items_[idx]){
	// 	swap(items_[idx], items_[smallerChild]);
	//  heapify(smallerChild);}

    if(comp(data.at(smallerChild - 1), data.at(loc - 1)))
    {
    	// swap function
        T temp = data.at(loc - 1);
        data.at(loc - 1) = data.at(smallerChild - 1);
        data.at(smallerChild - 1) = temp;

        // recursive call to new smallerChild
        heapify(data, smallerChild, comp);
    }
}

template<typename T, class Comparator>
void heapsort(std::vector<T>& data, Comparator comp = Comparator())
{
	// store data into a temporary array
    std::vector<T> store = data;

    // call heapify and implement trickle-down
    // heapify onto given data array
    for (int i = (store.size() / 2) ; i >= 0; i--) 
    {
        heapify(store, i, comp);
    }

    // holder integer temp for size of vector
    int temp = data.size();

    // normal heapsort for loop here
    // run for number of stuff in 
    // temp and sort accordingly
    for(int i = 0; i < temp; i++)
    {
        data.at(i)= store.at(0);
        store.at(0) = store.back();
        heapify(store, 1, comp);
        store.pop_back();
    }
}

#endif