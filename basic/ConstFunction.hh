// ConstFunction.hh

class ConstFunction {
    int* var;
public:
    ConstFunction();
    ConstFunction(int);
    ~ConstFunction();
    int get();
    void set(int);
    void modify() const;
};
