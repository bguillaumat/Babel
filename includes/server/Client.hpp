/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.hpp
*/

#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#include <iostream>
#include <set>
#include <string>

class Client {
private:
	std::string	_ip;
	std::string	_username;
	bool		_state;

public:
	~Client();
	Client(std::string, std::string, bool);
	const std::string	getIp();
	const std::string	getUsername();
	void			setIp(std::string);
	void			setUsername(std::string);
	void			client_connected();
	void			client_disconnected();
};

class Clients {
private:
	std::set<Client>	_participants;

public:
	virtual ~Clients();

};

#endif //CPP_BABEL_2018_SERVER_HPP
