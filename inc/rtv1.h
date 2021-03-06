/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:21:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/12/11 14:30:10 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H 
# define RTV1_H 

# include <SDL.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <stdio.h>//

#include "object.h"
#include "vec_3.h"  //TODO podumai o nuzhnosti ukazaniya vseh
#include "camera.h"
#include "ray.h"

//WIDTH ALWAYS >= HEIGHT
# define SCR_WIDTH  1680
# define SCR_HEIGHT 1050
# define FOV 90	


# define R 2
# define G 1
# define B 0

# define SET_PIX(x, y, i, c) i[x + y * SCR_WIDTH] = c
# define RADIAN(angle) (M_PI/180.0*(angle))
# define SQR(n) ((n) * (n))

typedef union		u_color
{
	unsigned int	c_32;
	unsigned char	c_8[3];
}					t_color;

typedef unsigned char	t_byte;
typedef unsigned short	t_ushort;

typedef struct s_drawer	t_drawer;
typedef struct s_scene	t_scene;
typedef struct s_light	t_light;
typedef struct s_hit	t_hit;
typedef struct s_material	t_material;

struct	s_material
{
	t_vec_3	ambient;
	t_vec_3	diffuse;
	t_vec_3	specular;
};

struct	s_light
{
	t_vec_3	pos;	
	t_vec_3	ambient;
	t_vec_3	diffuse;
	t_vec_3	specular;
	t_light	*next;
};


struct s_hit
{
	t_object	*obj;
	t_vec_3		pnt;
};

struct	s_drawer
{
	SDL_Window		*window;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
};

struct	s_scene
{
	t_camera	camera;
	t_object	*objects;
	t_light		*lights;
};

Uint32		shade_pixel(t_hit hit, t_scene *scene);
int     	init_drawer(t_drawer *drw);
void    	init_scene(int argc, char **argv, t_scene *scene);
void    	trace_rays(t_scene scene, Uint32 *img_arr);
t_hit		ray_trace(t_ray ray, t_object *object);//peremesti v ray.h
void		update_window(Uint32 *img_arr, SDL_Texture *texture,
				SDL_Renderer *renderer);
int     catch_exit(void);

#endif
