/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:38:47 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 15:52:17 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen_engine.h"

size_t	zen_loop(t_zen *zen)
{
	if (!zen)
	{
		zen_log(2, "zen_loop(): t_zen struct is NULL");
		return (0);
	}
	while(!glfwWindowShouldClose(zen->window))
	{
    	glfwSwapBuffers(zen->window);
    	glfwPollEvents();    
	}
	return (1);
}
