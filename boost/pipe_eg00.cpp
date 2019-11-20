#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <cstdio>
#include <boost/process/async_pipe.hpp>
namespace bp = boost::process;


int main()
{
    boost::asio::io_service ios;
    std::vector<char> buf(20);
    bp::async_pipe ap(ios, "\\\\.\\pipe\\SamplePipe");
    boost::asio::async_read(ap, boost::asio::buffer(buf),
            [](const boost::system::error_code &ec, std::size_t size) {});
    ios.run();

    return 0;
}
