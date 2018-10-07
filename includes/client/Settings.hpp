/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#ifndef CPP_BABEL_2018_SETTINGS_HPP
#define CPP_BABEL_2018_SETTINGS_HPP

#include <vector>
#include <string>

class Settings {
public:
	Settings(char *av[], int ac);
	bool isContinue() const;
	int getReturnCode() const;
	const std::string &getIp() const;
	const std::string &getPort() const;

private:
	void parse();
	void displayHelp();
	bool isValidIp(std::string const &ip);
	bool isOnlyDigit(std::string const &str);

private:
	std::vector<std::string> _settings;
	std::string              _ip;
	std::string              _port;
	bool                     _continue;
	int                      _returnCode;
};

#endif //CPP_BABEL_2018_SETTINGS_HPP
