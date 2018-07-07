/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:47:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 11:43:52 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

#include <math.h>

static t_coefficients	cone_get_coefficients(t_object *object, t_ray ray)
{
	t_vec_3			oc;		//TODO find a name(ray_to_obj_center)
	t_coefficients	coeff;
	t_cone			*cone;

	cone = (t_cone *)object->figure;
	oc = ray.pos - object->pos;
	coeff.a = vec_dot_product(ray.dir, ray.dir) -
		(1 + cone->tg_half_angle * cone->tg_half_angle) * 
		SQR(vec_dot_product(cone->axis, ray.dir));
	coeff.b = (vec_dot_product(oc, ray.dir) - 
		(1 + cone->tg_half_angle * cone->tg_half_angle) * 
		vec_dot_product(cone->axis, ray.dir) * 
		vec_dot_product(cone->axis, oc)) *
		2;
	coeff.c = vec_dot_product(oc, oc) -
		(1 + cone->tg_half_angle * cone->tg_half_angle) * 
		SQR(vec_dot_product(cone->axis, oc)) ;
		//SQR(5);
	return (coeff);
}

double		cone_get_parameter(t_object *object, t_ray ray)
{
	double			d;	
	t_coefficients	coef;
	//t_cone			*cone;

	coef = cone_get_coefficients(object, ray);
	d = SQR(coef.b) - 4 * coef.a * coef.c;
	if (d > 0)
		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
	return (0);
}

t_vec_3				cone_get_normal(t_object *object, t_vec_3 hitpoint)
{
	t_cone			*cone;

	cone = (t_cone *)object->figure;
	double	m = (vec_dot_product(hitpoint, cone->axis) -
				vec_dot_product(object->pos, cone->axis)) /
				vec_dot_product(cone->axis, cone->axis); //name dat shet
	double	a = m * cone->tg_half_angle * cone->tg_half_angle;
	return (vec_normalize(hitpoint - object->pos - vec_mul_scal(cone->axis, m) - 
			vec_mul_scal(cone->axis, a)));
}

void			*new_cone(t_vec_3 axis, double radius, double angle)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	(void)radius;
	//cone->radius = radius;
	cone->axis = axis;
	cone->tg_half_angle= tan(angle / 2);
	return (cone);
}
