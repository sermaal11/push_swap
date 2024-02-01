/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:19:37 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 23:46:22 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En count_words se hace lo siguiente:
1.	Se inicializan las variables i y count a 0.
2.	Se recorre la cadena s y si el caracter es distinto de c, se incrementa 
	count y se recorre la cadena hasta que el caracter sea igual a c.
3.	Si el caracter es igual a c, se incrementa i.
4.	Se retorna count.	
*/
static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

/*
En get_init_len se hace lo siguiente:
1.	Se inicializa la variable i a 0.
2.	Se recorre la cadena s y si el caracter es distinto de '\0' y distinto de c,
	se incrementa i.
3.	Se retorna i.
*/
static size_t	get_init_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

/*
En free_memory se hace lo siguiente:
1.	Mientras i sea mayor que 0, se decrementa i.
2.	Se libera la memoria de la cadena str.
*/
static void	free_memory(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(*(str + i));
	}
	free(str);
}

/*
En to_split se hace lo siguiente:
1.	Se inicializan las variables row y col a 0.
2.	Se recorre la cadena s y si el caracter es distinto de '\0' y distinto de c,
	se incrementa col.
3.	Se reserva memoria para la cadena str.
4.	Se recorre la cadena s y si el caracter es distinto de '\0' y distinto de c,
	se incrementa col.
5.	Se incrementa row.
6.	Se iguala el ultimo elemento de la cadena str a NULL.
7.	Se retorna str.
*/
static char	**to_split(const char *s, char c, char **str, size_t w_count)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < w_count)
	{
		while (*(s + col) != '\0' && *(s + col) == c)
		{
			col++;
		}
		*(str + row) = ft_substr(s, col, get_init_len(&*(s + col), c));
		if (*(str + row) == NULL)
		{
			free_memory(row, str);
			return (NULL);
		}
		while (*(s + col) != '\0' && *(s + col) != c)
		{
			col++;
		}
		row++;
	}
	*(str + row) = NULL;
	return (str);
}

/*
En ft_split se hace lo siguiente:
1.	Se inicializa la variable words con el numero de palabras que hay en la 
	cadena s.
2.	Se reserva memoria para la cadena str.
3.	Se llama a to_split para dividir la cadena s en subcadenas y se retorna 
	str.
4.	Se retorna str.
*/
char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = to_split(s, c, str, words);
	return (str);
}
