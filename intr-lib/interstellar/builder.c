#include "builder.h"
#include "../interstellar.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void compile_jobs(struct project *p, struct project_jobber *pj)
{
    inter_log("Starting job daemon.", JOBS);

    /*char inc[5000];

    for (size_t i = 0; i < p->include_count; i++)
    {
        char *e[5000];

        snprintf(e, "-I%s ", 5000, p->include[i]);

        strncat(inc, 5000, e);
    }

    printf("%s\n", inc);*/

    for (size_t i = 0; i < p->source_count; i++)
    {
        inter_log(p->source_files[i], JOBS);

        char *s = malloc(4096);
        char *o = malloc(4096);
        snprintf(o, 4096, "%s.o", p->source_files[i]);

        snprintf(s, 4096, "%s %s %s -o %s", p->cc, p->flags, p->source_files[i], p->ld_flags, o);

        printf("%s\n", s);
    }
};