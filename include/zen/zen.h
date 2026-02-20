/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 19:24:23 by Hyphona          ###   ########.fr       */
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

t_zen		*init_zen(void);
void		zen_log(size_t log_level, char *msg);
GLFWwindow	*create_window(int w, int h, char *t, int f_screen);
size_t		zen_loop(t_zen *zen);
void		zen_terminate(t_zen *zen);

#endif
