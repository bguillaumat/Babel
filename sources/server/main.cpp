/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include "Server.hpp"


int	main(int ac, char **argv)
{
	int	port;

	if (ac != 2) {
		std::cerr << "Usage: ./babel_server port" << std::endl;
		std::cerr << "Port must me a number" << std::endl;
		return (84);
	}
	port = atoi(argv[1]);
	if (port <= 0) {
		std::cerr << "Bad port value" << std::endl;
		return (84);
	}
	try
	{
		boost::asio::io_service io_service;
		Tcp server(io_service, port);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
