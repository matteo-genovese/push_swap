/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:56:08 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/15 19:32:35 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_a < 2)
		return ;
	i = stack->size_a - 1;
	temp = stack->stack_a[i];
	while (i--)
		stack->stack_a[i + 1] = stack->stack_a[i];
	stack->stack_a[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_b < 2)
		return ;
	i = stack->size_b - 1;
	temp = stack->stack_b[i];
	while (i--)
		stack->stack_b[i + 1] = stack->stack_b[i];
	stack->stack_b[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr_fd("rrr\n", 1);
}
