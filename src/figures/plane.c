/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:10:08 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 14:55:21 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "figures.h"
#include "vector.h"

double	plane_get_discriminant(t_object *object, t_ray ray)
{
	t_vec_3 oc;		//TODO find a name(ray_to_obj_center)
	double 	a;
	double 	b;
	double 	c;

	oc = ray.pos - object.pos;
	a = vec_dot_product(ray.dir, ray.dir);
	b = vec_dot_product(oc, ray.dir) * 2;//poprobui ubrat' zero
	c = vec_dot_product(oc, oc) - SQR(object.radius);
	return (SQR(b) - 4.0 * a * c);
}
