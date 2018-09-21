#include "can.h"
static double scalar_product(struct vector *p1,struct vector *p2) {
    assert(p1->dim = p2->dim);
    int ret = 0;
    for (int i = 0; i < p1->dim; i++)
    {
        ret += p1->element[i] * p2->element[i];
    }
    return ret;
}

static struct vector scalar_mult(struct vector *p1,double r) {
    struct vector ret;
    ret.dim = p1->dim;
    for (int i = 0; i < p1->dim; i++)
    {
        ret.element[i] += p1->element[i]*r;
    }
    return ret;
}

static struct vector v_add(struct vector *p1,struct vector *p2) {
    assert(p1->dim == p2->dim);
    struct vector ret;
    ret.dim = p1->dim;
    for (int i = 0; i < p1->dim; i++)
    {
        ret.element[i] = p1->element[i] + p2->element[i];
    }
    return ret;
}



static struct vector v_mult(struct vector *p1,struct vector *p2) {
    assert(p1->dim == p2->dim);
    struct vector ret;
    ret.dim = p1->dim;
    for (int i = 0; i < p1->dim; i++)
    {
        ret.element[i] = p1->element[i] * p2->element[i];
    }
    return ret;
}

static struct vector v_sub(struct vector *p1,struct vector *p2) {
    assert(p1->dim == p2->dim);
    struct vector ret;
    ret.dim = p1->dim;
    for (int i = 0; i < p1->dim; i++)
    {
        //printf("%f = %f - %f\n",ret.element[i] ,p2->element[i] ,p1->element[i]);
        ret.element[i] = p1->element[i] - p2->element[i];
    }
    return ret;
}

static double product(struct vector *p) {
    double ret = 1;
    for (int i = 0; i < p->dim; i++)
    {
        //printf("%f = %f - %f\n",ret.element[i] ,p2->element[i] ,p1->element[i]);
        ret *= p->element[i];
    }
    return ret;
}

bool is_overlapping(int a) {
    return false;
}

bool is_neighbor(struct can_node *self, struct can_node *other) {
    assert(self->start.dim == other->start.dim);
    int overlap = 0, non_overlap = 0;
    for (int i = 0; i < self->start.dim;i++) {

    }
}

double volume(struct can_node *n) {
    struct vector len = v_sub(&n->direction, &n->start);
    return product(&len);
}

int print_node(struct can_node *n) {
    printf("dim: %d: (",n->start.dim);
    for (int i = 0; i < n->start.dim; i++)
    {
        printf("%f,",n->start.element[i]);
    }
    printf(") -> (");
    for (int i = 0; i < n->direction.dim; i++)
    {
        printf("%f,",n->direction.element[i]);
    }
    printf(")\n");
}

int split(struct can_node *a, struct can_node *b) {
    memcpy(b, a, sizeof(struct can_node));
    double half = a->direction.element[(a->start.dim-a->split_dim)-1] / 2;
    a->direction.element[(a->start.dim-a->split_dim)-1] = half;
    b->start.element[(a->start.dim-a->split_dim)-1] = half;

    a->split_dim++;
    if (a->split_dim > a->start.dim)
    {
        a->split_dim = 0;
    }

    b->split_dim++;
    if(b->split_dim > b->start.dim) {
        b->split_dim = 0;
    }
}

bool in_body(struct can_node *n,struct vector *p) {
    struct vector n_norm = v_sub(&n->direction,&n->start);
    struct vector p_norm = v_sub(p, &n->start);
    for (int i = 0; i < n_norm.dim; i++)
    {
        if (p_norm.element[i] < 0 || p_norm.element[i] > n_norm.element[i])
        {
            return false;
        }
    }
    return true;
}