#! /bin/bash

mkdir build

gcc -std=gnu99 ./src/*.c -o ./build/inter -lm -pthread -I./include 

gcc -std=gnu99 ./intr-lib/interstellar.c -c -o ./build/interstellar.o -lm -pthread -fPIC
gcc -std=gnu99 ./intr-lib/interstellar/builder.c -c -o ./build/builder.o -lm -pthread -fPIC
gcc -std=gnu99 ./build/interstellar.o ./build/builder.o -shared -o ./build/libinterstellar.so -lm -pthread

if [ "$1" = "install" ];
    then
        echo "Installing.."
        sudo mkdir /usr/local/include/interstellar
        sudo cp ./intr-lib/interstellar/*.h /usr/local/include/interstellar
        sudo cp ./build/libinterstellar.so /usr/local/lib
        sudo cp ./intr-lib/interstellar.h /usr/local/include

        sudo cp ./build/inter /usr/local/bin

        sudo ldconfig
fi