/**
 * @file interstellar.hbuild
 * @author Sir Obsidian
 * @brief 
 * @version 0.1
 * @date 2022-01-17
 * 
 * 
 */

#include <stdio.h>

#ifndef _h_interstellar
#define _h_interstellar

enum project_type {
    EXECUTABLE,
    SHARED_LIBRARY,
    DYNAMIC_LIBRARY
};

enum log_type {
    INFO,
    WARNING,
    ERROR,
    
    INTER,
    JOBS
};

typedef struct project
{
    char* cc;

    char* flags;
    char* ld_flags;

    char source_files[FILENAME_MAX][1024];
    char* out;

    char include[FILENAME_MAX][1024];

    enum project_type type;

    int source_count;
    int include_count;
} project;

void start_interstellar();
void build_project(struct project *p);
void inter_log(char *message, enum log_type type);

#endif