/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:42:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/03 10:28:05 by snikitin         ###   ########.fr       */
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

double      vec_dot_product(t_vec_3 a, t_vec_3 b)
{
    return (a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z]);
}

t_vec_3		vec_cross_product(t_vec_3 a, t_vec_3 b)
{
	t_vec_3	result;
	
	result[X]= a[Y] * b[Z] - a[Z] * b[Y];
	result[Y]= a[Z] * b[X] - a[X] * b[Z];
	result[Z]= a[X] * b[Y] - a[Y] * b[X];
	return (result);
}

double		vec_magnitude(t_vec_3 a)
{
	return (sqrt(SQR(a[X]) + SQR(a[Y]) + SQR(a[Z])));
}

t_vec_3		vec_normalize(t_vec_3 v)
{
	return (vec_div_scal(v, vec_magnitude(v)));
}
