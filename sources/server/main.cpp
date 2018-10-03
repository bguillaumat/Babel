/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include "Server.hpp"

int	main(int ac, char *av[])
{
	std::cout << system_clock::now() << std::endl;
	#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
	std::cout << steady_clock::now() << std::endl;
	#endif
	std::cout << high_resolution_clock::now() << std::endl;

	#ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
	std::cout << process_real_cpu_clock::now() << std::endl;
	std::cout << process_user_cpu_clock::now() << std::endl;
	std::cout << process_system_cpu_clock::now() << std::endl;
	std::cout << process_cpu_clock::now() << std::endl;
	#endif

	#ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
	std::cout << thread_clock::now() << std::endl;
	#endif

	return 0;
}
