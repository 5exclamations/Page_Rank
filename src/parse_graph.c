#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "utils.h"
#include "main.h"
#include "opt.h"
#include "parse_graph.h"

int size_of = 0;



struct graph parse_graph(char* file_adr){
    FILE* file;
    
    file = fopen(file_adr, "r");
    if (!file) exit(1);
    char text[512];
    int i = 0;    
    int end = 0;
    int temp;
    int check = 1;
    struct graph newGraph;


    while (fscanf(file, "%s", text) == 1){
        i++;
    }
    size_of = i;
    fclose(file);
    file = fopen(file_adr, "r");
    memset(&newGraph, 0, sizeof(newGraph));
    newGraph.number_of_destinations = (int*)malloc(size_of * sizeof(int));
    newGraph.in = (char**) malloc(size_of * sizeof(char*));

    for(int j = 0; j < i; j++)
    newGraph.in[j] = (char*) malloc(512 * sizeof(char));

    newGraph.out = (char**) malloc(size_of * sizeof(char*));

    for(int j = 0; j < i; j++)
    newGraph.out[j] = (char*) malloc(512 * sizeof(char));

    newGraph.vertices = (char**) malloc(size_of * sizeof(char*));

    for(int j = 0; j < i; j++)
    newGraph.vertices[j] = (char*) malloc(512 * sizeof(char));

    newGraph.destination = (int**) malloc(size_of * sizeof(int*));

    for(int j = 0; j < i; j++)
    newGraph.destination[j] = (int*) malloc(size_of * sizeof(int));

    newGraph.number_of_in = 0;
    newGraph.number_of_out = 0;
    memset(newGraph.number_of_destinations, 0, i);


    fscanf(file, "%s", text);
    if (strcmp(text, "digraph") != 0) exit (1);
    fscanf(file, "%s", newGraph.identificator);
    fscanf(file, "%s", text);
    if (strcmp(text, "{") != 0) exit (1);


    while(fscanf(file, "%s", text) == 1){
        if (strcmp(text, "->") == 0) {
            newGraph.number_of_edges++;
            fscanf(file, "%s", newGraph.in[newGraph.number_of_in]);
            for (i = 0; i < 256; i++){
                if (newGraph.in[newGraph.number_of_in][i] == '\0'){
                    end = i;
                }
            }
            if(newGraph.in[newGraph.number_of_in][end - 1] != ';') exit(1);
            newGraph.in[newGraph.number_of_in][end - 1] = '\0';
            newGraph.number_of_in++;
        }
        else if (strcmp(text, "}") == 0) break;
        else if (*text != EOF){
            strcpy(newGraph.out[newGraph.number_of_out], text);   
            newGraph.number_of_out++;         
        }
        else exit(1);
    }

    for(i = 0; i < newGraph.number_of_edges; i++ ){
        for(int j = 0; j < newGraph.number_of_vertices; j++){
            if (strcmp(newGraph.vertices[j], newGraph.out[i]) == 0) {
                check = 0;
            }
        }
        if (check == 1) {
            strcpy(newGraph.vertices[newGraph.number_of_vertices], newGraph.out[i]);
            newGraph.number_of_vertices++;
        }
        check = 1;
        temp = 0;
    }
    for(i = 0; i < newGraph.number_of_edges; i++){
        for(int j = 0; j <= newGraph.number_of_vertices; j++){
                if (strcmp(newGraph.vertices[j], newGraph.in[i]) == 0) {
                    check = 0;
                    temp++;
                    if (temp > newGraph.in_degree_max) {
                        newGraph.in_degree_max = temp;
                    }
                }
            }
            if (check == 1) {
                strcpy(newGraph.vertices[newGraph.number_of_vertices], newGraph.in[i]);
                newGraph.number_of_vertices++;
            }
            check = 1;
            temp = 0;
    }
    for (i = 0; i < newGraph.number_of_vertices; i++){
        for (int j = 0; j < newGraph.number_of_out; j++){
            if(strcmp(newGraph.vertices[i], newGraph.out[j]) == 0){
                temp++;
                if (temp > newGraph.out_degree_max) {
                    newGraph.out_degree_max = temp;
                }  
            }
        }
        temp = 0;
        for (int j = 0; j < newGraph.number_of_in; j++){
            if(strcmp(newGraph.vertices[i], newGraph.in[j]) == 0){
                temp++;
                if (temp > newGraph.in_degree_max) {
                    newGraph.in_degree_max = temp;
                }  
            }
        }
        temp = 0;
    }
    newGraph.in_degree_min = newGraph.in_degree_max;
    newGraph.out_degree_min = newGraph.out_degree_max;
    for (i = 0; i < newGraph.number_of_vertices; i++){
        for (int j = 0; j < newGraph.number_of_out; j++){
            if(strcmp(newGraph.vertices[i], newGraph.out[j]) == 0){
                temp++;
            }
        }
        if (temp < newGraph.out_degree_min) {
            newGraph.out_degree_min = temp;
        }  
        temp = 0;
        for (int j = 0; j < newGraph.number_of_in; j++){
            if(strcmp(newGraph.vertices[i], newGraph.in[j]) == 0){
                temp++;
            }
        }
        if (temp < newGraph.in_degree_min) {
            newGraph.in_degree_min = temp;
        }  
        temp = 0;
    }
    for(i = 0; i < newGraph.number_of_vertices; i++){
        for(int j = 0; j < newGraph.number_of_out; j++){
            if (strcmp(newGraph.out[j], newGraph.vertices[i]) == 0){
                for(int k = 0; k < newGraph.number_of_vertices; k++){
                    if((strcmp(newGraph.vertices[k], newGraph.in[j])) == 0) {
                    newGraph.destination[i][newGraph.number_of_destinations[i]] = k;
                    }
                }
                newGraph.number_of_destinations[i]++;
            }
        }
    }


    fclose(file);
    return newGraph;
}



void free_memory(struct graph newGraph){
    for(int j = 0; j < size_of; j++){
    free(newGraph.vertices[j]);
    }
    for(int j = 0; j < size_of; j++){
    free(newGraph.in[j]);
    }
    for(int j = 0; j < size_of; j++){
    free(newGraph.out[j]);
    }
    for(int j = 0; j < size_of; j++){
    free(newGraph.destination[j]);
    }
    free(newGraph.destination);
    free(newGraph.in);
    free(newGraph.out);
    free(newGraph.vertices);
    free(newGraph.number_of_destinations);
}