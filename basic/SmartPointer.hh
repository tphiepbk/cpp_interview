// SmartPointer.hh

class SmartPointer {
private:
    int* smartPtr = nullptr;
public:
    SmartPointer(int* p = nullptr);
    ~SmartPointer();
    int& operator*();
};

// Demo purpose
class Rectangle {
private:
    int a = 0;
    int b = 0;
public:
    Rectangle(int inpA, int inpB);
    ~Rectangle();
    int area();
};
