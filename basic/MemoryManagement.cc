// MemoryMangement.cc

#include "define.hh"
#include "MemoryManagement.hh"

MemoryMangement::MemoryMangement() {
    pprint("MemoryMangement::MemoryMangement() is called");
    this->value = 2992;
}

MemoryMangement::~MemoryMangement() {
    pprint("MemoryMangement::~MemoryMangement() is called");
}

int MemoryMangement::get() {
    pprint("MemoryMangement::get() is called");
    return this->value;
}

