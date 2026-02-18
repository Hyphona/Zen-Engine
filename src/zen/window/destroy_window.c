/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:41:28 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 02:32:11 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Destroy a window and terminate GLFW
 *
 * Issue a warning in the console if window is NULL
 * The window was likely already destroyed
 *
 * @param window The window to destroy
 *
 * @return 1 on success, 0 if the window was NULL
 */
void	destroy_window(GLFWwindow *window)
{
	if (!window)
		zen_log(0, 1, "destroy_window(): window is NULL");
	else
		glfwDestroyWindow(window);
	glfwTerminate();
}
