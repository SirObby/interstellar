#include <stdlib.h>
#include <argp.h>

#include "comp.h"

const char *argp_program_version =
    "argp-ex3 1.0";
const char *argp_program_bug_address =
    "<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] =
    "Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "Function";

/* The options we understand. */
static struct argp_option options[] = {
    {"verbose", 'v', 0, 0, "Produce verbose output"},
    {"quiet", 'q', 0, 0, "Don't produce any output"},
    {"silent", 's', 0, OPTION_ALIAS},
    //{"output", 'o', "FILE", 0,
    // "Output to FILE instead of standard output"},
    {"jobs", 'j', "JOBCOUNT", 0,
     "Amount of jobs to run simoultaneously."},
    {"compiler", 'c', "FILE", 0,
     "The C Compiler to use for the Interstellar cbuilds."},
    {0}};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *args[99]; /* arg1 & arg2 */
    int silent, verbose, jobs;
    //char *output_file;
    char *compiler;
};

/* Parse a single option. */
static error_t
parse_opt(int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'q':
    case 's':
        arguments->silent = 1;
        break;
    case 'v':
        arguments->verbose = 1;
        break;
    //case 'o':
    //    arguments->output_file = arg;
    //    break;
    case 'c':
        arguments->compiler = arg;
        break;
    case 'j':
        arguments->jobs = atoi(arg);
        break;
    case ARGP_KEY_ARG:
        //if (state->arg_num >= 2)
            /* Too many arguments. */
        //    argp_usage(state);

        arguments->args[state->arg_num] = arg;

        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1)
            /* Not enough arguments. */
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv)
{
    struct arguments arguments;

    /* Default values. */
    arguments.silent = 0;
    arguments.verbose = 0;
    arguments.jobs = 0;
    //arguments.output_file = "-";
    arguments.compiler = "/usr/bin/gcc";

    /* Parse our arguments; every option seen by parse_opt will
       be reflected in arguments. */
    argp_parse(&argp, argc, argv,
               0,
               0, &arguments);

    start_comp(arguments.silent, arguments.verbose, arguments.jobs, arguments.compiler, arguments.args[0]);

    exit(0);
}