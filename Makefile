# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 14:46:31 by prambaud          #+#    #+#              #
#    Updated: 2025/07/01 18:33:47 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	webserv

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++11 -g3

# directories
SRCS_WS_DIR	=	srcs/ws/
SRCS_SA_DIR	=	srcs/sa/
OBJS_DIR	=	.objs/
INCS_DIR	=	includes/

# colors
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

# source files for webserv (ws)
SRCS_FILES_WS =	main.cpp \
				sighandler.cpp \
				confParsing.cpp \
				serverSetUp.cpp \
				requestParsing.cpp \
				HTTPRequest.cpp \
				responseParsing.cpp \
				HTTPResponse.cpp \
				callCGI.cpp \
				CGIProcess.cpp \
				autoIndexManagement.cpp \
				serverManagement.cpp \
				requestParsUtils.cpp \
				methodeHandlerUtils.cpp \
				deleteHandler.cpp \
				postHandler.cpp \
				requestFullyReceivedCheck.cpp \
				methodeHandler.cpp \
				postMultipart.cpp \
				serverSetUpUtils.cpp \
				updatemission_in_process.cpp \
				handleRequestSA.cpp

# source files for space alerte (sa)
SRCS_FILES_SA =	classFonctions/cannon.cpp \
				classFonctions/carte.cpp \
				classFonctions/chemin_menace.cpp \
				classFonctions/jeux.cpp \
				classFonctions/joueur.cpp \
				classFonctions/menace.cpp \
				classFonctions/menace_msg.cpp \
				classFonctions/menace_actions.cpp \
				classFonctions/menace_interne.cpp \
				classFonctions/menace_externe.cpp \
				classFonctions/zoneGetSet.cpp \
				classFonctions/zoneActDir.cpp \
				classFonctions/zoneActAct.cpp \
				classFonctions/zoneUtils.cpp \
				initialisation.cpp \
				calculDegatsCanons.cpp \
				calculDegatsRockets.cpp \
				apparitionMenaces.cpp \
				parsingConfig.cpp \
				actionsDesJoueurs.cpp \
				checkMaintenance.cpp \
				main.cpp \
				utils.cpp

# Full source paths
SRCS_WS = $(addprefix $(SRCS_WS_DIR), $(SRCS_FILES_WS))
SRCS_SA = $(addprefix $(SRCS_SA_DIR), $(SRCS_FILES_SA))

# Object files (.o) in corresponding .objs/ws and .objs/sa folders to avoid collisions
OBJS_WS = $(patsubst $(SRCS_WS_DIR)%.cpp, $(OBJS_DIR)ws/%.o, $(SRCS_WS))
OBJS_SA = $(patsubst $(SRCS_SA_DIR)%.cpp, $(OBJS_DIR)sa/%.o, $(SRCS_SA))

OBJS = $(OBJS_WS) $(OBJS_SA)

# Dependency files (.d)
DEPS = $(OBJS:.o=.d)

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(RESET)"

# Compile object files for ws
$(OBJS_DIR)ws/%.o: $(SRCS_WS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< ...$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I $(INCS_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Compiled $@$(RESET)"
	@printf "$(UP)$(CUT)"

# Compile object files for sa
$(OBJS_DIR)sa/%.o: $(SRCS_SA_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< ...$(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I $(INCS_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Compiled $@$(RESET)"
	@printf "$(UP)$(CUT)"

-include $(DEPS)

clean:
	@if [ -d "$(OBJS_DIR)" ]; then \
		rm -rf $(OBJS_DIR); \
		echo "$(BLUE)Removed object files$(RESET)"; \
	else \
		echo "No object files to remove"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Removed executable $(NAME)$(RESET)"; \
	else \
		echo "No executable to remove"; \
	fi

re: fclean all

.PHONY: all clean fclean re
