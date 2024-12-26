/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:45 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 16:40:47 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	printstack(t_node **a)
{
	t_node	*cu;

	cu = *a;
	while (cu != NULL)
	{
		printf("%d\n", cu->data);
		cu = cu->next;
	}
}*/
void	call_a_sorting_algo(t_node **a, t_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 5 || stack_len(*a) == 4)
		sort_five(a, b);
	else
		sort_big(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		flag;

	b = NULL;
	a = NULL;
	flag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		flag = 1;
	}
	init_stack_a(&a, argv + 1, flag);
	if (!stack_sorted(a))
		call_a_sorting_algo(&a, &b);
	free_stack(&a);
	if (flag == 1)
		free_split(argv);
}
/*
printf("print stack A\n");
printstack(&a);
printf("\n");
printf("print stack B\n");
printstack(&b);
*/
