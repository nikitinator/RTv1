/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:42 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 16:31:10 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define EPS 0.0000000000001 //in C file wow

t_hit			ray_trace(t_ray ray, t_object *object)
{
	t_hit		hit;
	double		distance;
	double		min_distance;

	distance = 0;
	min_distance = 0;
	ft_bzero(&hit, sizeof(t_hit));
	while (object)
	{
		distance = object->get_distance(object, ray);
		if (distance > 0 && (distance < min_distance || !hit.obj))
		{
			hit.obj = object;
			min_distance = distance;
		}
		object = object->next;
	}
	if (hit.obj)
		hit.pnt = ray.pos + vec_mul_scal(ray.dir, min_distance - EPS);
	return (hit);
}
