/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:49:30 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 19:49:27 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Terminate Zen Engine
 *
 * @param zen The Zen Engine structure
 */
void	zen_terminate(t_zen *zen)
{
	if (!zen)
		write(0, "zen_terminate() Null 'zen' pointer\n", 35);
	if (zen->window)
		destroy_window(zen->window);
	terminate_logger();
	free(zen);
}
