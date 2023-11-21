# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/11/20 22:34:07 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C
CFLAGS = -Wall -Wextra -Werror
ADD = -fsanitize=address -g
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
OBJ = $(C_FILES:.c=.o)
LIBFT_D = libft/
DEBUGGER = debugger/

NAME = 
MAIN =
TEST =
A_FILE = libft.a
C_FILES =
BONUS_FILES =

.PHONY: clean fclean re all c

all: $(NAME)

bonus: $(OBJ+)
	@$(LIB) $(NAME) $(OBJ+)

$(NAME) : $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

%.o : %.c 
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ+)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

debug: c
	@$(CC) $(ADD) $(CCFLAGS) $(H_FILE) $(C_FILES) $(MAIN)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@mv *.gch $(DEBUGGER)
	@make fclean

test: c
	@$(CC) $(ADD) $(CCFLAGS) $(H_FILE) $(TEST)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@mv *.gch $(DEBUGGER)
	@make fclean

c: fclean
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch 