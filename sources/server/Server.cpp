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
	char	buffers[sizeof(char) * 2];
	int	nb = 0;

	message_ = "200\n";
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&Server::handle, this,
			boost::asio::placeholders::error)
	);

	boost::asio::read(socket_, boost::asio::buffer(buffers, 2));

	nb = atoi(buffers);
	std::cout << nb << std::endl;
	std::cout << "Infos récupéré chez le client => [" << nb << "]" <<std::endl;

	message_ = "200\n";
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&Server::handle, this,
			boost::asio::placeholders::error)
	);

	getClientData(nb);
}

void	Server::getClientData(int nb)
{
	char	buffers[sizeof(char) * nb];
	std::string			data;
	int				x = 0;
	int 				option;
	bool				is_connected;
	std::string			ip, username;
	std::vector<std::string>	tokens;

	if (nb >= 10)
		nb += 1;
	boost::asio::read(socket_, boost::asio::buffer(buffers, nb));
	if (!isalnum(buffers[0]))
		x++;
	if (nb >= 10)
		nb -= 1;
	while (buffers[x] && isprint(buffers[x]) && nb) {
		data.push_back(buffers[x]);
		nb--;
		x++;
	}
		boost::algorithm::split(tokens, data, boost::is_any_of("|"));
	option = atoi(tokens[0].c_str());
	username = tokens[1];
	ip = tokens[2];
	if (option == 0) {
		is_connected = true;
		Client	new_client(ip, username, is_connected);
	//	_participants.insert(new_client);
	}
	else if (option == 1) {
		is_connected = false;
		Client	new_client(ip, username, is_connected);
		std::cout << username << " leaved the server" <<std::endl;
		/*for (auto participant: _participants) {
			if (participant == new_client) {
				_participants.erase(participant);
				break;
			}
		}*/
	}
	else if (option == 2) {
		std::string msg ="You are trying to call " + username + "\n";
		boost::asio::async_write(socket_, boost::asio::buffer(msg),
			boost::bind(&Server::handle, this,
				boost::asio::placeholders::error)
		);
	}
	std::cout << "Infos récupéré chez le client => [" << data << "]" <<std::endl;
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