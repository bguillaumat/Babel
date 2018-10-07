/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.cpp
*/

#include "Server.hpp"

Server::Server(boost::asio::io_service &io_service) : socket_(io_service)
{
}

void Server::handler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
	if (!error && !bytes_transferred){}
}

void Server::startServer(std::list<Client>& client_list, std::list<std::string>& msg_list)
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

	if (nb != 0) {
		message_ = "200\n";
		boost::asio::async_write(socket_, boost::asio::buffer(message_),
			boost::bind(&Server::handle, this,
				boost::asio::placeholders::error));

		getClientData(nb, client_list, msg_list);
	}
}

void	Server::getClientData(int nb, std::list<Client>& client_list, std::list<std::string>& msg_list)
{
	char	buffers[sizeof(char) * nb];
	std::string			data;
	int				x = 0;
	int 				option;
	bool				is_connected;
	bool				find = false;
	std::string			ip, username;
	std::vector<std::string>	tokens;
	std::list<Client>::iterator	it1;
	std::list<std::string>::iterator	it2;

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

	//std::string client_ip = socket_.remote_endpoint().address().to_string();
	boost::algorithm::split(tokens, data, boost::is_any_of("|"));
	option = atoi(tokens[0].c_str());
	username = tokens[1];
	ip = socket_.remote_endpoint().address().to_string();
	if (option == 0) {
		is_connected = true;
		Client	new_client(ip, username, is_connected);
		client_list.push_back(new_client);
	}
	else if (option == 1) {
		is_connected = false;
		Client	current_client(ip, username, is_connected);
		for (it1 = client_list.begin(); it1 != client_list.end(); it1++) {
			if ((*it1).getIp() == current_client.getIp() &&
				(*it1).getUsername() ==
					current_client.getUsername()) {
				std::cout << username << " leaved the server"
					<< std::endl;
				it1 = client_list.erase(it1);
			}
		}
		std::cout << client_list.size() << std::endl;
	}
	else if (option == 2) {
		for (it1 = client_list.begin(); it1 != client_list.end(); it1++) {
			if ((*it1).getUsername() == username) {
				//print
				find = true;
				std::string msg ="500|" + (*it1).getIp() +"\n";
				boost::asio::async_write(socket_, boost::asio::buffer(msg),
					boost::bind(&Server::handle, this,
						boost::asio::placeholders::error)
				);
				msg = (*it1).getIp() + "|" + "500|" + ip;
				msg_list.push_back(msg);
			}
		}
		if (!find) {
			std::string msg = "404\n";
			boost::asio::async_write(socket_,
				boost::asio::buffer(msg),
				boost::bind(&Server::handle, this,
					boost::asio::placeholders::error));
		}
	}
	else if (option == 3) {
		std::string msg ="";
		for (it1 = client_list.begin(); it1 != client_list.end(); it1++) {
			if (it1 != client_list.begin())
				msg += "|";
			msg += (*it1).getIp() + ":" + (*it1).getUsername();
		}
		msg += "\n";
		boost::asio::async_write(socket_, boost::asio::buffer(msg),
			boost::bind(&Server::handle, this,
				boost::asio::placeholders::error)
		);
	}

	else if (option == 5) {
		boost::algorithm::split(tokens, data, boost::is_any_of("|"));
		for (it2 = msg_list.begin(); it2 != msg_list.end(); it2++) {
			boost::algorithm::split(tokens, (*it2), boost::is_any_of("|"));
			std::string delivery = tokens[1] + "|" + tokens[2] + "\n";
			if (tokens[0] == ip) {
				find = true;
				boost::asio::async_write(socket_,
					boost::asio::buffer(delivery),
					boost::bind(&Server::handle, this,
						boost::asio::placeholders::error));
				it2 = msg_list.erase(it2);
				break;
			}
		}
		if (!find)
		{
			std::string msg = "0\n";
			boost::asio::async_write(socket_, boost::asio::buffer(msg),
				boost::bind(&Server::handle, this,
					boost::asio::placeholders::error)
			);
		}
		//if msg parse ip|msg ip == current ip dire ce qu'il y'a
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
	: Client("", "", false), accept_(io_service, tcp::endpoint(tcp::v4(), port))
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
		new_connection->startServer(_participants, _msg);
		begin_accept();
	}
}