/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** server.hpp
*/
#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#ifdef  __unix__
#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
#elif _WIN32
	#include <winsock2.h>
#endif


#endif //CPP_BABEL_2018_SERVER_HPP
