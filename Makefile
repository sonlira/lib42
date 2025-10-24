# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		:= lib42.a

# Compilador y flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iinclude

# Directorios
SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

# Comando para crear archivos y borrar
AR			:= ar rcs
RM			:= rm -rf

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Buscar todos los .c en src/ de forma recursiva
SRC			:= $(shell find $(SRC_DIR) -type f -name '*.c')

# Generar los nombres de los .o correspondientes en obj/
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
	@echo "$(GREEN)✔ Librería compilada correctamente.$(RESET)"

# Compilar los objetos (línea dinámica)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K$(GREEN)Compilando:$(RESET) $(CYAN)%s$(RESET)" "$(notdir $<)"

# Limpiar objetos y librería
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)✔ Objetos eliminados.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✔ Librería eliminada.$(RESET)"

re: fclean all

# Regla de conveniencia
print-%:
	@echo '$*=$($*)'

# Evitar conflictos con archivos
.PHONY: all clean fclean re print-%
.SILENT:
