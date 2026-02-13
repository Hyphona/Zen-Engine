/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:52:53 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/13 15:46:24 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_H
# define ZEN_H

# include <GLFW/glfw3.h>
# include <glad/glad.h> 

typedef struct zen_s
{
	GLFWwindow	*window;

}				t_zen;

ssize_t	zen_log(size_t mode, char *msg);
ssize_t	game_log(size_t mode, char *msg);

#endif
