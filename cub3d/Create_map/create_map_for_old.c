#include "maze.h"

typedef struct	s_data
{
	char **map;
	char **tmp;
	int p_x, p_y;
	int g_x, g_y;
	int reach_f;
}				t_data;

void disp_tmp(t_data *data)
{
	int i, j;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (data->tmp[i][j] == PLAYER)
				printf("\x1b[34mP\x1b[0m ");
			else if (data->tmp[i][j] == LAND)
				printf("  ");
			else if (data->tmp[i][j] == WALL)
				(j == WIDTH-1) ? printf("#") : printf("# ");
			else if (data->tmp[i][j] == PASSED)
				printf("* ");
			else if (data->tmp[i][j] == GOAL)
				printf("\x1b[31mX\x1b[0m ");
			else
				printf("  ");
			j++;
		}
		printf("\n");
		i++;
	}
}
void disp_map(t_data *data)
{
	int i, j;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (data->map[i][j] == PLAYER)
				printf("\x1b[34mP\x1b[0m ");
			else if (data->map[i][j] == LAND)
				printf("  ");
			else if (data->map[i][j] == WALL)
				(j == WIDTH-1) ? printf("#") : printf("# ");
			else if (data->map[i][j] == GOAL)
				printf("\x1b[31mX\x1b[0m ");
			else if (data->tmp[i][j] == PASSED)
				printf("* ");
			else
				printf("  ");
			j++;
		}
		printf("\n");
		i++;
	}
}

void select_root(int **root)
{
	int i, j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		(*root)[i] = rand()%4;
		while (j < i)
		{
			if ((*root)[i] == (*root)[j])
			{
				i--;
				break;
			}
			j++;
		}
		i++;
	}
}	

void flood_fill(int x, int y, t_data *data)
{
	if (data->reach_f == 1)
		return ;
	if (data->tmp[x][y] == GOAL)
	{
		for (int k=0; k<HEIGHT; k++)
			strcpy(data->map[k], data->tmp[k]);
		data->reach_f = 1;
		return ;
	}
	int *root;
	root = malloc(sizeof(int) * 4);
	select_root(&root);
	data->tmp[x][y] = PASSED;
	for (int i=0; i<4; i++)
	{
		switch(root[i])
		{
			case 0:
				if (0 <= (x-1) && (data->tmp[x-1][y] == LAND || data->tmp[x-1][y] == GOAL))
					flood_fill(x-1, y, data);
			case 1:
				if ((x+1) < HEIGHT && (data->tmp[x+1][y] == LAND || data->tmp[x+1][y] == GOAL))
					flood_fill(x+1, y, data);
			case 2:
				if (0 <= (y-1) && (data->tmp[x][y-1] == LAND || data->tmp[x][y-1] == GOAL))
					flood_fill(x, y-1, data);
			case 3:
				if ((y+1) < WIDTH && (data->tmp[x][y+1] == LAND || data->tmp[x][y+1] == GOAL))
					flood_fill(x, y+1, data);
		}
	}
	free(root);
}

void fill_wall(t_data *data)
{
	int i, j;
	i = 1;
	while (i < HEIGHT-1)
	{
		j = 1;
		while (j < WIDTH-1)
		{
			if (data->map[i][j] == LAND && (rand()%100 > (100-LAND_TO_WALL)))
				data->map[i][j] = WALL;
			if (data->map[i][j] == PASSED && (rand()%100 > (100-PASS_TO_WALL)))
				data->map[i][j] = WALL;
			if (data->map[i][j] == PASSED)
				data->map[i][j] = LAND;
			j++;
		}
		i++;
	}
	data->map[data->p_x][data->p_y] = PLAYER;
	data->map[data->g_x][data->g_y] = GOAL;
}

void set_basic_data(FILE *fd)
{
	fprintf(fd, "R %s\n", SCREEN_SIZE);
	fprintf(fd, "F %s\n", FLOOR_C);
	fprintf(fd, "C %s\n", CEILING_C);
	fprintf(fd, "EA %s\n", TEXT_EA);
	fprintf(fd, "SO %s\n", TEXT_SO);
	fprintf(fd, "WE %s\n", TEXT_WE);
	fprintf(fd, "NO %s\n", TEXT_NO);
	fprintf(fd, "S %s\n\n", TEXT_S);
	
	printf("R %s\n", SCREEN_SIZE);
	printf("F %s\n", FLOOR_C);
	printf("C %s\n", CEILING_C);
	printf("EA %s\n", TEXT_EA);
	printf("SO %s\n", TEXT_SO);
	printf("WE %s\n", TEXT_WE);
	printf("NO %s\n", TEXT_NO);
	printf("S %s\n\n", TEXT_S);
}

int main(void)
{
	FILE *fd;
	int i, j;
	t_data data;	

	if ((fd = fopen(OUT_F, "w")) == NULL)
	{
		fprintf(stderr, "OPEN ERROR\n");
		return (0);
	}
	srand((unsigned int)time(NULL));
	data.p_x = data.p_y = data.g_x = data.g_y = 0;
	data.reach_f = 0;
	while (data.p_x == data.g_x && data.p_y == data.g_y)
	{
		data.p_x = rand() % (WIDTH-2) + 1;
		data.p_y = rand() % (HEIGHT-2) + 1;
		data.g_x = rand() % (WIDTH-2) + 1;
		data.g_y = rand() % (HEIGHT-2) + 1;
	}
	data.map = malloc(sizeof(char *) * HEIGHT);
	data.tmp = malloc(sizeof(char *) * HEIGHT);
	for (i=0; i<HEIGHT; i++)
	{
		data.map[i] = malloc(sizeof(char) * (WIDTH+1));
		data.tmp[i] = malloc(sizeof(char) * (WIDTH+1));
		for(j=0; j<WIDTH; j++)
		{
			if (1 <= i && i < (HEIGHT-1) && 1 <= j && j < (WIDTH-1))
				data.map[i][j] = LAND;
			else
				data.map[i][j] = WALL;
		}
	}
	data.map[data.p_x][data.p_y] = PLAYER;
	data.map[data.g_x][data.g_y] = GOAL;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (data.map[i][j] == PLAYER)
			{
				for (int k=0; k<HEIGHT; k++)
					strcpy(data.tmp[k], data.map[k]);
				flood_fill(i, j, &data);
			}
			j++;
		}
		i++;
	}
	fill_wall(&data);
	system("clear");
	set_basic_data(fd);
	disp_map(&data);

	i = 0;
	while (i < HEIGHT)
	{
		fprintf(fd, "%s\n", data.map[i]);
		i++;
	}

	i = 0;
	while(i < HEIGHT)
	{
		free(data.map[i]);
		i++;
	}
	free(data.map);
	return (0);
}
