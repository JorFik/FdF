# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2024/01/04 00:21:01 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * ---------------------- AVOID CHANGES IN THIS AREA ---------------------- * #
LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C
OBJ = $(addprefix $(SRC_DIR), $(C_FILES:.c=.o))
OBJ+ = $(addprefix $(SRC_DIR), $(BONUS_FILES:.c=.o))
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
CFLAGS = -Wall -Wextra -Werror -fsanitize=address\
$(addprefix -I, $(H_FILES_DIR))
ADD = -fsanitize=address -g \
$(addprefix -L, $(LIBRARIES_DIR))\
$(addprefix -l, $(subst lib,,$(subst /,,$(LIBRARIES_DIR))))
#_----------------------------------------------------------------------------_#

# ? -------------------------- DO YOU HAVE BONUS? -------------------------- ? #
# If you have bonus, change the value of the variable BONUS to 1 and add the
#  bonus files to the variable BONUS_FILES
BONUS = 1
BONUS_FILES = 
# If it compiles together with the rest of the files, change the value of the
# variable COMPILE_TOGETHER to 1
COMPILE_TOGETHER = 1
#_----------------------------------------------------------------------------_#

# ? --------------------------- IS IT A PROGRAM? --------------------------- ? #
# If it is a program, change the value of the variable PROGRAM to 1 and make
# sure that you have int main(void) in your one of files in C_FILES
PROGRAM = 1

#_----------------------------------------------------------------------------_#

# * --------------------------- CHANGE THIS AREA --------------------------- * #
NAME = fdf
# CFLAGS += -framework Cocoa -framework OpenGL -framework IOKit
ADD += -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
H_FILES_DIR = headers/ libft/h_files/\
	$(addprefix $(MLX42), $(addprefix include/, $(MLX42_H)))
LIBRARIES_DIR = libft/ libmlx42/
MLX42 = MLX42/
MLX42_H = MLX42/ lodepng/ KHR/ glad/
SRC_DIR = src/
C_FILES = main.c
#_----------------------------------------------------------------------------_#

# * ----------------------------- BASIC RULES ----------------------------- * #

.PHONY: clean fclean re all c bonus debug test a_files submodule aclean

ifeq ($(BONUS), 1)
ifeq ($(COMPILE_TOGETHER), 1)
all: bonus
else
all: $(NAME) bonus
endif
else
all: $(NAME)
endif

ifeq ($(PROGRAM), 1)
$(NAME) : a_files $(OBJ)
	@echo "	Compiling $@..."
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(ADD)
else
$(NAME) : a_files $(OBJ)
	@echo "	Compiling $(NAME)..."
	@$(LIB) $(NAME) $(OBJ) $(ADD)
endif

clean: aclean
	@echo "	Cleanig traces..."
	@echo "	Ereasing Files .o"
	@$(RM) $(OBJ+) $(OBJ)

aclean:
	@for dir in $(LIBRARIES_DIR); do \
		if test -d $$dir; then \
			if test $$dir = libft/; then \
				echo "	Cleaning $$dir..."; \
				$(CALLMAKE) $$dir fclean; \
			else \
				echo "	Cleaning $$dir..."; \
				$(CALLMAKE) $$dir clean; \
			fi \
		else \
			echo "	No need to clean $$dir"; \
		fi \
	done

fclean: clean
	@echo "	Ereasing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

submodule:
	@git submodule update --init --recursive

a_files: submodule $(LIBRARIES_DIR)
	@for dir in $(LIBRARIES_DIR); do \
		echo "	Compiling $$dir..."; \
		$(CALLMAKE) $$dir; \
	done

%.o : %.c
	@echo "	Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $<

#_----------------------------------------------------------------------------_#

# * ----------------------------- EXTRA RULES ----------------------------- * #

# Here you can add extra rules to compile your program

libmlx42:
	@echo "	Creating libmlx42..."
	@cmake MLX42/ -B libmlx42 && cmake --build libmlx42 --parallel -j4

git_clean : fclean
	@echo "	Preparring to save to git repository..."
	@echo "	Removing $(LIBRARIES_DIR)..."
	@$(RM) $(LIBRARIES_DIR)
	@echo "	Removing $(MLX42)..."
	@$(RM) $(MLX42)
	@git add .
	@echo "	Added all files"
	@echo "	Commit message:"
	@read msg; \
		echo "	Commiting..."; \
		git commit -m "$$msg"
	@git push

#_----------------------------------------------------------------------------_#

# * ----------------------------- DEBUG AREA ------------------------------ * #

# To debug your program, just call the rule debug
# It will compile your program with the flag -g and move the executable to the
# folder DEBUGGER
DEBUGGER = debugger/

# If you want to test your program, but just some files, add them to the
# variable TEST and use the rule test
TEST =

c: fclean
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch 

debug: c a_files
	@$(CC) $(CFLAGS) $(SRC) $(ADD)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@make fclean

test: c
	@$(CC) $(CFLAGS) $(TEST) $(ADD)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@make fclean

#_----------------------------------------------------------------------------_#

# * ----------------------------- BONUS RULES ----------------------------- * #

ifeq ($(BONUS), 1)
ifeq ($(COMPILE_TOGETHER), 1)
bonus: a_files $(OBJ+) $(OBJ)
	@echo "	Compiling $(NAME) with bonus..."
	@$(CC) -o $(NAME) $(OBJ+) $(OBJ) $(CFLAGS) $(ADD)
endif
else
bonus: a_files $(OBJ+)
	@echo "	Compiling $(NAME)_bonus..."
	@$(CC) -o $(NAME)_bonus $(OBJ+) $(CFLAGS) $(ADD)
endif

#_----------------------------------------------------------------------------_#
