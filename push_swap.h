/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:28:20 by sergio            #+#    #+#             */
/*   Updated: 2024/01/30 18:25:41 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list	t_list;

typedef struct s_list
{
	int		content;
	t_list	*next;
}	t_list;

void	ft_check_input(int argc, char **argv, t_list **stack_a);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_error(void);
int		ft_strlen(const char *str);
int		ft_isdigit(int c);
void	ft_add_number_to_node(int num, t_list **stack_a);

#endif