#include <iostream>

class test
{
private:
    static int i;
public:
    int geti(){return i;}
    test();
    ~test();
};

test::test()
{
    i++;
}

test::~test()
{}

int test::i = 0;

template<typename T>
decltype(T()) func(T i)
{
    std::cout<<"callde"<<std::endl;
    return 3;
}

int main ()
{
    test t;
    std::cout<<t.geti()<<std::endl;
    std::cout<<test().geti()<<std::endl;
    return 0;
}