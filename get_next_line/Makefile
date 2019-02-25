COMMAND = ./a.out file1 file2 file3 testt2.txt | cat -e

run: re
	clear
	@echo "\033[0;31m$(COMMAND)"
	@echo "\033[0;37m"
	@$(COMMAND)

re:
	cd libft; make
	gcc -g main.c get_next_line.c -Llibft/ -lft -Wall -Wextra -Werror
	clear