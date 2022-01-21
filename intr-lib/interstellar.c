/**
 * @file main.c
 * @author Sir Obsidian
 * @brief The Interstellar's C interpreter (8cc) will interface with this.
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "interstellar.h"
#include <string.h>

#include "interstellar/builder.h"

void start_interstellar() {
    printf("\e[44m  INTER \e[0m Starting the Interstellar build system.   \n");
}

void build_project(struct project *p) {
    //printf("STARTING INTERSTELLAR.\n");

    printf("\e[44m  INTER \e[0m Compiling project %s.   \n", p->out);

    struct project_jobber pj;        
    pj.p = p;
    pj.jobs = 0;

    create_jobs(p, &pj);

    printf("\e[44m  INTER \e[0m Project %s, has been compiled!  \n", p->out);
}

void inter_log(char *message, enum log_type type) {

    char *s;

    switch (type)
    {
    case INFO:
        strcpy(s, "\e[46m  INFO  ");
        break;
    case WARNING:
        strcpy(s, "\e[41m  ERROR ");
        break;
    case ERROR:
        strcpy(s, "\e[43m  WARN  ");
        break;
    case INTER:
        strcpy(s, "\e[44m  INTER ");
        break;
    case JOBS:
        strcpy(s, "\e[42m  JOBS  ");
        break;
    default:
        break;
    }

    printf("%s\e[0m %s \n", s, message);
};