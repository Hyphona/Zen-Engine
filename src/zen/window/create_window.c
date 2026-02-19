/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:26 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 01:13:04 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Init GLFW
 *
 * @returns 1 on success, 0 if it fails
 *
 * We can add this to make it works on MacOS:
 *	- glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 */
static size_t	init_glfw(void)
{
	if (glfwInit() == GL_FALSE)
		return (0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return (1);
}

/**
 * Adjust the viewport when the user resize the window
 */
void	framebuffer_size_callback(GLFWwindow *window, int w, int h)
{
	(void) window;
	glViewport(0, 0, w, h);
}

/**
 * Create a window
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

	if (!w || !h || !t)
		return (NULL);
	if (!init_glfw())
		return (NULL);
	if (!f_screen)
		window = glfwCreateWindow(w, h, t, NULL, NULL);
	else
		window = glfwCreateWindow(w, h, t, glfwGetPrimaryMonitor(), NULL);
	if (!window)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		destroy_window(window);
		return (NULL);
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, w, h);
	return (window);
}
