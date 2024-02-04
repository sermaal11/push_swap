# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio <sergio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 12:32:56 by smarin-a          #+#    #+#              #
#    Updated: 2024/02/04 01:28:09 by sergio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#******************************************************************************#
#********************************* C MAKEFILE *********************************#
#******************************************************************************#
#------------------------------------------------------------------------------#

# Nombre del ejecutable a crear (sin espacios)
NAME = push_swap
# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten)
CFLAGS = -Wall -Wextra -Werror -g3
# Directorio de los archivos objeto (no tocar)
OBJDIR = objects
# Archivos fuente (agregar los que se necesiten)
SRCS =	main.c \
		ft_lst.c \
		ft_utils.c \
		ft_split.c \
		ft_substr.c \
		ft_radix_sort.c \
		ft_check_input.c \
		ft_harcoded_sort.c \
		ft_node_movements.c \
		ft_node_movements_dup.c 

#------------------------------------------------------------------------------#

# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)

#------------------------------------------------------------------------------#

# Colores para el make
RESET = \033[0m
GREEN = \033[92m
CYAN = \033[96m
RED = \033[91m
BOLD_GREEN = \033[1;32m
BOLD_RED = \033[1;31m

#------------------------------------------------------------------------------#

# Reglas del make (no tocar)

# $@ -> nombre del objetivo (en este caso, el nombre del ejecutable)
all: $(NAME)
	@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡$(NAME) compilado con exito!!! (⌐■_■)$(RESET)"

# La regla $(NAME) compila el ejecutable con los archivos objeto creados 
$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)Objetos creados!$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $@ $^

# La regla %.o compila los archivos objeto
$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# La regla $(OBJDIR) crea el directorio de los archivos objeto
$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos...$(RESET)"
	mkdir $(OBJDIR)
	@echo "$(GREEN)Directorio de objetos creado!$(RESET)"
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

# La regla git agrega, hace commit y hace push
git:
	git add .
	git status
	@read -p "Quieres continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
		@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡Git push realizado!!! (⌐■_■)$(RESET)"; \
	else \
		echo "$(BOLD_RED)(҂◡_◡) ¡¡¡Git push no realizado!!! (҂◡_◡)!!!$(RESET)"; \
	fi

# La regla test ejecuta el script de prueba
test: re
	@echo "$(CYAN)Copiando $(NAME) a la carpeta de prueba...$(RESET)"
	cp $(NAME) test/
	@echo "$(CYAN)Ejecutando el comando push_swap_test.sh...$(RESET)"
	cd test; ./push_swap_test.sh

# La regla valgrind ejecuta valgrind en el ejecutable
valgrind: re
	@echo "$(CYAN)Ejecutando Valgrind en $(NAME)...$(RESET)"
	valgrind --leak-check=full ./$(NAME) 2 1 3 6 5 8

# La regla 'run' ejecuta todas las pruebas
run: re run5 run6 run10 run50 run100 run500

run5 run6 run10 run50 run100 run500:
	@NUM=$$(echo $@ | grep -o -E '[0-9]+'); \
	echo "$(CYAN)Ejecutando $(NAME) con $$NUM numeros...$(RESET)"; \
	ARG=`ruby -e "puts (1..$$NUM).to_a.shuffle.join(' ')"`; \
	echo "Lista de numeros: $$ARG"; \
	RESULT=$$(./$(NAME) $$ARG | tee /dev/tty | wc -l); echo $$((RESULT - (($$NUM * 2) + 6)))
	@read -p "Presione enter para continuar con el siguiente test o Ctrl+C para cancelar..."

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean o re
.PHONY: all clean fclean re test valgrind run run5 run6 run10 run50 run100 run500 git

#------------------------------------------------------------------------------#