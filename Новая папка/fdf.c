#include "fdf.h"


int count_words(const char *str, char delimiter)
{
    int count = 0;
    int is_word = 0;

    while (*str != '\0')
    {
        if (*str != delimiter)
        {
            if (is_word == 0)
            {
                count++;
                is_word = 1;
            }
        }
        else
        {
            is_word = 0;
        }
        str++;
    }

    return count;
}

// Функция для получения ширины карты
int get_map_width(char *file_path)
{
    int fd;
    char *line;
    int width = 0;

    // Проверка наличия файла
    if (access(file_path, F_OK) == -1)
    {
        ft_printf("ERROR: File not found\n");
        return -1;
    }

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("ERROR: Failed to open file\n");
        return -1;
    }

    if ((line = get_next_line(fd)) != NULL)
    {
        width = count_words(line, ' ');
        free(line);
    }

    close(fd);
    return width;
}

// Функция для получения высоты карты
int get_map_height(char *file_path)
{
    int fd;
    char *line;
    int height = 0;

    // Проверка наличия файла
    if (access(file_path, F_OK) == -1)
    {
        ft_printf("ERROR: File not found\n");
        return -1;
    }

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("ERROR: Failed to open file\n");
        return -1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        height++;
        free(line);
    }

    close(fd);
    return height;
}

// Функция для чтения карты и получения ширины и высоты
int **read_map(char *file_path, int *width, int *height)
{
    int fd;
    char *line;
    int **map;
    int _width = 0;
    int _height = 0;

    // Получаем ширину карты
    _width = get_map_width(file_path);
    if (_width <= 0)
    {
        return NULL;
    }

    // Получаем высоту карты
    _height = get_map_height(file_path);
    if (_height <= 0)
    {
        return NULL;
    }

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("ERROR: Failed to open file\n");
        return NULL;
    }

    // Выделение памяти для карты
    map = (int **)malloc(_height * sizeof(int *));
    if (map == NULL)
    {
        ft_printf("ERROR: Failed to allocate memory for map\n");
        return NULL;
    }

    int row = 0;
    while (row < _height)
    {
        map[row] = (int *)malloc(_width * sizeof(int));
        if (map[row] == NULL)
        {
            ft_printf("ERROR: Failed to allocate memory for row in map\n");
            while (row > 0)
            {
                row--;
                free(map[row]);
            }
            free(map);
            return NULL;
        }
        row++;
    }

    // Считывание чисел из файла и сохранение их в массив
    row = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        // Парсинг чисел из строки line и сохранение их в массив map
        int col = 0;
        char **tokens = ft_split(line, ' ');
        while (tokens[col] != NULL)
        {
            map[row][col] = ft_atoi(tokens[col]);
            free(tokens[col]);
            col++;
        }
        free(tokens);
        free(line);
        row++;
    }

    close(fd);

    *width = _width;
    *height = _height;

    return map;
}



void fill_map(int **map, int width, int height, char *file_path)
{
    int fd;
    char *line;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("ОШИБКА: Не удалось открыть файл\n");
        return;
    }

    int row = 0;
    while (row < height)
    {
        if ((line = get_next_line(fd)) == NULL)
        {
            ft_printf("ОШИБКА: Неверные данные карты\n");
            close(fd);
            return;
        }

        int col = 0;
        char *token = split_str(line, ' ');
        while (token != NULL && col < width)
        {
            map[row][col] = ft_atoi(token);
            token = split_str(NULL, ' ');
            col++;
        }

        free(line);
        row++;
    }

    close(fd);
}

char *split_str(char *str, char delimiter)
{
    static char *next_token = NULL;
    char *token;

    if (str != NULL)
    {
        next_token = str;
    }

    if (next_token == NULL || *next_token == '\0')
    {
        return NULL;
    }

    token = next_token;

    while (*next_token != '\0' && *next_token != delimiter)
    {
        next_token++;
    }

    if (*next_token == delimiter)
    {
        *next_token = '\0';
        next_token++;
    }

    return token;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}

