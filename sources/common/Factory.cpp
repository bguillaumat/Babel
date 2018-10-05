/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Factory
*/

#include <iostream>
#include "includes/common/Factory.hpp"

template <class Object,class Key>
void	Factory<Object,Key>::Register(Key key, Object* obj)
{
	if(_map.find(key) == _map.end()) {
		_map[key]=obj;
	} else {
		throw std::runtime_error("already exist !");
	}
}

template <class Object, class Key>
Object	*Factory<Object, Key>::Make(const Key &key)
{
	Object	*tmp = nullptr;
	auto	it = _map.find(key);

	if(it != _map.end()) {
		tmp = ((*it).second)->clone();
	}
	return tmp;
}
