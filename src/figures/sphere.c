/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:10:08 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/06 20:30:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

static t_coefficients	sphere_get_coefficients(t_object *object, t_ray ray)
{
	t_vec_3			oc;		//TODO find a name(ray_to_obj_center)
	t_coefficients	coeff;

	oc = ray.pos - object->pos;
	coeff.a = vec_dot_product(ray.dir, ray.dir);
	coeff.b = vec_dot_product(oc, ray.dir) * 2;
	coeff.c = vec_dot_product(oc, oc) - SQR(((t_sphere *)object->figure)->radius);
	return (coeff);
}

double		sphere_get_parameter(t_object *object, t_ray ray)
{
	double			d;	
	t_coefficients	coef;

	coef = sphere_get_coefficients(object, ray);
	d = SQR(coef.b) - 4 * coef.a * coef.c;
	if (d > 0)
		return ((-coef.b - sqrt(d)) / (2.0 * coef.a));
	return (0);
}

t_vec_3				sphere_get_normal(t_object *object, t_vec_3 hitpoint)
{
	return (vec_normalize(hitpoint - object->pos));
}

void			*new_sphere(double	radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->radius = radius;
	return (sphere);
}
