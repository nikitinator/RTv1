/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:21:36 by snikitin          #+#    #+#             */
/*   Updated: 2018/11/26 18:53:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"
#include <SDL.h>

int		main(int argc, char **argv)
{
	Uint32			*img_arr;
	t_drawer		draw;
	t_scene			scene;

	//if (parser_init_scene(argc, argv, &scene))
	//	return (1);
	init_scene(argc, argv, &scene);
	if (!(img_arr = ft_memalloc(SCR_WIDTH * SCR_HEIGHT * sizeof(Uint32))))
		return (1);
	trace_rays(scene, img_arr);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (init_drawer(&draw))
		return (1);
	update_window(img_arr, draw.texture, draw.renderer);
	catch_exit();
	SDL_DestroyWindow(draw.window);
	SDL_Quit();
	return (0);
}
