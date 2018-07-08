/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:36:12 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 19:42:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vec_3.h"

t_ray	ray_new(int x, int y, t_camera cam)
{
	t_ray	ray;

	ray.pos = cam.pos;
	ray.dir = cam.dir +
		vec_mul_scal(cam.right, (2 * ((x + 0.5) / (double)SCR_WIDTH)) - 1) +
		vec_mul_scal(cam.up, (1 - 2 * ((y + 0.5) / (double)SCR_HEIGHT)));
	ray.dir = vec_normalize(ray.dir);
	return (ray);
}
