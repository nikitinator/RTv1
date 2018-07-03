/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:10:08 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/15 18:21:08 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "figures.h"
#include "vec_3.h"

t_coefficients	sphere_get_coefficients(t_object *object, t_ray ray)
{
	t_vec_3			oc;		//TODO find a name(ray_to_obj_center)
	t_coefficients	coeff;
	//t_circle		*circle

	oc = ray.pos - object->pos; //right way i guess
	//oc = object->pos - ray.pos;
	coeff.a = vec_dot_product(ray.dir, ray.dir);
	coeff.b = vec_dot_product(oc, ray.dir) * 2;//poprobui ubrat' zero
	coeff.c = vec_dot_product(oc, oc) - SQR(((t_sphere *)object->figure)->radius);
	return (coeff);
}

void			*new_sphere(double	radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(sphere))))
		return (NULL);
	sphere->radius = radius;
	return (sphere);
}
