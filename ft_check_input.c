/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/18 20:54:12 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Validación de input:

// - Solo números enteros
//     - Es decir solo negativos, 0 y positivos dentro del max_int y min_int
//     - No numeros duplicados
// - Si no hay parametros de entrada, sin mensaje de error y exit(1).
// ! Como lo diferencio de un 0 real de entrada de un error
// chekear cosas pegaditas despues de los numerso como "4f "o "56yhu"cd
// Chekar que no acabe en signo, ejemplo: "+5 6 -7 -"

void	ft_check_input(int argc, char **argv)
{
	int		i;
	int		y;
	char	**matrix;
	int		input;

	i = argc - 1;
	while (i > 0)
	{
		matrix = ft_split(argv[i], ' ');
		y = 0;
		while (matrix[y] != NULL)
		{
			input = ft_atoi(matrix[y]);
			if (input == 0)
				ft_error();
			y++;
		}
		i--;
	}
}
