// SmartPointer.cc

#include "SmartPointer.hh"
#include "define.hh"

// Class SmartPointer
SmartPointer::SmartPointer(int* p) {
    pprint("SmartPointer::SmartPointer(): is called");
    this->smartPtr = p;
}

SmartPointer::~SmartPointer() {
    pprint("SmartPointer::~SmartPointer(): is called");
    delete smartPtr;
}

int& SmartPointer::operator*() {
    pprint("SmartPointer::operator*(): is called");
    return *(this->smartPtr);
};

// Class Rectangle
Rectangle::Rectangle(int inpA, int inpB) {
    pprint("Rectangle::Rectangle(): is called");
    this->a = inpA;
    this->b = inpB;
}

Rectangle::~Rectangle() {
    pprint("Rectangle::~Rectangle(): is called");
}

int Rectangle::area() {
    pprint("Rectangle::area(): is called");
    return this->a * this->b;
}


