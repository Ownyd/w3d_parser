# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:20:07 by emarin            #+#    #+#              #
#    Updated: 2018/03/30 07:14:24 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=wolf3d
SRCS_PATH=srcs
OBJ_PATH=obj
INCLUDE_PATH=includes
LIB=libft.a
LIB_PATH=libft

OBJ_NAME= main.o textures.o ray.o draw_txt.o
		

OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADERS=$(INCLUDE_PATH)/wolf3d.h

FLAGS= -I $(INCLUDE_PATH) 
#-Wall -Wextra -Werror
LINK_FLAGS= -L $(LIB_PATH) -lft -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RED=\033[31m
GREEN=\033[32m
ORANGE=\033[33m
EOC=\033[0m

all: $(LIB) $(NAME)

.display:
	@echo "--> make $(ORANGE)$(NAME)$(EOC)"
	@touch .display

$(NAME): .display $(LIB_PATH)/$(LIB) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LINK_FLAGS)
	@echo "\n\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r$(NAME)"

$(OBJ_PATH)/%.o:$(SRCS_PATH)/%.c $(HEADERS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc -o $@ -c $< $(FLAGS)
	@echo "\r\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r$@\c"

$(LIB):
	@$(MAKE) -C $(LIB_PATH)

.PHONY: fclean all clean re $(LIB)

clean:
	@echo "--> fclean $(ORANGE)$(LIB_PATH)/$(EOC)"
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -rf $(OBJ_PATH)
	@rm -f .display
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r*.o"

fclean: clean
	@rm -f $(NAME)
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r$(NAME)"

re: fclean all
