CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ_MAIN = main.o
OBJ_FDF = fdf.o
OBJ_FDF_UTILS = fdf_utils.o

MINILIBX_PATH = minilibx_macos
MINILIBX_LIB = $(MINILIBX_PATH)/libmlx.a
MINILIBX_INC = -I$(MINILIBX_PATH)

fdf_utils:
	$(CC) $(CFLAGS) -c fdf_utils.c -o fdf_utils.o

main.o: main.c fdf.h
	$(CC) $(CFLAGS) $(MINILIBX_INC) -c main.c -o main.o

fdf.o: fdf.c fdf.h
	$(CC) $(CFLAGS) $(MINILIBX_INC) -c fdf.c -o fdf.o

all: ft_printf gnl $(MINILIBX_LIB) $(OBJ_MAIN) $(OBJ_FDF) $(OBJ_FDF_UTILS)
	$(CC) $(CFLAGS) -o a.out $(OBJ_MAIN) $(OBJ_FDF) $(OBJ_FDF_UTILS) -Lft_printf -lftprintf -Lgnl -lgnl -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_PATH)

ft_printf:
	$(MAKE) -C ft_printf

gnl:
	$(MAKE) -C gnl

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C gnl clean
	rm -f $(OBJ_MAIN) $(OBJ_FDF) $(OBJ_FDF_UTILS)

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C gnl fclean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re ft_printf gnl
