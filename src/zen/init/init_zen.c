/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hyphona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:35:44 by Hyphona           #+#    #+#             */
/*   Updated: 2026/02/19 13:43:27 by Hyphona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zen/zen_engine.h"

/**
 * Init Zen Engine
 *
 * @returns A pointer to the t_zen structure
 * @returns An empty pointer if it fails
 */
t_zen	*init_zen(void)
{
	t_zen	*zen;

	zen = malloc(sizeof(t_zen));
	if (!zen)
	{
		write(0, "init_zen(): Couldn't init Zen Engine\n", 37);
		return (NULL);
	}
	zen->window = NULL;
	return (zen);
}
