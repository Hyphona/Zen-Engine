/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/15 12:36:06 by Hyphona          ###   ########.fr       */
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

size_t	game_log(size_t mode, char *msg);
t_zen	*zen_init(size_t w, size_t h, char *t, size_t fs);
size_t	zen_terminate(t_zen *zen);

#endif
