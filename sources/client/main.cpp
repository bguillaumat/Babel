/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifdef  __unix__
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
#elif _WIN32
	#include <winsock2.h>
#endif

#include <portaudio.h>
#include <iostream>
#include <memory>
#include <QApplication>
#include <QPushButton>
#include <ICompressor.hpp>
#include <Opus.hpp>
#include <PaOutput.hpp>
#include <PaInput.hpp>


typedef int SOCKET;

void	socket_udp()
{
	SOCKET myFirstUdpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (myFirstUdpSocket < 0)
	{
		std::cout << "Erreur création socket : ";
	}

	unsigned short port;
	std::cout << "Port local ? ";
	std::cin >> port;

	sockaddr_in addr;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	if (bind(myFirstUdpSocket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
	{
		std::cout << "Erreur bind socket : " << std::endl;
	}

	unsigned short portDst;
	std::cout << "Port du destinataire ? ";
	std::cin >> portDst;
	sockaddr_in	to;
	inet_pton(AF_INET, "127.0.0.1", &to.sin_addr.s_addr);
	to.sin_family = AF_INET;
	to.sin_port = htons(portDst);

	std::cout << "Entrez le texte à envoyer (vide pour quitter)> ";
	while (true)
	{
		std::string data;
		std::getline(std::cin, data);
		if (data.empty())
			continue;
		ssize_t ret = sendto(myFirstUdpSocket, data.data(), static_cast<int>(data.length()), 0, reinterpret_cast<const sockaddr*>(&to), sizeof(to));
		if (ret <= 0)
		{
			std::cout << "Erreur envoi de données : . Fermeture du programme.";
			break;
		}
		char buff[1500] = { 0 };
		sockaddr_in from;
		socklen_t fromlen = sizeof(from);
		ret = recvfrom(myFirstUdpSocket, buff, 1499, 0, reinterpret_cast<sockaddr*>(&from), &fromlen);
		if (ret <= 0)
		{
			std::cout << "Erreur réception de données : . Fermeture du programme.";
			break;
		}
		std::cout << "Recu : " << buff << " de " << std::endl;
	}
}

int	main(int ac, char *av[])
{
	QApplication	app(ac, av);
	QPushButton		button("Salut les Zéros, la forme ?");
	Babel::ICompressor	*compressor = new Babel::Opus();
	Babel::IAudio		*audio1 = new Babel::PaOutput();
	Babel::IAudio		*audio = new Babel::PaInput();

//	socket_udp();
	audio->start();
	audio1->start();
	button.show();
	app.exec();
	audio->stop();
	audio1->stop();
	return 0;
}
