/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:27 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 12:49:59 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fills the first n bytes of the memory area s with null characters
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
