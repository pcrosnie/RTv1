/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:10:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/12 15:03:28 by pcrosnie         ###   ########.fr       */
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
	struct	s_spot	*spot;
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
	double	a;
	double	b;
	double	c;
	double	ax;
	double	ay;
	double	az;
	double	bx;
	double	by;
	double	bz;
	double	height;
	double	width;
}		t_wall;

typedef	struct	s_spot
{
	double	posx;
	double	posy;
	double	posz;
	double	rx;
	double	ry;
	double	rz;
	double	angle;
	double  distance_max;
	double	sol;
}				t_spot;

void	ft_set_rays(t_data *ptr);
void	ft_set_wall_angles(t_data *ptr);
void	ft_set_spot(t_data *ptr, double rx, double ry, double rz);

#endif
