/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:41:28 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 13:16:38 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

size_t	destroy_window(t_zen *zen)
{
	if (!zen)
	{
		zen_log(2, "destroy_window() - t_zen struct is NULL\n");
		return (0);
	}
	if (!zen->window)
	{
		zen_log(1, "destroy_window() - No window to destroy\n");
		return (1);
	}
	glfwDestroyWindow(zen->window);
	return (1);
}
