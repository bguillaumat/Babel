/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.cpp
*/

#include "../../includes/server/Server.hpp"

Server::Server(boost::asio::io_service &io_service) : Client("", "", false), socket_(io_service)
{
}

void Server::handler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
	if (!error && !bytes_transferred){}
}

void Server::startServer()
{
	char	buffers[sizeof(char *)];

	message_ = "Welcome in our Server\n";
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&Server::handle, this,
			boost::asio::placeholders::error)
	);
	boost::asio::read(socket_, boost::asio::buffer(buffers));

	std::cout << "Infos récupéré chez le client => [" << buffers << "]" <<std::endl;
}

void Server::handle(const boost::system::error_code &error)
{
	if (!error)
	{
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

Tcp::Tcp(boost::asio::io_service &io_service, int port)
	: accept_(io_service, tcp::endpoint(tcp::v4(), port))
{
	begin_accept();
}

void Tcp::begin_accept()
{
	Server::pointer new_connection = Server::create(accept_.get_io_service());

	accept_.async_accept(new_connection->getSocket(),
		boost::bind(&Tcp::check_accept, this, new_connection,
			boost::asio::placeholders::error));
}

void Tcp::check_accept(Server::pointer new_connection, const boost::system::error_code& error)
{
	if (!error)
	{
		std::cout<<"A new client is connected!"<<std::endl;
		new_connection->startServer();
		begin_accept();
	}
}