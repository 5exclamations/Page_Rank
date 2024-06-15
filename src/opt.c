#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "markov.h"
#include "opt.h"
#include "parse_graph.h"
#include "rand_surf.h"
#include "statistics.h"
#include "utils.h"
#include "main.h"

long int M;
int N;

int is_dot_file(const char *path) {
    const char *dot = strrchr(path, '.');
    if(!dot || dot == path) return 0;
    return strcmp(dot, ".dot") == 0;
}

void opt(int const argc, char *const *argv){
    int opt;
    char adress[512];
    struct graph newStruct;
    while ((opt = getopt(argc, argv, "hr:m:s:p:")) != -1) {
        switch (opt) {
            case 'h':
                printf("Usage : ./ pagerank [ OPTIONS ] ... [ FILENAME] \n");
                printf("Perform pagerank computations for a given file in the DOT format\n \n");
                printf("    -h Print a brief overview of the available command line parameters\n");
                printf("    -r N Simulate N steps of the random surfer and output the result\n");
                printf("    -m N Simulate N steps of the Markov chain and output the result\n");
                printf("    -s Compute and print the statistics of the graph as defined\n");
                printf("    -p P Set the parameter p to P%%. ( Default : P = 10)\n");
                break;
            case 'r': 
                
                N = atoi(optarg);
                optind--;
                if (N < 0) exit(1);
                optind++;
                strcpy(adress, argv[optind]);
                if (!is_dot_file(adress)) {
                    exit(1);
                }
                struct graph newGraph = parse_graph(adress);
                rand_surf(newGraph);
                free_memory(newGraph);
                break;
            case 'm':
                optind--;
                N = atoll(optarg);
                if (N < 0) exit(1);
                optind++;
                strcpy(adress, argv[optind]);
                markov(adress);
                break;
            case 's':
                newStruct = parse_graph(optarg);
                statistics(newStruct);
                free_memory(newStruct);
                break;
            case 'p':
                if (*optarg < 0 || *optarg > 100) exit (1);
                parameter = atoi(optarg);
                break;
            default:
            break;
        }
    }
}