/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/01/30 19:45:11 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	current = lst;
	count = 0;
	while (current != NULL)
	{
		printf("nodo %d -> Memdir %p -> Value %d\n", count, &current->content, current->content);
		current = current->next;
		count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	//t_list	stack_b;

	stack_a = NULL;
	if (argc > 1)
	{
		ft_check_input(argc, argv, &stack_a);
	}
	else
		ft_error();
	ft_stack_clear(&stack_a);
	//ft_stack_clear(&stack_b);
	
	// Funciones de control
	ft_lstsize(stack_a);
	system("leaks -q push_swap");
	return (0);
}
