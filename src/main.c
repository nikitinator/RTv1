/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:21:36 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/14 17:23:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <SDL.h>

int     catch_exit(void)//uberi v drugoi fail nah
{
    SDL_Event   e;

	while (1)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym ==
					SDLK_ESCAPE))
				return (1);
		}
	}
    return (0);
}

int		main(int argc, char **argv)
{
	Uint32			*img_arr;
	t_drawer		draw;
	t_scene			scene;

	init_scene(argc, argv, &scene);
	if (!(img_arr = ft_memalloc(sizeof(Uint32) * SCR_WIDTH * SCR_HEIGHT)))
		return (1);
	trace_rays(scene, img_arr);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (init_drawer(&draw))
		return (1);
	update_window(img_arr, draw.texture, draw.renderer);
	catch_exit(); //fgnya nazwanie
	SDL_DestroyWindow(draw.window);
	SDL_Quit();
	return (0);
}
