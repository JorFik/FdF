# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/12/01 18:22:52 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C
CFLAGS = -Wall -Wextra -Werror -Iheaders
#-framework Cocoa -framework OpenGL -framework IOKit
ADD = -fsanitize=address -g
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
OBJ = $(C_FILES:.c=.o)
LIBS_D = libft/
DEBUGGER = debugger/

NAME = fdf
A_FILE = libft.a libmlx.a
C_FILES = src/main.c
BONUS_FILES =

.PHONY: clean fclean re all c

all: $(NAME)

bonus: $(OBJ+)
	@$(LIB) $(NAME) $(OBJ+)

$(NAME) : $(OBJ) a_files
	@echo "	Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
	@clean

a_files: $(LIBS_D)
	@for dir in $(LIBS_D); do \
		echo "	Compiling $$dir..."; \
		$(CALLMAKE) $$dir; \
	done
	@echo "	Compiling mlx..."
	@cmake --build mlx -j4
	@mv mlx/libmlx.a .

%.o : %.c 
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "	Cleanig traces..."
	@echo "	Ereasing Files .o"
	@$(RM) $(OBJ+)
	@echo "	Ereasing Files .a"
	@$(RM) *.a

fclean: clean
	@echo "	Ereasing $(NAME)..."
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