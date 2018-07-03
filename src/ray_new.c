/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:36:12 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/15 18:26:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vec_3.h"

t_ray	ray_new(int x, int y, t_camera cam)
{
	t_ray	ray;

	ray.pos = cam.pos;
	ray.dir = cam.dir +
				vec_mul_scal(cam.right, (2 *((x + 0.5) / (double)SCR_WIDTH)) - 1) +
				vec_mul_scal(cam.up, (1 - 2 * ((y + 0.5) / (double)SCR_HEIGHT)));
	//printf ("X:%f Y:%f Z:%f\t\n", ray.pos[X], ray.pos[Y], ray.pos[Z]);
	ray.dir = vec_normalize(ray.dir);
	//printf ("X:%f Y:%f Z:%f\t\n\n", ray.dir[X], ray.dir[Y], ray.dir[Z]);
	return (ray);
}
