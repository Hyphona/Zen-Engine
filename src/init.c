/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:21 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/14 12:43:16 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

static size_t	check(size_t w, size_t h, char *t)
{
	if (!w)
	{
		zen_log(2, "zen_init(w, ..., ...): Missing width parameter");
		return (0);
	}
	if (!h)
	{
		zen_log(2, "zen_init(..., h, ...): Missing height parameter");
		return (0);
	}
	if (!t)
		zen_log(1, "zen_init(..., ..., t): Missing title parameter");
	return (1);
}

t_zen	*zen_init(size_t w, size_t h, char *t, size_t fs)
{
	t_zen	*zen;

	if (!check(w, h, t))
	{
		zen_log(2, "Can't init Zen Engine!");
		return (NULL);
	}
	zen = malloc(sizeof(t_zen));
	if (!zen)
	{
		zen_log(2, "Failed to malloc t_zen struct");
		return (NULL);
	}
	return (zen);
}
