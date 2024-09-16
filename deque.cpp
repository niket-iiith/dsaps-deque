#include<iostream>

using namespace std;

template <typename T>
class deque 
{    
    private:
        T* arr;
        int frontIndex;
        int rearIndex;
        int capacity;
        int length;

    public: 
        deque() {
            arr = new T[1];
            capacity = 1;
            length = 0;
            frontIndex = 0;
            rearIndex = -1;
        }

        deque(int _capacity) {
            arr = new T[_capacity];
            capacity = _capacity;
            length = 0;
            frontIndex = 0;
            rearIndex = -1;
        } 

        deque(int _capacity, T _val) {
            arr = new T[_capacity];
            capacity = _capacity;
            length = _capacity;
            frontIndex = 0;
            rearIndex = _capacity - 1;

            for(int i=0; i<_capacity; i++){
                arr[i] = _val;
            }
        }

        void push_back(T _val) {
            if(length == capacity){
                resize(capacity * 2);
            }
            rearIndex = (rearIndex + 1) % capacity;
            arr[rearIndex] = _val;
            if(length == 0) frontIndex = rearIndex;         
            length++;
        }

        void pop_back() {
            if(length == 0) 
                throw out_of_range("error: Deque is Empty");

            rearIndex = (rearIndex - 1 + capacity) % capacity;
            length--;
        }

        void push_front(T _val) {
            if(length == capacity){
                resize(capacity * 2);
            }
            frontIndex = (frontIndex - 1 + capacity) % capacity;
            arr[frontIndex] = _val;
            if(length == 0) rearIndex = frontIndex;
            length++;
        }

        void pop_front() {
            if(length == 0) 
                throw out_of_range("error: Deque is Empty");
            frontIndex = (frontIndex + 1) % capacity;
            length--;
        }

        T front() {
            if(empty()) 
                throw out_of_range("Deque is empty");
            return arr[frontIndex];
        }

        T back() {
            if(empty()) 
                throw out_of_range("Deque is empty");
            return arr[rearIndex];
        }

        T& operator[](int index) {
            if (index < 0 || index >= length) {
                throw out_of_range("Index out of bounds");
            }
            return arr[(frontIndex + index) % capacity];    // Circular wrap for random access
        }

        bool empty() {
            return (length == 0);
        }

        int size() {
            return length;
        }

        void resize(int _capacity) {
            T* newArr = new T[_capacity];
            for(int i=0; i<length; i++) {
                newArr[i] = (*this)[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = _capacity;
            frontIndex = 0;
            rearIndex = length - 1;
        }

        void resize(int _capacity, T _val)
        {    
            // If the new size n is greater than the current size of the deque, 
            // then insert new elements with value d at the end of the queue.
            if(_capacity > length) {
                if(_capacity > capacity){
                    resize(_capacity);
                }
                for(int i=length; i<_capacity; i++) {
                    push_back(_val);
                }
            }
            // If the new size n is smaller than the current size,
            // then keep n elements from the beginning of the deque.
            else if (_capacity < length) {
                while (length-- > _capacity) {
                    pop_back();  
                }
            }
        }

        // change the capacity of deque to n, if n > current capacity; otherwise do nothing.
        void reserve(int _capacity) {
            if(_capacity > capacity) 
                resize(_capacity);
        }

        void shrink_to_fit() {
            if (capacity > length) {
                resize(length);  
            }
        }

        // removes all elements of deque
        void clear() {
            length = 0;
            frontIndex = 0;
            rearIndex = -1;
        }

        // return the capacity of the queue
        int getCapacity() {
            return capacity;
        }

};

int main() {
    deque<int> dq(5,100);

    dq.push_back(200);
    dq.push_back(4123);
    dq.push_back(34);
    dq.push_back(5);
    dq.push_back(876);

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";  
    }
    cout << endl;

    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;  // Should print 100
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;
    dq.pop_front();
    cout << "After pop_front, front element: " << dq.front() << endl;

    dq.resize(20, 3);

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";  
    }
    cout << endl;

    dq.clear();
    cout << "After clear, size of deque: " << dq.size() << endl;  // Should print 0
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;  // Should print "Yes"

    dq.push_back(200);
    dq.push_back(4123);
    dq.push_back(34);
    dq.push_back(5);
    dq.push_back(876);

    dq.resize(3, 2);

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";  
    }
    cout << endl;


    return 0;
}