/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:08:30 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 16:18:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "vec_3.h"
# include "rtv1.h" //coefficients
# include "ray.h"

typedef struct s_sphere		t_sphere;
typedef struct s_cone		t_cone;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

/* 
** Sphere
*/
struct	s_sphere
{
	double	radius;
};
void			*new_sphere(double radius);
t_coefficients	sphere_get_coefficients(t_object *object, t_ray ray);

struct	s_cone
{
	t_vec_3	axis;
	double	radius;
	double	tg_half_angle;
};

struct	s_plane
{
	t_vec_3	normal;	
	//size???
};

struct	s_cylinder
{
	t_vec_3	axis;
	double	radius;
};

#endif
