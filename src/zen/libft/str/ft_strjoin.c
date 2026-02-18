/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:33 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 18:04:22 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/**
 * Join two strings
 *
 * @param s1 First string to join
 * @param s2 Second string to join
 * @returns On success, a pointer to the joined string
 * @returns On fail, an empty pointer
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	str = calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	memcpy(str, s1, s1_len);
	memcpy(str + s1_len, s2, s2_len);
	return (str);
}
