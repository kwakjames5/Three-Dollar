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
  int head_;
  int tail_;
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
  this->size_ = 0;
  this->capacity_ = 5;
  this->head_ = 0;
  this->tail_ = 0;
  this->data_ = new T[this->capacity_];
}

// WORKS
template <typename T>
Deque<T>::Deque(size_t capacity)
:capacity_(capacity)
{
  // creates new deque with specific capacity
  this->size_ = 0;
  this->head_ = 0;
  this->tail_ = 0;
  this->data_ = new T[capacity];
}

// WORKS
template <typename T>
Deque<T>::~Deque()
{
  // deletes data
  // this needs to be done since data_ is the only variable in deque that is dynamically allocated
  delete [] this->data_;
}

// WORKS
template <typename T>
size_t Deque<T>::size() const
{
  // returns size
  return this->size_;
}

// WORKS
template <typename T>
bool Deque<T>::empty() const
{
  // checks if deque is empty
  if(this->size_ == 0)
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
  // modified_idx is the index that i wants on this circular array
  // head_ + i indicates the distance from head_ that we are looking for
  // the added capacity_ and the % capacity_ serve to make i work on a circular array

  // NOTE: Not entirely sure what the capacity_ and %capacity_ do
  // found the computations from old summer hw file, I think I got it from a teacher 
  // I am not sure exactly what it does but I have a rough idea and it works

  size_t modified_idx = (head_ + i + capacity_) % capacity_;

  // returns the i-th element fron head
  return this->data_[modified_idx];
}

// FIXED
template <typename T>
T const & Deque<T>::operator[](size_t i) const
{
  // modified_idx is the index that i wants on this circular array
  // head_ + i indicates the distance from head_ that we are looking for
  // the added capacity_ and the % capacity_ serve to make i work on a circular array

  // NOTE: Not entirely sure what the capacity_ and %capacity_ do
  // found the computations from old summer hw file, I think I got it from a teacher 
  // I am not sure exactly what it does but I have a rough idea and it works

  size_t modified_idx = (head_ + i + capacity_) % capacity_;

  // returns the i-th element fron head
  return this->data_[modified_idx];
}

// FIXED
template <typename T>
void Deque<T>::push_back(const T& item)
{
  // if the capacity of the deque has been met, specific operations must be done to set up a new deque with a larger capacity
  if(this->size_ == this->capacity_)
  {
    // creates a temporary T* with a capacity that has been upgraded by 5
    // this T* has more room for more elements to be pushed into
    size_t new_capacity_ = this->capacity_ + 5;
    T* new_data_ = new T[new_capacity_]; 

    // copy old deque data into temporary T* temp
    // run for the capacity_, which is the old size since we have not updated it yet
    for(int i = this->head_; i < this->tail_; i++)
    {
      // two new indexes are defined for the copying of data_ into new_data_
      // since data_ and new_data_ have different sized capacities, they have different indexes based on their capacities and the circular nature of the deque
      // for these reasons, two indexes must be found, one for the old capacity for data_ and one for the new capacity for new_data_
      size_t old_idx = (i + this->capacity_) % this->capacity_;
      size_t new_idx = (i + new_capacity_) % new_capacity_;
      new_data_[new_idx] = this->data_[old_idx];
    }

    // set data_ to the temp T*, which is basically the same thing except with a larger capacity
    // also increment capacity_ up by 5 since that has been updataed in data_ now
    this->data_ = new_data_;
    this->capacity_ = new_capacity_;
  }

  // move the tail_ up by 1 (tail_ since this is push_back)
  // now that tail_ has been moved up once, access the updated tail_'s index in the T* data_
  // update this new tail's element to be the item
  // update size_ by 1 since we just pushed an item
    
  this->data_[this->tail_] = item;
  this->tail_++;
  this->size_++;
}

// DOES NOT WORK
template <typename T>
void Deque<T>::push_front(const T& item)
{
  // checks if deque is already full
  if(this->size_ == this->capacity_)
  {
    // create new temporary deque
    size_t new_capacity_ = this->capacity_ + 5;
    T* new_data_ = new T[new_capacity_];

    // copy old deque data into temporary deque.
    for(int i = this->head_; i < this->tail_; i++)
    {
      // two new indexes are defined for the copying of data_ into new_data_
      // since data_ and new_data_ have different sized capacities, they have different indexes based on their capacities and the circular nature of the deque
      // for these reasons, two indexes must be found, one for the old capacity for data_ and one for the new capacity for new_data_
      size_t old_idx = (i + this->capacity_) % this->capacity_;
      size_t new_idx = (i + new_capacity_) % new_capacity_;
      new_data_[new_idx] = this->data_[old_idx];
    }

    this->data_ = new_data_;
    this->capacity_ = new_capacity_;
  }

  // first, set head to one index before it
  // since head_ will never be within the proper boundaries and will go past into the circular part of the array
  // modify it the same way the indexes above have been modified
  this->head_ = this->head_ - 1;
  int mod_head = (this->head_ + capacity_) % capacity_;
  this->data_[mod_head] = item;
  this->size_++;
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
  this->tail_ = this->size_;
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
  this->head_++;
  this->size_--;
}
#endif