/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mturk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:13:00 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/24 11:27:58 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	mturk(t_stack *stack)
{
	int	i_cheapest;
	int	d;

	pb(stack);
	pb(stack);
	while (stack->size_a > 3)
	{
		i_cheapest = find_cheapest(stack);
		move_to_top(stack, i_cheapest);
		d = move_correct_index_b(stack, stack->stack_a[0]);
		if (d < 0)
			rotate_to_sort_b(stack);
		else
			move_to_top_b(stack, d);
		pb(stack);
	}
	sort_three(stack);
	push_to_a(stack, d);
	rotate_to_sort_a(stack);
}

void	push_to_a(t_stack *stack, int d)
{
	while (stack->size_b > 0)
	{
		d = move_correct_index_a(stack, stack->stack_b[0]);
		if (d < 0)
			rotate_to_sort_a(stack);
		else
			move_to_top(stack, d);
		pa(stack);
	}
}

int	n_moves_total(t_stack *stack, int i)
{
	int	n_pos_rot;
	int	n_neg_rot;
	int	n_moves;

	n_pos_rot = i;
	n_neg_rot = stack->size_a - i;
	n_moves = move_correct_index_b(stack, stack->stack_a[i]);
	if (n_moves == stack->size_b)
		n_moves = 1;
	if (n_moves > stack->size_b / 2)
		n_moves = stack->size_b - n_moves + 1;
	if (n_pos_rot < n_neg_rot)
		n_moves += n_pos_rot;
	else
		n_moves += n_neg_rot;
	return (n_moves);
}

int	find_cheapest(t_stack *stack)
{
	int	i;
	int	min_mv;
	int	min_i;

	i = 0;
	min_mv = n_moves_total(stack, i);
	min_i = i;
	while (++i < stack->size_a)
	{
		if (n_moves_total(stack, i) < min_mv)
		{
			min_mv = n_moves_total(stack, i);
			min_i = i;
			if (min_mv == 1)
				return (min_i);
		}
	}
	return (min_i);
}

void	move_to_top(t_stack *stack, int index)
{
	if (index <= stack->size_a / 2)
		while (index-- > 0)
			ra(stack);
	else
		while (index++ < stack->size_a)
			rra(stack);
}
