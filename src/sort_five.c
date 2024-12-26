/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:41:32 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 16:41:34 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_node **a, int min_data)
{
	int		pos;
	t_node	*temp;
	int		len;

	pos = 0;
	temp = *a;
	len = stack_len(*a);
	while (temp && temp->data != min_data)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= len / 2)
		ra(a, false);
	else
		rra(a, false);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min;

	if (*a == NULL)
		return ;
	min = find_min(*a);
	while (stack_len(*a) > 3)
	{
		while ((*a)->data != min->data)
		{
			rotate_to_min(a, min->data);
		}
		pb(b, a, false);
		min = find_min(*a);
	}
	sort_three(a);
	while (stack_len(*b))
		pa(a, b, false);
}

/**************Light_Version*************/
/*void sort_five (t_node **a, t_node **b)
{
	t_node	*min;

    min = find_min(*a);
    
    while(stack_len(*a) > 3)
    {
    while ((*a)->data != min->data )
    {
        rra(a, false);
    }
    pb(b,a,false);
    min = find_min(*a);
    }
    sort_three(a);
    while(stack_len(*b))
        pa(a, b, false);
}
*/
