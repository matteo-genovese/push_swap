/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mturk_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:20:35 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/20 16:35:58 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

int	move_correct_index_a(t_stack *stack, int num)
{
	int	i;
	int	n;
	int	i_n;

	i = -1;
	while (++i < stack->size_a)
	{
		if (num < stack->stack_a[i])
			break ;
	}
	if (i == stack->size_a)
		return (-1);
	n = stack->stack_a[i];
	i_n = i;
	while (++i < stack->size_a)
	{
		if (stack->stack_a[i] < n && stack->stack_a[i] > num)
		{
			n = stack->stack_a[i];
			i_n = i;
		}
	}
	return (i_n);
}

int	n_moves_stack_a(t_stack *stack, int num)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < stack->size_a && num > stack->stack_a[i])
		++i;
	j = stack->size_a - 1;
	c = 0;
	while (j > 0 && num < stack->stack_a[j])
	{
		--j;
		++c;
	}
	if (i <= c)
		return (i);
	return (c * -1);
}

void	rotate_to_sort_a(t_stack *stack)
{
	int	min;
	int	i;
	int	i_min;

	i = 0;
	min = stack->stack_a[0];
	i_min = 0;
	while (++i < stack->size_a)
	{
		if (stack->stack_a[i] < min)
		{
			min = stack->stack_a[i];
			i_min = i;
		}
	}
	while (stack->stack_a[0] != min)
	{
		if (i_min <= stack->size_a / 2)
			ra(stack);
		else
			rra(stack);
	}
}
