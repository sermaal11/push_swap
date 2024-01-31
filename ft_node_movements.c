/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:47 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/31 18:24:40 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta funcion me realiza las operaciones de sa y sb
// Falta ss, que hace sa y sb a la vez

void	ft_swap(t_list **stack)
{
	int	temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
	return ;
}

// Esta funcion me realiza las operaciones de pa y pb

void	ft_push(t_list **source, t_list **destination)
{
	t_list	*temp;

	if (*source != NULL)
	{
		temp = *source;
		*source = (*source)->next;
		temp->next = *destination;
		*destination = temp;
	}
}

// Esta funcion me realiza las operaciones de ra y rb
// Falta rr, que hace ra y rb a la vez

void	ft_rotate_up(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
	}
}

// Esta funcion me realiza las operaciones de rra y rrb
// Falta rrr, que hace rra y rrb a la vez

void	ft_rotate_down(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
	}
}
