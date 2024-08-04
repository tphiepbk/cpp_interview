// main.cc

#include "define.hh"
#include "MemoryManagement.hh"
#include "SmartPointer.hh"
#include "StructClass.hh"
#include "OverloadOverride.hh"
#include "Casting.hh"
#include "ConstFunction.hh"
#include <cstddef>
#include <iterator>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <typeinfo>

void demoStackHeap() {
    section("Stack/Heap");

    subsection("Stack variable");
    int variableOnStack = 0;
    pprint("variableOnStack = " + std::to_string(variableOnStack));

    subsection("Heap variable");
    int* variableOnHeap = new int();
    *variableOnHeap = 1407;
    pprint("variableOnHeap = " + std::to_string(*variableOnHeap));
    delete variableOnHeap;
    variableOnHeap = nullptr;

    subsection("Heap array");
    size_t size = 10;
    int* heapArr = new int[size];
    heapArr[0] = 10;
    pprint("variableOnHeap = ");
    for (size_t i = 0; i < 10; i++) {
        std::cout << heapArr[i] << " ";
    }
    delete[] heapArr;
    heapArr = nullptr;
}

void demoMemoryManagement() {
    section("Memory allocation/deallocation");
    pprint("new and delete");
    MemoryMangement* memtest = new MemoryMangement();
    pprint(memtest->get());
    delete memtest;
    pprint("malloc and free");
    MemoryMangement* memtest1 = (MemoryMangement*)malloc(sizeof(MemoryMangement));
    pprint(memtest1->get());
}

void demoSmartPointer() {
    section("SmartPointer - manual implementation");
    SmartPointer smartPtr(new int());
    *smartPtr = 20;
    pprint(*smartPtr);
}

void demoSTDSmartPointer() {
    section("SmartPointer - from std");
    subsection("std::unique_ptr");
    std::unique_ptr<Rectangle> uniqPtr(new Rectangle(10, 5));
    pprint("uniqPtr->area = " + std::to_string(uniqPtr->area()));
    pprint("switching");
    std::unique_ptr<Rectangle> anotherUniqPtr;
    anotherUniqPtr = std::move(uniqPtr);
    pprint("ptr2->area = " + std::to_string(anotherUniqPtr->area()));
    blankline;

    subsection("std::shared_ptr");
    std::shared_ptr<Rectangle> sharedPtr(new Rectangle(5, 6));
    pprint("shared_ptr->area = " + std::to_string(sharedPtr->area()));
    std::shared_ptr<Rectangle> anotherSharedPtr = sharedPtr;
    pprint("anotherShared_ptr->area = " + std::to_string(anotherSharedPtr->area()));

    // Should output "2" because there are 2 pointers refer to the Rectangle instance
    pprint("shared_ptr->useCount = " + std::to_string(sharedPtr.use_count()));
    pprint("anotherSharedPtr->useCount = " + std::to_string(anotherSharedPtr.use_count()));
    blankline;

    subsection("std::weak_ptr");

    // weak_ptr doesn't have the constructor for initialization
    // so this line of code should cause error
    // std::weak_ptr<Rectangle> weakPtr(new Rectangle(1, 2));

    std::weak_ptr<Rectangle> weakPtr(sharedPtr);

    // Should output "2" instead of "3" because there are 2 pointers refer to the
    // Rectangle instance as above
    // The weak_ptr doesn't maintain the Reference Counter
    pprint("shared_ptr->useCount = " + std::to_string(sharedPtr.use_count()));
    pprint("weakPtr->useCount = " + std::to_string(weakPtr.use_count()));
    blankline;
}

// Demo thread
void threadFunc(unsigned int threadNumber, unsigned int sleepTime) {
    pprint("Running thread number " + std::to_string(threadNumber));
    pprint("Sleeping for " + std::to_string(sleepTime) + " seconds");
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
}

void demoThread() {
    section("Thread");
    unsigned int numberOfThreads = 5;
    std::vector<std::thread> threadList;

    // Create threads
    for (unsigned int i = 0; i < numberOfThreads; i++) {
        std::thread threadObj(threadFunc, i, i);
        threadList.push_back(std::move(threadObj));
    }

    // Close threads
    for (std::vector<std::thread>::reverse_iterator it = threadList.rbegin() ; it != threadList.rend() ; ++it) {
        it->join();
    }

    pprint("Finish executing all threads");
}

void demoStructClass() {
    section("Struct vs Class");
    FooStruct fooStruct;
    fooStruct.set(9);
    std::cout << fooStruct.ptr << "\n";
    pprint("fooStruct = " + std::to_string(fooStruct.get()));
    FooClass* fooClass = new FooClass();
    fooClass->set(10);
    pprint("fooClass = " + std::to_string(fooClass->get()));
    delete fooClass;
}

void demoPointer() {
    section("Pointers");
    int* ptr = new int();
    int value = 10;
    ptr = &value;
    pprint(*ptr);
    delete ptr;
    ptr = nullptr;
}

void demoOverloadOverride() {
    section("OverloadOverride");
    Parent parent;
    parent.overloadingMethod();
    parent.overloadingMethod(5);
    parent.overloadingMethod("helloworld");
    Child* child = new Child();
    child->overridingMethod();
    child->overloadingMethod(5);
}

void passByValue(int a) {
    a = 10;
    pprint("passByValue(): a = " + std::to_string(a));
}

void passByRef(int& a) {
    a = 10;
    pprint("passByValueFunc(): a = " + std::to_string(a));
}

void demoPassByValueReference() {
    section("Pass by value and reference");
    int a = 5;
    pprint("Before: a = " + std::to_string(a));
    passByValue(a);
    pprint("After passed by value: a = " + std::to_string(a));
    passByRef(a);
    pprint("After passed by reference: a = " + std::to_string(a));
}

void demoCasting() {
    section("Casting");
    subsection("static_cast");
    int intVar = 10;
    float floatVar = static_cast<float>(intVar);
    pprint("floatVar: type = " + std::string(typeid(floatVar).name()) + ", value = " + std::to_string(floatVar));
    double doubleVar = static_cast<double>(intVar);
    pprint("doubleVar: type = " + std::string(typeid(doubleVar).name()) + ", value = " + std::to_string(doubleVar));

    subsection("dynamic_cast");
    Animal* animalPtr = new Dog();
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr) dogPtr->speak();
    else pprint("Failed to cast from Animal* to Dog*");
    Cat* catPtrFromAnimal = dynamic_cast<Cat*>(animalPtr);
    if (catPtrFromAnimal) catPtrFromAnimal->speak();
    else pprint("Failed to cast from Dog* to Cat*");

    subsection("const_cast");
    const int constVar = 10;
    const int* ptr = &constVar;
    int* nonConstPtr = const_cast<int*>(ptr);
    *nonConstPtr = 12;
    pprint("*nonConstPtr = " + std::to_string(*nonConstPtr));

    subsection("reinterpret_cast");
    int* intVarPtr = &intVar;
    double* doubleVarPtr = reinterpret_cast<double*>(intVarPtr);
    pprint(*doubleVarPtr);
}

inline void demoInlineFunctions() {
    pprint("this is an inline function");
}

void demoConstFunction() {
    section("Const function");
    ConstFunction* obj = new ConstFunction(10);
    pprint("obj->get(): " + std::to_string(obj->get()));
    obj->set(2992);
    pprint("obj->get(): " + std::to_string(obj->get()));
    obj->modify();
}

void demoUnsignedIntLoop() {
    // Infinite loop
    // for (size_t i = 10 ; i >= 0 ; i--) {
    //     pprint("i = " + std::to_string(i));
    // }
    size_t a = 0;
    pprint("a = " + std::to_string(a));
    a--;
    pprint("a = " + std::to_string(a));
}

int main() {
    // demoStackHeap();
    // demoMemoryManagement();
    // demoSmartPointer();
    // demoSTDSmartPointer();
    // demoThread();
    // demoStructClass();
    // demoPointer();
    // demoOverloadOverride();
    // demoPassByValueReference();
    // demoCasting();
    // demoInlineFunctions();
    // demoConstFunction();
    demoUnsignedIntLoop();
    blankline;
}

