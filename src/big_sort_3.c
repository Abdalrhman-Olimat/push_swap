/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:44:57 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 17:45:00 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmidvalue2(int *array, int size)
{
	if (size <= 0)
		return (-1);
	return (array[size / 4]);
}

bool	stack_sorted_descending(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	bubble_sort(int *sortedArray, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sortedArray[j] > sortedArray[j + 1])
			{
				temp = sortedArray[j];
				sortedArray[j] = sortedArray[j + 1];
				sortedArray[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	copy_to_sorted_array(t_node *head, int **sortedArray)
{
	int		size;
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	size = stack_len(head);
	while (current != NULL && i < size)
	{
		(*sortedArray)[i] = current->data;
		current = current->next;
		i++;
	}
	bubble_sort(*sortedArray, size);
}

void	free_mid_point_algo2(int *stack, int *k)
{
	free(stack);
	free(k);
}
