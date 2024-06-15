#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "utils.h"
#include "parse_graph.h"
#include "main.h"
#include <string.h>
#include "opt.h"


void print_result(double* probabilities, struct graph newGraph){
    for(int j = 0; j < newGraph.number_of_vertices; j++){
        if(N > 0)
        probabilities[j] = probabilities[j] / N;
        printf("%s      %.10f \n", newGraph.vertices[j], probabilities[j]);
    }
    return;
}

void rand_surf(struct graph newGraph){
    
    if(N == 0){
        for (int j = 0; j < newGraph.number_of_vertices; j++)
        printf("%s        %.10f\n", newGraph.vertices[j], 0.);
        free_memory(newGraph);
        return;
    }
    while(N > 150000 ){
        N /= 2;
    }

    int rand_num;
    int generated_graphs[N + 1];
    double probabilities[newGraph.number_of_vertices];
    memset(probabilities, 0., sizeof(probabilities));
    if (N < 0) exit(1);
    if (parameter > 100 || parameter < 0) exit(1);
    if (newGraph.number_of_vertices > 0)
    generated_graphs[0] = randu(newGraph.number_of_vertices);


    for(int j = 1; j <= N; j++){
        rand_num = randu(100);
        if (rand_num < parameter && newGraph.number_of_vertices > 0){
            generated_graphs[j] = randu(newGraph.number_of_vertices);
        }  else if (newGraph.number_of_vertices > 0){
            if(newGraph.number_of_destinations[generated_graphs[j - 1]] != 0)
            generated_graphs[j] = newGraph.destination[generated_graphs[j - 1]][randu(newGraph.number_of_destinations[generated_graphs[j - 1]])];
            else generated_graphs[j] = randu(newGraph.number_of_vertices);
        } 
    }
    for(int j = 0; j < N; j++){
        for(int k = 0; k < newGraph.number_of_vertices; k++){
            if(generated_graphs[j + 1] == k) {
                probabilities[k] += 1;
            }
        }
    }

    print_result(probabilities, newGraph);
    return;
}