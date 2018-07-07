/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:42 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/06 20:19:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//double		x1;	
//double		x2;	
//
//x1 = (-coef.b - sqrt(d)) / (2.0 * coef.a);
//x2 = (-coef.b + sqrt(d)) / (2.0 * coef.a);
//return ((x1 < x2) ? x1 : x2);

//static double		get_parameter(t_coefficients coef)
//{
//	double		d;	
//
//	d = SQR(coef.b) - 4 * coef.a * coef.c;
//	if (d > 0)
//		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
//	return (0);
//}	

t_hit			ray_trace(t_ray ray, t_object *object)
{
	t_hit		hit;
	double		parameter;
	double		min_parameter;

	parameter = 0;
	min_parameter = 0;
	ft_bzero(&hit, sizeof(t_hit));
	while(object)
	{
		parameter = object->get_parameter(object, ray);
		if (parameter > 0 && (parameter < min_parameter || !hit.obj))
		{
			hit.obj = object;
			min_parameter = parameter;	
		}
		object = object->next;
	}
	if (hit.obj)
		hit.pnt = ray.pos + vec_mul_scal(ray.dir, min_parameter);
	return (hit);
}
