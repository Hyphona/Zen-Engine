/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:31:50 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/16 00:51:34 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

/**
 * Tell the window that it should close when the close key is pressed
 *
 * @param zen The t_zen struct
 */
void	process_close_input(t_zen *zen)
{
	if (glfwGetKey(zen->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(zen->window, true);
}
