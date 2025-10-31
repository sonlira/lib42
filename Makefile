# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		:= lib42.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iinclude -Isrc/printf/internal

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

AR			:= ar rcs
RM			:= rm -rf

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Buscar todos los .c (incluyendo printf)
SRC			:= $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ			:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
CYAN		:= \033[0;36m
RESET		:= \033[0m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

# Crear la librería única
$(NAME): $(OBJ)
	@printf "\n$(YELLOW)→ Creando librería:$(RESET) $(CYAN)$@$(RESET)\n"
	@$(AR) $@ $(OBJ)
	@ranlib $@
	@echo "$(GREEN)✔ Librería $(NAME) creada correctamente.$(RESET)"

# Compilar cada archivo .c a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K$(GREEN)Compilando:$(RESET) $(CYAN)%s$(RESET)" "$(notdir $<)"

# Limpiar objetos
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)✔ Objetos eliminados.$(RESET)"

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✔ Librería eliminada.$(RESET)"

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re
.SILENT:
