/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:30:47 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 20:40:55 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Create a log node
 *
 * @param msg The log message
 * @returns On success, a pointer to a t_log_node object
 * @returns On fail, a null pointer
 */
t_log_node	*create_log_node(char *msg)
{
	t_log_node	*new;

	if (!msg)
		return (NULL);
	new = malloc(sizeof(t_log_node));
	if (!new)
		return (NULL);
	new->msg = msg;
	new->next = NULL;
	return (new);
}

/**
 * Add a log node to the queue
 *
 * @param head The address of the head pointer
 * @param new A pointer to the new t_log_node entry
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
 * @param head The address of the head pointer
 */
void	remove_from_log_queue(t_log_node **head)
{
	t_log_node	*tmp;

	if (!*head)
		return ;
	free((*head)->msg);
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
