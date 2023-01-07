#include "viewer.h"

int parse(char *fileName, t_info *info)
{
    info_init(info);
    if (!vf_count(fileName, info))
        return 0;
    if (!vf_parse(fileName, info))
        return 0;
    return 1;
}

int vf_count(char *fileName, t_info *info)
{
    char    *str;
    size_t  n;

    FILE *fr = fopen(fileName, "r");
    if (!fr)
        return 0;
    while(getline(&str, &n, fr))
    {
        if (str[0] == 'v' && str[1] == ' ')
            info->v_amount++;
        else if (str[0] == 'f' && str[1] == ' ')
        {
            int i = 2;
            while (str[i])
            {
                if (isdigit(str[i]))
                {
                    info->f_amount++;
                    while (isdigit(str[i]))
                        i++;
                }
                else
                    i++;
            }
        }
        free(str);
    }
    fclose(fr);
    info->vertexes = (double *)malloc(info->v_amount * 3 * sizeof(double));
    info->facets = (int *)malloc(info->f_amount * 2 * sizeof (int));
    return 1;
}

int vf_parse(char *fileName, t_info *info)
{
    char    *str;
    size_t  n;
    int     tmp_f, tmp_s, tmp_t;
    double  tmp_x, tmp_y, tmp_z;

    int v = 0;
    int f = 0;
    FILE *fr = fopen(fileName, "r");
    if (!fr)
        return 0;
    while(getline(&str, &n, fr))
    {
        if (str[0] == 'v' && str[1] == ' ')
        {
            sscanf(str, "v %lf %lf %lf", &tmp_x, &tmp_y, &tmp_z);
            info->vertexes[v] = tmp_x;
            info->vertexes[v + 1] = tmp_y;
            info->vertexes[v + 2] = tmp_z;
            ft_minMax(tmp_x, tmp_y, tmp_z, info);
            v += 3;
        }
        else if (str[0] == 'f' && str[1] == ' ')
        {
            sscanf(str, "f %d %d %d", &tmp_f, &tmp_s, &tmp_t);
            info->facets[f + 0] = tmp_f;
            info->facets[f + 1] = tmp_s;
            info->facets[f + 2] = tmp_s;
            info->facets[f + 3] = tmp_t;
            info->facets[f + 4] = tmp_t;
            info->facets[f + 5] = tmp_f;
            f += 6;
        }
        free(str);
    }
    fclose(fr);
    return 1;
}
