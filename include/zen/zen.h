/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 20:37:13 by Hyphona          ###   ########.fr       */
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
	GLFWwindow		*window;
}					t_zen;

/**
 * Init Zen Engine
 *
 * @returns A pointer to the t_zen structure
 * @returns An empty pointer if it fails
 */
t_zen	*init_zen(void);

/**
 * Log a message to the console / zen_engine_logs.txt
 *
 * @param log_level The log level - (0) INFO - (1) WARNING - (2) ERROR
 * @param msg The log message
 */
void	zen_log(size_t log_level, const char *msg);

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
GLFWwindow	*create_window(int w, int h, char *t, int f_screen);

/**
 * Working on it
 */
size_t	zen_loop(t_zen *zen);

/**
 * Terminate Zen Engine
 *
 * @param zen A t_zen object
 */
void	zen_terminate(t_zen *zen);

#endif
