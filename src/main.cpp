#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>

#include "build.h"

int jobs = 1;

int main(int argc, char *args[]) {

    char d[] = ".";

    for (size_t i = 0; i < argc; i++)
    {
        if(args[i][0] == '-') if(args[i][1] == 'j') jobs = std::stoi(args[i + 1]);
    };

    build(d, jobs);

    return 0;
}