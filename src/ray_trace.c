/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:42 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/15 18:38:04 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double		get_parameter(t_coefficients coef)
{
	double		d;	

	d = SQR(coef.b) - 4 * coef.a * coef.c;
	if (d > 0)
	{
		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
		//x1 = (-coef.b - sqrt(d) / (2.0 * coef.a);
		//x2 = (-coef.b + sqrt(d) / (2.0 * coef.a);
		//return ((x1 < x2) ? x1 : x2);
	}
	return (0);
}	

t_hit			ray_trace(t_ray ray, t_object *object)
{
	t_hit		hit;
	double		parameter;
	double		max_parameter;

	parameter = 0;
	max_parameter = 0;
	ft_bzero(&hit, sizeof(t_hit));
	while(object)
	{
		parameter = get_parameter(object->get_coefficients(object, ray));
		//if (ABS(parameter) > max_parameter)
		if (parameter)
		{
			hit.obj = object;
			max_parameter = parameter;	
			if (hit.obj)
			{
				hit.pnt = vec_mul_scal(ray.dir, max_parameter);
				return (hit);
			}

		}
		object = object->next;
	}
	if (hit.obj)
		hit.pnt = vec_mul_scal(ray.dir, max_parameter);
	return (hit);
}
