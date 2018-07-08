/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:47:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 14:26:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"
#include <math.h>

double	cone_get_distance(t_object *object, t_ray ray)
{
	t_coefficients	coef;
	t_vec_3			oc;
	t_cone			*cone;

	cone = (t_cone *)object->figure;
	oc = ray.pos - object->pos;
	coef.a = vec_dot_product(ray.dir, ray.dir) -
		(1 + cone->tg_half_angle * cone->tg_half_angle) *
		SQR(vec_dot_product(cone->axis, ray.dir));
	coef.b = (vec_dot_product(oc, ray.dir) -
		(1 + cone->tg_half_angle * cone->tg_half_angle) *
		vec_dot_product(cone->axis, ray.dir) *
		vec_dot_product(cone->axis, oc)) * 2;
	coef.c = vec_dot_product(oc, oc) -
		(1 + cone->tg_half_angle * cone->tg_half_angle) *
		SQR(vec_dot_product(cone->axis, oc));
	return (first_hit_distance(coef));
}

t_vec_3	cone_get_normal(t_object *object, t_vec_3 hitpoint)
{
	double	m;
	t_cone	*cone;

	cone = (t_cone *)object->figure;
	m = (vec_dot_product(hitpoint, cone->axis) -
		vec_dot_product(object->pos, cone->axis)) /
		vec_dot_product(cone->axis, cone->axis);
	return (vec_normalize(hitpoint - object->pos -
		vec_mul_scal(cone->axis, m) -
		vec_mul_scal(cone->axis, m * SQR(cone->tg_half_angle))));
}

void	*new_cone(t_vec_3 axis, double angle)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	cone->axis = axis;
	cone->tg_half_angle= tan(angle / 2);
	return (cone);
}
