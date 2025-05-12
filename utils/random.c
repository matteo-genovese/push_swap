/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:35:36 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/20 10:30:46 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

static void	ft_aux(size_t *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
}

int	*ft_split_int(char const *s, char c)
{
	size_t	i[3];
	int		*split;
	char	*str;

	if (!s)
		return (NULL);
	split = (int *)malloc((ft_count_words(s, c) + 1) * sizeof(int));
	if (!split)
		return (NULL);
	ft_aux(i);
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			++i[0];
		if (s[i[0]])
		{
			i[1] = i[0];
			while (s[i[0]] != c && s[i[0]])
				(i[0])++;
			str = ft_substr(s, i[1], i[0] - i[1]);
			split[++(i[2])] = ft_atoi(str);
			free(str);
		}
	}
	return (split);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

int	get_min(int *arr)
{
	if (arr[1] < 0)
		arr[1] = arr[1] * -1;
	if (arr[0] > arr[1])
		return (arr[1]);
	return (arr[0]);
}
