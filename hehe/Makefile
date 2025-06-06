# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 14:46:31 by prambaud          #+#    #+#              #
#    Updated: 2025/05/30 18:19:21 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	webserv

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
UP			=	\033[A
CUT			=	\033[K

SRC_FILES	=	classFonction/joueur.cpp \
				classFonction/zone.cpp \
				classFonction/carte.cpp \
				classFonction/menace.cpp \
				classFonction/menace_externe.cpp \
				classFonction/menace_interne.cpp \
				classFonction/cannon.cpp \
				classFonction/chemin_menace.cpp \
				classFonction/menace_interne_serieuse.cpp \
				classFonction/jeux.cpp \
				main.cpp \
				initialisation.cpp \
				utils.cpp

OBJ			=	$(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC_FILES))
DEPS		=	$(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(BLUE)Deleting all objects from /ex00...$(RESET)"; \
	else \
		echo "No objects to remove from /ex00."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /ex00...$(RESET)"; \
	else \
		echo "No Executable to remove from /ex00."; \
	fi;

re: fclean all

.PHONY: all clean fclean re

