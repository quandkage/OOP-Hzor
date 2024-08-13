#include <iostream>
#include "vec.h"

vec::vec(): arr(nullptr), size(0), cap(5) {}

vec::vec(size_t cap): size(0), cap(cap)
{ 
    arr = new int[cap];
}
vec::vec(const vec& o)
{ 
    arr = o.arr;
    size = o.size;
    cap = o.cap;
}
vec::~vec(){
    if(arr != nullptr && deleted)
    { 
        delete[] arr;
        arr = nullptr;
    }
}
void vec::push(int value)
{
    if(size == cap){
        cap *= 2;
        int *tmp = new int[cap];
        for(int i = 0; i < size; i++){
            tmp[i] = arr[i];
        }
        delete[] arr;
        deleted = false;
        arr = tmp;
        tmp = nullptr;
    }
    arr[size] = value;
    ++size;
}

void vec::print() const
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ' << std::endl;
    }
}

