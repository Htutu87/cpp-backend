
#include <iostream>
#include <asio.hpp>
#include <date_time/posix_time/posix_time.hpp>

int main() 
{
    std::cout << "Hello, world!" << '\n'; 
    std::cout << "Asio installed!" << '\n'; 
    std::cout << "Timer 1 example!" << '\n'; 

	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait();

    std::cout << "5 seconds have passed!" << "\n\n"; 

    return 0;
}
