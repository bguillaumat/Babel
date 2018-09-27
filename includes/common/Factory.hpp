/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Factory
*/

#ifndef CPP_BABEL_2018_FACTORY_HPP
#define CPP_BABEL_2018_FACTORY_HPP

#include <string>
#include <map>

template <class Object, class Key = std::string>
class Factory {
public:
	Factory() = default;
	void	Register(Key key,Object* obj);
	Object	*Make(const Key& key);

private:
	std::map<Key, Object *>	_map;
};
#endif //CPP_BABEL_2018_FACTORY_HPP
