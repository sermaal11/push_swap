#------------------------------------------------------------------------------#

# Nombre del ejecutable a crear (sin espacios)
NAME = push_swap
# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten)
CFLAGS = -Wall -Wextra -Werror

#------------------------------------------------------------------------------#

# Archivos fuente (agregar los que se necesiten)
SRCS = main.c
# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)

#------------------------------------------------------------------------------#

# Colores para el make (opcional)
RESET = \033[0m
GREEN = \033[92m
MAGENTA = \033[95m

#------------------------------------------------------------------------------#

# Reglas del make (no tocar)

# $@ -> nombre del objetivo (en este caso, el nombre del ejecutable)
# $^ -> todas las dependencias
# $< -> la primera dependencia

# $@ -> nombre del objetivo (en este caso, el nombre del ejecutable)
all: $(NAME)
	@echo "$(GREEN)$(NAME) compilado exitosamente!!$(RESET)"

# La regla $(NAME) compila el ejecutable con los archivos objeto creados 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# La regla %.o compila los archivos objeto
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# La regla clean elimina todos los archivos objeto
clean:
	@echo "$(MAGENTA)Eliminando archivos objeto ...$(RESET)"
	rm -rf $(OBJS)
	@echo "$(GREEN)Todos los archivos objeto han sido eliminados$(RESET)"

# La regla fclean elimina todos los archivos objeto y el ejecutable
fclean: clean
	@echo "$(MAGENTA)Eliminando ejecutable ...$(RESET)"
	rm -rf $(NAME)
	@echo "$(GREEN)El ejecutable ha sido eliminado$(RESET)"

# La regla re elimina todo y compila nuevamente
re: fclean all

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean o re
.PHONY: all clean fclean re

#------------------------------------------------------------------------------#