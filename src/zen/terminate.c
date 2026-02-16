/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:49:30 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/16 01:23:32 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Terminate Zen Engine
 *
 * Issue a warning in the console if t_zen is NULL
 *
 * @param zen A t_zen object
 */
void	zen_terminate(t_zen *zen)
{
	if (!zen)
	{
		zen_log(1, "zen_terminate(): t_zen struct is NULL");
		return ;
	}
	destroy_window(zen->window);
	free(zen);
	glfwTerminate();
}
