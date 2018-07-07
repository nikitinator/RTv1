/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:26:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 11:54:18 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

static t_coefficients	cylinder_get_coefficients(t_object *object, t_ray ray)
{
	t_vec_3			oc;		//TODO find a name(ray_to_obj_center)
	t_coefficients	coeff;
	t_cylinder			*cylinder;

	cylinder = (t_cylinder *)object->figure;

	oc = ray.pos - object->pos;
	coeff.a = vec_dot_product(ray.dir, ray.dir) -
		SQR(vec_dot_product(cylinder->axis, ray.dir));
	coeff.b = (vec_dot_product(oc, ray.dir) - 
		vec_dot_product(cylinder->axis, ray.dir) * 
		vec_dot_product(cylinder->axis, oc)) *
		2;
	coeff.c = vec_dot_product(oc, oc) -
		SQR(vec_dot_product(cylinder->axis, oc)) - 
		SQR(cylinder->radius);
	return (coeff);
}

double		cylinder_get_distance(t_object *object, t_ray ray)
{
	double			d;	
	t_coefficients	coef;
	//t_cylinder			*cylinder;

	coef = cylinder_get_coefficients(object, ray);
	d = SQR(coef.b) - 4 * coef.a * coef.c;
	if (d > 0)
		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
	return (0);
}

t_vec_3				cylinder_get_normal(t_object *object, t_vec_3 hitpoint)
{
	t_cylinder			*cylinder;

	cylinder = (t_cylinder *)object->figure;
	double	m = (vec_dot_product(hitpoint, cylinder->axis) -
				vec_dot_product(object->pos, cylinder->axis)) /
				vec_dot_product(cylinder->axis, cylinder->axis); //name dat shet
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
