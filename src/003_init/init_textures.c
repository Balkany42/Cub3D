#include "../../include/cub3d.h"

void load_textures (t_game *g)
{
    g->tex_no = mlx_xpm_file_to_image(g->mlx, "NO.xpm", &g->tex_w, &g->tex_h);
    g->addr_no = mlx_get_data_addr(g->tex_no, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_so = mlx_xpm_file_to_image(g->mlx, "SO.xpm", &g->tex_w, &g->tex_h);
    g->addr_so = mlx_get_data_addr(g->tex_so, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_we = mlx_xpm_file_to_image(g->mlx, "WE.xpm", &g->tex_w, &g->tex_h);
    g->addr_we = mlx_get_data_addr(g->tex_we, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_ea = mlx_xpm_file_to_image(g->mlx, "EA.xpm", &g->tex_w, &g->tex_h);
    g->addr_ea = mlx_get_data_addr(g->tex_ea, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
}