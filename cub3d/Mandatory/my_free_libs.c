#include "cub3d.h"

int	free_all(char **line, char **buf, char **tmp, int result)
{
	if (line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	if (buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	if (tmp != NULL)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (result);
}

int	free_int_arr(int ***arr, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (-1);
}

int	free_char_arr(char ***arr, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (-1);
}

int	free_members(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
		free(info->map.t_path[i++]);
	if (info->map.map != NULL)
		free_char_arr(&(info->map.map), 0, info->map.height);
	return (0);
}

void	clear_all_params(t_info *info)
{
	int	i;

	i = 0;
	free_members(info);
	if (info->buf != NULL)
	{
		while (i < info->s_h)
			free(info->buf[i++]);
	}
	free(info->buf);
	i = 0;
	if (info->tex != NULL)
	{
		while (i < 4)
			free(info->tex[i++]);
	}
	free(info->tex);
	if (info->img.img != NULL)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
//	mlx_destroy_display(info->mlx);
	free(info->mlx);
}
