#! /bin/bash

gcc ./src/*.c -o ./build/inter -lm -pthread -I./include

gcc ./intr-lib/interstellar.c -c -o ./build/interstellar.o -lm -pthread 
gcc ./build/interstellar.o -shared -o ./build/libinterstellar.so -lm -pthread 

sudo cp ./build/libinterstellar.so /usr/local/lib
sudo cp ./intr-lib/interstellar.h /usr/local/include