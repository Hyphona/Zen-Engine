/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zen_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:41:14 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 02:09:17 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEN_ENGINE_H
# define ZEN_ENGINE_H

# include "zen/zen.h"
# include <pthread.h>
# include <string.h>

typedef struct log_node_s
{
	char				*msg;
	struct log_node_s	*next;
}						t_log_node;

typedef struct logger_s
{
	pthread_mutex_t		mutex;
	pthread_t			t_id;
	struct log_node_s	*head;
	_Atomic int			stop_flag;
}						t_logger;

void		terminate_logger(void);
t_logger	*get_logger(void);
void		*logger_worker(void *arg);
t_log_node	*create_log_node(char *msg);
void		add_to_log_queue(t_log_node **head, t_log_node *new);
void		remove_from_log_queue(t_log_node **head);
GLFWwindow	*create_window(int w, int h, char *t, int f_screen);
void		destroy_window(GLFWwindow *window);
char		*ft_strjoin(const char *s1, const char *s2);
void		process_close_input(t_zen *zen);

#endif
