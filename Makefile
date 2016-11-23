SRCS = ft_printf.c \
	   ft_flags.c \
	   ft_field.c \
	   ft_format.c \
	   main.c \

OBJS = $(addprefix objs/,$(SRCS:.c=.o))
NAME = ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS)

objs/%.o: srcs/%.c
	gcc -Wall -Wextra -Werror -Iincs -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
