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

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	 zone.cpp \
						joueur.cpp \
						carte.cpp \
						menace.cpp \
						menace_externe.cpp \
						zone_haut_blue.cpp \
						menace_interne.cpp \
						zone_haut_red.cpp \
						chemin_menace.cpp \
						zone_bas_white.cpp \
						menace_interne_serieuse.cpp \
						zone_haut_white.cpp \
						zone_bas_blue.cpp \
						zone_bas_red.cpp \
						jeux.cpp \
						main.cpp \
						utils.cpp


OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEPS		=	$(OBJ:.o=.d)

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

-include $(DEPS)

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex00...$(RESET)"; else \
	echo "No objects to remove from /ex00."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from /ex00...$(RESET)"; else \
	echo "No Executable to remove from /ex00."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re
