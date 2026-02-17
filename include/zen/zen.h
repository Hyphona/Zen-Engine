/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/17 12:33:00 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_H
# define ZEN_H

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct zen_s
{
	GLFWwindow	*window;

}				t_zen;

/**
 * Game logging method
 *
 * @param mode info (0), warning (1), error (2)
 * @param msg The message to log
 * @returns On success, the number of bytes written
 * @returns On error, 0
 */
size_t	game_log(size_t mode, char *msg);

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
t_zen	*zen_init(int width, int height, char *title, int f_screen);

/**
 * Working on it
 */
size_t	zen_loop(t_zen *zen);

/**
 * Terminate Zen Engine
 *
 * Issue a warning in the console if t_zen is NULL
 *
 * @param zen A t_zen object
 */
void	zen_terminate(t_zen *zen);

#endif
