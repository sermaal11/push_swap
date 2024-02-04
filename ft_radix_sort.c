/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:51 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/04 00:58:02 by sergio           ###   ########.fr       */
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

/*
En ft_bitwise se hace lo siguiente:
1.	Se inicializa i a 0.
2.	Dentro del bucle while se desplaza el tamaño de la lista - 1 i veces. Esto 
	se hace para obtener el numero de bits necesarios para representar el 
	tamaño de la lista.
3.	Se devuelve i.
*/
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

/*
En ft_radix se hace lo siguiente:
1.	Se inicializan las variables i, j y lst_size.
2.	Se iguala lst_size a ft_lstsize. Esto se hace para obtener el tamaño de la 
	lista.
3.	Se iguala i a 0.
4.	Se llama a ft_index_nodes. Esto se hace para obtener el indice de cada nodo.
5.	Se recorre la lista y se iguala j a 0.
6.	Se recorre la lista y si el bit i del indice del nodo es 1, se llama a 
	ft_rotate_up, si es 0 se llama a ft_push.
7.	Se recorre la lista b y se llama a ft_push hasta que la lista b este vacia.
*/
void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	lst_size;

	lst_size = ft_lstsize(*stack_a);
	i = 0;
	ft_index_nodes(stack_a);
	ft_print_stack_info(*stack_a, 'a');
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
