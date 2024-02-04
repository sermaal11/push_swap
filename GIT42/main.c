/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:42 by sergio            #+#    #+#             */
/*   Updated: 2024/02/04 21:01:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
