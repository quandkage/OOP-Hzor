#include <iostream>
#include "vec.h"

int main()
{
    vec arr(2);
    arr.push(10);
    arr.push(20);
    arr.push(30);
    vec arr2(arr);
    arr2.print();
    std::cout << std::endl;
    arr.print();
    
    return 0;
}
