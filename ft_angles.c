/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:05:10 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/12 17:22:19 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	ft_set_wall_angles(t_data *ptr)
{
	double tmp;
	double tmp2;
	double tmp3;
	double tmp4;
//	double tmp5;
//	double tmp6;

	tmp = ptr->wall->az;
	tmp2 = ptr->wall->ay;
	tmp3 = ptr->wall->bz;
	tmp4 = ptr->wall->by;
//	tmp5 = ptr->wall->b;
//	tmp6 = ptr->wall->c;
//	ptr->wall->b = (tmp5 * cos(ptr->ahor)) - (tmp6 * sin(ptr->ahor));
//	ptr->wall->c = (tmp5 * sin(ptr->ahor)) + (tmp6 * cos(ptr->ahor));
	ptr->wall->az = (tmp * cos(ptr->ahor)) - (tmp2 * sin(ptr->ahor));
	ptr->wall->ay = (tmp * sin(ptr->ahor)) + (tmp2 * cos(ptr->ahor));
	ptr->wall->bz = (tmp3 * cos(ptr->ahor)) - (tmp4 * sin(ptr->ahor));
	ptr->wall->by = (tmp3 * sin(ptr->ahor)) + (tmp4 * cos(ptr->ahor));
	ft_set_rays(ptr);
	ptr->wall->az = tmp;
	ptr->wall->ay = tmp2;
	ptr->wall->bz = tmp3;
	ptr->wall->by = tmp4;
//	ptr->wall->b = tmp5;
//	ptr->wall->c = tmp6;
}

void	ft_set_spot(t_data *ptr, double rx, double ry, double rz)
{
	double	coeff;
	double sol;

	sol = ptr->spot->sol;
	ptr->spot->distance_max = sqrt(((ptr->spot->posx - ptr->sph->cx) * (ptr->spot->posx - ptr->sph->cx)) + ((ptr->spot->posy - ptr->sph->cy) * (ptr->spot->posy - ptr->sph->cy)) + ((ptr->spot->posz - ptr->sph->cz) * (ptr->spot->posz - ptr->sph->cz))) + ptr->sph->rayon;
	coeff = ptr->spot->distance_max - sqrt(((ptr->spot->posx - (ptr->posx + (rx * sol))) * (ptr->spot->posx - (ptr->posx + (rx * sol)))) + ((ptr->spot->posy - (ptr->posy + (ry * sol))) * (ptr->spot->posy - (ptr->posy + (ry * sol)))) + ((ptr->spot->posz - (ptr->posz + (rz * sol))) * (ptr->spot->posz - (ptr->posz + (rz * sol)))));
//	ptr->green = coeff;
	ptr->blue = coeff / 2 + 125;
	ptr->red = coeff / 2 + 125;
	if (coeff / 2 + 125 > 255 || !coeff)
	{
		ptr->blue = 255;
		ptr->red = 255;
	}
	else if (coeff / 2 + 125 < 0)
	{
		ptr->blue = 0;
		ptr->red = 0;
	}
}
