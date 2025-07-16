# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:00:00 by sabejaou          #+#    #+#              #
#    Updated: 2024/05/30 10:00:00 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFTPRINTF_DIR = libftprintf

# Sources principales
SRCS_CORE = $(wildcard $(SRC_DIR)/core/*.c)
SRCS_UTILS = $(wildcard $(SRC_DIR)/utils/*.c)

# Sources libftprintf
LIBFTPRINTF_SRCS = $(wildcard $(LIBFTPRINTF_DIR)/srcs/*.c)
LIBFTPRINTF_OBJS = $(LIBFTPRINTF_SRCS:$(LIBFTPRINTF_DIR)/srcs/%.c=$(OBJ_DIR)/libftprintf/%.o)

# Objets
OBJS_CORE = $(SRCS_CORE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_UTILS = $(SRCS_UTILS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INC_DIR) -I$(LIBFTPRINTF_DIR)/incl

all: $(NAME)

$(NAME): $(OBJS_CORE) $(OBJS_UTILS) $(LIBFTPRINTF_OBJS)
	@echo "Edition des liens pour $(NAME)..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS_CORE) $(OBJS_UTILS) $(LIBFTPRINTF_OBJS)
	@echo "Binaire $(NAME) créé avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/libftprintf/%.o: $(LIBFTPRINTF_DIR)/srcs/%.c | $(OBJ_DIR)/libftprintf
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/libftprintf:
	@mkdir -p $(OBJ_DIR)/libftprintf

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage terminé !"

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé !"

re: fclean all

test: all
	@echo "Test de compilation terminé !"

.PHONY: all clean fclean re test 