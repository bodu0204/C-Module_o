#include "Data.hpp"
#include <iostream>

int main() {
    Data stack(42);

    std::cout<<"&stack: "<<&stack<<std::endl;
    std::cout<<"serialize(stack): "<<std::hex<< serialize(&stack) <<std::endl;
    std::cout<<"deserialize(serialize(&stack)): "<<deserialize(serialize(&stack))<<std::endl;
    std::cout<<"deserialize(serialize(&stack))->get_i(): "<<std::dec<<deserialize(serialize(&stack))->get_i()<<std::endl;
    return 0;
}