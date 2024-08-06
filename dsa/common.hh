// common.hh

#include <iostream>

// Common
#define blankline std::cout << "\n"
#define pprint(message) std::cout << message << "\n"
#define section(title) std::cout << "==================== " << title << " ====================" << "\n"
#define subsection(title) std::cout << "********* " << title << " *********" << "\n"
#define db(message) std::cout << "[debug]: " << message << "\n"

void swap(int*, int, int);

