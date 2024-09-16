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

        bool push_back(T _val) {
            if(length == capacity){
                resize(capacity * 2);
            }
            rearIndex = (rearIndex + 1) % capacity;
            arr[rearIndex] = _val;
            if(length == 0) frontIndex = rearIndex;         
            length++;
            return true;
        }

        bool pop_back() {
            if(length == 0) {
                return false;
            }

            rearIndex = (rearIndex - 1 + capacity) % capacity;
            length--;
            return true;
        }

        bool push_front(T _val) {
            if(length == capacity){
                resize(capacity * 2);
            }
            frontIndex = (frontIndex - 1 + capacity) % capacity;
            arr[frontIndex] = _val;
            if(length == 0) rearIndex = frontIndex;
            length++;
            return true;
        }

        bool pop_front() {
            if(length == 0) 
                return false;

            frontIndex = (frontIndex + 1) % capacity;
            length--;
            return true;
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
                newArr[i] = arr[(frontIndex + i) % capacity]; 
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

int main() 
{
    deque<int> dq;
    int menu, x, n;

    while (true) {
        
        cin >> menu;

        switch (menu) {
            case 1:
                dq = deque<int>();
                break;
            case 2:
                cin >> n;
                dq = deque<int>(n);
                break;
            case 3:
                cin >> n >> x;
                dq = deque<int>(n, x);
                break;
            case 4:
                cin >> x;
                cout << boolalpha << dq.push_back(x) << endl;
                break;
            case 5:
                cout<< boolalpha << dq.pop_back() << endl;
                break;
            case 6:
                cin >> x;
                cout << boolalpha << dq.push_front(x) << endl;
                break;
            case 7:
                cout << boolalpha << dq.pop_front() << endl;
                break;
           case 8:
                cout << dq.front() << endl;
                break;
            case 9:
                cout << dq.back() << endl;
                break;
            case 10:
                cin >> n;
                cout << dq[n] << endl;
                break;
            case 11:
                cout << boolalpha << dq.empty() << endl;
                break;
            case 12:
                cout << dq.size() << endl;
                break;
            case 13:
                cin >> n;
                dq.resize(n);
                break;
            case 14:
                cin >> n >> x;
                dq.resize(n, x);
                break;
            case 15:
                cin >> n;
                dq.reserve(n);
                break;
            case 16:
                dq.shrink_to_fit();
                break;
            case 17:
                dq.clear();
                break;
            case 18:
                cout << dq.getCapacity() << endl;
                break;
            case 0:
                return 0;
        }
    }

    return 0;
}    