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

template <typename T>
Deque<T>::~Deque()
{
  // deletes data
  delete [] data_;
}

template <typename T>
size_t Deque<T>::size() const
{
  // returns size
  return size_;
}

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

template <typename T>
T& Deque<T>::operator[](size_t i)
{
  // checks i-th element from head. "% capacity_" is for when 
  // head_ + i ever loops around the circular array
  return data_[(head_ + i) % capacity_];
}

template <typename T>
T const & Deque<T>::operator[](size_t i) const
{
  // checks i-th element from head. "% capacity_" is for when 
  // head_ + i ever loops around the circular array
  return data_[(head_ + i) % capacity_];
}

template <typename T>
void Deque<T>::push_back(const T& item)
{
  // checks if deque is already full
  while(size_ == capacity_)
  {
    // increase capacity and create new temporary deque.
    T* temp = new T[capacity_ + 5]; 

    // copy old deque data into temporary deque.
    for(unsigned int i = 0; i < capacity_; i++)
    {
      temp[i] = data_[(head_ + i) % capacity_];
    }

    // get rid of initial data, then set it to 
    // the new remporary deque with bigger capacity (5n + 5)
    // i.e original size 5 will turn into 10 with the original 5 elements.
    data_ = temp;
    capacity_ += 5;
  }
  // when deque is either not full or updated
  // push item into last spot (push_back)
  // and updates the new tail_ and size_ accordingly.
  if(size_ == 0)
  {
    data_[tail_] = item;
    size_++;
  }
  else
  {
    tail_ = (tail_ + 1) % capacity_;
    data_[tail_] = item;
    size_++;
  }
}

// INCOMPLETE
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
      temp[i] = data_[(head_ + i) % capacity_];
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

  // when deque is either not full or updated
  // update head_'s spot to create a spot for item in the front
  // push item into front spot (push_front), then update size_
  head_ = (head_ - 1) % capacity_;
  data_[head_] = item;
  size_++;
}

template <typename T>
void Deque<T>::pop_back()
{
  // checks if there is nothing to pop
  if(this->empty())
  {
    return;
  }

  // updates new size and sets tail to the lower size
  // the original longer tail goes away
  size_--;
  tail_ = size_;
}

template <typename T>
void Deque<T>::pop_front()
{
  // checks if there is nothing to pop
  if(this->empty())
  {
    return;
  }

  // pushes the entire head up by 1
  // lower size accordingly, original head goes away
  head_ = (head_ + 1) % capacity_;
  size_--;
}
#endif