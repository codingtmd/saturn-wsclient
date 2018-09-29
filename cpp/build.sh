#!/bin/bash

# update the OS
sudo apt-get -y update

sudo apt-get install -y autoconf cmake make automake libtool git g++ libcpprest-dev

cmake .

make
