/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:34:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 17:21:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec_3.h"
#include "rtv1.h" //shirina i vysota

t_camera	camera_new(double fov, t_vec_3 cam_pos, t_vec_3 cam_rot)
{
	t_camera camera;

	camera.pos = cam_pos;
	//camera.dir = vec_normalize(cam_dir);
	double	half_height = tan(RADIAN(fov/2));
	double	half_width = half_height * ((double)SCR_WIDTH / (double)SCR_HEIGHT);
	camera.dir = 	(t_vec_3){0, 0, -1};
	camera.up =  	(t_vec_3){0, half_height, 0};
	camera.right = 	(t_vec_3){half_width, 0, 0}; //TODO zatesti dot product
	(void)cam_rot;
	return (camera);
}
