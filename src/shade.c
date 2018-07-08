/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:40:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 19:41:42 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "vec_3.h"

static t_vec_3	clamp_to_one(t_vec_3 result)
{
	if (result[0] > 1)
		result[0] = 1;
	if (result[1] > 1)
		result[1] = 1;
	if (result[2] > 1)
		result[2] = 1;
	return (result);
}

static Uint32	ads_to_rgb(t_vec_3 result)
{
	t_color	clr;

	clr.c_32 = 0;
	clr.c_8[R] = 255 * result[0];
	clr.c_8[G] = 255 * result[1];
	clr.c_8[B] = 255 * result[2];
	return (clr.c_32);
}

static int		see_the_light(t_vec_3 point, t_vec_3 light_pos,
		t_object *objects)
{
	t_hit	hit;

	hit = ray_trace((t_ray){point, vec_normalize(light_pos - point)}, objects);
	if (hit.obj &&
			(vec_magnitude(hit.pnt - point) < vec_magnitude(light_pos - point)))
		return (0);
	return (1);
}

Uint32			shade_pixel(t_hit hit, t_scene *scene)
{
	t_vec_3	total;
	t_light *lights;
	t_vec_3	normal;
	double	dot_p;

	total = (t_vec_3){0, 0, 0};
	lights = scene->lights;
	while (lights)
	{
		total += hit.obj->ambient * lights->ambient;
		normal = hit.obj->get_normal(hit.obj, hit.pnt);
		dot_p = vec_dot_product(vec_normalize(lights->pos - hit.pnt),
				normal);
		if (dot_p > 0 && see_the_light(hit.pnt, lights->pos, scene->objects))
		{
			total += vec_mul_scal(hit.obj->diffuse * lights->diffuse, dot_p);
			total += vec_mul_scal(hit.obj->specular * lights->specular,
				pow(vec_dot_product(normal,
				vec_normalize(lights->pos - hit.pnt +
				scene->camera.pos - hit.pnt)), 256));
		}
		lights = lights->next;
	}
	return (ads_to_rgb(clamp_to_one(total)));
}
