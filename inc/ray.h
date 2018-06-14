/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:31:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 16:38:12 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vec_3.h"
#include "camera.h"

typedef struct s_ray	t_ray;

struct	s_ray
{
	t_vec_3	pos;	
	t_vec_3	dir;
};

t_ray	ray_new(int x, int y, t_camera cam);

#endif
