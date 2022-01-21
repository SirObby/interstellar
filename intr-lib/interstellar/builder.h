#ifndef _H_INTERSTELLAR_BUILDER
#define _H_INTERSTELLAR_BUILDER

#include "../interstellar.h"


struct project_jobber
{
    struct project *p;
    
    char **cmds;
    int jobs;
};


void compile_jobs(struct project *p, struct project_jobber *pj);

#endif