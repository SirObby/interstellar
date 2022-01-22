#include <interstellar.h>
#include <string.h>

struct project mainp;
struct project intrlib;

void main() {

    start_interstellar();

    mainp.cc = "/usr/bin/gcc";
    mainp.flags = "-Wall";
    mainp.ld_flags = "-lm -pthread";
    
    strcpy(mainp.source_files[0], "./src/main.c");
    strcpy(mainp.source_files[1], "./src/comp.c");
    strcpy(mainp.include[0], "./include");
    intrlib.source_count = 1;
    intrlib.include_count = 0;

    mainp.out = "./build/inter";
    mainp.type = EXECUTABLE;

    intrlib.cc = "/usr/bin/gcc";

    intrlib.flags = "-Wall";
    intrlib.ld_flags = "-lm -pthread";
    
    strcpy(intrlib.source_files[0], "./intr-lib/main.c");
    strcpy(intrlib.source_files[1], "./intr-lib/interstellar/builder.c");
    strcpy(intrlib.include[0], "./intr-lib/");
    intrlib.source_count = 1;
    intrlib.include_count = 0;

    intrlib.out = "./build/libinterstellar.so";
    intrlib.type = SHARED_LIBRARY;

    build_project(&mainp);
    build_project(&intrlib);
}