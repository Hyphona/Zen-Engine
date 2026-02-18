/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:41:14 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/18 00:36:57 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_ENGINE_H
# define ZEN_ENGINE_H

# include "zen/zen.h"
# include <string.h>

char		*build_log_line(size_t from, size_t log_level, const char *msg);
GLFWwindow	*create_window(int w, int h, char *t, int f_screen);
void		destroy_window(GLFWwindow *window);
char		*ft_strjoin(const char *s1, const char *s2);
void		process_close_input(t_zen *zen);

#endif
