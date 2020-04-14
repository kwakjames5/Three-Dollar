#ifndef DEQUE_H
#define DEQUE_H
#include <stdexcept>

/**
 * Implements a templated, array-based, 
 * double-ended queue.
 *
 * The Deque should allow for amortized O(1) 
 * insertion and removal from either end. 
 * It should dynamically resize, when it becomes
 * full, but never needs to shrink.  
 *
 * It should use a circular buffer approach
 * by tracking the "front" and "back" location.
 *
 */


template <typename T>
class Deque
{
 public:
  /* START - DO NOT CHANGE ANY OF THESE LINES */
  /**
   *  Default constructor 
   *   Create an array of size 1 by default
   */
  Deque();

  /**
   *  Default constructor 
   *   Create an array of the given capacity.
   */
  Deque(size_t capacity);

  /**
   *  Destructor
   */
  ~Deque();

  /**
   *  Returns the number of elements in the Deque. 
   *   - Must run in O(1)
   */
  size_t size() const;

  /**
   *  returns true if the deque is empty
   *   - Must run in O(1)
   */
  bool empty() const;

  /**
   *  returns  the i-th element from the front
   *   - Must run in O(1)
   *   - Must throw std::range_error if i is
   *      an invalid location
   */
  T& operator[](size_t i);

  /**
   *  returns  the i-th element from the front
   *   - Must run in O(1)
   *   - Must throw std::range_error if i is
   *      an invalid location
   */
  T const & operator[](size_t i) const;

  /**
   *  Inserts a new item at the back of the
   *  Deque
   *   - Must run in amortized O(1)
   */
  void push_back(const T& item);

  /**
   *  Inserts a new item at the front of the
   *  Deque
   *   - Must run in amortized O(1)
   */
  void push_front(const T& item);

  /**
   *  Removes the back item from the Deque
   *   - Must run in amortized O(1)
   *   - Simply return if the deque is empty
   */
  void pop_back();

  /**
   *  Removes the front item from the Deque
   *   - Must run in amortized O(1)
   *   - Simply return if the deque is empty
   */
  void pop_front();
  /* END - DO NOT CHANGE ANY OF THESE LINES */
 private:
  /* Add data members and private helper 
   * functions below 
   */
  size_t size_;
  size_t capacity_;
  size_t head_;
  size_t tail_;
  T* data_;

};

/* Implement each Deque<T> member function below 
 * taking care to meet the runtime requirements
 */

// WORKS
template <typename T>
Deque<T>::Deque()
{
  // creates new deque with default capacity (5)
  size_ = 0;
  capacity_ = 5;
  head_ = 0;
  tail_ = 0;
  data_ = new T[capacity_];
}

// WORKS
template <typename T>
Deque<T>::Deque(size_t capacity)
:capacity_(capacity)
{
  // creates new deque with specific capacity
  size_ = 0;
  head_ = 0;
  tail_ = 0;
  data_ = new T[capacity_];
}

// WORKS
template <typename T>
Deque<T>::~Deque()
{
  // deletes data
  // this needs to be done since data_ is the only variable in deque that is dynamically allocated
  delete [] data_;
}

// WORKS
template <typename T>
size_t Deque<T>::size() const
{
  // returns size
  return size_;
}

// WORKS
template <typename T>
bool Deque<T>::empty() const
{
  // checks if deque is empty
  if(size_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }

  return 0;
}

// FIXED
template <typename T>
T& Deque<T>::operator[](size_t i)
{
  // returns the i-th element fron head
  return data_[(head_ + i)];
}

// FIXED
template <typename T>
T const & Deque<T>::operator[](size_t i) const
{
  // returns i-th element from head
  return data_[(head_ + i)];
}

// FIXED
template <typename T>
void Deque<T>::push_back(const T& item)
{
  // if the capacity of the deque has been met, specific operations must be done to set up a new deque with a larger capacity
  if(size_ == capacity_)
  {
    // creates a temporary T* with a capacity that has been upgraded by 5
    // this T* has more room for more elements to be pushed into
    T* temp = new T[capacity_ + 5]; 

    // copy old deque data into temporary T* temp
    // run for the capacity_, which is the old size since we have not updated it yet
    for(unsigned int i = 0; i < capacity_; i++)
    {
      temp[i] = data_[(head_ + i)];
    }

    // set data_ to the temp T*, which is basically the same thing except with a larger capacity
    // also increment capacity_ up by 5 since that has been updataed in data_ now
    data_ = temp;
    capacity_ += 5;
  }

  // this is for when the deque is empty
  if(size_ == 0)
  {
    // set the tail_ as the item since this is push_back
    // update size_ by 1 since we just pushed an item
    // no need to touch capacity since we are not at capacity yet
    data_[tail_] = item;
    size_++;
  }
  else
  {
    // move the tail_ up by 1 (tail_ since this is push_back)
    // now that tail_ has been moved up once, access the updated tail_'s index in the T* data_
    // update this new tail's element to be the item
    // update size_ by 1 since we just pushed an item
    tail_ = (tail_ + 1);
    data_[tail_] = item;
    size_++;
  }
}

// DOES NOT WORK
template <typename T>
void Deque<T>::push_front(const T& item)
{
  // checks if deque is already full
  while(size_ == capacity_)
  {
    // create new temporary deque
    T* temp = new T[capacity_ + 5];

    // copy old deque data into temporary deque.
    for(unsigned int i = 0; i < capacity_; i++)
    {
      temp[i] = data_[(head_ + i)];
    }

    data_ = temp;
    capacity_ += 5;
  }

  // off set the existing data_ by 1 in order to create room for
  // the new head and pushed value
  int i = size_;
  while(i--)
  {
    data_[i + 1] = data_[i];
  }

  for(int i = 0; i < size_; i++)
  {
    data_[i] += 1;
  }

  // when deque is either not full or updated
  // update head_'s spot to create a spot for item in the front
  // push item into front spot (push_front), then update size_
  head_ = (head_ - 1) % capacity_;
  data_[head_] = item;
  size_++;
}

// FIXED
template <typename T>
void Deque<T>::pop_back()
{
  // checks if there is nothing to pop
  // NOTE: empty() is a bool expression that returns true or false depending on the empty status of the deque
  // if empty is true, return and end this function since nothing can be popped
  if(this->empty())
  {
    return;
  }

  // decrement size_ down by one (opposite of when we did push_back and upgraded tail_ and size_)
  size_--;

  // now that size_ is essentialy size_ - 1, move the tail_ down with the size_
  // this will automatically pop whatever was at the initial size_ tail_
  tail_ = size_;
}


// FIXED
template <typename T>
void Deque<T>::pop_front()
{
  // checks if there is nothing to pop
  // NOTE: empty() is a bool expression that returns true or false depending on the empty status of the deque
  // if empty is true, return and end this function since nothing can be popped
  if(this->empty())
  {
    return;
  }

  // pushes the entire head up by 1
  // doing so automatically gets rid of whatever was initially sitting at the original head_
  // decrement size now that the front has been popped
  head_ = (head_ + 1);
  size_--;
}
#endif