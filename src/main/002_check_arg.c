#include "../../include/cub3d.h"

int check_arg(int argc, char**argv)
{
    int len_arg;

    if(argc != 2)
        return (printf("Incorrect number of arguments detected"));
    if(argv[1][0] == '.' || check_hidden_file_in_path(argv[1]))
        return (printf("Argument is a hidden file"));
    len_arg = len_arg_with_path(argv[1]) - 4;
    if(len_arg < 5)
        return (printf("Incorrect map name detected"));
    len_arg = ft_strlen(argv[1]) - 4;
    if (ft_strncmp((argv[1] + len_arg), ".cub", 4) != 0)
        return (printf("Incorrect extension detected"));
}

int check_hidden_file_in_path(char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(src[i])
    {
        if(src[i] == '/')
            j = i;
        i++;
    }
    if (j == 0)
        return (0);
    if(src[j + 1] == '.')
        return (1);
    return (0);
}

int len_arg_with_path(char *src)
{
    int i;
    int j;
    int k;

    k = 0;
    i = 0;
    j = 0;
    while(src[i])
    {
        if(src[i] == '/')
            j = i;
        i++;
    }
    if (i == j)
        return (i);
    j++;
    while(src[j])
    {
        j++;
        k++;
    }
    return (k);
}
