/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_movements_dup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:09:54 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 15:14:16 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, NULL);
	ft_swap(stack_b, NULL);
	write(1, "ss\n", 3);
}

void	ft_rotate_up_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_up(stack_a, NULL);
	ft_rotate_up(stack_b, NULL);
	write(1, "rr\n", 3);
}

void	ft_rotate_down_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_down(stack_a, NULL);
	ft_rotate_down(stack_b, NULL);
	write(1, "rrr\n", 4);
}