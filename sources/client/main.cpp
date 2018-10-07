/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <QApplication>
#include "includes/client/Core.hpp"
#include "includes/client/Settings.hpp"

QByteArray readTextFile(const QString &file_path)
{
	QFile      input_file(file_path);
	QByteArray input_data;

	if (input_file.open(QIODevice::Text | QIODevice::Unbuffered |
				    QIODevice::ReadOnly)) {
		input_data = input_file.readAll();
		input_file.close();
		return input_data;
	} else {
		return QByteArray();
	}
}

int main(int ac, char *av[])
{
	Settings settings(av, ac);
	try {
		QApplication _app(ac, av);
		QFontDatabase::addApplicationFont(":/media/Pacifico.ttf");
		QFont   font       = QFont("Pacifico", 10, 2);
		QString styleSheet = readTextFile(QCoreApplication::applicationDirPath() + "/media/stylesheet.qss");
		Core    core(settings);

		_app.setFont(font);
		_app.setStyleSheet(styleSheet);
		_app.exec();
	} catch (const std::invalid_argument &invalidArgument) {
		return settings.getReturnCode();
	} catch (const std::runtime_error &runtimeError) {
		std::cerr << "A runtime error occur:" << std::endl << "\t"
			<< runtimeError.what() << std::endl;
		return 84;
	} catch (const std::exception &exception) {
		std::cerr << "An unexpected error occur:" << std::endl << "\t"
			<< exception.what() << std::endl;
		return 84;
	}
	return 0;
}
