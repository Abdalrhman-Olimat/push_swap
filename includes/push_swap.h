/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:54:18 by aeleimat          #+#    #+#             */
/*   Updated: 2024/11/04 17:54:39 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>  //for max_int and min_int
# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	struct t_node	*next;
	struct t_node	*prev;
}					t_node;

long				ft_atol(const char *str);
void				*ft_calloc(size_t n_elem, size_t size);
void				*ft_memset(void *s, int c, size_t n);
//***Handle errors
int					error_syntax(char *str_n);
int					error_duplicate(t_node *a, int n);
void				free_stack(t_node **stack);
void				free_errors(t_node **a, int flag, char **argv);
//***Stack initiation
void				init_stack_a(t_node **a, char **argv, int flag);
char				**split(char *s, char c);
//sort thee
void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b);
void				sort_big(t_node **a, t_node **b);
//stack utiles
bool				stack_sorted(t_node *stack);
int					stack_len(t_node *stack);
t_node				*find_max(t_node *stack);
t_node				*find_last(t_node *stack);
t_node				*find_min(t_node *stack);

//command
void				sa(t_node **a, bool print);
void				sb(t_node **b, bool print);
void				ss(t_node **a, t_node **b, bool print);

void				ra(t_node **a, bool print);
void				rb(t_node **b, bool print);
void				rr(t_node **a, t_node **b, bool print);

void				rra(t_node **a, bool print);
void				rrb(t_node **b, bool print);
void				rrr(t_node **a, t_node **b, bool print);

void				pa(t_node **a, t_node **b, bool print);
void				pb(t_node **b, t_node **a, bool print);
///
void				free_split(char **array);
////big sort
int					findmidvalue(int *array, int size);
int					findchunksize(int *arr, int val);
void				reversearray(int *array, int size);
int					findchunksize2(int *arr, int start, int size, int val);
int					*chunk_counter(int *sorted_arr, int size, int *chunk_count);
bool				stack_sorted_descending(t_node *stack);
void				bubble_sort(int *sortedArray, int size);
void				copy_to_sorted_array(t_node *head, int **sortedArray);
void				free_mid_point_algo2(int *stack, int *k);
int					findmidvalue2(int *array, int size);
#endif
