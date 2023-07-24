NAME = libftprintf.a

SRCS =	ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c \
		ft_putund.c ft_hex.c ft_printf.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
rm		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

norme :
	norminette

.PHONY : all clean fclean re norme
