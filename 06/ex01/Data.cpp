#include <inttypes.h>
#include <stddef.h>
#include "Data.hpp"

int Data::get_i() const{return this->i;}

Data::Data (int int_num){
    this->i = int_num;
}

Data::Data (Data const &d){
    this->i = d.get_i();
}

Data const & Data::operator=(Data const &d){
    this->i = d.get_i();
    return *this;
}

Data::Data (){
    this->i = 0;
}

Data::~Data (){}
