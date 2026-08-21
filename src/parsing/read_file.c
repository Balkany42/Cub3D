#include "cub3d.h"

static void strip_newline(char *line)
{
    int len;

    len = (int)ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}

static char **append_line(char **lines, char *line)
{
    int     count;
    char  **new;

    count = 0;
    if (lines)
        while (lines[count])
            count++;

    new = malloc(sizeof(char *) * (count + 2));
    if (!new)
        return (NULL);

    for (int i = 0; i < count; i++)
        new[i] = lines[i];

    new[count] = line;
    new[count + 1] = NULL;

    free(lines);
    return (new);
}

char **read_file(char *path)
{
    int     fd;
    char    *line;
    char  **lines;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);

    lines = NULL;
    while ((line = get_next_line(fd)))
    {
        strip_newline(line);
        lines = append_line(lines, line);
        if (!lines)
        {
            close(fd);
            return (NULL);
        }
    }
    close(fd);
    return (lines);
}
