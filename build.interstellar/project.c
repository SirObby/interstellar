#include <interstellar.h>
#include <string.h>

struct project mainp;
struct project intrlib;

void main() {

    mainp.cc = "/usr/bin/gcc";
    mainp.flags = "-Wall";
    mainp.ld_flags = "-lm -pthread";
    
    strcpy(mainp.source_files[0], "./src/main.c");
    strcpy(mainp.include[0], "./include");

    mainp.out = "./build/inter";
    mainp.type = EXECUTABLE;

    intrlib.cc = "/usr/bin/gcc";

    intrlib.flags = "-Wall";
    intrlib.ld_flags = "-lm -pthread";
    
    strcpy(intrlib.source_files[0], "./intr-lib/main.c");
    strcpy(intrlib.include[0], "./intr-lib/");

    intrlib.out = "./build/libinterstellar.so";
    intrlib.type = SHARED_LIBRARY;

    build_project(&mainp);
    build_project(&intrlib);
}