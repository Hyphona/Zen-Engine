/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:21 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/17 12:32:37 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Check the zen_init() method parameters
 *
 * @param w The window width
 * @param h The window height
 * @param t The window title
 *
 * @returns 1 on success, 0 if it fails
 */
static size_t	check_params(int width, int height, char *title)
{
	if (!width || !height || !title)
	{
		if (!width)
			zen_log(2, "zen_init(): Missing width parameter");
		else if (!height)
			zen_log(2, "zen_init(): Missing height parameter");
		else
			zen_log(2, "zen_init(): Missing title parameter");
		return (0);
	}
	return (1);
}

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
	{
		zen_log(2, "init_glfw(): Failed");
		return (0);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return (1);
}

/**
 * Init the Zen Engine
 *
 * @param width The window width (in pixel)
 * @param height The window height (in pixel)
 * @param title The window title
 * @param f_screen If the window should be fullscreen or not
 *	- 0 Not in fullscreen
 *	- 1 In fullscreen
 *
 * @returns A t_zen object on success, NULL if it fails
 */
t_zen	*zen_init(int width, int height, char *title, int f_screen)
{
	t_zen	*zen;

	if (!check_params(width, height, title))
		return (NULL);
	zen = malloc(sizeof(t_zen));
	if (!zen)
	{
		zen_log(2, "zen_init(): Failed to malloc t_zen struct");
		return (NULL);
	}
	if (!init_glfw())
	{
		free(zen);
		return (NULL);
	}
	zen->window = create_window(width, height, title, f_screen);
	if (!zen->window)
	{
		free(zen);
		return (NULL);
	}
	return (zen);
}
