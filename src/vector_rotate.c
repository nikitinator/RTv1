/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:16:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 14:38:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_3.h"
#include <math.h>

t_vec_3	vector_rotate_x(t_vec_3 v, double angle)
{
	t_vec_3 result;

	result[X] = v[X];
	result[Y] = v[Y] * cos(angle) - v[Z] * sin(angle);
	result[Z] = v[Y] * sin(angle) + v[Z] * cos(angle);
	return (result);
}

t_vec_3	vector_rotate_y(t_vec_3 v, double angle)
{
	t_vec_3 result;

	result[X] = v[Z] * sin(angle) + v[X] * cos(angle);
	result[Y] = v[Y];
	result[Z] = v[Z] * cos(angle) - v[X] * sin(angle);
	return (result);
}

t_vec_3	vector_rotate_z(t_vec_3 v, double angle)
{
	t_vec_3 result;

	result[X] = v[X] * cos(angle) - v[Y] * sin(angle);
	result[Y] = v[X] * sin(angle) + v[Y] * cos(angle);
	result[Z] = v[Z];
	return (result);
}
