#! /bin/bash

gcc ./src/*.c -o ./build/inter -lm -pthread -I./include

gcc ./intr-lib/interstellar.c -c -o ./build/interstellar.o -lm -pthread 
gcc ./intr-lib/interstellar/builder.c -c -o ./build/builder.o -lm -pthread 
gcc ./build/interstellar.o ./build/builder.o -shared -o ./build/libinterstellar.so -lm -pthread 



if [ "$1" = "install" ];
    then
        echo "Installing.."
        sudo mkdir /usr/local/include/interstellar
        sudo cp ./intr-lib/interstellar/*.h /usr/local/include/interstellar
        sudo cp ./build/libinterstellar.so /usr/local/lib
        sudo cp ./intr-lib/interstellar.h /usr/local/include
fi