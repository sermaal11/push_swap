/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/18 17:31:40 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! Si me da un 0 el atoi, como lo diferencio de un 0 real de entrada de un error

void	ft_check_input(int argc, char **argv)
{
	int i;
	int y;
	char **matrix;
	int input;

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
