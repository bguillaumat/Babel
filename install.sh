#!/usr/bin/env bash

# necessary for portaudio
sudo apt-get install libjack-dev

# download conan for ubuntu
curl -C - -L -O https://dl.bintray.com/conan/installers/conan-ubuntu-64_1_7_3.deb

# install conan
sudo dpkg -i conan-ubuntu-64_1_7_3.deb

# install all dependencies with conan
conan install . --build portaudio