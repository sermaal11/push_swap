/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/30 14:34:44 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 5  "0 0" Output actual -> 0 0 Numeros repetiddos
// 6  "-01 -001" Output actual -> -1 -1 Numeros repetidos
// 8  "-3 -2 -2" Output actual -> -3 -2 -2 Numeros repetidos
// 13  "8 008 12" Output actual -> 8 8 12 Numeros repetidos
// 14  "10 -1 -2 -3 -4 -5 -6 90 99 10" Output actual ->  10 -1 -2 -3 -4 -5 -6 90 99 10 Numeros repetidos
// 15  "1 +1 -1" Output actual -> 1 1 -1 Numeros repetidos
// 18  "111111 -4 3 03" Output actual -> 111111 -4 3 3 Numeros repetidos
// 21  "0 1 2 3 4 5 0" Output actual -> 0 1 2 3 4 5 0 Numeros repetidos
// 22  "3 +3" Output actual -> 3 3 Numeros repetidos
// 24  "42 42" Output actual -> 42 42 Numeros repetidos
// 25  "42 -42 -42 " Output actual -> 42 -42 -42 Numeros repetidos
// 36  "0000000000000000000000009 000000000000000000000009" Output actual -> 9 9 Numeros repetidos
// 37  "00000001 1 9 3" Output actual -> 1 1 9 3 Numeros repetidos
// 38  "00000003 003 9 1" Output actual -> 3 3 9 1  Numeros repetidos
// 40  "1 01" Output actual -> 1 1 Numeros repetidos
// 42  "-00042 -000042" Output actual -> -42 -42 Numeros repetidos

static void ft_check_string(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[0])
		ft_error();
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			ft_error();
		i++;
	}
}

void	ft_check_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		iy;
	char	**matrix;

	i = 1;
	while (i != argc)
	{
		matrix = ft_split(argv[i], ' ');
		iy = 0;
		if (matrix[iy] == NULL)
			ft_error();
		while (matrix[iy] != NULL)
		{
			ft_check_string(matrix[iy]);
			if (ft_atoi(matrix[iy]) == 0 && matrix[iy][0] != '0')
				ft_error();
			if (ft_atoi(matrix[iy]) > INT_MAX || ft_atoi(matrix[iy]) < INT_MIN)
				ft_error();
			ft_add_number_to_node(ft_atoi(matrix[iy]), stack_a);
			free(matrix[iy]);
			iy++;
		}
		i++;
		free(matrix);
	}
}
