
#include <string>
#include <iostream>
#include <stdalign.h>
#include <cstddef>

class test
{
private:
    char c;
    int i;
public:
    test(/* args */);
    ~test();
};

int main( void ) {
std::cout << sizeof(int) << std::endl;
auto a = alignof(int);
std::cout << a << std::endl;
return 0;
}
