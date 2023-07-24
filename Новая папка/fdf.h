#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "minilibx_macos/mlx.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct
{
	int		wid;
	int		hei;
	int		**mat;
	int	zoom;
	int color;

	void *mlx_ptr;
	void *win_ptr;
}			fdf;

void draw_without_isometric(fdf *data);
float mod(float i);
void draw(fdf *data);
void bresenham(float x, float y, float x1, float y1, fdf *data);
char	**ft_split(char const *s, char c);
int **read_map(char *file_path, int *width, int *height);
int count_words(const char *str, char delimiter);
int ft_atoi(const char *str);
int get_map_width(char *file_path);
int get_map_height(char *file_path);
int	ft_atoi(const char *str);
char *split_str(char *str, char delimiter);
#endif