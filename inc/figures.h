/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:08:30 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 12:26:05 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "rtv1.h" //coefficients //object
# include "vec_3.h"
# include "ray.h"

typedef struct s_coefficients t_coefficients;
struct	s_coefficients
{
	double	a;
	double	b;	
	double	c;	
};

double	first_hit_distance(t_coefficients coef);

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
//t_coefficients	sphere_get_coefficients(t_object *object, t_ray ray);
double		sphere_get_distance(t_object *object, t_ray ray);
t_vec_3			sphere_get_normal(t_object *object, t_vec_3 hitpoint);

/* 
** Cone
*/
struct	s_cone
{
	t_vec_3	axis;
	double	tg_half_angle;
};
void			*new_cone(t_vec_3 axis, double angle);
double			cone_get_distance(t_object *object, t_ray ray);
t_vec_3			cone_get_normal(t_object *object, t_vec_3 hitpoint);


/* 
** Plane
*/
struct	s_plane
{
	t_vec_3	normal;	
};
void			*new_plane(t_vec_3 normal);
double			plane_get_distance(t_object *object, t_ray ray);
t_vec_3			plane_get_normal(t_object *object, t_vec_3 hitpoint);


/* 
** Cylinder 
*/
struct	s_cylinder
{
	t_vec_3	axis;
	double	radius;
};
void			*new_cylinder(t_vec_3 axis, double radius);
double			cylinder_get_distance(t_object *object, t_ray ray);
t_vec_3			cylinder_get_normal(t_object *object, t_vec_3 hitpoint);

#endif
