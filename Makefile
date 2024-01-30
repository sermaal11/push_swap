
#******************************************************************************#
#********************************* C MAKEFILE *********************************#
#******************************************************************************#

# Nombre del ejecutable a crear (sin espacios)
NAME = push_swap
# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten)
CFLAGS = -Wall -Wextra -Werror -g3
# Directorio de los archivos objeto (no tocar)
OBJDIR = obj
# Archivos fuente (agregar los que se necesiten)
SRCS =	main.c \
		ft_check_input.c \
		ft_lst.c \
		ft_atoi.c \
		ft_split.c \
		ft_substr.c \
		ft_error.c \
		ft_strlen.c \
		ft_isdigit.c

#------------------------------------------------------------------------------#

# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)

#------------------------------------------------------------------------------#

# Colores para el make
RESET = \033[0m
GREEN = \033[92m
CYAN = \033[96m
RED = \033[91m
BACKGROUND_GREEN = \033[42m

#------------------------------------------------------------------------------#

# Reglas del make (no tocar)

# $@ -> nombre del objetivo (en este caso, el nombre del ejecutable)
all: $(NAME)
	@echo "$(BACKGROUND_GREEN)El Programa $(NAME) ha sido compilado!$(RESET)"

# La regla $(NAME) compila el ejecutable con los archivos objeto creados 
$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)Objetos creados con exito!$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $@ $^

# La regla %.o compila los archivos objeto
$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# La regla $(OBJDIR) crea el directorio de los archivos objeto
$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos...$(RESET)"
	mkdir $(OBJDIR)
	@echo "$(GREEN)Directorio de objetos creado con éxito!$(RESET)"
	@echo "$(CYAN)Creando objetos...$(RESET)"
# La regla clean elimina todos los archivos objeto y el directorio
clean:
	@echo "$(RED)Eliminando archivos objeto...$(RESET)"
	rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)Todos los archivos objeto han sido eliminados!$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos...$(RESET)"
	rm -rf $(OBJDIR)
	@echo "$(GREEN)Directorio de objetos eliminado!$(RESET)"

# La regla fclean elimina todos los archivos objeto y el ejecutable
fclean: clean
	@echo "$(RED)Eliminando ejecutable ...$(RESET)"
	rm -rf $(NAME)
	@rm -rf test/$(NAME)
	@echo "$(GREEN)El ejecutable ha sido eliminado!$(RESET)"

# La regla re elimina todo y compila nuevamente
re: fclean all

test: all
	@echo "$(CYAN)Copiando $(NAME) a la carpeta de prueba...$(RESET)"
	cp $(NAME) test/
	@echo "$(CYAN)Ejecutando el comando push_swap_test.sh...$(RESET)"
	cd test; ./push_swap_test.sh

valgrind: all
	@echo "$(CYAN)Ejecutando Valgrind en $(NAME)...$(RESET)"
	valgrind --leak-check=full ./$(NAME) -9 5 -3 12 -7

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean o re
.PHONY: all clean fclean re

#------------------------------------------------------------------------------#