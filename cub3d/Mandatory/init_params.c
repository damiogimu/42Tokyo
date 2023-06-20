#include "cub3d.h"

int	init_params(t_info *info)
{
	init_map_data(info);
	init_info_data(info);
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (-1);
	mlx_get_screen_size(info->mlx, &(info->s_w), &(info->s_h));
	if (SCREEN_WIDTH < info->s_w)
		info->s_w = SCREEN_WIDTH;
	if (SCREEN_HEIGHT < info->s_h)
		info->s_h = SCREEN_HEIGHT;
	return (0);
}

void	init_map_data(t_info *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map.t_path[0] = NULL;
	info->map.t_path[1] = NULL;
	info->map.t_path[2] = NULL;
	info->map.t_path[3] = NULL;
	info->map.rgb[0] = -1;
	info->map.rgb[1] = -1;
	info->map.rgb[2] = -1;
	info->map.f_color = -1;
	info->map.c_color = -1;
	info->map.max_width = 0;
	info->map.height = 0;
	info->map.tmpmap = NULL;
	info->map.map = NULL;
}

void	init_info_data(t_info *info)
{
	info->posx = -1.0;
	info->posy = -1.0;
	info->dirx = 0;
	info->diry = 0;
	info->cp_x = 0;
	info->cp_y = 0;
	info->movespeed = 0.1;
	info->rotspeed = 0.05;
	info->key_w = 0;
	info->key_a = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->key_ar_l = 0;
	info->key_ar_r = 0;
	info->buf = NULL;
	info->tex = NULL;
	info->img.img = NULL;
	info->img.data = NULL;
}

char	set_player_pos(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < ft_strlen(info->map.map[i]))
		{
			if (ft_chrstr(info->map.map[i][j], "EWSN") == 1)
			{
				if (info->posx != -1.0 || info->posy != -1.0)
					return (0);
				info->posx = (double)j + 0.5;
				info->posy = (double)i + 0.5;
			}
			else if (ft_chrstr(info->map.map[i][j], "01 ") == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (info->posx == -1 || info->posx == -1)
		return (0);
	return (info->map.map[(int)info->posy][(int)info->posx]);
}

void	set_player_dir(char p_dir, t_info *info)
{
	if (p_dir == 'N')
	{
		info->diry = -1.0;
		info->cp_x = 1.0;
	}
	if (p_dir == 'S')
	{
		info->diry = 1.0;
		info->cp_x = -1.0;
	}
	if (p_dir == 'E')
	{
		info->dirx = 1.0;
		info->cp_y = 1.0;
	}
	if (p_dir == 'W')
	{
		info->dirx = -1.0;
		info->cp_y = -1.0;
	}	
}
