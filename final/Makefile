# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 06:02:17 by hazali            #+#    #+#              #
#    Updated: 2026/03/01 09:01:37 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
CFLAGS = -Werror -Wextra -Wall


INC_DIR = ./inc
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ_DIR = ./obj
SRC_DIR = ./src
LEXER_DIR = $(SRC_DIR)/lexer
PARSER_DIR = $(SRC_DIR)/parser
EXEC_DIR = $(SRC_DIR)/exec
UTILS_DIR = $(SRC_DIR)/utils
BUILTINS_DIR = $(SRC_DIR)/builtins

LEXER_FILES = 	$(LEXER_DIR)/lexer.c \
				$(LEXER_DIR)/lexer2.c \
				$(LEXER_DIR)/lexer3.c  \
				$(LEXER_DIR)/lexer4.c  \
				$(LEXER_DIR)/lexer5.c  \
				$(LEXER_DIR)/lexer6.c

PARSER_FILES = 	$(PARSER_DIR)/parser.c \
				$(PARSER_DIR)/parser_utils.c \
				$(PARSER_DIR)/parser_utils2.c \
				$(PARSER_DIR)/parser_node.c \
				$(PARSER_DIR)/parser_clean.c \
				$(PARSER_DIR)/parser_args.c \
				$(PARSER_DIR)/expand.c \
				$(PARSER_DIR)/debug.c \
				$(PARSER_DIR)/debug2.c \
				$(PARSER_DIR)/expand2.c 

EXEC_FILES = 	$(EXEC_DIR)/exec.c \
				$(EXEC_DIR)/exec_and_or.c \
				$(EXEC_DIR)/exec_cmd.c \
				$(EXEC_DIR)/exec_pipe.c \
				$(EXEC_DIR)/get_path.c \
				$(EXEC_DIR)/redir.c \
				$(EXEC_DIR)/hd.c 
UTILS_FILES = 	$(UTILS_DIR)/signals.c \
				$(UTILS_DIR)/utils.c \
				$(UTILS_DIR)/utils2.c \
				$(UTILS_DIR)/utils4.c \
				$(UTILS_DIR)/utils3.c

BUILTINS_FILES = 	$(BUILTINS_DIR)/builtins.c \
					$(BUILTINS_DIR)/cd.c \
					$(BUILTINS_DIR)/echo.c \
					$(BUILTINS_DIR)/env.c \
					$(BUILTINS_DIR)/exit.c \
					$(BUILTINS_DIR)/export.c \
					$(BUILTINS_DIR)/pwd.c \
					$(BUILTINS_DIR)/unset.c 

SRC = 	$(SRC_DIR)/main.c $(LEXER_FILES) $(PARSER_FILES) \
		$(EXEC_FILES) $(UTILS_FILES) $(BUILTINS_FILES)
OBJ =	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -I $(INC_DIR) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	@make -C ./Libft

clean:
	@make -C ./Libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./Libft fclean
	rm -f $(NAME)

re: fclean $(NAME)