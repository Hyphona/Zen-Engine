/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:38:47 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/16 01:31:44 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

size_t	zen_loop(t_zen *zen)
{
	if (!zen)
	{
		zen_log(2, "zen_loop(): t_zen struct is NULL");
		return (0);
	}
	while (!glfwWindowShouldClose(zen->window))
	{
		process_close_input(zen);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(zen->window);
		glfwPollEvents();
	}
	return (1);
}
