/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:26 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/14 13:32:10 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

GLFWwindow	*create_window(size_t w, size_t h, char *t, size_t fs)
{
	GLFWwindow	*window;

	if (!fs)
	{
		window = glfwCreateWindow(w, h, t, NULL, NULL);
		return (window);
	}
	window = glfwCreateWindow(w, h, t, glfwGetPrimaryMonitor(), NULL);
	return (window);
}
