/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.hpp
*/

#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#ifdef	__unix__
#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
#elif	_WIN32
	#include <winsock2.h>
#endif

#include <set>
#include <string>
#include <boost/asio.hpp>

class Client {
private:
	const std::string	_ip;
	const std::string	_username;
	bool			_state;

public:
	~Client();
	Client(std::string, std::string);
	const std::string	getIp();
	const std::string	getUsername();
	void	setIp(std::string);
	void	setUsername(std::string);
	void	client_connected();
	void	client_disconnected();
};

class Clients {
private:
	std::set<Client>	_participants;

public:

};

#endif //CPP_BABEL_2018_SERVER_HPP
