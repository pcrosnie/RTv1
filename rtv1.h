/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:10:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/10 15:44:33 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft/libft.h"
# include "math.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*im;
	char	*data_addr;
	int		bits;
	int		len;
	int		endian;
	double	posx;
	double	posy;
	double	posz;
	double	ahor;
	double	aver;
	int		red;
	int		green;
	int		blue;
	double	distance;
	struct	s_sph	*sph;
	struct	s_wall	*wall;
	struct	s_wall	*ground;
}				t_data;

typedef struct	s_sph
{
	double	cx;
	double	cy;
	double	cz;
	double	rayon;
}				t_sph;

typedef struct	s_wall
{
	int		ax;
	int		ay;
	int		az;
	int		bx;
	int		by;
	int		bz;
	int		height;
	int		width;
}		t_wall;

#endif
