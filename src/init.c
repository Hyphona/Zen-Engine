/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:21 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 13:16:18 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

static size_t	check(size_t w, size_t h, char *t)
{
	if (!w)
	{
		zen_log(2, "zen_init(): Missing width parameter\n");
		return (0);
	}
	if (!h)
	{
		zen_log(2, "zen_init(): Missing height parameter\n");
		return (0);
	}
	if (!t)
	{
		zen_log(2, "zen_init(): Missing title parameter\n");
		return (0);
	}
	return (1);
}

t_zen	*zen_init(size_t w, size_t h, char *t, size_t fs)
{
	t_zen	*zen;

	if (!check(w, h, t))
		return (NULL);
	zen = malloc(sizeof(t_zen));
	if (!zen)
	{
		zen_log(2, "Failed to malloc t_zen struct\n");
		return (NULL);
	}
	zen->window = create_window(w, h, t, fs);
	if (!zen->window)
	{
		zen_log(2, "Failed to create the window\n");
		free(zen);
		return (NULL);
	}
	return (zen);
}
