/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:26:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 14:20:25 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

double		cylinder_get_distance(t_object *object, t_ray ray)
{
	t_coefficients	coef;
	t_vec_3			oc;
	t_cylinder		*cylinder;

	oc = ray.pos - object->pos;
	cylinder = (t_cylinder *)object->figure;
	coef.a = vec_dot_product(ray.dir, ray.dir) -
		SQR(vec_dot_product(cylinder->axis, ray.dir));
	coef.b = (vec_dot_product(oc, ray.dir) - 
		vec_dot_product(cylinder->axis, ray.dir) * 
		vec_dot_product(cylinder->axis, oc)) * 2;
	coef.c = vec_dot_product(oc, oc) -
		SQR(vec_dot_product(cylinder->axis, oc)) - 
		SQR(cylinder->radius);
	return (first_hit_distance(coef));
}

t_vec_3				cylinder_get_normal(t_object *object, t_vec_3 hitpoint)
{
	t_cylinder			*cylinder;
	double				m;

	cylinder = (t_cylinder *)object->figure;
	m = (vec_dot_product(hitpoint, cylinder->axis) -
				vec_dot_product(object->pos, cylinder->axis)) /
				vec_dot_product(cylinder->axis, cylinder->axis);
	return (vec_normalize(hitpoint - object->pos - vec_mul_scal(cylinder->axis, m)));
}

void			*new_cylinder(t_vec_3 axis, double radius)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->radius = radius;
	cylinder->axis = axis;
	return (cylinder);
}
