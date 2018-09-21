#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "can.h"
#include "math.h"

static double r2()
{
    return (double)rand() / (double)RAND_MAX ;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    struct can_config config;
    struct can_node node;
    struct can_node node2;
    struct can_node node3;
    struct can_node node4;

    struct vector test;
    test.dim = DIM;
    for (int i = 0; i < DIM;i++) {
      test.element[i] = r2();
    }

    config.dimensions = DIM;
    init_can(&node);
    //printf("argc: %d\n",argc);
    if (argc > 1 && argv[1] != NULL && strncmp(argv[1], "master", sizeof("master")) == 0)
    {
        //printf("master node\n");
        create_network(&node, &config);
        split(&node, &node2);
        split(&node2, &node3);
        split(&node, &node4);
        //print_node(&node);
        //print_node(&node2);
        //print_node(&node3);
        //print_node(&node4);
        printf("%d vol: %f\n",1,volume(&node));
        printf("%d vol: %f\n",2,volume(&node2));
        printf("%d vol: %f\n",3,volume(&node3));
        printf("%d vol: %f\n",4,volume(&node4));
        return 0;
        //dim: 2: (0.000000,0.000000,) -> (1.000000,0.500000,)
        //dim: 2: (0.000000,0.500000,) -> (1.000000,1.000000,)
        for (int e = 0; e < 10000000; e++)
        {
            for (int i = 0; i < DIM; i++)
            {
                test.element[i] = r2();
            }
            if (in_body(&node, &test))
            {
                printf("1\n");
            }
            if (in_body(&node2, &test))
            {
                printf("2\n");
            }
            if (in_body(&node3, &test))
            {
                printf("3\n");
            }
            if (in_body(&node4, &test))
            {
                printf("4\n");
            }
            assert(in_body(&node, &test) ^ in_body(&node2, &test) ^ in_body(&node3, &test) ^ in_body(&node4, &test));
        }
    }
    else
    {
    }
}