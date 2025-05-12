/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:11:00 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/10 15:22:36 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
