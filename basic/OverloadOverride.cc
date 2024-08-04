// OverloadOverride.cc

#include "OverloadOverride.hh"
#include "define.hh"

Parent::Parent() {
    pprint("Parent::Parent() is called");
}

Parent::~Parent() {
    pprint("Parent::~Parent() is called");
}

void Parent::overloadingMethod() {
    pprint("Parent::overloadingMethod() is called");
}

void Parent::overloadingMethod(int a) {
    pprint("Parent::overloadingMethod() is called, int value = " + std::to_string(a));
}

void Parent::overloadingMethod(std::string str) {
    pprint("Parent::overloadingMethod() is called, string value = " + str);
}

Child::Child() {
    pprint("Child::Child() is called");
}

Child::~Child() {
    pprint("Child::~Child() is called");
}

void Child::overridingMethod() {
    pprint("Child::overridingMethod() is called");
}

