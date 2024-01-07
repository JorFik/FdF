# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2024/01/07 21:15:28 by JFikents         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code
HEADERS = $(addprefix -I, $(HEADERS_DIR))
DEBUG_FLAGS = -fsanitize=address -g
LIBRARIES = $(patsubst %, -L%/, $(LIBRARIES_DIR))\
$(patsubst lib%,-l%,$(LIBRARIES_DIR))
default_target: all
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
# NAME is the name of the executable or library
NAME = fdf

# If you need to add more flags to the compilation, add them here in CFLAGS
# -Wall -Wextra -Werror -Wunreachable-code are already added
CFLAGS += -Ofast

# If you need to add libraries, add them to the variable LIBRARIES_DIR
#_ Don't add '/' at the end of the directory
LIBRARIES_DIR = libft libmlx42

# If your libraries are created in a different directory or with a 
# different name, add the appropriate flags to the variable LIBRARIES
# Example of flags that need to be added:
# LIBRARIES += -lglfw
# The Automatically added flags are created with the following pattern:
# -l$(LIBRARY_DIR - "lib" at the beginning) -L$(LIBRARY_DIR + "/" at the end)
# (e.g. libft -> -lft -Llibft/)
LIBRARIES += -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -ldl

# Here you can add the headers that you need to compile your program
# The headers are added with the flag -I
HEADERS_DIR = headers/ libft/h_files/\
	$(addprefix $(MLX42), $(addprefix include/, $(MLX42_H)))

# Here you can add the subdirectory where your source files are
SRC_DIR = src/

# Here you can add the files that you need to compile your program
#_ NOTE: to every file in C_FILES, the path in SRC_DIR will be added at the
#_ beginning
C_FILES = main.c error_handle.c rgba_utils.c sprite.c

# Here you can add the files that you need to compile that are not inside the
# SRC_DIR
SRC +=

MLX42 = MLX42/
MLX42_H = MLX42/ lodepng/ KHR/ glad/
#_----------------------------------------------------------------------------_#

# * ----------------------------- DEBUG AREA ------------------------------ * #

# To debug your program, just call the rule debug
# It will compile your program with the flag -g and move the executable to the
# folder DEBUGGER
DEBUGGER = debugger/

# If you want to test your program, but just some files, add them to the
# variable TEST and use the rule test
TEST = src/test.c

# If you want to add more flags to the debug rule, add them to the variable
# DEBUG_FLAGS
# -g and -fsanitize=address are already added
DEBUG_FLAGS +=

c:
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch 

debug: c a_files
	@$(CC) $(CFLAGS) $(SRC) $(DEBUG_FLAGS) $(HEADERS) $(LIBRARIES)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
# @make fclean

test: c a_files
	@$(CC) $(CFLAGS) $(TEST) $(DEBUG_FLAGS) $(HEADERS) $(LIBRARIES)
	@mv a.out $(DEBUGGER)
	@mv a.out.dSYM $(DEBUGGER)
	@make fclean

#_----------------------------------------------------------------------------_#

# * ----------------------------- EXTRA RULES ----------------------------- * #

# Here you can add extra rules to compile your program

libmlx42/:
	@echo "	Creating libmlx42..."
	@cmake $(MLX42) -B libmlx42 && cmake --build libmlx42 --parallel -j4

git : fclean
	@echo "	Preparring to save to git repository..."
	@$(RM) libmlx42/
	@git add .
	@echo "	Added all files"
	@echo "	Commit message:"
	@read msg; \
		echo "	Commiting..."; \
		git commit -m "$$msg"
	@git push

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
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(HEADERS) $(LIBRARIES)
else
$(NAME) : a_files $(OBJ)
	@echo "	Compiling $(NAME)..."
	@$(LIB) $(NAME) $(OBJ) $(HEADERS) $(LIBRARIES)
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
		$(CALLMAKE) $$dir -s; \
	done

%.o : %.c
	@echo "	Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

run : all
	@echo "	arg?"
	@read arg; \
		./$(NAME) $$arg

#_----------------------------------------------------------------------------_#

# * ----------------------------- BONUS RULES ----------------------------- * #

ifeq ($(BONUS), 1)
ifeq ($(COMPILE_TOGETHER), 1)
bonus: a_files $(OBJ+) $(OBJ)
	@echo "	Compiling $(NAME) with bonus..."
	@$(CC) -o $(NAME) $(OBJ+) $(OBJ) $(CFLAGS) $(HEADERS) $(LIBRARIES)
endif
else
bonus: a_files $(OBJ+)
	@echo "	Compiling $(NAME)_bonus..."
	@$(CC) -o $(NAME)_bonus $(OBJ+) $(CFLAGS) $(HEADERS) $(LIBRARIES)
endif

#_----------------------------------------------------------------------------_#
