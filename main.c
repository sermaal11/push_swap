/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 12:26:20 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_print_stack(t_list *lst, char c)
// {
// 	t_list	*current;
// 	int		count;

// 	current = lst;
// 	count = 0;
// 	printf("\nstack %c\n\n", c);
// 	while (current != NULL)
// 	{
// 		printf("nodo %d -> Value %d\n", count, current->content);
// 		current = current->next;
// 		count++;
// 	}
// 	printf("\n");
// }


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
		// ft_print_stack(stack_a, 'a');
		if (ft_lstsize(stack_a) <= 5)
			ft_hardcoded(&stack_a, &stack_b, ft_lstsize(stack_a));
		// ft_print_stack(stack_a, 'a');
	}
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
