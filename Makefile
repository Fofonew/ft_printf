LIB = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strndup.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_countwords.c \
	  ft_isspace.c \
	  ft_lstpush.c \
	  ft_itoabase.c \
	  ft_putunbr.c

SRCS = ft_printf.c \
	   ft_flags.c \
	   ft_field.c \
	   ft_format.c \

CONV = ft_conv_di.c \
	   ft_conv_u.c \
	   ft_conv_o.c \
	   ft_conv_c.c \
	   ft_conv_s.c \
	   ft_conv_p.c \
	   ft_conv_x.c \
	   ft_conv_e.c \
	   ft_conv_f.c \
	   ft_conv_g.c \
	   ft_conv_a.c \
	   ft_conv_n.c \
	   ft_conv_b.c \
	   ft_conv_r.c \
	   ft_conv_k.c \

LOBJS = $(addprefix lib/, $(LIB:.c=.o))
SOBJS = $(addprefix srcs/, $(SRCS:.c=.o))
COBJS = $(addprefix conv/, $(CONV:.c=.o))

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LOBJS) $(SOBJS) $(COBJS)
	@ar -rsc $(NAME) $(LOBJS) $(SOBJS)
	@echo "[$(NAME)]"
	@$(CC) -I incs -o printf $(NAME) main.c
	@echo "[printf]"

lib/%.o: lib/%.c
	@$(CC) $(FLAGS) -I incs -o $@ -c $<
	@echo "[$@]"

srcs/%.o: srcs/%.c
	@$(CC) $(FLAGS) -I incs -o $@ -c $<
	@echo "[$@]"

conv/%.o: conv/%.c
	@$(CC) $(FLAGS) -I incs -o $@ -c $<
	@echo "[$@]"

clean:
	@rm -f $(LOBJS) $(SOBJS) $(COBJS)
	@echo "[objs removed]"

fclean: clean
	@rm -f $(NAME)
	@rm -f printf
	@echo "[workspace clean]"

re: fclean all
