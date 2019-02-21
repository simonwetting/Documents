NAME = libft.a
EXTRA_FUNCTIONS = ft_clowcase ft_cupcase ft_intlen ft_iswhitespace ft_itoc ft_lstadd_end ft_lstcount ft_lstiterr ft_memsdel ft_strcofi ft_repp
FUNCTIONS = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper

OBJECTS = $(EXTRA_FUNCTIONS:%=%.o) $(FUNCTIONS:%=%.o) 
FILES = $(FUNCTIONS:%=%.c) $(EXTRA_FUNCTIONS:%=%.c)


all: $(NAME) $(OBJECTS)

$(NAME): $(OBJECTS)
	@gcc -c -g -Wall -Werror -Wextra $(FILES)
	@ar rc libft.a $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

test: all compile-test
	clear
	@./a.out

test-v: all compile-test
	@./a.out

compile-test:
	@gcc -Wall -Werror -Wextra testing.c utf.c test_functions.c $(OBJECTS)