SRCS = ft_printf.c \
	   ft_flags.c \
	   ft_field.c \
	   ft_format.c \
	   ft_strlen.c \
	   main.c \

OBJS = $(SRCS:.c=.o)
NAME = ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS)

%.o: srcs/%.c
	gcc -Wall -Wextra -Werror -Iincs -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
