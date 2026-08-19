#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>

# if defined(__has_include)
#  if __has_include(<mlx.h>)
#   include <mlx.h>
#  endif
# else
#  include <mlx.h>
# endif

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	orientation;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
} t_map;

typedef struct s_img
{
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		f_set;
	int		c_set;
} t_config;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_config	config;
}	t_game;
int		check_arg(int argc);
int		has_valid_extension(char *filename);
int		check_file(char *filename);
int		is_blank(char *line);
int		is_map_line(char *line);
int		match_token(char *line, char *token);
char	*get_value(char *line, char *token);
int		parse_component(char *str, int *out);
int		try_texture_token(t_config *cfg, char *line, int *handled);
int		try_color_token(t_config *cfg, char *line, int *handled);
int		config_is_complete(t_config *cfg);
int		parse_config_line(t_config *cfg, char *line);
int		parse_config(t_config *cfg, char **lines, int *i);
int		parse_map(t_map *map, char **lines, int start);
int		check_map(t_map *map);
int		parse_error(char *msg);
void	free_config(t_config *cfg);
void	free_map(t_map *map);
void	free_all(t_game *game);

int		ft_strlen(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	ft_putstr_fd(const char *s, int fd);
int		ft_isdigit(int c);
#endif