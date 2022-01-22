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

        //printf("%s %s %s %s -o %s.o\n", p->cc, p->flags, p->source_files[i], p->ld_flags, p->source_files[i]);

        char s[sizeof(p->cc) + sizeof(p->flags) + sizeof(p->source_files[i]) + sizeof(p->ld_flags) + sizeof(p->source_files[i]) + 1] = /*(char *)malloc(sizeof(p->cc) + sizeof(p->flags) + sizeof(p->source_files[i]) + sizeof(p->ld_flags) + sizeof(p->source_files[i]) + 1)*/ "";
        s[sizeof(p->cc) + sizeof(p->flags) + sizeof(p->source_files[i]) + sizeof(p->ld_flags) + sizeof(p->source_files[i]) + 1] = '\0';

        printf("%ld\n", sizeof(s));

        sprintf(s, "%s %s %s %s -o %s.o", p->cc, p->flags, p->source_files[i], p->ld_flags, p->source_files[i]);

        printf("%s\n", s);

        free(s);
    }
};