#include "fdf.h"
#include <math.h>

#define MAX1(a, b) ((a) > (b) ? (a) : (b))
#define MAX(a, b) MAX1(a, b)
#define MOD(a) ((a < 0) ? -a : a)

static	int	ft_countwords(const char *str, char ceporator)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == ceporator)
			i++;
		else
		{
			words++;
			while (str[i] != '\0' && str[i] != ceporator)
				i++;
		}
	}
	return (words);
}

static	char	*ft_wd(const char *str, char c)
{
	int		i;
	char	*wd;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char ) * (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		wd[i] = str[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

static	void	ft_freeword(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr_words;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	ptr_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr_words)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = ft_wd(s, c);
		if (ptr_words[i] == NULL)
			ft_freeword(i, ptr_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}


float mod(float i)
{
    return (i < 0) ? -i : i;
}


void isometric(float *x, float *y, int z)
{
    float angle = 0.8; // Угол для изометрического преобразования

    *x = (*x - *y) * cos(angle);
    *y = (*x + *y) * sin(angle) - z;
}


void bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    int max;


    int z = data->mat[(int)y][(int)x];
    int z1 = data->mat[(int)y1][(int)x1];
	

	//-------zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//---------color
	data->color = (z) ? 0xe80c0c : 0xffffff;
	//--------3D
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
	//-------shift
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;


    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || MOD(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
		printf("gere");
    }
}


void draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->hei)
	{
		x = 0;
		while (x < data->wid)
		{
			if(x < data->wid - 1)
				bresenham(x, y, x + 1, y, data);
			if(y < data->hei - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}