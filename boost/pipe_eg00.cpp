#include <boost/asio.hpp>
#include <boost/process/async_pipe.hpp>
#include <boost/thread.hpp>
#include <cstdio>
namespace bp = boost::process;

/// echo hello, pipe > \\\\.\\pipe\\SamplePipe
int main()
{
    boost::asio::io_service ios;
    std::vector<char> buf(5);
    bp::async_pipe ap(ios, "\\\\.\\pipe\\SamplePipe");
    boost::asio::async_read(
        ap, boost::asio::buffer(buf),
        [](const boost::system::error_code &ec, std::size_t size) {});
    ios.run();
    for (auto i : buf)
        printf("%c", i);

    return 0;
}
