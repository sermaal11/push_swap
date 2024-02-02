/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/02/02 01:58:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! ELIMINAR ESTA FUNCION!
static void	print_bits(int value)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (value >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	printf("\n");
}

// ! ELIMINAR ESTA FUNCION!
void	ft_print_stack_info(t_list *lst, char c)
{
	t_list	*current;
	int		count;

	current = lst;
	count = 0;
	printf("stack %c\n", c);
	while (current != NULL)
	{
		printf("nodo %d -> Content %d -> Index %d -> Index.bits ",
			count, current->content, current->index);
		fflush(stdout);
		print_bits(current->index);
		current = current->next;
		count++;
	}
	printf("\n");
}

/*
En el main se hace lo siguiente:
1.	Se crea una lista stack_a vacia.
2.	Se crea una lista stack_b vacia.
3.	Se comprueba que el numero de argumentos sea mayor que 1.
4.	Se comprueba que los argumentos sean numeros validos mediante ft_check_input
	y se añaden a la lista stack_a.
5.	Se comprueba si la lista esta ordenada mediante ft_check_ordered_yet.
6.	Se comprueba si el tamaño de la lista es menor o igual a 5. Si es asi, se
	ordena mediante ft_hardcoded.
7.	Se comprueba si el tamaño de la lista es mayor a 5. Si es asi, se ordena
	mediante ft_radix.
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		ft_check_input(argc, argv, &stack_a);
		if (ft_check_ordered_yet(&stack_a) == 0)
			return (0);
		if (ft_lstsize(stack_a) <= 5)
			ft_hardcoded(&stack_a, &stack_b, ft_lstsize(stack_a));
		if (ft_lstsize(stack_a) > 5)
			ft_radix(&stack_a);
	}
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
