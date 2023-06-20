#include <stdio.h>

typedef struct xyz
{
    int value;
    struct xyz *left;
    struct xyz *right;
} node;

node creatnode