/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:10:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/03 11:13:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int     catch_exit(void)
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
