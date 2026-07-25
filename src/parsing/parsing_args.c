#include "cub3d.h"

int check_arg(int argc)
{
    if(argc != 2)
        return(1);
    return(0);
}

int	has_valid_extension(char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 4)
		return (1);
	if (strcmp(filename + (len - 4), ".cub") == 0)
		return (0);
	return (1);
}
int check_file(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (1);
    close(fd);
    return (0);
}
