/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#include <IObservable.hpp>

#include "IObservable.hpp"

void IObservable::notify() const
{
	for (auto const &listener : _observateurs) {
		listener->notifier();
	}
}

void IObservable::addListener(IObservateur *observateur)
{
	_observateurs.push_front(observateur);
}

void IObservable::supprimerObservateur(IObservateur *observateur)
{
	_observateurs.remove(observateur);
}
