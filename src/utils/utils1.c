#include "../../include/cub3d.h"

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while(src[i])
        i++;
    return (i);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}
ft_strlen_break (char *src, size_t n)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        i++;
        if(i == n)
            return (1);
    }
    return (0);
}