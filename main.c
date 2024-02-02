/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/02/02 12:41:26 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_check_ordered_yet(&stack_a) == 1)
			return (0);
		if (ft_lstsize(stack_a) <= 5)
			ft_hardcoded(&stack_a, &stack_b, ft_lstsize(stack_a));
		if (ft_lstsize(stack_a) > 5)
			ft_radix(&stack_a, &stack_b);
	}
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
