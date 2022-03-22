#!/bin/bash

cd src
g++ -c -I/usr/include/boost main.cpp
g++ main.o -o ../bin/main -pthread
rm main.o 
