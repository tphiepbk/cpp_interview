// StructClass.hh

class FooClass {
    int* ptr;
public:
    FooClass();
    ~FooClass();
    int get();
    void set(int);
};

struct FooStruct {
    int* ptr;
    FooStruct();
    ~FooStruct();
    int get();
    void set(int);
};
