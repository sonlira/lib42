# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		:= lib42.a
LIBFT		:= libft.a
PRINTF		:= libftprintf.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iinclude

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

AR			:= ar rcs
RM			:= rm -rf

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Buscar todos los .c excepto los de printf
SRC			:= $(shell find $(SRC_DIR) -type f -name '*.c' ! -path "$(SRC_DIR)/printf/*")
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

# Crear la librería global combinada
$(NAME): $(LIBFT) $(PRINTF)
	@printf "\n$(YELLOW)→ Creando librería global:$(RESET) $(CYAN)$@$(RESET)\n"
	@$(AR) $@ $(LIBFT) $(SRC_DIR)/printf/$(PRINTF)
	@echo "$(GREEN)✔ Librería global $(NAME) creada correctamente.$(RESET)"

# Crear la parte base (todo menos printf)
$(LIBFT): $(OBJ)
	@printf "\n$(YELLOW)→ Creando librería base:$(RESET) $(CYAN)$@$(RESET)\n"
	@$(AR) $@ $(OBJ)
	@echo "$(GREEN)✔ Librería base compilada correctamente.$(RESET)"

# Compilar la parte printf por separado
$(PRINTF):
	@printf "\n$(YELLOW)→ Compilando printf...$(RESET)\n"
	@$(MAKE) -s -C $(SRC_DIR)/printf
	@echo "$(GREEN)✔ Printf compilado correctamente.$(RESET)"

# Compilar los objetos (libft)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K$(GREEN)Compilando:$(RESET) $(CYAN)%s$(RESET)" "$(notdir $<)"

# Limpiar
clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -s -C $(SRC_DIR)/printf clean
	@echo "$(RED)✔ Objetos eliminados.$(RESET)"

fclean: clean
	@$(MAKE) -s -C $(SRC_DIR)/printf fclean
	@$(RM) $(NAME) $(LIBFT) $(PRINTF)
	@echo "$(RED)✔ Librerías eliminadas.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
