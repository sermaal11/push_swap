/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_harcoded_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:39 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 23:33:06 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_hardcoded_size_three se hace lo siguiente:
1.	Se busca el numero mas bajo de la lista.
2.	Si el numero mas bajo es el primer nodo, se rota hacia arriba, se compara
	los dos primeros nodos y si el primero es mayor que el segundo, se 
	intercambian. Para finalizar, se rota hacia abajo.
3.	Si el numero mas bajo es el segundo nodo, se rota hacia abajo, se compara
	los dos primeros nodos y si el primero es mayor que el segundo, se 
	intercambian. Para finalizar, se rota hacia abajo.
4.	Si el numero mas bajo es el tercer nodo, se compara los dos primeros nodos 
	y si el primero es mayor que el segundo, se intercambian. Para finalizar,
	se rota hacia abajo.
*/
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

/*
En ft_hardcoded_size_four se hace lo siguiente:
1.	Se busca el numero mas bajo de la lista.
2.	Si el numero mas bajo es el primer nodo, se mueve el primer nodo a la lista
	stack_b.
3.	Si el numero mas bajo es el segundo nodo, se intercambian los dos primeros 
	nodos y se mueve el primer nodo a la lista stack_b.
4.	Si el numero mas bajo es el tercer nodo, se rota hacia abajo dos veces y se 
	mueve el primer nodo a la lista stack_b.
5.	Si el numero mas bajo es el cuarto nodo, se rota hacia abajo y se mueve el
	primer nodo a la lista stack_b.
6.	Se llama a ft_hardcoded_size_three.
7.	Se mueve el primer nodo de la lista stack_b a la lista stack_a.
*/
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

/*
En ft_hardcoded_size_five se hace lo siguiente:
1.	Se busca el numero mas bajo de la lista.
2.	Si el numero mas bajo es el primer nodo, se mueve el primer nodo a la lista
	stack_b.
3.	Si el numero mas bajo es el segundo nodo, se intercambian los dos primeros 
	nodos y se mueve el primer nodo a la lista stack_b.
4.	Si el numero mas bajo es el tercer nodo, se llama a ft_jariskan.
5.	Si el numero mas bajo es el cuarto nodo, se rota hacia abajo dos veces y se 
	mueve el primer nodo a la lista stack_b.
6.	Si el numero mas bajo es el quinto nodo, se rota hacia abajo y se mueve el 
	primer nodo a la lista stack_b.
7.	Se llama a ft_hardcoded_size_four.
8.	Se mueve el primer nodo de la lista stack_b a la lista stack_a.
*/
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

/*
En se hace lo siguiente:
1.	Si la lista tiene tamaño 2, se ordena mediante ft_swap.
2.	Si la lista tiene tamaño 3, 4 o 5, llama a la funcion correspondiente.
*/
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
