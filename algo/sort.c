/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:07:30 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/18 22:23:40 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	solve(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a == 4)
		sort_four(stack);
	else if (stack->size_a == 5)
		sort_five(stack);
	else
		mturk(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[0] < stack->stack_a[2])
		sa(stack);
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[0] > stack->stack_a[2])
	{
		if (stack->stack_a[1] < stack->stack_a[2])
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[0] > stack->stack_a[2])
		rra(stack);
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[0] < stack->stack_a[2]
		&& stack->stack_a[1] > stack->stack_a[2])
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_four(t_stack *stack)
{
	int	i;
	int	min;
	int	i_min;

	i = -1;
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
		if (i_min < stack->size_a / 2)
			ra(stack);
		else
			rra(stack);
	}
	pb(stack);
	sort_three(stack);
	pa(stack);
}

void	sort_five(t_stack *stack)
{
	int	i;
	int	min;
	int	i_min;

	i = -1;
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
		if (i_min < stack->size_a / 2)
			ra(stack);
		else
			rra(stack);
	}
	pb(stack);
	sort_four(stack);
	pa(stack);
}
