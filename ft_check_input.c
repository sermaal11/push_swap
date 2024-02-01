/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:38:40 by sergio            #+#    #+#             */
/*   Updated: 2024/02/01 15:13:51 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En ft_check_string se hace lo siguiente:
1.	Se crea un contador y se inicializa a 0.
2.	Si el primer elemento de la cadena es '+' o '-', se incrementa el contador.
3.	Mediante (!str[0]) se comprueba que el primer elemento de la cadena no sea
	NULL. Si lo es, se imprime "Error" y se sale del programa.
4.	Mediante ft_isdigit se comprueba que los elementos de la cadena sean
	digitos.
*/
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

/*
En ft_check_duplicates se hace lo siguiente:
1.	Mediante el bucle while se comprueba si el numero ya existe en la lista.
2.	Si el numero ya existe, se devuelve un 1.
3.	Si el numero no existe, se devuelve un 0.
*/
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

/*
En ft_add_number_to_node se hace lo siguiente:
1.	Se crea un nodo temporal.
2.	Mediante el bucle while se comprueba si cada numero es mayor que el
	anterior.
3. 	Si devolvemos un 1, significa que la lista no esta ordenada y continuamos
	con el programa.
4.	Si devolvemos un 0, significa que la lista esta ordenada y se sale del
	programa liberando la memoria de la lista mediante ft_stack_clear.
*/
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

/*
En ft_check_lowest_number se hace lo siguiente:
1.	Se crea un nodo current y se inicializa a stack_a.
2.	Se crea un nodo lowest_number y se inicializa a stack_a.
3.	Mediante el bucle while se comprueba si el numero actual es menor que el
	numero mas bajo.
4.	Si el numero actual es menor que el numero mas bajo, se actualiza el numero
	mas bajo.
5.	Se devuelve el numero mas bajo encontrado.
*/
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

/*
En ft_check_input se hace lo siguiente:
1.	Se crea una matriz matrix con los argumentos de argv.
2.	Se crea un contador y se inicializa a 0.
3.	Si el primer elemento de la matriz es NULL, se imprime "Error" y se sale del
	programa.
4.	Se comprueba que los argumentos sean numeros validos mediante 
	ft_check_string.
5.	Se comprueba que los argumentos sean numeros validos mediante ft_atol. Si no
	lo son, se imprime "Error" y se sale del programa.
6. 	Mediane ft_add_number_to_node se añaden los numeros a la lista stack_a.
7.	Se libera la memoria de la matriz.
*/
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
