/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/
#ifndef CPP_BABEL_2018_HOME_HPP
#define CPP_BABEL_2018_HOME_HPP

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include "includes/client/Core.hpp"

namespace Babel {

	namespace UI {

		class Home : public QWidget {
		Q_OBJECT
		public:
			Home(QStackedWidget *stack);

		private slots:
			void makeCall();
		private:
			size_t         _width;
			size_t         _height;
			QPushButton    *_signin;
			QHBoxLayout    *_buttonLayout;
			QVBoxLayout    *_layout;
			QStackedWidget *_stack;
		};
	}
}
#endif //CPP_BABEL_2018_HOME_HPP
