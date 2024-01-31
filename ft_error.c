/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:06:02 by sergio            #+#    #+#             */
/*   Updated: 2024/01/31 23:59:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_error se hace lo siguiente:
1.	Se escribe "Error" en la salida de error estandar.
2.	Se sale del programa.
*/
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
