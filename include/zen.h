/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:40:59 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/14 12:44:18 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_H
# define ZEN_H

# include <GLFW/glfw3.h>
# include <glad/glad.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct zen_s
{
	GLFWwindow	*window;

}				t_zen;

size_t	game_log(size_t mode, char *msg);

#endif
