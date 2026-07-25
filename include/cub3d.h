#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <mlx.h>

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
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_config
{
	t_img	tex_no;
	t_img	tex_so;
	t_img	tex_we;
	t_img	tex_ea;
	int		floor_color;
	int		ceiling_color;
}	t_config;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_config	config;
}	t_game;

#endif