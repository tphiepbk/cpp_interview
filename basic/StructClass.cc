// StructClass.cc

#include "define.hh"
#include "StructClass.hh"

FooClass::FooClass() {
    pprint("FooClass::FooClass() is called");
    this->ptr = nullptr;
}

FooClass::~FooClass() {
    pprint("FooClass::~FooClass() is called");
    // delete this->ptr;
}

int FooClass::get() {
    return *(this->ptr);
}

void FooClass::set(int input) {
    // *(this->ptr) = input;
    this->ptr = &input;
}

FooStruct::FooStruct() {
    pprint("FooStruct::FooStruct() is called");
    this->ptr = nullptr;
}

FooStruct::~FooStruct() {
    pprint("FooStruct::~FooStruct() is called");
    // delete this->ptr;
}

int FooStruct::get() {
    return *(this->ptr);
}

void FooStruct::set(int input) {
    // *(this->ptr) = input;
    this->ptr = &input;
}
