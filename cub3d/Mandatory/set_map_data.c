#include "cub3d.h"

int	read_cub_file(int fd, t_info *info)
{
	char	*line;
	char	*tmp;
	int		result;
	int		not_finish;

	tmp = NULL;
	info->valid_count = 0;
	not_finish = 1;
	while (not_finish != 0)
	{
		not_finish = get_next_line(fd, &line, &tmp);
		if (not_finish == -1 || (info->valid_count == 0 && line[0] == '\0'))
			return (-1);
		else if (info->valid_count == 6 && line[0] != '\0')
			result = read_map(line, info);
		else
		{
			result = get_identifier_info(line, info, not_finish);
			if (result == 1)
				info->valid_count++;
		}
		if (result == -1)
			return (free_all(&line, NULL, &tmp, result));
	}
	return (0);
}

int	get_identifier_info(char *line, t_info *info, int not_finish)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (*line != '\0')
		result = check_identifier(&line[i], info);
	if (result == -1)
		return (-1);
	if (not_finish == 1 && info->map.map != NULL && line[0] == '\0')
		return (-1);
	free(line);
	line = NULL;
	return (result);
}

int	read_map(char *line, t_info *info)
{
	int	i;

	if (info->map.map != NULL && copy_map_to_tmp(info) == -1)
		return (-1);
	info->map.map = malloc(sizeof(char *) * (info->map.height + 1));
	if (info->map.map == NULL)
		return (free_char_arr(&(info->map.tmpmap), 0, info->map.height));
	i = -1;
	while (++i < info->map.height)
	{
		info->map.map[i] = gnl_strdup(&(info->map.tmpmap[i]), 0);
		if (info->map.map[i] == NULL)
		{
			free_char_arr(&(info->map.tmpmap), i, info->map.height);
			return (free_char_arr(&(info->map.map), 0, i));
		}
	}
	free(info->map.tmpmap);
	if (is_valid_size(info, line) == -1)
		return (free_char_arr(&(info->map.map), 0, i));
	info->map.map[i] = gnl_strdup(&line, 0);
	if (info->map.map[i] == NULL)
		return (free_char_arr(&(info->map.map), 0, i));
	info->map.height++;
	return (0);
}

int	copy_map_to_tmp(t_info *info)
{
	int	i;

	i = 0;
	info->map.tmpmap = malloc(sizeof(char *) * info->map.height);
	if (info->map.tmpmap == NULL)
		return (free_char_arr(&(info->map.map), 0, info->map.height));
	while (i < info->map.height)
	{
		info->map.tmpmap[i] = gnl_strdup(&(info->map.map[i]), 0);
		if (info->map.tmpmap[i] == NULL)
		{
			free_char_arr(&(info->map.map), i, info->map.height);
			return (free_char_arr(&(info->map).tmpmap, 0, i));
		}
		i++;
	}
	free(info->map.map);
	return (0);
}
