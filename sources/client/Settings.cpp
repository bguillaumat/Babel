/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <regex>
#include "includes/client/Settings.hpp"

Settings::Settings(char *av[], int ac) : _settings(av + 1, av + ac), _continue(
	false), _returnCode(84)
{
	parse();
}

void Settings::parse()
{
	for (auto const &setting : _settings) {
		if (setting == "-h" || setting == "--help") {
			displayHelp();
			_continue = false;
			_returnCode = 0;
			return;
		}
	}
	if (_settings.size() == 2 && isValidIp(_settings.front()) && isOnlyDigit(_settings.back())) {
		_ip = _settings.front();
		_port = _settings.back();
		_continue = true;
	} else if (_settings.size() != 2) {
		std::cerr << "Illegal number of arguments" << std::endl;
		displayHelp();
	}
}

void Settings::displayHelp()
{
	std::cerr << "USAGE" << std::endl << "\t./babel_client ip port"
		<< std::endl << std::endl
		<< "\tip\tThe ip address of skipe server" << std::endl
		<< "\tport\tPort of skipe server" << std::endl;
}

bool Settings::isValidIp(std::string const &ip)
{
	std::regex ip_regex("(\\d{1,3}(\\.\\d{1,3}){3})");

	if (ip == "localhost") {
		return true;
	} else if (regex_match(ip, ip_regex)) {
		return true;
	}
	std::cerr << ip << " isn't an ip" << std::endl;
	return false;
}

bool Settings::isOnlyDigit(std::string const &str)
{
	if (str.find_first_not_of("0123456789") == std::string::npos) {
		return true;
	}
	std::cerr << str << " isn't a valid port" << std::endl;
	return false;
}

bool Settings::isContinue() const
{
	return _continue;
}

int Settings::getReturnCode() const
{
	return _returnCode;
}

const std::string &Settings::getIp() const
{
	return _ip;
}

const std::string &Settings::getPort() const
{
	return _port;
}

