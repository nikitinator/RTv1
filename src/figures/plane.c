/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:10:08 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 11:52:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "figures.h"
#include "vec_3.h"
#include "ray.h"

double			plane_get_distance(t_object *object, t_ray ray)
{
	t_vec_3			oc;	
	t_plane			*plane;
	double			cos_ray_and_normal;

	oc = ray.pos - object->pos;
	plane = (t_plane *)object->figure;
	cos_ray_and_normal = vec_dot_product(ray.dir, plane->normal);
	if (cos_ray_and_normal)
		return (-vec_dot_product(oc, plane->normal) / cos_ray_and_normal);
	return (0);	
}

t_vec_3				plane_get_normal(t_object *object, t_vec_3 hitpoint)
{
	(void)hitpoint;
	return (((t_plane *)object->figure)->normal);
}

void			*new_plane(t_vec_3 normal)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (NULL);
	plane->normal = normal;
	return (plane);
}
