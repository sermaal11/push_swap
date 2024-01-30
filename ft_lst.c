/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:20 by sergio            #+#    #+#             */
/*   Updated: 2024/01/30 18:29:38 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicates(int content, t_list **stack_a)
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

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

void	ft_add_number_to_node(int num, t_list **stack_a)
{
	t_list	*new_node;
	int	duplicate;
	
	duplicate = ft_check_duplicates(num, stack_a);
	if (duplicate == 1)
		ft_error();
	new_node = ft_lstnew(num);
	ft_lstadd_back(stack_a, new_node);
}
