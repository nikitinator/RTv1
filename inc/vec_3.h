/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_3.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:49:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/15 13:31:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_3_H
# define VEC_3_H

# define X 0
# define Y 1
# define Z 2

# define DOT_PROD(a, b) (a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z]) 

typedef double	t_vec_3 __attribute__((vector_size(sizeof(double)*3)));

double			vec_dot_product(t_vec_3 a, t_vec_3 b);
double			vec_magnitude(t_vec_3 v);
t_vec_3     	vec_mul_scal(t_vec_3 v, double scalar);
t_vec_3     	vec_div_scal(t_vec_3 v, double scalar);
t_vec_3    		vec_normalize(t_vec_3 v);
t_vec_3			vector_rotate_x(t_vec_3 v, double angle);
t_vec_3			vector_rotate_y(t_vec_3 v, double angle);
t_vec_3			vector_rotate_z(t_vec_3 v, double angle);

#endif
