#include <iostream>

int main()
{
    int value = 0;
    for(size_t i=0;i<10;i++)
    {
        value+=4;
        value*=2;
        std::cout<<value<<std::endl;
    }
    return 0;
}