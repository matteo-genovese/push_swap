/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:14 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/19 11:11:02 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (!final_check(argc, argv))
	{
		if (argc > 1)
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	init_stack(argc, argv, &stack);
	if (is_sorted(stack.stack_a, stack.size_a))
	{
		free_stack(&stack);
		return (0);
	}
	solve(&stack);
	free_stack(&stack);
	return (0);
}
