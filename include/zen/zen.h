/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 02:30:25 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_H
# define ZEN_H

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct zen_s
{
	GLFWwindow	*window;

}				t_zen;

/**
 * Log a message to the console / zen_engine_logs.txt
 *
 * @param is_game If the log message comes from the game
 * @param log_level The log level - (0) INFO - (1) WARNING - (2) ERROR
 * @param log_msg The log message
 * @return The number of bytes written
 */
size_t	zen_log(size_t is_game, size_t log_level, const char *log_msg);

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
