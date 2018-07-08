/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:40:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 12:29:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		see_the_light(t_vec_3 point, t_light *light, t_object *objects)
{
	t_hit	hit;

	hit = ray_trace((t_ray){point, vec_normalize(light->pos - point)}, objects);
	if (hit.obj &&
			(vec_magnitude(hit.pnt - point) < vec_magnitude(light->pos - point)))
	{
		//printf("%f\n", vec_magnitude(hit.pnt - point));
		return (0);
	}
	return (1);
}

t_vec_3	clamp(t_vec_3 result)
{
	if (result[0] > 1)
		result[0] = 1;
	if (result[1] > 1)
		result[1] = 1;
	if (result[2] > 1)
		result[2] = 1;
	return (result);
}

//Uint32		ads_to_rgb(t_vec_3 ambient, t_vec_3 diffuse, t_vec_3 specular)
Uint32		ads_to_rgb(t_vec_3 result)
{
	t_color	clr;

	clr.c_32 = 0;
	clr.c_8[R] = 255 * result[0];
	clr.c_8[G] = 255 * result[1];
	clr.c_8[B] = 255 * result[2];
	return (clr.c_32);
}


Uint32		shade_pixel(t_hit hit, t_scene *scene)
{
	//t_vec_3	normal;
	t_light *lights = scene->lights;
	t_object *objects = scene->objects;
	t_camera *camera = &scene->camera;
	
	t_vec_3	total;
	total = (t_vec_3){0, 0, 0};
	(void)objects;
	while (lights)
	{
		total += hit.obj->ambient * lights->ambient;

		t_vec_3	normal = hit.obj->get_normal(hit.obj, hit.pnt);
		double	dot_p = vec_dot_product(vec_normalize(lights->pos - hit.pnt), normal);

		if (dot_p > 0  && see_the_light(hit.pnt, lights, objects))
		{
			total += vec_mul_scal(hit.obj->diffuse * lights->diffuse, dot_p);
			
			t_vec_3	l = lights->pos - hit.pnt;
			t_vec_3	v = camera->pos - hit.pnt;
			double	h = pow(vec_dot_product(normal, vec_normalize(l + v)), 256);
			total += vec_mul_scal(hit.obj->specular * lights->specular, h);
		}
		lights = lights->next;
	}
	return (ads_to_rgb(clamp(total)));
}
