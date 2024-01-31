/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_harcoded_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:39 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 00:21:55 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	ft_hardcoded_size_two(t_list *stack_a)
{
	return ((ft_swap(&stack_a)),*stack_a);
}

static t_list	ft_hardcoded_size_three(t_list *stack_a, t_list *stack_b)
{
	t_list	lowest_node;

	lowest_node = ft_check_lowest_number(stack_a);
	if (lowest_node.content == stack_a->content)
		ft_push(&stack_a, &stack_b);
	else if (lowest_node.content == stack_a->next->content)
	{
		ft_swap(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->content)
	{
		ft_rotate_down(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	ft_hardcoded_size_two(stack_a);
	ft_push(&stack_b, &stack_a);
	return (*stack_a);
}

static t_list	ft_hardcoded_size_four(t_list *stack_a, t_list *stack_b)
{
	t_list	lowest_node;

	lowest_node = ft_check_lowest_number(stack_a);
	if (lowest_node.content == stack_a->content)
		ft_push(&stack_a, &stack_b);
	else if (lowest_node.content == stack_a->next->content)
	{
		ft_swap(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->content)
	{
		ft_rotate_down(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->next->content)
	{
		ft_rotate_up(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	ft_hardcoded_size_three(stack_a, stack_b);
	ft_push(&stack_b, &stack_a);
	return (*stack_a);
}

static t_list	ft_hardcoded_size_five(t_list *stack_a, t_list *stack_b)
{
	t_list	lowest_node;

	lowest_node = ft_check_lowest_number(stack_a);
	if (lowest_node.content == stack_a->content)
		ft_push(&stack_a, &stack_b);
	else if (lowest_node.content == stack_a->next->content)
	{
		ft_swap(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->content)
	{
		ft_rotate_down(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->next->content)
	{
		ft_rotate_up(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	else if (lowest_node.content == stack_a->next->next->next->next->content)
	{
		ft_rotate_up(&stack_a);
		ft_rotate_up(&stack_a);
		ft_push(&stack_a, &stack_b);
	}
	ft_hardcoded_size_four(stack_a, stack_b);
	ft_push(&stack_b, &stack_a);
	return (*stack_a);
}

t_list	ft_hardcoded(t_list **stack_a, t_list **stack_b, int lst_size)
{
	if (lst_size == 2)
		return (ft_hardcoded_size_two(*stack_a));
	else if (lst_size == 3)
		return (ft_hardcoded_size_three(*stack_a, *stack_b));
	else if (lst_size == 4)
		return (ft_hardcoded_size_four(*stack_a, *stack_b));
	else if (lst_size == 5)
		return (ft_hardcoded_size_five(*stack_a, *stack_b));
	return (**stack_a);
}
