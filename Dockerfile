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

RUN apt-get -y install python3-pip python3-dev && pip3 install --updrade pip

RUN pip3 install pyopenssl ndg-httpsclient pyasn1
RUN pip3 install urllib3[secure] --upgrade

CMD /bin/bash

# Install latest CMake
RUN wget -q -O /tmp/cmake.tar.gz --no-check-certificate \
  https://cmake.org/files/v3.12/cmake-3.12.3-Linux-x86_64.tar.gz && \
  tar -xaf /tmp/cmake.tar.gz --strip-components=1 -C /usr/local && \
  rm /tmp/cmake.tar.gz

# Install conan
RUN pip3 install conan && conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan"



WORKDIR /build

COPY . /build
