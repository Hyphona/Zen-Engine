/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:42:28 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:51:50 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen.h"

static ssize_t	check_params(size_t w, size_t h, char *t)
{
	if (!w)
	{
		zen_log(2, "zen_init(w, ..., ...): Missing width parameter");
		return (-1);
	}
	if (!h)
	{
		zen_log(2, "zen_init(..., h, ...): Missing height parameter");
		return (-1);
	}
	if (!t)
		zen_log(1, "zen_init(..., ..., t): Missing title parameter");
	return (1);
}

t_zen	*zen_init(size_t w, size_t h, char *t, size_t fs)
{
	t_zen	*zen;

	if (!check_params(w, h, t))
	{
		zen_log(2, "Can't init Zen Engine!");
		return (NULL);
	}
}
