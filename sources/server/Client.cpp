/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** log_funcs.cpp
*/

#include "../../includes/server/Client.hpp"

Client::Client(std::string ip, std::string username, bool state)
	: _ip(ip), _username(username), _state(state)
{
	_state = false;
}

Client::~Client()
{
}

const std::string Client::getIp()
{
	return _ip;
}

const std::string Client::getUsername()
{
	return _username;
}

void Client::setIp(std::string ipaddress)
{
	this->_ip = ipaddress;
}

void Client::setUsername(std::string username)
{
	this->_username = username;
}