#include "viewer.h"

void    info_init(t_info *info)
{
    info->minMax[0] = DBL_MAX;
    info->minMax[1] = -DBL_MAX;
    info->minMax[2] = DBL_MAX;
    info->minMax[3] = -DBL_MAX;
    info->minMax[4] = DBL_MAX;
    info->minMax[5] = -DBL_MAX;
    info->v_amount = 0;
    info->f_amount = 0;
}

void    info_dup(t_info *info, t_info *copy)
{
    copy->f_amount = info->f_amount;
    copy->v_amount = info->v_amount;
    copy->minMax[0] = info->minMax[0];
    copy->minMax[1] = info->minMax[1];
    copy->minMax[2] = info->minMax[2];
    copy->minMax[3] = info->minMax[3];
    copy->minMax[4] = info->minMax[4];
    copy->minMax[5] = info->minMax[5];
    copy->facets = (int *)malloc(copy->f_amount * 2 * sizeof(int));
    for (size_t i = 0; i < copy->f_amount * 2; i++)
        copy->facets[i] = info->facets[i];
    copy->vertexes = (double *)malloc(copy->v_amount * 3 * sizeof(double));
    for (size_t i = 0; i < copy->v_amount * 3; i++)
        copy->vertexes[i] = info->vertexes[i];
}

void    info_free(t_info *info)
{
    free(info->facets);
    free(info->vertexes);
    free(info);
    info = NULL;
}

void    ft_minMax(double x, double y, double z, t_info *info)
{
    if (x < info->minMax[0])
        info->minMax[0] = x;
    if (x > info->minMax[1])
        info->minMax[1] = x;
    if (y < info->minMax[2])
        info->minMax[2] = y;
    if (y > info->minMax[3])
        info->minMax[3] = y;
    if (z < info->minMax[4])
        info->minMax[4] = z;
    if (z > info->minMax[5])
        info->minMax[5] = z;
}
