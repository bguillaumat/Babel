/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** log_funcs.cpp
*/

#include "../../includes/server/Server.hpp"

Client::Client(ip, username) : _ip(_ip), _username(_username)
{
}

Client::~Client()
{
}

void Client::client_connected()
{
	std::cout<<"The user "<<this->_username<<" is connected now"<<std::endl;
}

void Client::client_disconnected()
{
	std::cout<<"The user "<<this->_username<<" is now deconnected"std::endl;
}

const std::string Client::getIp()
{
	return _ip;
}

const std::string Client::getUsername()
{
	return _username
}

void Client::setIp(std::string ipaddress)
{
	_ip = ipaddress;
}

void Client::setUsername(std::string username)
{
	_username = username;
}