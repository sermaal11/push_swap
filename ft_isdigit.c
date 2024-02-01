/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:08:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 23:33:47 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_isdigit se hace lo siguiente:
1.	Se comprueba si el char c es un digito.
2. 	Se devuelve 1 si es un digito, 0 si no lo es.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
