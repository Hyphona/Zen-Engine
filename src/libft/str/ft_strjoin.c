/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:33 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/14 12:39:34 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static char	*ft_join(char *str, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	return (str);
}

/**
 * Join two strings
 *
 * @param s1 First string to join
 * @param s2 Second string to join
 * @returns On success, a pointer to the joined string
 * @returns On error, NULL
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = calloc(sizeof(char), strlen(s1) + strlen(s2) + 1);
	if (!str)
		return (NULL);
	return (ft_join(str, s1, s2));
}
