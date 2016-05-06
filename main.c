/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:10:05 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/06 12:26:23 by pcrosnie         ###   ########.fr       */
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

/*
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
*/

double	ft_solve_poly(t_data *ptr, double rx, double ry, double rz)
{
	double	d;
	double	b;
	double	sol1;
	double	sol2;

	b = 2 * ((rx * (ptr->posx - ptr->sph->cx) + (ry * (ptr->posy - ptr->sph->cy)) + (rz * (ptr->posz - ptr->sph->cz))));
	d = (b * b) - (4 * ((rx * rx) + (ry * ry) + (rz * rz))) * (((ptr->posx - ptr->sph->cx) * (ptr->posx - ptr->sph->cx)) + ((ptr->posy - ptr->sph->cy) * (ptr->posy - ptr->sph->cy)) + ((ptr->posz - ptr->sph->cz) * (ptr->posz - ptr->sph->cz)) - (ptr->sph->rayon * ptr->sph->rayon));
	if (d == 0)
		sol1 = (b * (-1)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
	else if (d >= 0)
	{
		sol1 = ((b * (-1)) - sqrt(d)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
		sol2 = ((b * (-1)) - sqrt(d)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
		if (sol1 > sol2)
		{
			if (ptr->distance > sol1 && ptr->distance != 0)
				return (-1);
		}
		else
		{
			if (ptr->distance > sol2 && ptr->distance != 0)
			return (-1);
		}
	}
	return (d);
}

int		ft_set_wall(t_data *ptr, double rx, double ry, double rz)
{
	double a;

	a = -ptr->posy / ry;
	if (ptr->posx + (rx * a) < 200 && ptr->posx + (rx * a) > 0 && ptr->posz + (rz * a) < 1000 && ptr->posz + (rz * a) > 0)
		return (1);
	return (0);
}

void	vector_normalize(double *rx, double *ry, double *rz)
{
	int	mod;

	mod = sqrt((*rx * *rx) + (*ry * *ry) + (*rz * *rz));
	*rx /= mod;
	*ry /= mod;
	*rz /= mod;
}

int		ft_set_ground(t_data *ptr, double rx, double ry, double rz)
{
	double a;

	a = -ptr->posx / rx;
	ptr->distance = 0;
	if (ptr->posz + (rz * a) < 1000 && ptr->posz + (rz * a) > 0 && ptr->posy + (ry * a) < 200 && ptr->posy + (ry * a) > 0)
	{
		ptr->distance = a;
		return (1);
	}
	return (0);
}

void	ft_check_impact(double x, double y, t_data *ptr)
{
	double rx;
	double ry;
	double rz;
//	double ret;

	ry = cos(ptr->ahor + ((M_PI_2 / 900) * (x))) * cos(ptr->aver + ((M_PI_2 / 900) * (y)));
	rx = cos(ptr->ahor + ((M_PI_2 / 900) * (x))) * sin(ptr->aver + ((M_PI_2 / 900) * (y)));
	rz = sin(ptr->ahor + ((M_PI_2 / 900) * (x)));
	if (ft_set_wall(ptr, rx, ry, rz) == 1)
	{
		ptr->green = 255;
//		ft_putstr("Wall\n");
		ft_draw(ptr, x, y);
		ptr->green = 0;
	}
	if (ft_set_ground(ptr, rx, ry, rz) == 1)
	{
		ptr->red = 255;
		ptr->blue = 0;
		ft_draw(ptr, x, y);
		ptr->red = 0;
		ptr->blue = 255;
	}
//	ret = ft_solve_poly(ptr, rx, ry, rz);
//	rx *= ret;
//	ry *= ret;
//	rz *= ret;
//	if (((ptr->posx + rx - ptr->sph->cx) * (ptr->posx + rx - ptr->sph->cx)) + ((ptr->posy + ry - ptr->sph->cy) * (ptr->posy + ry - ptr->sph->cy)) + ((ptr->posz + rz - ptr->sph->cz) * (ptr->posz + rz - ptr->sph->cz)) <= (ptr->sph->rayon * ptr->sph->rayon))
	if (ft_solve_poly(ptr, rx, ry, rz) >= 0)
	{
//		ft_putstr("Sphere\n");
		ft_draw(ptr, x, y);
	}
}

void	ft_set_rays(t_data *ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
		{
			ft_check_impact(x, y, ptr);
			y++;
		}
		x++;
	}
}

void	ft_set_sphere(t_data *ptr)
{
	t_sph *sph;

	sph = (t_sph *)malloc(sizeof(t_sph));
	sph->cx = 50;
	sph->cy = 50;
	sph->cz = 50;
	sph->rayon = 50;
	ptr->posx = 50;
	ptr->posy = 500;
	ptr->posz = 50;
	ptr->red = 0;
	ptr->green = 0;
	ptr->blue = 255;
	ptr->ahor = M_PI_2 + M_PI_4;
	ptr->aver = M_PI_2 + M_PI_4;
	ptr->sph = sph;
	ft_set_rays(ptr);
}

int	ft_move(int button, t_data *ptr)
{
	(button == 53) ? exit(0) : 0;
	(button == 126) ? ptr->posy -= 10 : 0;
	(button == 125) ? ptr->posy += 10 : 0;
	(button == 124) ? ptr->posz -= 10 : 0;
	(button == 123) ? ptr->posz += 10 : 0;
	(button == 34) ? ptr->ahor += M_PI_4 : 0;
	(button == 31) ? ptr->ahor -= M_PI_4 : 0;
	(button == 78) ? ptr->posx -= 10 : 0;
	(button == 69) ? ptr->posx += 10 : 0;
	(button == 15) ? ft_set_sphere(ptr) : 0;
	free(ptr->data_addr);
	ptr->im = mlx_new_image(ptr->mlx, 900, 900);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_rays(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
	return (0);
}

void	ft_set_window(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 900, 900, "RTv1");
	ptr->im = mlx_new_image(ptr->mlx, 900, 900);
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
