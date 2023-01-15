#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct  s_info
{
    double  minMax[6];
    size_t  v_amount;
    size_t  f_amount;
    double  *vertexes;
    int     *facets;
}               t_info;

void    info_init(t_info *info);
void    info_dup(t_info *info, t_info *copy);
void    info_free(t_info *info);

void    ft_translate(double *vertexes, int v_amount, int axis, double d);
void    ft_scale(double *vertexes, int v_amount, double x);
void    ft_ox_rotate(double *vertexes, int v_amount, double angle);
void    ft_oy_rotate(double *vertexes, int v_amount, double angle);
void    ft_oz_rotate(double *vertexes, int v_amount, double angle);

int     parse(const char *fileName, t_info *info);
int     vf_count(const char *fileName, t_info *info);
int     vf_parse(const char *fileName, t_info *info);
void    ft_minMax(double x, double y, double z, t_info *info);

#endif // VIEWER_H
