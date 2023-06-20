#include"cub3d.h"

int	error(int fd, int result, t_info *info)
{
	printf("Error\n");
	if (result == -1)
		printf("[ Wrong Commandline argument ]\n");
	else if (result == -2)
		printf("[ Failed to INITIALIZE paramaters ]\n");
	else if (result == -3)
		printf("[ Failed to READ cub_file ]\n");
	else if (result == -4)
		printf("[ Failed to LOAD texture ]\n");
	else if (result == -5)
		printf("[ Failed to OPEN game window ]\n");
	if (result <= -3)
		clear_all_params(info);
	close(fd);
	return (-1);
}

int	check_input_arg(int argc, char **argv)
{
	int i;
	int	fd;

	i = 0;
	fd = -1;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".cub") == 0 || ft_strstr(argv[1], "/.cub") == 1)
			return (-1);
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '.')
			{
				if (ft_strcmp(&(argv[1][i]), ".cub") == 0)
				{
					fd = open(argv[1], O_RDONLY);
					break;
				}
			}
			i++;
		}
	}
	return (fd);
}

int	check_color_val(t_map *map)
{
	if (map->c != 2)
		return (-1);
	if (map->rgb[0] == -1)
		return (-1);
	if (map->rgb[1] == -1)
		return (-1);
	if (map->rgb[2] == -1)
		return (-1);
	map->rgb[0] = -1;
	map->rgb[1] = -1;
	map->rgb[2] = -1;
	return (0);
}

int	check_start_zero(char *line)
{
	int	i;
	int	num_f;
	int	zero_f;

	i = 0;
	num_f = 0;
	zero_f = 0;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || '9' < line[i])
		{
			num_f = 0;
			zero_f = 0;
		}
		else if (zero_f == 1 && num_f == 0)
			return (1);
		else if (line[i] == '0')
			zero_f = 1;
		else
			num_f = 1;
		i++;
	}
	return (0);
}
