/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:12:35 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:19:38 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Calculate the lenght of the string pointed by str
 *
 * Returns the lenght of str, or 0 if NULL
 */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
