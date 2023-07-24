
# Настройки компилятора
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Пути к заголовочным файлам
INCLUDES = -I.

# Имена исходных файлов
SRCS = get_next_line.c \
	get_next_line_utils.c 

# Имена объектных файлов
OBJS = $(SRCS:.c=.o)

# Имя библиотеки
LIB_NAME = libgnl.a

# Правило для компиляции исходных файлов в объектные
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Правило для создания библиотеки
$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

# Правило для очистки объектных файлов
clean:
	rm -f $(OBJS)

# Правило для очистки библиотеки и объектных файлов
fclean: clean
	rm -f $(LIB_NAME)

# Правило для перекомпиляции всего
re: fclean $(LIB_NAME)

# Фиктивное правило для исключения случайного имени файла
.PHONY: all clean fclean re
