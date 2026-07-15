/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:35:22 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 07:35:36 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_update_max(t_square curr, int size, t_square *max)
{
	if (size > max->size)
	{
		max->size = size;
		max->r = curr.r;
		max->c = curr.c;
	}
}
