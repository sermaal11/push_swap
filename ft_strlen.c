/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:11:36 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 23:47:16 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_strlen se hace lo siguiente:
1.	Se inicializa la variable i a 0.
2.	Se recorre la cadena str y se incrementa i hasta que el caracter sea igual 
	a '\0'.
3.	Se retorna i.
*/
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
