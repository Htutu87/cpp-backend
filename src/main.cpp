
#include <iostream>
#include <thread>   
#include <chrono>  

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main() 
{
	boost::asio::io_context ioc;
	boost::system::error_code ec;

	// Endpoint uma entidade a qual podemos nos conectar.
	// Neste caso, estamos definindo um endpoint no formato TCP -> IP:Porta.
	boost::asio::ip::tcp::endpoint endpoint(
	boost::asio::ip::make_address("93.184.216.34", ec), 80 ); 

	// Socket é a entidade que se comunica com os driveres de rede do sistemaoperacional.
	boost::asio::ip::tcp::socket socket(ioc);

	socket.connect(endpoint, ec);

	if (!ec)
	{
		std::cout << "Connected!\n";
	}
	else 
	{
		std::cout << "Failed to connect to address: " << ec.message() << std::endl;
	}

	if (socket.is_open())
	{
		// Como estamos nos conectando a um website, sabemos que ele está esperando uma
		// requisição HTTP.
		
		std::string sRequest =
			"GET /index.html HTTP/1.1\r\n"
			"Host: example.com\n"
			"Connection: close\n\n";

		std::cout << sRequest;

		socket.write_some( boost::asio::buffer( sRequest.data(), sRequest.size() ), ec );

		socket.wait(socket.wait_read);

		size_t bytes = socket.available();
		std::cout << "Bytes available to read: " << bytes << std::endl;

		if (bytes > 0)
		{
			std::vector<char> vBuffer(bytes);
			socket.read_some(boost::asio::buffer( vBuffer.data(), vBuffer.size() ), ec );
		
			for (auto c : vBuffer)
				std::cout << c;
		}
	}



    return 0;
}
