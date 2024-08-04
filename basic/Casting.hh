// Casting.hh

#include "define.hh"

class Animal {
public:
    virtual void speak() {
        pprint("Animal is speaking");
    }
};

class Dog : public Animal {
public:
    void speak();
};

class Cat : public Animal {
public:
    void speak();
};
