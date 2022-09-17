CFLAGS=-Wall

all:
	# Compile files individually 
	g++ src/main.cpp ${CFLAGS} -c -o main.o
	# Link them all
	g++ main.o -o inter ${CFLAGS}
