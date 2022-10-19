#include <cstddef>
#include <iostream>

struct hoge {
  char c[63];
  short s;
  double i;
};

struct empty {
};

int main()
{
  std::cout <<
    
    "std::max_align_t:  " << alignof(std::max_align_t) << std::endl <<
    sizeof(std::max_align_t)<<std::endl<<
    "char:              " << alignof(char) << std::endl <<
    sizeof(char)<<std::endl<<
    "int:               " << alignof(int) << std::endl <<
    sizeof(int)<<std::endl<<
    "double:            " << alignof(double) << std::endl <<
    sizeof(double)<<std::endl<<
    "struct hoge:       " << alignof(hoge) << std::endl <<
    sizeof(hoge)<<std::endl<<
    "struct empty:      " << alignof(empty) << std::endl <<
    sizeof(empty)<<std::endl<<
    "char *:            " << alignof(char *) << std::endl << 
    sizeof(char *)<<std::endl;
  return 0;
}