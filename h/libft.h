/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:46:10 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/11 11:50:38 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_count_words(char const *str, char c);

#endif
