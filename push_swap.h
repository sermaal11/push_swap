/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:28:20 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 15:43:06 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list	t_list;

typedef struct s_list
{
	int		content;
	int		index;
	t_list	*next;
}	t_list;

// ft_split divide una cadena en subcadenas usando el char c como delimitador.
char	**ft_split(const char *s, char c);
// ft_substr devuelve una subcadena de la cadena s. La usa ft_split.
char	*ft_substr(const char *s, unsigned int start, size_t len);
// ft_strlen devuelve la longitud de la cadena s.
int		ft_strlen(const char *str);
// ft_isdigit devuelve 1 si el char c es un digito, 0 si no lo es.
int		ft_isdigit(int c);
// ft_atol convierte la cadena str a un long int.
long	ft_atol(const char *str);
// ft_lstsize devuelve el numero de nodos de la lista.
int		ft_lstsize(t_list *lst);
// ft_add_number_to_node añade un numero a un nodo de la lista.
void	ft_add_number_to_node(int num, t_list **stack_a);
// ft_check_input comprueba que los argumentos sean numero.
void	ft_check_input(int argc, char **argv, t_list **stack_a);
// ft_check_duplicates comprueba que no haya numeros repetidos.
int		ft_check_duplicates(int content, t_list **stack_a);
// ft_check_ordered_yet comprueba si la lista esta ordenada.
int		ft_check_ordered_yet(t_list **stack_a);
// ft_check_lowest_number devuelve el nodo con el numero mas bajo.
int		ft_check_lowest_number(t_list *stack_a);
// ft_swap intercambia los dos primeros nodos de la lista.
void	ft_swap(t_list **stack, char *str);
// ft_push mueve el primer nodo de la lista source a la lista destination.
void	ft_push(t_list **source, t_list **destination, char *str);
// ft_rotate_up mueve el primer nodo de la lista al final de la lista.
void	ft_rotate_up(t_list **stack, char *str);
// ft_rotate_down mueve el ultimo nodo de la lista al principio de la lista.
void	ft_rotate_down(t_list **stack, char *str);
// ft_hardcoded ordena la lista de 2 o 5 nodos.
void	ft_hardcoded(t_list **stack_a, t_list **stack_b, int lst_size);
// ft_error imprime "Error" y sale del programa.
void	ft_error(void);
// ft_stack_clear libera la memoria de la lista.
void	ft_stack_clear(t_list **stack);

void	ft_swap_ss(t_list **stack_a, t_list **stack_b);

void	ft_rotate_up_rr(t_list **stack_a, t_list **stack_b);

void	ft_rotate_down_rrr(t_list **stack_a, t_list **stack_b);

void	ft_radix(t_list **stack);

#endif