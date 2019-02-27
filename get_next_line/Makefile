FILE = file2
COMMAND = ./a.out $(FILE) > output.txt; diff $(FILE) output.txt

run: re
	clear
	@echo "\033[0;31m$(COMMAND)"
	@echo "\033[0;37m"
	@$(COMMAND)

re:
	cd libft; make
	gcc -g main.c get_next_line.c -Llibft/ -lft -Wall -Wextra -Werror
	clear