COMMAND = ./a.out file3 | cat -e

run: re
	clear
	@echo "\033[0;31m$(COMMAND)"
	@echo "\033[0;37m"
	@$(COMMAND)

re:
	gcc main.c get_next_line.c -Llibft/ -lft -Wall -Wextra -Werror -g
	clear