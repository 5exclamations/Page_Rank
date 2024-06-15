/*
 * main.c
 *
 * Programming 2 - Project 3 (PageRank)
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "markov.h"
#include "opt.h"
#include "parse_graph.h"
#include "rand_surf.h"
#include "statistics.h"
#include "utils.h"

int parameter = 10;
int main(int argc, char *const *argv) {
  rand_init();
  opt(argc, argv);
  exit(0);
}
