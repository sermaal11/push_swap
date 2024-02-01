/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_movements_dup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:09:54 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/01 23:41:11 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_swap_ss se hace lo siguiente:
1.	Se llama a ft_swap con stack_a.
2.	Se llama a ft_swap con stack_b.
3.	Se escribe "ss\n" en la salida estandar.
*/
void	ft_swap_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, NULL);
	ft_swap(stack_b, NULL);
	write(1, "ss\n", 3);
}

/*
EN ft_rotate_up_rr se hace lo siguiente:
1.	Se llama a ft_rotate_up con stack_a.
2.	Se llama a ft_rotate_up con stack_b.
3.	Se escribe "rr\n" en la salida estandar.
*/
void	ft_rotate_up_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_up(stack_a, NULL);
	ft_rotate_up(stack_b, NULL);
	write(1, "rr\n", 3);
}

/*
En ft_rotate_down_rrr se hace lo siguiente:
1.	Se llama a ft_rotate_down con stack_a.
2.	Se llama a ft_rotate_down con stack_b.
3.	Se escribe "rrr\n" en la salida estandar.
*/
void	ft_rotate_down_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_down(stack_a, NULL);
	ft_rotate_down(stack_b, NULL);
	write(1, "rrr\n", 4);
}
