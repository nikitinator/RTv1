/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:46:16 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/07 15:09:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H 
# define PARSER_H 

int		parser_init_scene(int argc, char **argv, t_scene *scene);

//private-----------------------------------------------------------------------
enum e_parser_errors
{
	PARSER_WRONG_USAGE = 1,
	PARSER_INVALID_FILE,
};

#endif

