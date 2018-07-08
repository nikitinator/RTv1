/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:10:08 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 13:58:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "figures.h"
#include "vec_3.h"

double	sphere_get_distance(t_object *object, t_ray ray)
{
	t_coefficients	coef;
	t_vec_3			oc;		

	oc = ray.pos - object->pos;
	coef.a = vec_dot_product(ray.dir, ray.dir);
	coef.b = vec_dot_product(oc, ray.dir) * 2;
	coef.c = vec_dot_product(oc, oc) -
		SQR(((t_sphere *)object->figure)->radius);
	return (first_hit_distance(coef));
}

t_vec_3	sphere_get_normal(t_object *object, t_vec_3 hitpoint)
{
	return (vec_normalize(hitpoint - object->pos));
}

void	*new_sphere(double radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->radius = radius;
	return (sphere);
}
