/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:45:51 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/15 19:32:19 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack)
{
	int	i;

	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i--)
		stack->stack_a[i + 1] = stack->stack_a[i];
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->size_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i--)
		stack->stack_b[i + 1] = stack->stack_b[i];
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
	ft_putstr_fd("pb\n", 1);
}
