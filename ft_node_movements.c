/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:47 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 23:38:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_swap se hace lo siguiente:
1.	Se comprueba si la lista stack no esta vacia y tenga al menos dos nodos.
2.	Si es asi, se intercambian los dos primeros nodos.
3.	Si el string str no es NULL, se escribe en la salida estandar.
*/
void	ft_swap(t_list **stack, char *str)
{
	int	temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
	if (str != NULL)
		write(1, str, 3);
}

/*
En ft_push se hace lo siguiente:
1.	Se comprueba si la lista source no esta vacia.
2.	Si es asi, se mueve el primer nodo de la lista source a la lista 
	destination.
3.	Si el string str no es NULL, se escribe en la salida estandar.
*/
void	ft_push(t_list **source, t_list **destination, char *str)
{
	t_list	*temp;

	if (*source != NULL)
	{
		temp = *source;
		*source = (*source)->next;
		temp->next = *destination;
		*destination = temp;
	}
	if (str != NULL)
		write(1, str, 3);
}

/*
En ft_rotate_up se hace lo siguiente:
1.	Se comprueba si la lista stack no esta vacia y tenga al menos dos nodos.
2.	Si es asi, se mueve el primer nodo de la lista al final de la lista.
3.	Si el string str no es NULL, se escribe en la salida estandar.
*/
void	ft_rotate_up(t_list **stack, char *str)
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
	if (str != NULL)
		write(1, str, 3);
}

/*
En ft_rotate_down se hace lo siguiente:
1.	Se comprueba si la lista stack no esta vacia y tenga al menos dos nodos.
2.	Si es asi, se mueve el ultimo nodo de la lista al principio de la lista.
3.	Si el string str no es NULL, se escribe en la salida estandar.
*/
void	ft_rotate_down(t_list **stack, char *str)
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
	if (str != NULL)
		write(1, str, 4);
}
