#include "circulararray.h"

// -------------------------------------------------------------------------------------------- Stack
template <typename T>
class StackArray : public CircularArray<T> {
private:
    T* array{};
    int capacity{}, size{};
    T front{};
public:
    void push_front(T data){
        if(size == 0){
            capacity =+ 3;
            array[0] = data;
            size++;
        }
        else{
            if(capacity == size)
                capacity+= 3;
            T temp = data;
            T hold;
            for(int i = 0; i < size; i++){
                hold = array[i];
                array[i] = temp;
                temp = hold;
            }
        }
        front = data;
    }
    T pop_front(){
        if(size == 0)
            return 0;
        else{
            return front;
        }
    }
    bool is_full() {
        if (capacity == size)
            return true;
        return false;
    }

    bool is_empty(){
        if(size == 0)
            return true;
        return false;
    }
    void clear(){
        for(int i = 0; i < capacity; i++){
            array[i] = 0;
        }
        front = 0;
        size = 0;
    }
    void reverse(){
        T *newArray = new T[capacity];
        for(int i = 0; i < size; i++){
            newArray[i] = array[size - i];
        }
        front = array[size];
        array = newArray;
    }
};