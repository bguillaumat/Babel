FROM         ubuntu:latest
MAINTAINER   Brice Lang-Nguyen <brice.lang-nguyen@epitech.eu>

# Required system packages
RUN apt-get update && apt-get -y install \
  apt-utils \
  build-essential \
  curl \
  doxygen \
  git \
  tar \
  wget \
  zsh \
  xz-utils \
  libjack-dev \
  libxcb1-dev \
  libx11-dev \
  libc6-dev \
  libgl1-mesa-dev \
  libx11-6 \
  libasound2-dev

CMD /bin/bash

# Install latest CMake
RUN wget -q -O /tmp/cmake.tar.gz --no-check-certificate \
  https://cmake.org/files/v3.12/cmake-3.12.3-Linux-x86_64.tar.gz && \
  tar -xaf /tmp/cmake.tar.gz --strip-components=1 -C /usr/local && \
  rm /tmp/cmake.tar.gz

# Install conan
RUN curl -C - -L -O https://dl.bintray.com/conan/installers/conan-ubuntu-64_1_7_3.deb && dpkg -i conan-ubuntu-64_1_7_3.deb && conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan" && rm conan-ubuntu-64_1_7_3.deb



WORKDIR /build

COPY . /build