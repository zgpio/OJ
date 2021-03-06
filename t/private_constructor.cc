// 类中“私有”权限的含义就是：私有成员只能在类域内被访问，不能在类域外进行访问。
//
// 把析构函数定义为私有的，就阻止了用户在类域外对析构函数的使用。这表现在如下两个方面：
// 1. 禁止用户对此类型的变量进行定义，即禁止在栈内存空间内创建此类型的对象。要创建对象，只能用 new 在堆上进行。
// 2. 禁止用户在程序中使用 delete 删除此类型对象。
//
// 对象的删除只能在类内实现，也就是说只有类的实现者才有可能实现对对象的 delete，用户不能随便删除对象。
// 如果用户想删除对象的话，只能按照类的实现者提供的方法进行。
//
//
// 用声明创建一个栈对象时，会发生如下操作
// 1、会移动栈顶指针以“挪出”适当大小的空间
// 2、在这个空间上直接调用对应的构造函数以形成一个栈对象
// 3、当函数返回时，会调用其析构函数释放这个对象
// 4、调整栈顶指针收回那块栈内存
//
//
// 为什么要禁止生成栈对象（什么情况下需要自己调用析构函数呢？）
//
// 比如这样一种情况，你希望在析构之前必须做一些事情，但是用你类的人并不知道，
// 那么你就可以重新写一个函数，里面把要做的事情全部做完了再调用析构函数。
// 这样人家只能调用你这个函数析构对象，从而保证了析构前一定会做你要求的动作。
// 为什么不直接在析构函数中做这些处理？可能这些处理需要用户指定参数。


// 将析构函数设为private除了会限制栈对象生成外，还有其它影响吗？是的，这还会限制继承。
//
// 如果一个类不打算作为基类，通常采用的方案就是将其析构函数声明为private。
//
// 为了限制栈对象，却不限制继承，我们可以将析构函数声明为protected，这样就两全其美了。
//

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

    void destory() {
        // 析构前的必要步骤
        delete this;
    }
};


int main()
{
    // MyClass  A;   // Compilation error !
    MyClass* B = new MyClass;
    // delete B;   // Compilation error !
    B->destory();
}
