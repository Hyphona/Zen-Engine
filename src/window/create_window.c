/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:26 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 21:04:26 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Create a window and init GLAD, if anything fails GLFW will be terminated
 *
 * @param w The window width (in pixel)
 * @param h The window height (in pixel)
 * @param t The window title
 * @param fs If the window should be fullscreen or not
 *	- 0 Not in fullscreen
 *	- 1 In fullscreen
 *
 * @return A GLFWwindow object on success, NULL if it fails
 */
GLFWwindow	*create_window(size_t w, size_t h, char *t, size_t fs)
{
	GLFWwindow	*window;

	if (!fs)
		window = glfwCreateWindow(w, h, t, NULL, NULL);
	else
		window = glfwCreateWindow(w, h, t, glfwGetPrimaryMonitor(), NULL);
	if (!window)
	{
		zen_log(2, "create_window(): Failed");
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	zen_log(2, "create_window(): Failed to init GLAD");
		destroy_window(window);
		glfwTerminate();
    	return (NULL);
	}
	glViewport(0, 0, w, h);
	return (window);
}
