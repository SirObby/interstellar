#ifndef _H_INTERSTELLAR_BUILDER
#define _H_INTERSTELLAR_BUILDER

#include "../interstellar.h"

struct job
{
    int index;

    char *f;

    char *flags;
    char *ldflags;
};


struct project_jobber
{
    struct project *p;
    int jobs;

    struct job j[];
};


void create_jobs(struct project *p, struct project_jobber *pj);

#endif