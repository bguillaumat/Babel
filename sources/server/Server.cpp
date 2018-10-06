/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.cpp
*/

#include "../../includes/server/Server.hpp"

Server::Server(boost::asio::io_service &io_service) : socket_(io_service)
{
}

void Server::startServer()
{
	message_ = "Welcome in our Server\n";
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&Server::handle, this,
			boost::asio::placeholders::error)
	);
}

void Server::handle(const boost::system::error_code &error)
{
	if (!error)
	{
		// others actions
	}
}

Server::pointer Server::create(boost::asio::io_service &ios)
{
	return pointer(new Server(ios));
}

tcp::socket & Server::getSocket()
{
	return socket_;
}

/// server tcp creation ///

Tcp::Tcp(boost::asio::io_service &io_service, int port)
	: accept_(io_service, tcp::endpoint(tcp::v4(), port))
{
	begin_accept();
}

void Tcp::begin_accept()
{
	Server::pointer new_connection = Server::create(accept_.get_io_service());

	accept_.async_accept(new_connection->getSocket(),
		boost::bind(&Tcp::handle_accept, this, new_connection,
			boost::asio::placeholders::error));
}

void Tcp::handle_accept(Server::pointer new_connection, const boost::system::error_code& error)
{
	if (!error)
	{
		std::cout << "A client is connected!" << std::endl;
		new_connection->startServer();
		begin_accept();
	}
}