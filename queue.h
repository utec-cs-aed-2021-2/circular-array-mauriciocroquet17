#include "circulararray.h"

// -------------------------------------------------------------------------------------------- Stack
template <typename T>
class QueueArray : public CircularArray<T> {
private:
    T* array{};
    int capacity{}, size{};
    T front{}, back{};
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
    void push_back(T data){
        if(size == 0){
            capacity =+ 3;
            array[0] = data;
            size++;
        }
        else{
            if(capacity == size)
                capacity+= 3;
            array[size + 1] = data;
            size++;
        }
        back = data;
    }
    T pop_front(){
        if(size == 0)
            return 0;
        else{
            return front;
        }
    }
    T pop_back(){
        T temp = array[size];
        array[size] = 0;
        size--;
        return temp;
    }
    bool is_full(){
        if(size == capacity)
            return true;
        else{
            return false;
        }
    }
    bool is_empty(){
        if(size == 0)
            return true;
        else{
            return false;
        }
    }
    void clear(){
        for(int i = 0; i < capacity; i++){
            array[i] = 0;
        }
        front = 0;
        back = 0;
        size = 0;
    }
    void reverse(){
        T *newArray = new T[capacity];
        for(int i = 0; i < size; i++){
            newArray[i] = array[size - i];
        }
        front = array[size];
        back = array[0];
        array = newArray;
    }
};