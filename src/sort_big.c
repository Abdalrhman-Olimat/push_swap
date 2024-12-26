/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:45:22 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 17:45:24 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mid_point_algo_help(t_node **a, int midvalue)
{
	int		pos;
	t_node	*temp;

	pos = 0;
	temp = *a;
	while (temp && temp->data >= midvalue)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= stack_len(*a) / 2)
		ra(a, false);
	else
		rra(a, false);
}

void	mid_point_algo(t_node **a, t_node **b, int *s_arr)
{
	int	size;
	int	midvalue;
	int	chunksize;

	size = stack_len(*a);
	copy_to_sorted_array(*a, &s_arr);
	midvalue = findmidvalue2(s_arr, size);
	chunksize = findchunksize(s_arr, midvalue);
	while (chunksize > 0)
	{
		if ((*a)->data < midvalue)
		{
			pb(b, a, false);
			chunksize--;
		}
		else
			mid_point_algo_help(a, midvalue);
	}
}

void	move_to_top(t_node **stack, int target)
{
	int		pos;
	int		size;
	t_node	*temp;

	pos = 0;
	size = stack_len(*stack);
	temp = *stack;
	while (temp && temp->data != target)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack)->data != target)
			rb(stack, false);
	}
	else
	{
		while ((*stack)->data != target)
			rrb(stack, false);
	}
}

void	mid_point_algo2(t_node **a, t_node **b, int chunk_size)
{
	t_node	*max_node;

	while (chunk_size > 0)
	{
		max_node = find_max(*b);
		if (max_node)
		{
			move_to_top(b, max_node->data);
			pa(a, b, false);
		}
		chunk_size--;
	}
}

void	sort_big(t_node **a, t_node **b)
{
	int	*s_arr;
	int	size;
	int	*chunk_co;
	int	chunk_count;
	int	i;

	i = 0;
	size = stack_len(*a);
	s_arr = (int *)malloc(size * sizeof(int));
	if (!s_arr)
		return ;
	copy_to_sorted_array(*a, &s_arr);
	chunk_co = chunk_counter(s_arr, size, &chunk_count);
	while (stack_len(*a) > 3)
		mid_point_algo(a, b, s_arr);
	if (!stack_sorted(*a))
		sort_three(a);
	if (stack_sorted_descending(*b))
		while (*b)
			pb(b, a, false);
	while (chunk_count-- > 0)
		mid_point_algo2(a, b, chunk_co[i++]);
	free_mid_point_algo2(s_arr, chunk_co);
}
