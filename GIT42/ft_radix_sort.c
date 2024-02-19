/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:51 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/19 17:45:38 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index_nodes(t_list **stack)
{
	int		lst_size;
	int		index;
	t_list	*temp;
	t_list	*aux;
	int		i;

	i = -1;
	lst_size = ft_lstsize(*stack);
	temp = (*stack);
	while (++i < lst_size)
	{
		index = 0;
		aux = (*stack);
		while (aux)
		{
			if (temp->content > aux->content)
				temp->index = ++index;
			aux = aux->next;
		}
		temp = temp->next;
	}
}

static int	ft_bitwise(int lst_size)
{
	int	i;

	i = 0;
	while ((lst_size - 1) >> i != 0)
	{
		i++;
	}
	return (i);
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	lst_size;

	lst_size = ft_lstsize(*stack_a);
	i = 0;
	ft_index_nodes(stack_a);
	while (i < ft_bitwise(lst_size))
	{
		j = 0;
		while (j < lst_size)
		{
			if (((*stack_a)->index >> i & 1) == 1)
				ft_rotate_up(stack_a, "ra\n");
			else if (((*stack_a)->index >> i & 1) == 0)
				ft_push(stack_a, stack_b, "pb\n");
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_push(stack_b, stack_a, "pa\n");
		i++;
	}
}
