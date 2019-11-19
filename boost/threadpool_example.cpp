/// https://kezunlin.me/post/f241bd30/
/// g++ threadpool_example.cpp -o main -lboost_thread-mt -std=c++11
#include <chrono>   //std::chrono::seconds
#include <future>   //std::future std::promise
#include <iostream> //std::cout std::endl
#include <thread>   //std::thread
#include <utility>  //std::ref

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

using std::cout;
using std::endl;
class ThreadPool {
public:
    explicit ThreadPool(size_t size) : work_(io_service_)
    {
        for (size_t i = 0; i < size; ++i) {
            workers_.create_thread(
                boost::bind(&boost::asio::io_service::run, &io_service_));
        }
    }

    ~ThreadPool()
    {
        cout << "~ThreadPool" << endl;
        io_service_.stop(); // stop before join_all
        workers_.join_all();
    }

    // Add new work item to the pool.
    template <class F>
    void Enqueue(F f)
    {
        io_service_.post(f);
        // sync, return immediately
    }

private:
    boost::thread_group workers_;
    boost::asio::io_service io_service_;
    boost::asio::io_service::work work_;
};

boost::mutex io_mutex;

void count(int id)
{
    for (int i = 0; i < 10; i++) {
        boost::mutex::scoped_lock lock(io_mutex);
        cout << id << ":" << i << endl;
    }
}

void test_thread()
{
    boost::thread thrd1(boost::bind(&count, 1));
    boost::thread thrd2(boost::bind(&count, 2));
    thrd1.join();
    thrd2.join();
}

void print(int i)
{
    boost::mutex::scoped_lock lock(io_mutex);
    cout << "print() #" << boost::this_thread::get_id() << endl;
    cout << "hello " << i << endl;
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    cout << "world " << i << endl;
}

void test_thread_pool()
{
    // Create a thread pool of 4 worker threads.
    ThreadPool pool(4);

    // Queue a bunch of work items.
    for (int i = 0; i < 8; ++i) {
        pool.Enqueue(boost::bind(&print, i));
    }
}

void do_task(std::promise<int> &promiseObj)
{
    boost::mutex::scoped_lock lock(io_mutex);
    cout << "Inside thread id: " << std::this_thread::get_id() << endl;
    cout << "Inside thread: sleep 2 seconds... " << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    promiseObj.set_value(35);
}

void test_future()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    cout << "create thread..." << endl;
    std::thread th(do_task, std::ref(promiseObj));

    cout << "futureObj.get() block main thread." << endl;
    cout << futureObj.get() << endl;

    th.join();
    cout << "after join" << endl;
}

/*
std::bind
bind预先绑定的参数需要传具体的变量或值进去, 对于预先绑定的参数, 是pass-by-value的;
[使用std::ref()可以pass by reference]
对于不事先绑定的参数, 需要传std::placeholders进去, 从_1开始, 依次递增. placeholder是pass-by-reference的;
*/
/// 什么是多线程？比如在做一些下载的程序时, 同时开启5个下载任务, 对应的其实就是多线程.
///   在一些多线程的程序中, 响应请求的个数(即线程)的个数过多的话就会造成系统资源损耗过多而宕机,
///   一般最多线程是有上限的, 而且每次创建线程和销毁线程都会大量损耗资源和时间.
///   所以解决办法之一就是使用线程池控制线程个数, 复用创建过的线程.
/// 线程池可以减少创建和切换线程的额外开销, 利用已经存在的线程多次循环执行多个任务从而提高系统的处理能力.

int main(int argc, char *argv[])
{
    cout << "main thread id: " << std::this_thread::get_id() << endl;
    // test_thread();
    test_thread_pool();
    // test_future();
    return 0;
}
