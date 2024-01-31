/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_harcoded_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:39 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/31 20:52:22 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	ft_harcoded_size_two(t_list *stack_a)
{
	if (stack_a->content > stack_a->next->content)
		ft_swap(&stack_a);
	return (*stack_a);
}

static t_list	ft_harcoded_size_three(t_list *stack_a, t_list *stack_b)
{
	stack_b = NULL;
	// Si el numero mas bajo esta en la primera posicion llamar a ft_push(&stack_a, &stack_b)
	// Si el numero mas bajo esta en la segunda posicion llamar a ft_swap(&stack_a) y despues a ft_push(&stack_a, &stack_b)
	// Si el numero mas bajo esta en la tercera posicion llamar a ft_rotate_down(&stack_a) y despues a ft_push(&stack_a, &stack_b)
	// Una vez el numero mas bajo esta en el stack_b
	// Llamar a ft_harcoded_size_two
	// LLamar a ft_push(&stack_b, &stack_a);
	return (*stack_a);
}

static t_list	ft_harcoded_size_four(t_list *stack_a, t_list *stack_b)
{
	stack_b = NULL;
	return (*stack_a);
}

static t_list	ft_harcoded_size_five(t_list *stack_a, t_list *stack_b)
{
	stack_b = NULL;
	return (*stack_a);
}

t_list	ft_harcoded(t_list **stack_a, t_list **stack_b, int lst_size)
{
	stack_a = NULL;
	if (lst_size == 2)
		return (ft_harcoded_size_two(*stack_a));
	else if (lst_size == 3)
		return (ft_harcoded_size_three(*stack_a, *stack_b));
	else if (lst_size == 4)
		return (ft_harcoded_size_four(*stack_a, *stack_b));
	else if (lst_size == 5)
		return (ft_harcoded_size_five(*stack_a, *stack_b));
	return (**stack_a);
}
