/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:40:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/03 10:56:28 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Uint32		shade_pixel(t_object obj, t_vec_3 hitpoint, t_light *lights)//only hit
{
	t_vec_3	normal;
	t_color	clr;

	(void)hitpoint;

	normal = vec_normalize(hitpoint - obj.pos);

	double	dot_p = vec_dot_product(vec_normalize(lights->pos - hitpoint), normal);

	clr.c_32 = obj.color;
	return (clr.c_32);
	
	if (dot_p > 0)//&& dot_p < 1)
	{
		clr.c_8[R] *= dot_p;
		clr.c_8[G] *= dot_p;
		clr.c_8[B] *= dot_p;
	}
	else 
		return (0);
	return (clr.c_32);
}
