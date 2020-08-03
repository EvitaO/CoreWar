# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <eovertoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/02 17:11:36 by eovertoo      #+#    #+#                  #
#    Updated: 2020/08/03 13:21:46 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = vm

SRC =  main.c change_id.c check_args.c itoa_base.c reading.c intro.c str_rev_by_2.c

OBJ =  main.o change_id.o check_args.o itoa_base.o reading.o intro.o str_rev_by_2.o

INC = vm.h

all: $(NAME)

$(NAME):
	@echo "\x1B[36mCompiling... \x1B[0m"
	@Make -C ./libft
	@mv libft/libft.a .
	@mv libft/ft_printf/libftprintf.a .
	@gcc -Wall -Wextra -Werror -c -I.$(INC) $(SRC)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I.$(INC) libft.a libftprintf.a

clean:
	@echo "\x1B[34mObjects have been removed.\x1B[0m"
	@Make clean  -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "\x1B[35mLibrary has been removed.\x1B[0m"
	@Make fclean -C ./libft
	@/bin/rm -f $(NAME) libft.a libftprintf.a

re: fclean all