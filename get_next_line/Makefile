FILES = file1 file2 file3
COMMAND = ./a.out $(FILES) | cat -e

run: re
	clear
	@echo "\033[0;31m$(COMMAND)"
	@echo "\033[0;37m"
	@$(COMMAND)

test: re
	clear
	@sh check_output.sh $(FILES)

re:
	cd libft; make
	gcc -g main.c get_next_line.c -Llibft -lft -Wall -Wextra -Werror
	clear