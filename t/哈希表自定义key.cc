#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <type_traits>
using namespace std;

// std::unordered_map实现自定义key
//
// 1. unordered_map的定义
//
// template <class Key,
//           class T,
//           class Hash = hash<Key>,
//           class Pred = equal_to<Key>,
//           class Alloc = allocator<pair<const Key, T>>> class unordered_map;
//
// 第1个参数，存储key值。
// 第2个参数，存储mapped value。
// 第3个参数，为哈希函数的函数对象。
//            它将key作为参数，并利用函数对象中的哈希函数返回类型为size_t的唯一哈希值。默认值为std::hash<key>。
// 第4个参数，为等比函数的函数对象。
//            它内部通过等比操作符'=='来判断两个key是否相等，返回值为bool类型。
//            默认值是std::equal_to<key>。在unordered_map中，任意两个元素之间始终返回false。
//
// 2. 问题分析
// 对于unordered_map而言，当我们插入<key, value>的时候，
// 需要哈希函数的函数对象对key进行hash，又要利用等比函数的函数对象确保插入的键值对没有重复。
// 然而，当我们自定义类型时，c++标准库并没有对应的哈希函数和等比函数的函数对象。因此需要分别对它们进行定义。
//
// 因为都是函数对象，它们两个的实际定义方法并没有很大差别。不过后者比前者多了一个方法。
// 因为等比函数的函数对象默认值std::equal_to<key>内部是通过调用操作符"=="进行等值判断，
// 因此我们可以直接在自定义类里面进行operator==()重载（成员和友元都可以）。
//
// 因此，如果要将自定义类型作为unordered_map的键值，需如下两个步骤：
//   1) 定义哈希函数的函数对象；
//   2) 定义等比函数的函数对象或者在自定义类里重载operator==()。
//
// 3. 定义方法
// 本文所有案例在用g++编译时，需加上-std=c++11或者-std=c++0x；如果用VS编译，请选择2010年及以上版本。
//
// 为了避免重复，下文以讨论哈希函数的函数对象为主，参数4则是通过直接在自定义key类里面对operator==()进行重载。
//
class Person {
public:
    string name;
    int age;

    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    bool operator==(const Person &p) const
    {
        return name == p.name && age == p.age;
    }
};

struct hash_name {
    size_t operator()(const Person &p) const
    {
        // hash<string>()是函数对象
        // hash<string>()(p.name)用于求字符串的hash值
        return hash<string>()(p.name) ^ hash<int>()(p.age);
    }
};

int main(int argc, char *argv[])
{
    {
        // std::__1::hash<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > ()
        cout << typeid(hash<string>()).name() << endl;
        cout << typeid(hash<int>()).name() << endl;
        cout << typeid(hash_name()).name() << endl;
        cout << typeid(main).name() << endl;
        // hash<int> 是结构体类型
        assert(is_function<hash<int>>::value == false);
        assert(is_class<hash<int>>::value == true);
        assert(is_object<hash<int>>::value == true);
        assert(is_object<Person>::value == true);

        // 函数对象: classes with overloaded operator()
        assert(is_function<hash<int>()>::value == true);
        assert(is_object<hash<int>()>::value == false);
        assert(is_object<hash_name()>::value == false);
        assert(is_object<hash_name>::value == true);
    }

    unordered_map<Person, int, hash_name> ids; //不需要把哈希函数传入构造器
    ids[Person("Mark", 17)] = 40561;
    ids[Person("Andrew", 16)] = 40562;
    for (auto i = ids.begin(); i != ids.end(); i++)
        cout << i->first.name << " " << i->first.age << " : " << i->second << endl;
    return 0;
}

// mangle和demangle
// 从name mangling后的标识符转换成C++源程序标识符: c++filt命令
// 将C++ ABI标识符(C++ ABI identifier)转换成C++源程序标识符(original C++ source identifier)的过程称为demangle。

// 在C++中，是允许函数重载的，也就引出了编译器的name mangling机制，c++filt命令便与此有关。

// 我们可以在编译出so库后，用ldd -r命令来找出undefined的函数名(当然也可以用nm命令)，
// 比如用ldd -r test.so查出缺少_ZNK4Json5ValueixEPKc(这就是name mangling后的函数名),
// 那怎么知道这个name mangling后的名字的原函数名称呢? c++file命令如下：
// $ c++filt  _ZNK4Json5ValueixEPKc
// Json::Value::operator[](char const*) const
