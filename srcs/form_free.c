/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:37:25 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/19 14:34:21 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void form_free(t_form **head)
{
	t_form*	prev;

	prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

