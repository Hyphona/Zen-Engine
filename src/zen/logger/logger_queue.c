/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:30:47 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/23 17:04:51 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Remove the first node from the queue
 *
 * This method always succeed
 *
 * @param head The address of the pointer to the first node of the queue
 */
static void	update_log_queue(t_log_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->next;
}

/**
 * Create a 't_log_node' struct
 *
 * @param lvl The log level as 'char *'
 * @param msg The log message
 * @returns On success, a pointer to a 't_log_node' struc
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
		write(1, "create_log_node() Failed to allocate memory\n", 44);
		return (NULL);
	}
	new->lvl = lvl;
	new->msg = msg;
	new->next = NULL;
	return (new);
}

/**
 * Add a 't_log_node' struct to the queue
 *
 * This method always succeed
 *
 * @param head The address of the pointer to the first node of the queue
 * @param new A pointer to the new 't_log_node' struct entry
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
 * Pop the first node from the queue
 *
 * Aka: Return the first node of the queue & put the next node as 'head'
 * The popped node needs to be 'free()' when you're done with it
 *
 * @param head The address of the pointer to the first node of the queue
 * @return A pointer to a 't_log_node' struct
 */
t_log_node	*pop_from_log_queue(t_log_node **head)
{
	t_log_node	*node;

	if (!*head)
		return (NULL);
	node = *head;
	update_log_queue(head);
	return (node);
}
