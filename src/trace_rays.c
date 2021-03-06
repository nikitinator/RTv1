/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:19:30 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/31 17:16:03 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"

void	trace_rays(t_scene scene, Uint32 *img_arr)
{
	short		x;
	short		y;
	t_hit		hit;
	t_ray		ray;

	y = 0;
	while (y < SCR_HEIGHT)
	{
		x = 0;
		while (x < SCR_WIDTH)
		{
			ray = ray_new(x, y, scene.camera);	//(camera should generate rays)
			hit = ray_trace(ray, scene.objects);
			if ((hit.obj))
				SET_PIX(x, y, img_arr, shade_pixel(hit, &scene));
			x++;
		}
		y++;
	}
}
