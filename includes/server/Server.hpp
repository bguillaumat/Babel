/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by j-f,
*/
#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/array.hpp>
#include <set>
#include <vector>
#include <iterator>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include "Client.hpp"

using namespace boost::chrono;
using boost::asio::ip::tcp;

// class to make a connection between users
class Server : public std::enable_shared_from_this<Server>, public Client {
private:
	std::set<Client>	_participants;
	tcp::socket		socket_;
	std::string		message_;
	Server(boost::asio::io_service& io_service);
	void		handle(const boost::system::error_code& error);
	void handler(const boost::system::error_code& error,
		std::size_t bytes_transferred);



public:
	typedef boost::shared_ptr<Server> pointer;
	~Server(){};
	static		pointer create(boost::asio::io_service& ios);
	void		startServer();
	void		getClientData(int);
	tcp::socket&	getSocket();
	std::string	getMessage();
};


// Creation af an tcp server
class Tcp {
private:
	tcp::acceptor		accept_;
	void			begin_accept();
	void			check_accept(Server::pointer new_connection,
		const boost::system::error_code& error);

public:
	~Tcp(){};
	Tcp(boost::asio::io_service& io_service, int port);
};
#endif //CPP_BABEL_2018_SERVER_HPP
