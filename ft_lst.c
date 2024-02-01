/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:20 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 23:35:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_lstsize se hace lo siguiente:
1.	Se crea un contador y se inicializa a 0.
2.	Mediante el bucle while se recorre la lista y se incrementa el contador.
3.	Se devuelve el contador que sera el tamaño de la lista.
*/
int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	current = lst;
	count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

/*
En ft_lstlast se hace lo siguiente:
1.	Mediante recursividad se recorre la lista hasta llegar al ultimo nodo.
2.	Una vez termina la recursividad debido a que el nodo siguiente es NULL
	libera la memoria del ultimo nodo y lo pone a NULL y asi recursivamente
	hasta llegar al primer nodo y liberar toda la memoria de la lista.
3.	Por ultimo se iguala el puntero de la lista a NULL.
*/
void	ft_stack_clear(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_stack_clear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

/*
En ft_lstnew se hace lo siguiente:
1.	Declaramos un puntero a t_list llamado new_node.
2.	Reservamos memoria para el nuevo nodo.
3.	Comprobamos si la reserva de memoria ha sido correcta.
4.	Si ha sido correcta, inicializamos el contenido del nuevo nodo con el
	numero que le pasamos como argumento y el puntero next a NULL.
5.	Devolvemos el nuevo nodo.
*/
static t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
En ft_lstadd_back se hace lo siguiente:
1.	Declaramos un puntero a t_list llamado current y lo inicializamos al puntero
	de la lista.
2.	Comprobamos si la lista esta vacia. Si lo esta, igualamos el puntero de la
	lista al nuevo nodo.
3.	Si no esta vacia, recorremos la lista hasta llegar al ultimo nodo.
4.	Una vez llegamos al ultimo nodo, igualamos el puntero next del ultimo nodo
	al nuevo nodo.
*/
static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

/*
En ft_add_number_to_node se hace lo siguiente:
1.	Se crea un nodo nuevo.
2.	Comprobamos si el numero ya existe en la lista mediante ft_check_duplicates.
	Si el numero ya existe, se imprime "Error" y se sale del programa.
3.	Se añade el numero al nodo nuevo mediante ft_lstnew.
4.	Se añade el nodo nuevo al final lista mediante ft_lstadd_back.
*/

void	ft_add_number_to_node(int num, t_list **stack_a)
{
	t_list	*new_node;
	int		duplicate;

	duplicate = ft_check_duplicates(num, stack_a);
	if (duplicate == 1)
		ft_error();
	new_node = ft_lstnew(num);
	ft_lstadd_back(stack_a, new_node);
}
