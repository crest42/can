
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#define DIM 1237

struct can_config {
    int dimensions;
};

struct vector {
    double element[DIM];
    int dim;
};

struct can_node {
    struct vector start;
    struct vector direction;
    int split_dim;
};

struct can_node neighbors[2 * DIM];

int init_can(struct can_node *node);
int create_network(struct can_node *node, struct can_config *config);