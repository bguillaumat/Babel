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
			explicit Home(QStackedWidget *stack);
			const std::string &getIp() const;
			const std::string &getName() const;
			void setUsername(QString &username);

		private slots:
			void makeCall();
			void makeTestCall();
			void changeButtonName(QString const &currentText);
			void itemDoubleClicked(QListWidgetItem *);

		private:
			size_t         _width;
			size_t         _height;
			QFont          _font;
			QLabel         *_username;
			QListWidget    *_listWidget;
			QPushButton    *_call;
			QPushButton    *_test;
			QHBoxLayout    *_buttonLayout;
			QVBoxLayout    *_layout;
			QStackedWidget *_stack;
			QIcon          _icon;
			std::string    _ip;
			std::string    _name;
		};
	}
}
#endif //CPP_BABEL_2018_HOME_HPP
