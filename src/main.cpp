#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::chrono;
using namespace std;

class tcpconnection : public std::enable_shared_from_this<tcpconnection>
{
public:
	typedef std::shared_ptr<tcpconnection> shared_ptr;

	static shared_ptr create(boost::asio::io_service &srv)
	{
		return shared_ptr(new tcpconnection(srv));
	}

	tcp::socket& socket()
	{ return _socket; }

	void start()
	{
		auto tp = boost::chrono::steady_clock::now();
		cout << "client connected at " << tp <<endl;
		async_write(_socket, boost::asio::buffer("hello world"),
				[](const boost::system::error_code &code, size_t size)
				{
			   	});
	}

private:

	tcpconnection(boost::asio::io_service &srv)
		: _socket(srv)
	{  }

	tcp::socket _socket;
};

class tcpserver : boost::noncopyable
{
public:
	tcpserver(io_service &io)
		: _acceptor(io, tcp::endpoint(tcp::v4(), 1333))
	{
		start_accept();
	}

private:

	void start_accept()
	{
		tcpconnection::shared_ptr ptr =
			tcpconnection::create(_acceptor.get_io_service());

		_acceptor.async_accept(ptr->socket(),
				[this, ptr](const boost::system::error_code &code)
				{
					if (!code)
					{ ptr->start(); }
					start_accept();
			   	});


	}

	tcp::acceptor _acceptor;
};

int main()
{
	try
	{
		io_service io;
		tcpserver srv(io);
		io.run();
	}
	catch(std::exception &e)
	{
	}
	return 0;
}
