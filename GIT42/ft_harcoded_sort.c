/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_harcoded_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:39 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/04 21:05:01 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_hardcoded_size_three(t_list **stack_a)
{
	int	lowest_number;

	lowest_number = ft_check_lowest_number(*stack_a);
	if (lowest_number == (*stack_a)->content)
	{
		ft_rotate_up(stack_a, "ra\n");
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_swap(stack_a, "sa\n");
		ft_rotate_down(stack_a, "rra\n");
	}
	else if (lowest_number == (*stack_a)->next->content)
	{
		ft_rotate_down(stack_a, "rra\n");
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_swap(stack_a, "sa\n");
		ft_rotate_down(stack_a, "rra\n");
	}
	else if (lowest_number == (*stack_a)->next->next->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_swap(stack_a, "sa\n");
		ft_rotate_down(stack_a, "rra\n");
	}
}

static void	ft_hardcoded_size_four(t_list **stack_a, t_list **stack_b)
{
	int	lowest_number;

	lowest_number = ft_check_lowest_number(*stack_a);
	if (lowest_number == (*stack_a)->content)
		ft_push(stack_a, stack_b, "pb\n");
	else if (lowest_number == (*stack_a)->next->content)
	{
		ft_swap(stack_a, "sa\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	else if (lowest_number == (*stack_a)->next->next->content)
	{
		ft_rotate_down(stack_a, "rra\n");
		ft_rotate_down(stack_a, "rra\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	else if (lowest_number == (*stack_a)->next->next->next->content)
	{
		ft_rotate_down(stack_a, "rra\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	ft_hardcoded_size_three(stack_a);
	ft_push(stack_b, stack_a, "pa\n");
}

static void	ft_jariskan(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_down(stack_a, "rra\n");
	ft_rotate_down(stack_a, "rra\n");
	ft_rotate_down(stack_a, "rra\n");
	ft_push(stack_a, stack_b, "pb\n");
}

static void	ft_hardcoded_size_five(t_list **stack_a, t_list **stack_b)
{
	int	lowest_number;

	lowest_number = ft_check_lowest_number(*stack_a);
	if (lowest_number == (*stack_a)->content)
		ft_push(stack_a, stack_b, "pb\n");
	else if (lowest_number == (*stack_a)->next->content)
	{
		ft_swap(stack_a, "sa\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	else if (lowest_number == (*stack_a)->next->next->content)
		ft_jariskan(stack_a, stack_b);
	else if (lowest_number == (*stack_a)->next->next->next->content)
	{
		ft_rotate_down(stack_a, "rra\n");
		ft_rotate_down(stack_a, "rra\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	else if (lowest_number == (*stack_a)->next->next->next->next->content)
	{
		ft_rotate_down(stack_a, "rra\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	ft_hardcoded_size_four(stack_a, stack_b);
	ft_push(stack_b, stack_a, "pa\n");
}

void	ft_hardcoded(t_list **stack_a, t_list **stack_b, int lst_size)
{
	if (lst_size == 2)
		ft_swap(stack_a, "sa\n");
	else if (lst_size == 3)
		ft_hardcoded_size_three(stack_a);
	else if (lst_size == 4)
		ft_hardcoded_size_four(stack_a, stack_b);
	else if (lst_size == 5)
		ft_hardcoded_size_five(stack_a, stack_b);
}
