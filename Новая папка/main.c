#include "fdf.h"
#include <stdio.h>


int deal_key(int key)
{
    // Реализуйте логику обработки нажатия клавиши здесь
    printf("Нажата клавиша: %d\n", key);
    return 0;
}

void print_map(int **map, int width, int height)
{
    if (!map)
    {
        printf("Map is empty.\n");
        return;
    }

    printf("Map Contents:\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int width = 0;
    int height = 0;
    int **map;
    fdf data;

    // Чтение карты из файла
    map = read_map("test_maps/42.fdf", &width, &height);
    if (!map)
    {
        ft_printf("ERROR: Failed to read the map.\n");
        return 1;
    }

    // Инициализация структуры fdf
    data.mat = map;
    data.hei = height;
    data.wid = width;

    // Вывод содержимого карты в терминал (для отладки)
    print_map(data.mat, data.wid, data.hei);

    // Инициализация MiniLibX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        ft_printf("ERROR: Failed to initialize MiniLibX.\n");
        return 1;
    }

    // Создание графического окна
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "FDF");
    if (!data.win_ptr)
    {
        ft_printf("ERROR: Failed to create a window.\n");
        return 1;
    }

    // Зум для отображения
    data.zoom = 20;

    // Рисование карты
    draw(&data);

    // Обработка событий клавиатуры
    mlx_key_hook(data.win_ptr, deal_key, NULL);

    // Запуск главного цикла отображения окна
    mlx_loop(data.mlx_ptr);

    // Освобождение памяти и завершение программы
    for (int i = 0; i < height; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}



