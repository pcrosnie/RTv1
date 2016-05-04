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
	int i;

	i = 0;
	ret = 0;
	ptr->t = ptr->posy - sph->cy - 100;
//	while (ptr->t < ptr->posy - sph->cy)
//	{
//	rx = ptr->posx + (tan(ptr->ahor + ((M_PI_2 / 900) * (x + 1))) * ptr->t);
	rx = ptr->posx + ((cos(ptr->aver + ((M_PI / 3 / 900) * (y + 1) * ptr->t)) * cos(ptr->ahor + ((M_PI_2 / 900) * (x + 1)) * ptr->t)) / ptr->t);
	ry = ptr->posy + (ptr->t / (cos(ptr->aver + ((M_PI / 3 / 900) * (y + 1) * ptr->t)) * sin(ptr->ahor + ((M_PI_2 / 900) * (x + 1)) * ptr->t)));
	rz = ptr->posz + (sin(ptr->aver + ((M_PI / 3) / 600) * (y + 1)) * ptr->t);
	ret = ((rx - sph->cx) * (rx - sph->cx)) + ((ry - sph->cy) * (ry - sph->cy)) + ((rz - sph->cz) * (rz - sph->cz));
//	printf("%f : %f\n", rx, ret);
	if (ret <= 2500)
	{
		ft_draw(ptr, x, y);
	}
	ptr->t++;
//	ft_putnbr(ptr->posy - sph->cy);
//	ft_putchar('\n');
//	ft_putstr("here\n");
//	}
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
	ptr->sph = sph;
	ft_set_rays(ptr, sph);
}

int	ft_move(int button, t_data *ptr)
{
	(button == 53) ? exit(0) : 0;
	(button == 126) ? ptr->posy -= 10 : 0;
	(button == 125) ? ptr->posy += 10 : 0;
	(button == 124) ? ptr->posx += 10 : 0;
	(button == 123) ? ptr->posx -= 10 : 0;
	
	free(ptr->data_addr);
	ptr->im = mlx_new_image(ptr->mlx, 900, 600);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_rays(ptr, ptr->sph);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
	return (0);
}

void	ft_set_window(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 900, 600, "RTv1");
	ptr->im = mlx_new_image(ptr->mlx, 900, 600);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_sphere(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
	mlx_key_hook(ptr->win, ft_move, ptr);
	mlx_loop(ptr->mlx);
}

int		main(void)
{
	t_data	*ptr;
	
	ptr = (t_data *)malloc(sizeof(t_data));
	ft_set_window(ptr);
	return (0);
}
