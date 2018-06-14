/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:33:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 16:38:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec_3.h"

typedef struct s_camera t_camera;

struct	s_camera
{
	t_vec_3	pos;	
	t_vec_3	dir;
	t_vec_3	up;
	t_vec_3 right;
};

t_camera	camera_new(double fov, t_vec_3 cam_pos, t_vec_3 cam_rot);

#endif
