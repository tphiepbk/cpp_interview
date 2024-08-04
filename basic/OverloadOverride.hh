// OverloadOverride.hh

#include <iostream>
#include "define.hh"

class Parent {
public:
    Parent();
    ~Parent();
    virtual void overrdingMethod() {
        pprint("Parent::overridingMethod() is called");
    };
    void overloadingMethod();
    void overloadingMethod(int);
    void overloadingMethod(std::string);
};

class Child : public Parent {
public:
    Child();
    ~Child();
    void overridingMethod();
};
