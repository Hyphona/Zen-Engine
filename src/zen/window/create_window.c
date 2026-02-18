/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:26 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 00:48:40 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Adjust the viewport when the user resize the window
 */
void	framebuffer_size_callback(GLFWwindow *window, int w, int h)
{
	(void) window;
	glViewport(0, 0, w, h);
}

/**
 * Create a window and init GLAD, if anything fails GLFW will be terminated
 *
 * @param w The window width (in pixel)
 * @param h The window height (in pixel)
 * @param t The window title
 * @param f_screen If the window should be fullscreen or not
 *	- 0 Not in fullscreen
 *	- 1 In fullscreen
 *
 * @return A GLFWwindow object on success, NULL if it fails
 */
GLFWwindow	*create_window(int w, int h, char *t, int f_screen)
{
	GLFWwindow	*window;

	if (!f_screen)
		window = glfwCreateWindow(w, h, t, NULL, NULL);
	else
		window = glfwCreateWindow(w, h, t, glfwGetPrimaryMonitor(), NULL);
	if (!window)
	{
		zen_log(0, 2, "create_window(): Failed");
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		zen_log(0, 2, "create_window(): Failed to init GLAD");
		destroy_window(window);
		return (NULL);
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, w, h);
	return (window);
}
