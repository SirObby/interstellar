#include "builder.h"
#include "../interstellar.h"
#include <string.h>
#include <stdio.h>

void create_jobs(struct project *p, struct project_jobber *pj) {
    inter_log("Creating jobs.", JOBS);
    for (size_t i = 0; i < p->source_count; i++)
    {
        pj->jobs++;

        struct job j;
        j.f = p->source_files[i];
        j.flags = p->flags;
        j.ldflags = p->ld_flags;
        j.index = pj->jobs;

        pj->j[pj->jobs] = j;

        char o[FILENAME_MAX];
        
        //printf("%s\n", p->source_files[i]);

        //snprintf(o, FILENAME_MAX, "Created Job: %s\n", p->source_files[i]);
        //printf("%s", o);
        //strcat(o, p->source_files[i]);
        //strcat(o, "\n");
        //printf("JOB Created: %s\n", j.f);
        //sprintf(o, "Created: %s\n", (char *)j.f);

        //sprintf(o, "Created job: %s\n", j.f);
        //printf("%s\n", o);

        //printf("> %d\n", j.index);
        //inter_log(o, JOBS);
        //printf("%s\n" ,o);
    }

    //printf("%d\n", pj->jobs);
};