/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/01/31 20:48:16 by smarin-a         ###   ########.fr       */
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
			return (1);
		temp = temp->next;
	}
	ft_stack_clear(stack_a);
	return (0);
}

t_list ft_check_lowest_number(t_list *stack_a)
{
	t_list	*current;
	t_list	lowest_number;
	
	current = stack_a;
	lowest_number = *stack_a;
	while (current != NULL)
	{
		if (current->content < lowest_number.content)
			lowest_number = *current;
		current = current->next;
	}
	return (lowest_number);
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
		if (matrix[y] == NULL)
			ft_error();
		while (matrix[y] != NULL)
		{
			ft_check_string(matrix[y]);
			if (ft_atol(matrix[y]) == 0 && matrix[y][0] != '0')
				ft_error();
			if (ft_atol(matrix[y]) > INT_MAX || ft_atol(matrix[y]) < INT_MIN)
				ft_error();
			ft_add_number_to_node(ft_atol(matrix[y]), stack_a);
			free(matrix[y]);
			y++;
		}
		i++;
		free(matrix);
	}
}
