/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:41:14 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/16 00:51:59 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_ENGINE_H
# define ZEN_ENGINE_H

# include "zen.h"
# include <string.h>

GLFWwindow	*create_window(int w, int h, char *t, size_t fs);
size_t		destroy_window(GLFWwindow *window);
char		*ft_strjoin(const char *s1, const char *s2);
void		process_close_input(t_zen *zen);
size_t		zen_log(size_t mode, char *msg);

#endif
