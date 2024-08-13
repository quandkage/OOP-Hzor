#include <iostream>

class vec
{
    private:
        int *arr;
        size_t size;
        size_t cap;
        bool  deleted = false;
    public:
        vec();
        vec(size_t cap);
        vec(const vec& o);
        ~vec();
        void push(int value); 
        void print() const;     
};
