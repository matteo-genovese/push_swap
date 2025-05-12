/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:27:00 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/24 11:23:00 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

int		check_num(char **argv, int k);
int		check_doubles(char **argv, int k);
int		final_check(int argc, char **argv);
int		check_empty(char **argv, int k);
int		check_min_max(char *str);
int		check_valid_str(char *str);

void	free_split(char **split, int k);
void	copy_argv(char **argv, int argc, char **temp);
int		*ft_split_int(char const *s, char c);

void	print_argv(char **argv, int argc);

void	free_stack(t_stack *stack);
void	copy_stack(char **argv, int argc, int *temp);
void	init_stack(int argc, char **argv, t_stack *stack);
int		is_sorted(int *arr, int size);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	solve(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);

void	mturk(t_stack *stack);
int		move_correct_index_b(t_stack *stack, int num);
int		get_min(int *arr);
int		n_moves_total(t_stack *stack, int i);
int		find_cheapest(t_stack *stack);
void	move_to_top(t_stack *stack, int i);
void	rotate_to_sort_b(t_stack *stack);
int		move_correct_index_a(t_stack *stack, int num);
int		n_moves_stack_a(t_stack *stack, int num);
void	rotate_to_sort_a(t_stack *stack);
void	move_to_top_b(t_stack *stack, int index);
void	push_to_a(t_stack *stack, int d);
int		get_n_min_stack_b(t_stack *stack);

#endif
