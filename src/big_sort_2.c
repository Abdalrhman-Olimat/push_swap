/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:44:50 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 17:44:53 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmidvalue(int *array, int size)
{
	if (size <= 0)
		return (-1);
	return (array[size / 2]);
}

int	findchunksize(int *arr, int val)
{
	int	i;

	i = 0;
	while (arr[i] != val)
		i++;
	return (i);
}

void	reversearray(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		i++;
	}
}

int	findchunksize2(int *arr, int start, int size, int val)
{
	int	i;

	i = start;
	while (i < size && arr[i] < val)
		i++;
	return (i - start);
}

int	*chunk_counter(int *sorted_arr, int size, int *chunk_count)
{
	int	*chunk_sizes;
	int	start;
	int	midpoint;
	int	chunk_size;

	chunk_sizes = malloc(size * sizeof(int));
	if (!chunk_sizes)
		return (NULL);
	start = 0;
	*chunk_count = 0;
	while (start < size)
	{
		midpoint = findmidvalue(&sorted_arr[start], size - start);
		chunk_size = findchunksize2(sorted_arr, start, size, midpoint);
		if (size - start <= 2)
			break ;
		chunk_sizes[(*chunk_count)++] = chunk_size;
		start += chunk_size;
	}
	reversearray(chunk_sizes, *chunk_count);
	return (chunk_sizes);
}
