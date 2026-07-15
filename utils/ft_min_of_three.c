/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_of_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buoksuz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:01:00 by buoksuz           #+#    #+#             */
/*   Updated: 2026/07/15 11:01:22 by buoksuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_min_of_three(int a, int b, int c)
{
	int min;

	if (a < b)
		min = a;
	else
		min = b;
	if (c < min)
		min = c;
	return (min);
}
