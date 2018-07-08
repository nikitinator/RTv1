/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:47:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 18:57:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"
#include <math.h>

double	cone_get_distance(t_object *object, t_ray ray)
{
	t_vec_3			cone_axis;
	double			u;
	t_vec_3			oc;
	t_coefficients	coef;

	cone_axis = ((t_cone *)object->figure)->axis;
	u = (1 + SQR(((t_cone *)object->figure)->tg_half_angle));
	oc = ray.pos - object->pos;
	coef.a = vec_dot_product(ray.dir, ray.dir) -
		u * SQR(vec_dot_product(cone_axis, ray.dir));
	coef.b = (vec_dot_product(oc, ray.dir) -
		u * vec_dot_product(cone_axis, ray.dir) *
		vec_dot_product(cone_axis, oc)) * 2;
	coef.c = vec_dot_product(oc, oc) -
		u * SQR(vec_dot_product(cone_axis, oc));
	return (first_hit_distance(coef));
}

t_vec_3	cone_get_normal(t_object *object, t_vec_3 hitpoint)
{
	t_vec_3	cone_axis;
	double	m;

	cone_axis = ((t_cone *)object->figure)->axis;
	m = (vec_dot_product(hitpoint, cone_axis) -
		vec_dot_product(object->pos, cone_axis)) /
		vec_dot_product(cone_axis, cone_axis);
	return (vec_normalize(hitpoint - object->pos -
		vec_mul_scal(cone_axis, m) -
		vec_mul_scal(cone_axis, m *
		SQR(((t_cone *)object->figure)->tg_half_angle))));
}

void	*new_cone(t_vec_3 axis, double angle)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	cone->axis = vec_normalize(axis);
	cone->tg_half_angle = tan(angle / 2);
	return (cone);
}
