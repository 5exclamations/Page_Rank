#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "utils.h"
#include "parse_graph.h"


int statistics(struct graph newGraph){
    printf("%s:\n", newGraph.identificator);
    printf("- num nodes: %d\n", newGraph.number_of_vertices);
    printf("- num edges: %d\n", newGraph.number_of_edges);
    printf("- indegree: %d-%d\n", newGraph.in_degree_min, newGraph.in_degree_max);
    printf("- outdegree: %d-%d\n", newGraph.out_degree_min, newGraph.out_degree_max);
    return 0;
}