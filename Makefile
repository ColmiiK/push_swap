#Variables

NAME = push_swap
B_NAME = checker
INCLUDE = include
LIBFT = lib/libft
SRC_DIR = src/
B_SRC_DIR = src/bonus/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
	
SRC_FILES = main parsing moves perms_a perms_b perms_d sort init_a init_b utils_1 utils_2 utils_3 error
B_SRC_FILES = main parsing moves perms_a perms_b perms_d utils_1

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
B_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix _bonus.c, $(B_SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix _bonus.o, $(B_SRC_FILES)))
OBJF = .cache_exists

###

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR)
			@rm -f $(NAME)
			@rm -f $(B_NAME)
			@make fclean -C $(LIBFT)
			@echo "$(BLUE)$(NAME) executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)$(NAME) recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(B_SRC) $(INCLUDE) $(LIBFT)

bonus: $(B_OBJ)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(B_OBJ) -L$(LIBFT) -lft -o $(B_NAME)
			@echo "$(MAGENTA)$(B_NAME) compiled!$(DEF_COLOR)"

.PHONY: all clean fclean re norm bonus