/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_hit_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:11:51 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 12:23:00 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figures.h"
#include <math.h>

inline double	first_hit_distance(t_coefficients coef)
{
	double	d;

	d = SQR(coef.b) - 4 * coef.a * coef.c;
	if (d > 0)
		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
	return (0);
}
