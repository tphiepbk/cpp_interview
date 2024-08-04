// ConstFunction.cc

#include "define.hh"
#include "ConstFunction.hh"

ConstFunction::ConstFunction() {
    pprint("ConstFunction::ConstFunction() is called");
    this->var = new int();
}

ConstFunction::ConstFunction(int input) {
    pprint("ConstFunction::ConstFunction(int) is called");
    this->var = new int(input);
}

ConstFunction::~ConstFunction() {
    pprint("ConstFunction::~ConstFunction() is called");
    delete var;
    var = nullptr;
}

int ConstFunction::get() {
    return *this->var;
}

void ConstFunction::set(int input) {
    *this->var = input;
}

// This will raise error
// void ConstFunction::modify() const {
//     *(this->var)++;
// }

void ConstFunction::modify() const {
    pprint("ConstFunction::modify(): cannot modify data member in const function");
}

