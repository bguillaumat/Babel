/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by j-f,
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

#include <iostream>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>

using boost::asio::ip::tcp;
using namespace boost::chrono;

#endif //CPP_BABEL_2018_SERVER_HPP
