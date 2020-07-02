// C++11 - 强引用和弱引用
// “引用计数”不仅仅是为了内存自动回收和节省内存，
// 内存自动回收是一个原因，但是节省内存并不是真正的原因，真正的原因是有些对象如果被复制在现实中是不合事实的。
//
//
// 为什么有引用计数
//     C++中存在两种语义：值语义（value sematics）和对象语义（object sematic），对象语义也叫做指针语义、引用语义（reference sematics）。
// 值语义，指的是对象的拷贝与原对象无关，就像拷贝int一样，C++的常用类型数据等都是值语义。
// 对象语义，是禁止拷贝的。
//
//     在设计一个类的时候该类是否可以被拷贝（即具备拷贝构造函数），取决于拷贝后的语义是否成立，
//     比如一个Thread类，拷贝后系统中并不会启动另外一个线程，所以拷贝是禁止的。同样类似于Employee雇员类也是。
//
//     这么设计起码有两个好处：
//
//     1. 语义合理，有些对象复制是不符合常理的
//     2. 节省内存
//
//
// 强引用
// 当对象被创建时，计数为1；每创建一个变量引用该对象时，该对象的计数就增加1；当上述变量销毁时，对象的计数减1，当计数为0时，这个对象也就被析构了。
// 强引用计数在很多种情况下都是可以正常工作的，但是也有不奏效的时候，当出现循环引用时，就会出现严重的问题，以至于出现内存泄露，如下代码：

#include <iostream>

class parent;
class children;

typedef std::shared_ptr<parent> parent_ptr;
typedef std::shared_ptr<children> children_ptr;

class parent
{
public:
    ~parent() { std::cout <<"destroying parent\n"; }

public:
    children_ptr children;
};

class children
{
public:
    ~children() { std::cout <<"destroying children\n"; }

public:
    parent_ptr parent;
};

void test()
{
    parent_ptr father(new parent());
    children_ptr son(new children);

    father->children = son;
    son->parent = father;
}

int main()
{
    std::cout<<"begin test...\n";
    test();
    std::cout<<"end test.\n";
}

// 运行该程序可以看到，即使退出了test函数后，由于parent和children对象互相引用，
// 它们的引用计数都是1，不能自动释放，并且此时这两个对象再无法访问到。这就引起了c++中那臭名昭著的内存泄漏。
// 一般来讲，解除这种循环引用有下面有三种可行的方法：
// 1. 当只剩下最后一个引用的时候需要手动打破循环引用释放对象。
// 2. 当parent的生存期超过children的生存期的时候，children改为使用一个普通指针指向parent。
// 3. 使用弱引用的智能指针打破这种循环引用。
// 虽然这三种方法都可行，但方法1和方法2都需要程序员手动控制，麻烦且容易出错。
//
// 在多线程程序中，一个对象如果被多个线程访问，一般使用shared_ptr，通过引用计数来保证对象不被错误的释放导致其他线程访问出现问题。
// 但这种引用计数解决不了循环引用的问题。下面介绍弱引用
//
// std::weak_ptr是C++11提供的一个弱引用的智能指针，
//
// 定义变量：
// shared_ptr<T>  t(new T);
// weak_ptr<T> ptr(t); // t为一个T对象
// 则当t被销毁时，ptr 被自动置为无效。使用方法如下：
// if ( shard_ptr<T>  safePtr  = ptr.lock() )  safePtr->Fun();
//
// 可以看到，weak_ptr必须从一个share_ptr或另一个weak_ptr转换而来，
// 这也说明，进行该对象的内存管理的是那个强引用的share_ptr。
// weak_ptr只是提供了对管理对象的一个访问手段。
// weak_ptr除了对所管理对象的基本访问功能（通过get()函数）外，
// 还有两个常用的功能函数：expired()用于检测所管理的对象是否已经释放；lock()用于获取所管理的对象的强引用指针。
// 由于弱引用不更改引用计数，类似普通指针，只要把循环引用的一方使用弱引用，即可解除循环引用。
// 对于上面的那个例子来说，只要把children的定义改为如下方式，即可解除循环引用：

class children2
{
public:
    ~children2() { std::cout <<"destroying children\n"; }

public:
    std::weak_ptr<parent> parent;
};
// 最后值得一提的是，虽然通过弱引用指针可以有效的解除循环引用，但这种方式必须在程序员能预见会出现循环引用的情况下才能使用，
// 也可以是说弱引用仅仅是一种编译期的解决方案，如果程序在运行过程中出现了循环引用，还是会造成内存泄漏的。
// 因此，不要认为只要使用了智能指针便能杜绝内存泄漏。
// 毕竟，对于C++来说，由于没有垃圾回收机制，内存泄漏对每一个程序员来说都是一个非常头痛的问题。
//
// 弱引用：它仅仅是对象存在时候的引用，当对象不存在时弱引用能够检测到，从而避免非法访问，
// 弱引用也不会修改对象的引用计数。这意味这弱引用它并不对对象的内存进行管理，在功能上类似于普通指针，
// 然而一个比较大的区别是，弱引用能检测到所管理的对象是否已经被释放，从而避免访问非法内存。
