/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:34:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/03 18:37:18 by snikitin         ###   ########.fr       */
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
	double	half_width = tan(RADIAN(fov/2));
	double	half_height = half_width * ((double)SCR_HEIGHT / (double)SCR_WIDTH);
	camera.dir = 	(t_vec_3){0, 0, -1};
	camera.up =  	(t_vec_3){0, half_height, 0};
	camera.right = 	(t_vec_3){half_width, 0, 0}; //TODO zatesti dot product
	//camera.dir = vector_rotate_z(camera.dir, RADIAN(35));	
	//camera.up =  vector_rotate_z(camera.up, RADIAN(35));	
	//camera.right = vector_rotate_z(camera.right, RADIAN(35));
	camera_rotate(&camera, cam_rot);

	(void)cam_rot;
	return (camera);
}

void	camera_rotate(t_camera *camera, t_vec_3 angles)
{
	camera->dir = vector_rotate_x(camera->dir, RADIAN(angles[X]));
	camera->up =  vector_rotate_x(camera->up, RADIAN(angles[X]));
	camera->right = vector_rotate_x(camera->right, RADIAN(angles[X]));

	camera->dir = vector_rotate_y(camera->dir, RADIAN(angles[Y]));
	camera->up =  vector_rotate_y(camera->up, RADIAN(angles[Y]));
	camera->right = vector_rotate_y(camera->right, RADIAN(angles[Y]));

	camera->dir = vector_rotate_z(camera->dir, RADIAN(angles[Z]));
	camera->up =  vector_rotate_z(camera->up, RADIAN(angles[Z]));
	camera->right = vector_rotate_z(camera->right, RADIAN(angles[Z]));
}	
