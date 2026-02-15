/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:41:28 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 21:03:16 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Destroy a window
 *
 * Issue a warning in the console if window is NULL
 * The window was likely already destroyed
 *
 * @param window The window to destroy
 *
 * @return 1 on success, 0 if the window was NULL
 */
size_t	destroy_window(GLFWwindow *window)
{
	if (!window)
	{
		zen_log(1, "destroy_window(): window is NULL");
		return (0);
	}
	glfwDestroyWindow(window);
	return (1);
}
