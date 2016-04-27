/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:10:05 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/04/27 20:02:59 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	ft_draw(t_data *ptr, float x, float y)
{
	int	nb;

	nb = (x * ptr->bits) / 8 + (y * ptr->len);
	ptr->data_addr[nb] = ptr->red;
	ptr->data_addr[nb + 1] = ptr->green;
	ptr->data_addr[nb + 2] = ptr->blue;
}

void	ft_check_impact(double x, double y, t_data *ptr, t_sph *sph)
{
	double	rx;
	double	ry;
	double	rz;
	double	ret;

	rx = 450 + (tan(ptr->ahor + ((M_PI_2 / 900) * (x + 1))) * (ptr->posy - sph->cy));
	ry = 50;
	rz = ptr->posz + (tan(ptr->aver + ((M_PI / 3) / 600) * (y + 1)) * (ptr->posy - sph->cy));
	ret = ((rx - 450) * (rx - 450)) + ((ry - 50) * (ry - 50)) + ((rz - 50) * (rz - 50));
	printf("%f : %f : %f\n", tan(ptr->ahor + ((M_PI_2 / 900) * (x + 1))) * (ptr->posx - sph->cx), rx, ret);
	if (ret <= 2500)
	{
		ft_draw(ptr, x, y);
	}
}

void	ft_set_rays(t_data *ptr, t_sph *sph)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 600)
		{
			ft_check_impact(x, y, ptr, sph);
			y++;
		}
		x++;
	}
}

void	ft_set_sphere(t_data *ptr)
{
	t_sph *sph;

	sph = (t_sph *)malloc(sizeof(t_sph));
	sph->cx = 450;
	sph->cy = 50;
	sph->cz = 200;
	sph->rayon = 50;
	ptr->posx = 450;
	ptr->posy = 500;
	ptr->posz = 0;
	ptr->red = 0;
	ptr->green = 0;
	ptr->blue = 255;
	ptr->ahor = M_PI_2 + M_PI_4;
	ptr->aver = - M_PI / 6;
	ft_set_rays(ptr, sph);
}

void	ft_set_window(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 900, 600, "RTv1");
	ptr->im = mlx_new_image(ptr->mlx, 900, 600);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_sphere(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
	mlx_loop(ptr->mlx);
}

int		main(void)
{
	t_data	*ptr;
	
	ptr = (t_data *)malloc(sizeof(t_data));
	ft_set_window(ptr);
	return (0);
}
