#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    int size(){
        return back - front;
    }
    bool is_full(){
        return back == prev(front);
    }
    bool is_empty(){
        return size() == 0?;
    }
    void clear();
    void resize(){
        capacity++;
    }
    void push_front(T data){
        if(size() == 0){
            resize();
            array[0] = data;
            size++;
        }
        else{
            if(capacity == size())
                capacity+= 3;
            T temp = data;
            T hold;
            for(int i = 0; i < size(); i++){
                hold = array[i];
                array[i] = temp;
                temp = hold;
            }
        }
        front = data;
    }
    void push_back(T data){
        if(size() == 0){
            resize();
            array[0] = data;
        }
        else{
            if(capacity == size())
                capacity+= 3;
            array[size() + 1] = data;
        }
        back = data;
    }
    T &operator[](int);
    T front(){
        return array[front];
    }
    T back(){
        return array[back];
    }
    void sort()
    {
        for (int gap = size()/2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size(); i += 1)
            {
                int temp = array[i];
                int j;
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                    array[j] = array[j - gap];
                array[j] = temp;
            }
        }
    }
    void clear(){
        for(int i = 0; i < capacity; i++){
            array[i] = 0;
        }
    }
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

    void enqueue(int data){
        if(is_full()) resize();
        back = next(back);
        array[back] = data;
        size++;
    }
    void dequeue(){
        if(is_empty()){
            throw ("esta vacio");
        }
        front = next(front);
    }
    T pop_front(){
        dequeue();
        return array[front];
    }
    T pop_back(){
        back = prev(back);
        return array[back];
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

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
