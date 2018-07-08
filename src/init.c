/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:34:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/08 19:27:37 by snikitin         ###   ########.fr       */
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
	t_vec_3	cam_rot = {0 ,0, 0};
	scene->camera = camera_new(FOV, cam_pos, cam_rot);
//

	t_object	*objs;
	if (!(scene->objects = malloc(sizeof(t_object) * 5))) // 555
		exit(1);
	objs = scene->objects;

	objs[0].pos = (t_vec_3){0, 0, -10};
	//objs[0].pos = (t_vec_3){0, 0, -200};
	//objs[0].color = 0x0000FFFF; 

	objs[0].ambient = (t_vec_3){0, 0, 0.6};
	objs[0].diffuse = (t_vec_3){0, 0, 0.6};
	objs[0].specular = (t_vec_3){1, 1, 1};

	objs[0].figure = new_sphere(0.5);
	objs[0].get_distance = sphere_get_distance; 
	objs[0].get_normal= sphere_get_normal; 
	//objs[0].get_coefficients = sphere_get_coefficients; 
	objs[0].next = objs + 1; 
	
	objs[1].pos = (t_vec_3){-5.0, 0, -10};
	//objs[1].pos = (t_vec_3){-5.0, 0, -200};
	//objs[1].color = 0x0000FF00; 
	
	objs[1].ambient = (t_vec_3){0, 0.2, 0};
	objs[1].diffuse = (t_vec_3){0, 0.9, 0};
	objs[1].specular = (t_vec_3){1, 1, 1};
	objs[1].figure = new_sphere(3);
	objs[1].get_distance = sphere_get_distance; 
	objs[1].get_normal= sphere_get_normal; 
	objs[1].next = objs + 2;

	objs[2].pos = (t_vec_3){-5.0, 0, -30};
	//objs[2].color = 0x00FFFF00; 
	objs[2].ambient = (t_vec_3){0, 0.3, 0.3};
	objs[2].diffuse = (t_vec_3){0, 0.2, 0.2};
	objs[2].specular = (t_vec_3){0, 0, 0};
	objs[2].figure = new_plane((t_vec_3){0, 0, 1});
	objs[2].get_distance= plane_get_distance; 
	objs[2].get_normal= plane_get_normal; 
	objs[2].next = objs + 3;

	objs[3].pos = (t_vec_3){-2, 0, -30};
	//objs[3].color = 0x003FeF5a; 
	objs[3].ambient = (t_vec_3){0.2, 0.2, 0.3};
	objs[3].diffuse = (t_vec_3){0.7, 0.2, 0.3};
	objs[3].specular = (t_vec_3){1, 1, 1};
	objs[3].figure = new_cylinder((t_vec_3){0, 1, 0}, 5);
	objs[3].get_distance= cylinder_get_distance; 
	objs[3].get_normal= cylinder_get_normal; 
	objs[3].next = objs + 4;

	objs[4].pos = (t_vec_3){5, 0, -11};
	objs[4].ambient = (t_vec_3){0.2, 0.0, 0.0};
	objs[4].diffuse = (t_vec_3){0.5, 0.0, 0.0};
	objs[4].specular = (t_vec_3){1, 1, 1};
	objs[4].figure = new_cone((t_vec_3){0, 1, 0}, 30);
	objs[4].get_distance= cone_get_distance; 
	objs[4].get_normal= cone_get_normal; 
	objs[4].next =NULL; 

	if (!(scene->lights= malloc(sizeof(t_light) * 2)))
		exit(1);
	scene->lights->pos = (t_vec_3){0, 0, 0};
	scene->lights->ambient = (t_vec_3){1, 1, 1};
	scene->lights->diffuse = (t_vec_3){1, 1, 1};
	scene->lights->specular = (t_vec_3){1, 1, 1};
	scene->lights->next = NULL; 
	//scene->lights->pos = (t_vec_3){-1, 1, 5};
	((scene->lights) + 1)->pos = (t_vec_3){0, -3, 0};
}
