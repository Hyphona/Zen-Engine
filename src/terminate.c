/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:49:30 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 13:16:27 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

size_t	zen_terminate(t_zen *zen)
{
	if (!zen)
	{
		zen_log(2, "zen_terminate() - t_zen struct is NULL\n");
		return (1);
	}
	destroy_window(zen);
	free(zen);
	return (1);
}
