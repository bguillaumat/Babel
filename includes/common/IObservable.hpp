/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_IOBSERVABLE_HPP
#define CPP_BABEL_2018_IOBSERVABLE_HPP

#include <list>
#include "IObservateur.hpp"

class IObservable {
public:
	void	notify() const;
	void	addListener(IObservateur *observateur);
	void	supprimerObservateur(IObservateur *observateur);
private:
	std::list<IObservateur *>	_observateurs;
};

#endif //CPP_BABEL_2018_IOBSERVABLE_HPP
