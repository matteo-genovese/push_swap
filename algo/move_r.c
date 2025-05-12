/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:45 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/15 19:32:50 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_a < 2)
		return ;
	i = 0;
	temp = stack->stack_a[0];
	while (i < stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_b < 2)
		return ;
	i = 0;
	temp = stack->stack_b[0];
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}
