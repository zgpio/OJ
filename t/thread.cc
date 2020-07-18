#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class HelloThread {
public:
    static void hellothread()
    {
        std::cout << "hello world" << std::endl;
    }
    static void start()
    {
        std::thread t(hellothread);
        t.join();
    }
};
void hello()
{
    std::cout << "Hello:" << this_thread::get_id() << std::endl;
}
int msum(int a, int b)
{
    int c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    return c;
}
class HelloWorld {
public:
    void hello(int year)
    {
        std::cout << year << std::endl;
    }
};

// TODO: 更加实际的用例
int main(int argc, char *argv[])
{
    {
        std::thread t(hello);
        t.join();
    }
    {
        std::thread t(msum, 1, 2);
        t.join();
    }
    {
        HelloThread::start();
    }
    {
        HelloWorld obj;
        std::thread t(std::bind(&HelloWorld::hello, &obj, 26));
        t.join();
    }
    std::cout << "Main Thread" << std::endl;
    return 0;
}
