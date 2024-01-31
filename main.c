/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/01/31 20:35:38 by smarin-a         ###   ########.fr       */
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
			ft_harcoded(&stack_a, &stack_b, ft_lstsize(stack_a));
		ft_print_stack(stack_a, 'a');
	}
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
