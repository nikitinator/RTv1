/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:19:30 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/06 17:31:14 by snikitin         ###   ########.fr       */
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
			ray = ray_new(x, y, scene.camera);		
			hit = ray_trace(ray, scene.objects);
			if ((hit.obj))
			{
				Uint32 color = shade_pixel(hit.obj, hit.pnt, scene.lights);
				//send maybe only normal from object instead of object (oh and color)

				SET_PIX(x, y, img_arr, color);
			}	
			x++;
		}
		y++;
	}
}
