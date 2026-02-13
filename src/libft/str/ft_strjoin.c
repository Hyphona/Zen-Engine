/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:55:43 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:20:13 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The static method that actually join s1 and s2
 */
static char	*join(char const *s, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		j++;
		i++;
	}
	return (s);
}

/**
 * Join the string s1 and s2
 *
 * On success, the joined string s is returned
 * On error, NULL is returned
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	return (join(s, s1, s2));
}
