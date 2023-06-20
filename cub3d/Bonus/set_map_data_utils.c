#include "cub3d.h"

int	check_identifier(char *line, t_info *info)
{
	if (ft_chrstr(line[0], "FC") == 1 && check_start_zero(line) == 1)
			return (-1);
	else if (line[0] == 'F')
		return (get_color(line + 1, &(info->map), &(info->map.f_color)));
	else if (line[0] == 'C')
		return (get_color(line + 1, &(info->map), &(info->map.c_color)));
	else if (line[0] == 'N' && line[1] == 'O')
		return (get_texture_path(line + 2, info, 0));
	else if (line[0] == 'S' && line[1] == 'O')
		return (get_texture_path(line + 2, info, 1));
	else if (line[0] == 'W' && line[1] == 'E')
		return (get_texture_path(line + 2, info, 2));
	else if (line[0] == 'E' && line[1] == 'A')
		return (get_texture_path(line + 2, info, 3));
	else if (line[0] == 'S')
		return (get_texture_path(line + 1, info, 4));
	else
		return (-1);
}

int	get_texture_path(char *line, t_info *info, int num)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	len = ft_strlen(&(line[i]));
	if (info->map.t_path[num] != NULL)
		return (-1);
	info->map.t_path[num] = malloc(sizeof(char) * (len + 1));
	if (info->map.t_path[num] == NULL)
		return (-1);
	while (line[i] != '\0')
		info->map.t_path[num][j++] = line[i++];
	info->map.t_path[num][j] = '\0';
	return (1);
}

int	get_color(char *line, t_map *map, int *color)
{
	int	i;

	i = 0;
	map->c = 0;
	*color = 0;
	while (line[i] == ' ')
		i++;
	while ((('0' <= line[i] && line[i] <= '9') || line[i] == ',') && map->c < 3)
	{
		if (line[i] == ',')
			*color = (*color << 8) + map->rgb[(map->c)++];
		else
		{
			if (map->rgb[map->c] == -1)
				map->rgb[map->c] = 0;
			map->rgb[map->c] = map->rgb[map->c] * 10 + line[i] - '0';
			if (map->rgb[map->c] > 255)
				return (-1);
		}
		i++;
	}
	*color = (*color << 8) + map->rgb[map->c];
	if (check_color_val(map) == -1 || line[i] != '\0')
		return (-1);
	return (1);
}

int	is_valid_size(t_info *info, char *line)
{
	int count;

	count = 0;
	if (info->map.height >= 200)
		return (-1);
	while (line[count] != '\0')
	{
		count++;
		if (count >= 200)
			return (-1);
	}
	if (info->map.max_width < count)
		info->map.max_width = count;
	return (0);
}
