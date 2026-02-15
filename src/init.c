/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:39:21 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 20:59:01 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Check the zen_init() method parameters
 *
 * @param w The window width
 * @param h The window height
 * @param t The window title
 *
 * @returns 1 on success, 0 if it fails
 */
static size_t	check_params(size_t w, size_t h, char *t)
{
	if (!w || !h || !t)
	{
		if (!w)
			zen_log(2, "zen_init(): Missing width parameter");
		else if (!h)
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
 * @param w The window width (in pixel)
 * @param h The window height (in pixel)
 * @param t The window title
 * @param fs If the window should be fullscreen or not
 *	- 0 Not in fullscreen
 *	- 1 In fullscreen
 *
 * @returns A t_zen object on success, NULL if it fails
 */
t_zen	*zen_init(size_t w, size_t h, char *t, size_t fs)
{
	t_zen	*zen;

	if (!check_params(w, h, t))
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
	zen->window = create_window(w, h, t, fs);
	if (!zen->window)
	{
		free(zen);
		return (NULL);
	}
	return (zen);
}
