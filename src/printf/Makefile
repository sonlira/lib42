# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		:= libftprintf.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I../../include -Iinternal
AR			:= ar rcs
RM			:= rm -rf

SRC_DIR		:= .
OBJ_DIR		:= obj

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Busca todos los .c dentro de printf
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

# Crear la librería
$(NAME): $(OBJ)
	@printf "\n$(YELLOW)→ Creando librería:$(RESET) $(CYAN)$@$(RESET)\n"
	@$(AR) $@ $(OBJ)
	@echo "$(GREEN)✔ Printf compilado correctamente.$(RESET)"

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K$(GREEN)Compilando printf:$(RESET) $(CYAN)%s$(RESET)" "$(notdir $<)"

# Limpieza
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)✔ Objetos de printf eliminados.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✔ Librería printf eliminada.$(RESET)"

re: fclean all

print-%:
	@echo '$*=$($*)'

.PHONY: all clean fclean re print-%
.SILENT:
