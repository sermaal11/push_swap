/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:16:29 by sergio            #+#    #+#             */
/*   Updated: 2024/02/02 01:11:39 by sergio           ###   ########.fr       */
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

/*
En ft_isdigit se hace lo siguiente:
1.	Se comprueba si el char c es un digito.
2. 	Se devuelve 1 si es un digito, 0 si no lo es.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

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

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			return ((long)INT_MAX + 1);
		i++;
	}
	return (sign * result);
}
