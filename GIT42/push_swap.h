/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:28:20 by sergio            #+#    #+#             */
/*   Updated: 2024/02/04 21:02:39 by sergio           ###   ########.fr       */
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
	int		index;
	t_list	*next;
}	t_list;

char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_lstsize(t_list *lst);
void	ft_add_number_to_node(int num, t_list **stack_a);
void	ft_check_input(int argc, char **argv, t_list **stack_a);
int		ft_check_duplicates(int content, t_list **stack_a);
int		ft_check_ordered_yet(t_list **stack_a);
int		ft_check_lowest_number(t_list *stack_a);
void	ft_swap(t_list **stack, char *str);
void	ft_push(t_list **source, t_list **destination, char *str);
void	ft_rotate_up(t_list **stack, char *str);
void	ft_rotate_down(t_list **stack, char *str);
void	ft_hardcoded(t_list **stack_a, t_list **stack_b, int lst_size);
void	ft_error(void);
void	ft_stack_clear(t_list **stack);
void	ft_swap_ss(t_list **stack_a, t_list **stack_b);
void	ft_rotate_up_rr(t_list **stack_a, t_list **stack_b);
void	ft_rotate_down_rrr(t_list **stack_a, t_list **stack_b);
void	ft_radix(t_list **stack, t_list **stack_b);

#endif