/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <QtCore/QCoreApplication>
#include <includes/client/UI/Home.hpp>

#include "includes/client/UI/Home.hpp"

Babel::UI::Home::Home(QStackedWidget *stack)
	: QWidget(), _width(300), _height(300), _font("Pacifico", 20, 2),
	_stack(stack)
{
	QIcon tmp(QCoreApplication::applicationDirPath() + "/media/call.png");
	QIcon mic(QCoreApplication::applicationDirPath() + "/media/mic.png");
	_icon         = tmp;
	_username     = new QLabel("Username");
	_listWidget   = new QListWidget;
	_call         = new QPushButton("Call");
	_test         = new QPushButton("Test Micro");
	_buttonLayout = new QHBoxLayout;
	_layout       = new QVBoxLayout;
	_call->setIcon(_icon);
	_call->setIconSize(QSize(30, 30));
	_test->setIcon(mic);
	_test->setIconSize(QSize(30, 30));
	_username->setAlignment(Qt::AlignCenter);
	_username->setFont(_font);
	_buttonLayout->addWidget(_test);
	_buttonLayout->addWidget(_call);
	_layout->addWidget(_username);
	_layout->addWidget(_listWidget);
	_layout->addLayout(_buttonLayout);
	setLayout(_layout);
	connect(_call, SIGNAL(clicked()), this, SLOT(makeCall()));
	connect(_listWidget, SIGNAL(currentTextChanged(
					    const QString & )), this,
		SLOT(changeButtonName(
			     const QString & )));
	connect(_test, SIGNAL(clicked()), this, SLOT(makeTestCall()));
	connect(_listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(itemDoubleClicked(QListWidgetItem *)));

	QStringList contact = {"Freddy Armstrong", "Lacie-Mae Davies",
		"Essa Dunne", "Aden Grimes", "Ansh Dillon", "Kingston Donnelly",
		"Helen Gregory", "Jude Pugh", "Iram Park", "Gregg Naylor",
		"Kaylem Callaghan", "Cormac Mckay", "Jordan-Lee Mcgee",
		"Leo Andersen", "Jordon Horn", "Nazifa Horne", "Fredrick Ward",
		"Leia Sweet", "Carrie Stephens", "Nafeesa Plummer",
		"Liya Russell", "Vivek Clark", "Traci Halliday", "Myla Phan",
		"Terrell Bone", "Reece Valenzuela", "Luciano Hilton",
		"Ralph Everett", "Cem Doherty", "Alessandra Abbott",
		"Lola-Rose Kerr", "Zi Hendrix", "Lillie Fuentes",
		"Theon Ratcliffe", "Astrid Jeffery", "Addie Kaye",
		"Emma-Louise William", "Alisha Parsons", "Luqman Hays",
		"Jamelia Schwartz", "Louis Bloggs", "Jakub Enriquez",
		"Nate Acosta", "Pauline Parkes", "Zuzanna Heath", "Zoey Ryan",
		"Nicole Bevan", "Ivo Orozco", "Asiya King", "Kornelia Carson"};
	_listWidget->addItems(contact);
	_font.setPointSize(15);
	_listWidget->setFont(_font);
}

void Babel::UI::Home::makeCall()
{
	_ip   = "127.0.0.1";// take ip from
	_name = _listWidget->currentItem()->text().toStdString();
	_stack->setCurrentIndex(2);
}

void Babel::UI::Home::changeButtonName(QString const &currentText)
{
	_call->setText("Call (" + currentText + ").");
}

const std::string &Babel::UI::Home::getIp() const
{
	return _ip;
}

const std::string &Babel::UI::Home::getName() const
{
	return _name;
}

void Babel::UI::Home::makeTestCall()
{
	_ip   = "127.0.0.1";
	_name = _username->text().toStdString();
	_stack->setCurrentIndex(2);
}

void Babel::UI::Home::setUsername(QString &username)
{
	_username->setText(username);
}

void Babel::UI::Home::itemDoubleClicked(QListWidgetItem *listWidgetItem)
{
	(void)listWidgetItem;
	makeCall();
}
