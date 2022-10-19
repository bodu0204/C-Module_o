#include <iostream>

auto func(void)->decltype(int())
{
    std::cout<<"callde"<<std::endl;
    return 3;
}

int main ()
{
    int i = func();
    std::cout<<i<<std::endl;
    return 0;
}