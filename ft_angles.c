/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:05:10 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/11 12:16:37 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_set_wall_angles(t_data *ptr)
{
	double tmp;
	double tmp2;
	double tmp3;
	double tmp4;
	double tmp5;
	double tmp6;

	tmp = ptr->wall->ay;
	tmp2 = ptr->wall->az;
	tmp3 = ptr->wall->by;
	tmp4 = ptr->wall->bz;
	tmp5 = ptr->wall->a;
	tmp6 = ptr->wall->c;
	ptr->wall->a = (tmp5 * cos(ptr->ahor)) - (tmp6 * sin(ptr->ahor));
	ptr->wall->b = (tmp5 * sin(ptr->ahor)) + (tmp6 * cos(ptr->ahor));
	ptr->wall->ay = (tmp * cos(ptr->ahor)) - (tmp2 * sin(ptr->ahor));
	ptr->wall->az = (tmp * sin(ptr->ahor)) + (tmp2 * cos(ptr->ahor));
	ptr->wall->by = (tmp3 * cos(ptr->ahor)) - (tmp4 * sin(ptr->ahor));
	ptr->wall->bz = (tmp3 * sin(ptr->ahor)) + (tmp4 * cos(ptr->ahor));
	ft_set_rays(ptr);
	ptr->wall->ay = tmp;
	ptr->wall->az = tmp2;
	ptr->wall->by = tmp3;
	ptr->wall->bz = tmp4;
	ptr->wall->a = tmp5;
	ptr->wall->b = tmp6;
}
