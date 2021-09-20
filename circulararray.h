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
        return front > back ? (capacity - front + back + 1) : (back - front + 1);
    }
    bool is_full(){
        return back == prev(front);
    }
    bool is_empty(){
        return this->size() == 0?;
    }
    void resize(){
        capacity++;
    }
    void push_front(T data){
        if(this->size() == 0){
            rethis->size();
            array[0] = data;
            size++;
        }
        else{
            if(capacity == this->size())
                capacity+= 3;
            T temp = data;
            T hold;
            for(int i = 0; i < this->size(); i++){
                hold = array[i];
                array[i] = temp;
                temp = hold;
            }
        }
        front = data;
    }
    void push_back(T data){
        if(this->size() == 0){
            rethis->size();
            array[0] = data;
        }
        else{
            if(capacity == this->size())
                capacity+= 3;
            array[this->size() + 1] = data;
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
        for (int gap = this->size()/2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < this->size(); i += 1)
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
    bool is_sorted(){
        for(int i = front; i < this->size(); i++){
            if(array[i] > array[i+1]){
                return false;
            }
        }
    }
    string to_string(string sep=" ");

    void enqueue(int data){
        if(is_full()) rethis->size();
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
    for (int i = 0; i < this->size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
