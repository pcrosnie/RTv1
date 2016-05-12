/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:05:10 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/12 11:41:59 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
