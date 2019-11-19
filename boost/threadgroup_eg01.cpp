#include <boost/atomic.hpp>
#include <boost/thread.hpp>
#include <cstdio>

boost::mutex io_mu; // io流操作锁

void printing(boost::atomic_int &x, const std::string &str)
{
    for (int i = 0; i < 5; ++i) {
        boost::mutex::scoped_lock lock(io_mu); //锁定io流操作
        printf("%s: %d\n", str.c_str(), ++x);
    }
}

int main()
{
    boost::atomic_int x(0);

    boost::thread_group tg;
    tg.create_thread(boost::bind(printing, std::ref(x), "hello"));
    tg.create_thread(boost::bind(printing, std::ref(x), "hi"));
    tg.create_thread(boost::bind(printing, std::ref(x), "boost"));
    tg.join_all();
    // getchar();
    return 0;
}
