/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:51 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/02 00:08:47 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_index_nodes se hace lo siguiente:
1.	Se inicializan las variables lst_size, index, temp, aux e i.
2.	Se obtiene el tamaño de la lista mediante ft_lstsize.
3.	Se iguala temp a stack.
4.	Se recorre la lista y se iguala index a 0.
5.	Se iguala aux a stack.
6.	Se recorre la lista y si temp->content es mayor que aux->content, 
	se incrementa index.
7.	Se iguala temp->index a index de esta forma se obtiene el indice de 
	cada nodo.
8.	Se iguala temp a temp->next.
*/
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
	ft_print_stack_info(*stack, 'a');
}
