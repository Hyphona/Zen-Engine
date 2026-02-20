/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:30:47 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/20 19:22:08 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Create a t_log_node structure that contain a pointer to the log message
 *
 * @param lvl The log level as 'char *'
 * @param msg The log message
 * @returns On success, a pointer to a t_log_node structure
 * @returns On fail, a null pointer
 */
t_log_node	*create_log_node(char *lvl, char *msg)
{
	t_log_node	*new;

	if (!msg)
	{
		log_e("create_log_node() Null pointer 'msg'");
		return (NULL);
	}
	new = malloc(sizeof(t_log_node));
	if (!new)
	{
		log_e("create_log_node() Failed to allocate memory");
		return (NULL);
	}
	new->lvl = lvl;
	new->msg = msg;
	new->next = NULL;
	return (new);
}

/**
 * Add a t_log_node structure to the queue
 *
 * This method always succeed
 *
 * @param head The address of the first node of queue
 * @param new A pointer to the new t_log_node structure entry
 */
void	add_to_log_queue(t_log_node **head, t_log_node *new)
{
	t_log_node	*current;

	if (!*head)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

/**
 * Remove the first node from the queue
 *
 * This method always succeed
 *
 * @param head The address of the first node of queue
 */
void	remove_from_log_queue(t_log_node **head)
{
	t_log_node	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
