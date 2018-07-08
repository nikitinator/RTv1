/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:26:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 15:43:00 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

double		cylinder_get_distance(t_object *object, t_ray ray)
{
	t_vec_3			cyl_axis;
	t_vec_3			oc;
	t_coefficients	coef;

	cyl_axis = ((t_cylinder *)object->figure)->axis;
	oc = ray.pos - object->pos;
	coef.a = vec_dot_product(ray.dir, ray.dir) -
		SQR(vec_dot_product(cyl_axis, ray.dir));
	coef.b = (vec_dot_product(oc, ray.dir) -
		vec_dot_product(cyl_axis, ray.dir) *
		vec_dot_product(cyl_axis, oc)) * 2;
	coef.c = vec_dot_product(oc, oc) -
		SQR(vec_dot_product(cyl_axis, oc)) -
		SQR(((t_cylinder *)object->figure)->radius);
	return (first_hit_distance(coef));
}

t_vec_3		cylinder_get_normal(t_object *object, t_vec_3 hitpoint)
{
	t_vec_3		cyl_axis;
	double		m;

	cyl_axis = ((t_cylinder *)object->figure)->axis;
	m = (vec_dot_product(hitpoint, cyl_axis) -
		vec_dot_product(object->pos, cyl_axis)) /
		vec_dot_product(cyl_axis, cyl_axis);
	return (vec_normalize(hitpoint - object->pos - vec_mul_scal(cyl_axis, m)));
}

void		*new_cylinder(t_vec_3 axis, double radius)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->radius = radius;
	cylinder->axis = vec_normalize(axis);
	return (cylinder);
}
