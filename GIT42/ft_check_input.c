/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/02/04 21:05:28 by sergio           ###   ########.fr       */
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

int	ft_check_duplicates(int content, t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->content == content)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_check_ordered_yet(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	ft_stack_clear(stack_a);
	return (1);
}

int	ft_check_lowest_number(t_list *stack_a)
{
	t_list	*current;
	int		lowest_number;

	current = stack_a;
	lowest_number = INT_MAX;
	while (current != NULL)
	{
		if (current->content < lowest_number)
			lowest_number = current->content;
		current = current->next;
	}
	return (lowest_number);
}

void	ft_check_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		y;
	char	**matrix;

	i = 0;
	while (++i != argc)
	{
		matrix = ft_split(argv[i], ' ');
		y = -1;
		if (matrix[0] == NULL)
			ft_error();
		while (matrix[++y] != NULL)
		{
			ft_check_string(matrix[y]);
			if ((ft_atol(matrix[y]) == 0
					&& ((matrix[y][0] != '-' || matrix[y][0] != '+')
				&& matrix[y][1] != '0')) && matrix[y][0] != '0')
				ft_error();
			if (ft_atol(matrix[y]) > INT_MAX || ft_atol(matrix[y]) < INT_MIN)
				ft_error();
			ft_add_number_to_node(ft_atol(matrix[y]), stack_a);
			free(matrix[y]);
		}
		free(matrix);
	}
}
