/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:34:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/07 11:45:07 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "figures.h"

int		init_drawer(t_drawer *drw)
{
	if (!(drw->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT,
		SDL_WINDOW_SHOWN)))
		return (1);
	if (!(drw->renderer = SDL_CreateRenderer(drw->window, -1, 0)))
		return (1);
	if (!(drw->texture = SDL_CreateTexture(drw->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET,
		SCR_WIDTH, SCR_HEIGHT)))
		return (1);
	return (0);
}

void	init_scene(int argc, char **argv, t_scene *scene)
{
	(void)argc;
	(void)argv;

//
	t_vec_3	cam_pos = {0, 0, 0};
	t_vec_3	cam_rot = {0 , 0, 0};
	scene->camera = camera_new(FOV, cam_pos, cam_rot);
//

	t_object	*objs;
	if (!(scene->objects = malloc(sizeof(t_object) * 5))) // 555
		exit(1);
	objs = scene->objects;

	objs[0].pos = (t_vec_3){0, 0, -10};
	objs[0].color = 0x0000FFFF; 
	objs[0].figure = new_sphere(0.5);
	objs[0].get_parameter = sphere_get_parameter; 
	objs[0].get_normal= sphere_get_normal; 
	//objs[0].get_coefficients = sphere_get_coefficients; 
	objs[0].next = objs + 1; 
	
	objs[1].pos = (t_vec_3){-5.0, 0, -10};
	//objs[1].pos = (t_vec_3){0, 0, -20};
	objs[1].color = 0x0000FF00; 
	objs[1].figure = new_sphere(3);
	objs[1].get_parameter = sphere_get_parameter; 
	objs[1].get_normal= sphere_get_normal; 
	//objs[1].get_coefficients = sphere_get_coefficients; 
	objs[1].next = objs + 2;

	objs[2].pos = (t_vec_3){-5.0, 0, -30};
	objs[2].color = 0x00FFFF00; 
	objs[2].figure = new_plane((t_vec_3){1, 0, 0});
	objs[2].get_parameter= plane_get_parameter; 
	objs[2].get_normal= plane_get_normal; 
	objs[2].next = objs + 3;

	objs[3].pos = (t_vec_3){10, 0, -30};
	objs[3].color = 0x003FeF5a; 
	objs[3].figure = new_cylinder((t_vec_3){0, 1, 0}, 5);
	objs[3].get_parameter= cylinder_get_parameter; 
	objs[3].get_normal= cylinder_get_normal; 
	objs[3].next = objs + 4;

	objs[4].pos = (t_vec_3){5, 0, -11};
	objs[4].color = 0x00FF0000; 
	objs[4].figure = new_cone((t_vec_3){0, 1, 0}, 000000000000, 30);
	objs[4].get_parameter= cone_get_parameter; 
	objs[4].get_normal= cone_get_normal; 
	objs[4].next =NULL; 



	if (!(scene->lights= malloc(sizeof(t_light) * 1)))
		exit(1);
	//scene->lights->pos = (t_vec_3){2, 2, -5};
	scene->lights->pos = (t_vec_3){0, 0, 1};
}
