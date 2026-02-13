/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:23:07 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 12:55:28 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *str);

#endif