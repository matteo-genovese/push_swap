/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:05 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/10 15:22:24 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	i = -1;
	if (len < ft_strlen(s) - start)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!str || !s)
		return (NULL);
	while (++i < len && i < ft_strlen(s) && s[i + start])
		str[i] = s[i + start];
	str[i] = '\0';
	return (str);
}
