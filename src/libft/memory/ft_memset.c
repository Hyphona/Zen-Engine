/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:27:17 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:21:45 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Fills the first n bytes of the memory area pointed by s with the constant byte c
 *
 * Returns a pointer to the memory area s
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ps;

	if (n == 0)
		return (s);
	i = 0;
	ps = (char *) s;
	while (i < n)
	{
		ps[i] = (char) c;
		i++;
	}
	return (s);
}
