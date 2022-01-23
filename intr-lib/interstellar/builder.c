#include "builder.h"
#include "../interstellar.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void compile_jobs(struct project *p, struct project_jobber *pj)
{
    inter_log("Starting job daemon.", JOBS);

    // fprintf(File, "Hello world!");

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

        // printf("%s %s %s %s -o %s.o\n", p->cc, p->flags, p->source_files[i], p->ld_flags, p->source_files[i]);

        inter_log("Opening ./README.md", INFO);

        FILE *fp = fopen("/home/sir/documents/coding/cpp/interstellar/README.md", "rw");
        if (fp == NULL)
        {
            printf("Couldn't open %s: %s\n", "./README.md", strerror(errno));
            fprintf(stderr, "Couldn't open %s: %s\n", "./README.md", strerror(errno));
            exit(1);
        }
        fclose(fp);

        inter_log("Closing ./README.md", INFO);

        /*char *s = (char *)malloc(sizeof(p->cc) + sizeof(p->flags) + sizeof(p->source_files[i]) + sizeof(p->ld_flags) + sizeof(p->source_files[i]) + 32 + 1);
        s[sizeof(p->cc) + sizeof(p->flags) + sizeof(p->source_files[i]) + sizeof(p->ld_flags) + sizeof(p->source_files[i]) + 32 + 1] = '\0';

        printf("%ld\n", sizeof(s));

        sprintf(s, "%s %s %s %s -o %s.o", p->cc, p->flags, p->source_files[i], p->ld_flags, p->source_files[i]);

        printf("%s\n", s);

        free(s);*/
    }

    // fclose(File);
};