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
mkdir build && cd build && conan install --build missing .. && cmake .. -G “Unix
Makefiles” && cmake –build .
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

# Authors
**Brice Lang-Nguyen** brice.lang-nguyen@epitech.eu  
**Johanne-Franck Ngbokoli** franck.ngbokoli@epitech.eu  
**Bastien Guillaumat** bastien.guillaumat@epitech.eu  
