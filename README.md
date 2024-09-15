# DEQUE

## Problem Statement: Implement Deque

## What is deque?
● Deque is the same as dynamic arrays with the ability to resize itself automatically when an element is inserted, with their storage being handled automatically by the container.
● They support insertion and deletion from both ends in amortized constant time.
● Inserting and erasing in the middle is linear in time.

### Operations : 
The C++ standard specifies that a legal (i.e., standard-conforming) implementation of deque must satisfy the following performance requirements: (consider the data type as T)
1. deque() - initialize an empty deque. Time complexity: O(1)
2. deque(n) - initialize a deque of length n with all values as default value of T. Time complexity: O(n)
3. deque(n, x) - Initialize a deque of length n with all values as x. Time complexity: O(n)
4. void push_back(x) - append data x at the end. Time complexity: constant amortized time
5. void pop_back() - erase data at the end. Time complexity: constant amortized time
6. bool push_front(x) - append data x at the beginning. Time complexity: constant amortized time
7. bool pop_front() - erase an element from the beginning. Time complexity: constant amortized time
8. T front() - returns the first element(value) in the deque. If the first element is not present, return the default value of T. Time complexity: O(1)
9. T back() - returns the last element(value) in the deque. If the last element is not present, return the default value. Time complexity: O(1)
10. T D[n] - returns the nth element of the deque. You need to overload the [ ] operator. If nth element is not present return default value of T. Time complexity: O(1)
11. bool empty() - returns true if deque is empty else returns false. Time complexity: O(1)
12. int size() - returns the current size of deque. Time complexity: O(1)
13. void resize(n) - change the size dynamically to new size n. Time complexity: O(n)
    ◦ If the new size n is greater than the current size of the deque, then insert new elements with the default value of T at the end of the queue.
    ◦ If the new size n is smaller than the current size, then keep n elements from the beginning of the deque.
14. void resize(n, d) - change the size dynamically to new size n. Time complexity: O(n)
    ◦ If the new size n is greater than the current size of the deque, then insert new elements with value d at the end of the queue.
    ◦ If the new size n is smaller than the current size, then keep n elements from the beginning of the deque.
15. void reserve(n) : change the capacity of deque to n, if n > current capacity; otherwise do nothing. Time complexity: O(n)
16. void shrink_to_fit() - reduce the capacity of the deque to current size. Time Complexity: O(size())
17. void clear() - remove all elements of deque. Time complexity: O(n)
18. int capacity() - return the current capacity of deque. Time complexity: O(1) 

#### Note :
1. Your deque should be generic type i.e. it should be datatype independent and can support primitive data types like integer, float, string, etc. Hint: Use template in C++ (link)
2. For 1, 2 & 3 You can either define a constructor for the class or initialize the class object using void return type functions.
3. C++ STL is not allowed (including vectors, design your own if required)
4. D[0] - element at index 0 (i.e. first element from the front), D[1] - element at index 1 (i.e. second element from the front), D[-1] - element at last index (i.e. first element from the back), D[-2] - element at second last index (i.e. second element from the back)
5. Size of the deque is the number of elements currently present in your deque.
6. Capacity of the deque is the number of elements your deque can accommodate with currently held memory.
7. During Operation 1 both size and capacity of the deque should be set to zero.
8. If size is equal to capacity and a new element is inserted, then the capacity is doubled, unless capacity is zero, then it will become one.
9. If you have doubts about deciding the new capacity in any of the operations, refer to the behavior of the member functions of STL vector containers.
