/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include "Server.hpp"


int	main()
{
	try
	{
		boost::asio::io_service io_service;
		Tcp server(io_service, 8080);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
