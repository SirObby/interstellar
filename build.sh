#! /bin/bash

g++ ./src/*.cpp -o ./build/inter -lm -pthread -I./include -fno-stack-protector