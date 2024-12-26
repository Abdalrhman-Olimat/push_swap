/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:28 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 16:40:37 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_node **head, int x)
{
	t_node	*new_node;
	t_node	*cu;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		write(1, "Failed to allocate memory\n",
			sizeof("Failed to allocate memory\n"));
		exit(EXIT_FAILURE);
	}
	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		cu = *head;
		while (cu->next != NULL)
		{
			cu = cu->next;
		}
		cu->next = new_node;
		new_node->prev = cu;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 11)
		return (1);
	else
		return (0);
}

void	init_stack_a(t_node **a, char **argv, int flag)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, flag, argv - 1);
		if (ft_strlen(argv[i]))
			free_errors(a, flag, argv - 1);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, flag, argv - 1);
		if (error_duplicate(*a, (int)n))
			free_errors(a, flag, argv - 1);
		append_node(a, (int)n);
		i++;
	}
}
