#include <iostream>
#include <string>
using namespace std;

class MyClass {

private:
    ~MyClass(){};
    int _age;
    std::string _name;

public:
    MyClass() = default;
    MyClass(int age, std::string name):_age(age),_name(name){}

    void destory() { std::cout << "析构前的必要步骤" << std::endl; delete this; }
};


int main()
{
    // MyClass  A;   // error !
    MyClass* B = new MyClass;
    // delete B;
    B->destory();
}
