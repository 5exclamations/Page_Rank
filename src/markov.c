#include <stdio.h>
#include <stdlib.h>
#include "getopt.h"
#include "utils.h"
#include "opt.h"
#include "parse_graph.h"
#include "main.h"
#include "markov.h"
#include <string.h>


int calc_times_inside(struct graph newGraph, int i, int val){
    int return_value = 0;
    for(int j = 0; j < newGraph.number_of_destinations[i]; j++){
        if(newGraph.destination[i][j] == val){
            return_value++;
        }
    }
    return return_value;
}

void markov(char file_adr[512]){
    if(parameter < 0 || parameter > 100) exit(1);
    N += 1;
    while (N > 150000){
        N /= 10;
    }
    struct graph newGraph = parse_graph(file_adr);
    int n = newGraph.number_of_vertices;
    double vector[N][n];
    double matrix[n][n];
    double prob_param = parameter / 100.0;
    for(int i = 0; i < N; i++){
        memset(vector[i], 0, n * sizeof(vector[i][i]));
    }
    

    for(int i = 0; i < newGraph.number_of_vertices; i++){
        vector[0][i] = 1. / newGraph.number_of_vertices;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(newGraph.number_of_destinations[i] == 0){
                matrix[i][j] = (1. / n);
            }
            else{
                matrix[i][j] = prob_param / n + (1.0 - prob_param) * calc_times_inside(newGraph, i, j) / newGraph.number_of_destinations[i];
            }
        }
    }
    for(int k = 1; k < N; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vector[k][i] += vector[k - 1][j] * matrix[j][i];
            }
        }
    }
    for(int i = 0; i < newGraph.number_of_vertices; i++){
        printf("%s   %.10f \n", newGraph.vertices[i], vector[N - 1][i]);
    }
    free_memory(newGraph);
    return;
}

