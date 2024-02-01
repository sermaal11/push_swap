/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:51 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 20:40:52 by smarin-a         ###   ########.fr       */
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

void	ft_radix(t_list **stack)
{
	ft_index_nodes(stack);
	
}
