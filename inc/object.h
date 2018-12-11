/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:21:51 by snikitin          #+#    #+#             */
/*   Updated: 2018/12/11 15:14:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H 
# define OBJECT_H 

#include "ray.h"
#include "vec_3.h"

typedef struct s_object	t_object;

struct	s_object
{
	void			*figure;
	double			(*get_distance)(t_object *object, t_ray ray);
	t_vec_3			(*get_normal)(t_object *object, t_vec_3 hitpoint);


	t_vec_3			pos;	
	t_vec_3			ambient;
	t_vec_3			diffuse;
	t_vec_3			specular;
	t_object		*next;
};

#endif
