/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:21:54 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 23:47:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_substr se hace lo siguiente:
1.	Se inicializan las variables i y s_len.
2.	Se comprueba si s es NULL.
3.	Si start es mayor o igual que s_len, len es igual a 0.
4.	Si start + len es mayor que s_len, len es igual a s_len - start.
5.	Se reserva memoria para sub_s.
6.	Se recorre la cadena s y se copia en sub_s.
7.	Se retorna sub_s.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub_s;	

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
