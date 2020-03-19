#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
template <
         typename T,
         typename KComparator = std::equal_to<T>,
         typename PComparator = std::less<T>,
         typename Hasher = std::hash<T> >
class Heap
{
public:
    /// Constructs an m-ary heap. M should be >= 2
    Heap(int m = 2,
         const PComparator& c = PComparator(),
         const Hasher& hash = Hasher(),
         const KComparator& kcomp = KComparator()  );

    /// Destructor as needed
    ~Heap();

    /// Adds an item
    void push(const T& item);

    /// returns the element at the top of the heap
    ///  max (if max-heap) or min (if min-heap)
    T const & top() const;

    /// Removes the top element
    void pop();

    /// returns true if the heap is empty
    bool empty() const;

    /// decreaseKey - Finds key matching old object &
    /// updates its location in the heap based on the new value
    void decreaseKey(const T& old, const T& newVal);

 private:
    /// Add whatever helper functions and data members you need below
    void heapify(int index);

    void trickleUp(int loc);

 private:
   /// Data members - These should be sufficient
    std::vector< T > store_;
    int m_;
    PComparator c_;
    std::unordered_map<T, size_t, Hasher, KComparator> keyToLocation_;

};

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
Heap<T,KComparator,PComparator,Hasher>::Heap(
    int m,
    const PComparator& c,
    const Hasher& hash,
    const KComparator& kcomp ) :

    store_(),
    m_(m),
    c_(c),
    keyToLocation_(100, hash, kcomp)

{
}

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
Heap<T,KComparator,PComparator,Hasher>::~Heap()
{
}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::push( const T& item)
{
    // add, update, trickle
    store_.push_back(item);
    keyToLocation_[item] = store_.size() - 1;
    trickleUp(store_.size() - 1);
}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::decreaseKey(const T& old, const T& newVal)
{
    if(c_(old, newVal))
    {
        return;
    }

    typename std::unordered_map<T, size_t, Hasher, KComparator>::iterator it;
    it = keyToLocation_.find(old);

    if(it == keyToLocation_.end())
    {
        return;
    }

    int index = it->second;
    store_[index] = newVal;

    if(!c_(store_[(index - 1)/m_], newVal))
    {
        trickleUp(index);
    }
    else
    {
        heapify(index);
    }
}

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
T const & Heap<T,KComparator,PComparator,Hasher>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()) {
        throw std::logic_error("can't top an empty heap");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return store_[0];
}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::pop()
{
    if(empty()) 
    {
        throw std::logic_error("can't pop an empty heap");
    }

    store_[0] = store_[store_.size() - 1];
    store_.pop_back();
    heapify(0);
}

/// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
bool Heap<T,KComparator,PComparator,Hasher>::empty() const
{
    return store_.empty();
}

template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::heapify(int index)
{
    if((unsigned)index > ((store_.size() / 2) + 1) && (unsigned)index < store_.size())
    {
        return;
    }

    if((store_.size() > (unsigned)(m_ * index + 1)))
    {
        int smallest = m_ * index + 1;

        // check if it is the smallest

        for (int i = 2; i <= m_; i++) 
        {
            if ((unsigned)(m_ * index + i) < store_.size())
            {
                int temp = m_ * index + i;

                if (c_(store_[temp], store_[smallest]))
                {
                    smallest = temp;
                }
            }
        }

        // swap and heapify when <
        if (c_(store_[smallest], store_[index]))
        {
            std::swap(store_[index], store_[smallest]);
            heapify(smallest);
        }
    }
}

template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::trickleUp(int loc)
{
    int p = (loc - 1) / m_;

    while(p >= 0 && c_(store_[loc], store_[p]))
    {
        std::swap(store_[p], store_[loc]);
        loc = p;
        p = loc / 2;
    }
}

#endif

