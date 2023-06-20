#ifndef MAZE_H
# define MAZE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYER	'N'
#define LAND	'0'
#define WALL	'1'
#define PASSED	'3'
#define GOAL	'2'
#define NOW		'5'

#define WIDTH 40
#define HEIGHT 40

#define LAND_TO_WALL 100	// %
#define PASS_TO_WALL 0 // %

#define SCREEN_SIZE "600 400"
#define FLOOR_C "50,50,50"
#define CEILING_C "144,215,236"
#define TEXT_EA "../Textures/bluestone.xpm"
#define TEXT_SO "../Textures/bluestone.xpm"
#define TEXT_WE "../Textures/bluestone.xpm"
#define TEXT_NO "../Textures/bluestone.xpm"
#define TEXT_S "../Textures/barrel.xpm"

#define OUT_F "./field.cub"

#endif
