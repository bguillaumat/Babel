[![Build Status](https://travis-ci.com/bguillaumat/Babel.svg?token=JnqcJzSL9ygjbcHgxfkQ&branch=master)](https://travis-ci.com/bguillaumat/Babel)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/bguillaumat/Babel/master/LICENSE)
# Babel
Babel is a project who consists in a client/server architecture voice over IP application, similar to TeamSpeak
## Features:
* **Contact List**
* Can **call**/**hang-up**
* **Asynchronous Server**
* **Graphical Client**

# Build
The build need the utilisation of [conan](https://conan.io/).

For build use the following command: 
### Linux:
```sh
$ mkdir build && cd build && conan install --build missing .. && cmake .. && cmake –build .
$ export QT_QPA_PLATFORM_PLUGIN_PATH=~/.conan/data/Qt/5.11.2/bincrafters/stable/package/<random_package_id>/plugins
$ export QT_QPA_FONTDIR=~.fonts
```
### Windows:
```sh
$ mkdir build
$ cd build
$ pip install conan
$ conan install --build missing
$ cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release
$ cmake --build . --config Release
```


# Upgrades
* **Implementation of Opus for a sound compression**
* **Find a way to make a call on different network (actually it's work on lan)**
* **Pop-up when someone call**

# Architecture
The project is in **C++** and **Qt** is used for the graphical part in the client.
It's follow a **SIP** architecture: clients communique with the server in **TCP** and in **UDP** between them.  
The audio is transmitted via UDP

# Libraries
* **Qt**
* **Boost**
* **PortAudio**

# Authors
**[Brice Lang-Nguyen](https://github.com/BriceLN)** (brice.lang-nguyen@epitech.eu)  
**[Johanne-Franck Ngbokoli](https://github.com/Franck242)** (franck.ngbokoli@epitech.eu)  
**[Bastien Guillaumat](https://github.com/bguillaumat)** (bastien.guillaumat@epitech.eu)  
