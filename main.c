/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 00:30:55 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_list *lst, char c)
{
	t_list	*current;
	int		count;

	current = lst;
	count = 0;
	printf("stack %c\n\n", c);
	while (current != NULL)
	{
		printf("nodo %d -> Memdir %p -> Value %d\n",
			count, &current->content, current->content);
		current = current->next;
		count++;
	}
	printf("\n");
}

// Prueba de swap
// ft_print_stack(stack_a, 'a');
// ft_swap(&stack_a);
// ft_print_stack(stack_a, 'a');

// Prueba de push
// ft_print_stack(stack_a, 'a');
// ft_print_stack(stack_b, 'b');
// ft_push(&stack_a, &stack_b);
// ft_print_stack(stack_a, 'a');
// ft_print_stack(stack_b, 'b');
// ft_push(&stack_a, &stack_b);
// ft_print_stack(stack_a, 'a');
// ft_print_stack(stack_b, 'b');

// Prueba de rotate_up
// ft_print_stack(stack_a, 'a');
// ft_rotate_up(&stack_a);
// ft_print_stack(stack_a, 'a');

// Prueba de rotate_down
// ft_print_stack(stack_a, 'a');
// ft_rotate_down(&stack_a);
// ft_print_stack(stack_a, 'a');

// ! Tengo problemas con los siguientes inputs:
// ! 1.	./push_swap 2 1 30 20 15
// ! OUTPUT: 2, 1, 20, 30 -> Pierdo 1 nodo
// ! 2.	./push_swap 23 45 34 12 42
// ! OUTPUT: 23, 42, 34 -> Pierdo 2 nodos
// ! Pero este input me lo ordena bien
// ! ./push_swap 2 1 3 6 5
// ! OUTPUT: 1, 2, 3, 5, 6

/*
En main se hace lo siguiente:
1.	Se crea una lista stack_a vacia.
2.	Se crea una lista stack_b vacia.
3.	Se comprueba que el numero de argumentos sea mayor que 1.
4.	Se comprueba que los argumentos sean numeros validos mediante ft_check_input
	y se añaden a la lista stack_a.
5.	Se comprueba si la lista esta ordenada mediante ft_check_ordered_yet.
6.	Se comprueba si el tamaño de la lista es menor o igual a 5. Si es asi, se
	ordena mediante ft_hardcoded.
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
		ft_print_stack(stack_a, 'a');
		if (ft_lstsize(stack_a) <= 5)
			ft_hardcoded(&stack_a, &stack_b, ft_lstsize(stack_a));
		ft_print_stack(stack_a, 'a');
	}
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
