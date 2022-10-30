#include "Data.hpp"
#include <iostream>

int main() {
    Data stack(42);

    (void)stack;
    uintptr_t u = serialize(&stack);
    std::cout<<"serialize(stack): "<<u<<std::endl;
    std::cout<<"deserialize(u)->get_i(): "<<deserialize(u)->get_i()<<std::endl;
    return 0;
}