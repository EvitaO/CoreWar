# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <eovertoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/02 17:11:36 by eovertoo      #+#    #+#                  #
#    Updated: 2020/09/14 15:44:57 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = asm

NAME2 = corewar

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

PR = libft/ft_printf/libftprintf.a

all: $(LIB) $(PR) $(NAME1) $(NAME2)

$(NAME1)	: $(LIB) $(PR)
	@echo "\x1B[36mCompiling Assembler... \x1B[0m"
	@make -C Assembler/
	@ mv Assembler/asm .

$(NAME2)	: $(LIB) $(PR)
	@echo "\x1B[36mCompiling CoreWar... \x1B[0m"
	@make -C Virtual_Machine/
	@ mv Virtual_Machine/corewar .

$(LIB) :
	@make -C libft/

$(PR) :
	@make -C libft/ft_printf/

clean:
	@echo "\x1B[34mObjects have been removed.\x1B[0m"
	@make clean  -C Assembler/
	@make clean  -C Virtual_Machine/
	@make clean  -C libft/

fclean: clean
	@echo "\x1B[35mLibrary has been removed.\x1B[0m"
	@rm -rf asm
	@rm -rf corewar
	@make fclean  -C Assembler/
	@make fclean  -C Virtual_Machine/
	@make fclean -C libft/

re: fclean all