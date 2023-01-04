#ifndef VIEWER_H
#define VIEWER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_info
{
    double  minMax[6];
    size_t  v_amount;
    size_t  f_amount;
    double  *vertexes;
    int     *facets;
} t_info;

#endif // VIEWER_H
