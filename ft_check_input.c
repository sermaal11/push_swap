/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/19 15:52:47 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_check_string(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
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
	int		y;
	char	**matrix;

	i = 1;
	while (i != argc)
	{
		matrix = ft_split(argv[i], ' ');
		y = 0;
		while (matrix[y] != NULL)
		{
			ft_check_string(matrix[y]);
			if (ft_atoi(matrix[y]) == 0 && matrix[y][0] != '0')
				ft_error();
			if (ft_atoi(matrix[y]) > INT_MAX || ft_atoi(matrix[y]) < INT_MIN)
				ft_error();
			ft_add_number_to_node(ft_atoi(matrix[y]), stack_a);
			y++;
		}
		i++;
	}
}
