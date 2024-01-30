/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/30 18:29:16 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_string(char *str)
{
	int	i;

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
