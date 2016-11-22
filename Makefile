SRCS = ft_printf.c \
	   ft_strncmp.c \
	   ft_flags.c \
	   ft_main.c \

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o test $(OBJS)
	#ar rs $(NAME) $(OBJS)

%.o: srcs/%.c
	gcc -Wall -Wextra -Werror -Iincs -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
