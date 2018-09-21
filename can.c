#include "can.h"

int create_network(struct can_node *node, struct can_config *config)
{
    for (int i = 0; i < config->dimensions;i++) {
        node->direction.element[i] = 1;
    }
    node->start.dim = config->dimensions;
    node->direction.dim = config->dimensions;
}

int init_can(struct can_node *node) {
    memset(node, 0, sizeof(struct can_node));
}

int find_node(struct vector p,struct can_node *n) {
    return 0;

}