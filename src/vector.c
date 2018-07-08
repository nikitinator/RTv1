/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:42:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 12:45:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vec_3.h"

t_vec_3		vec_mul_scal(t_vec_3 v, double scalar)
{
	return (v * (t_vec_3){scalar, scalar, scalar});
}

t_vec_3		vec_div_scal(t_vec_3 v, double scalar)
{
	if (scalar)
		v /= (t_vec_3){scalar, scalar, scalar};
	return (v);
}

double		vec_dot_product(t_vec_3 a, t_vec_3 b)
{
	return (a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z]);
}

double		vec_magnitude(t_vec_3 a)
{
	return (sqrt(SQR(a[X]) + SQR(a[Y]) + SQR(a[Z])));
}

t_vec_3		vec_normalize(t_vec_3 v)
{
	return (vec_div_scal(v, vec_magnitude(v)));
}
