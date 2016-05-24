#include "rtv1.h"
#include <stdio.h>

void	ft_set_cylindre(t_data *ptr)
{
	t_cyl *cyl;

	cyl = (t_cyl *)malloc(sizeof(t_cyl));
	ptr->cyl = cyl;
	cyl->x = 0;
	cyl->y = 0;
	cyl->z = 0;
	cyl->ux = 200;
	cyl->uy = 300;
	cyl->uz = 200;
	cyl->rayon = 2;
	cyl->vx = cyl->ux - cyl->x;
	cyl->vy = cyl->uy - cyl->y;
	cyl->vz = cyl->uz - cyl->z;
}

double	ft_solve_cyl(t_data *ptr)
{
//	double	sol1;
//	double	sol2;
	double	d;

	d = ((ptr->cyl->bx) * (ptr->cyl->bx)) - (4 * ptr->cyl->ax * (ptr->cyl->cx));
//	printf("%f\n", d);
	return (d);
}	

double	ft_draw_cyl(t_data *ptr, double rx, double ry, double rz)
{
	double	p1;
	double	p2;
	
	p1 = (rx * ptr->cyl->vx) + (ry * ptr->cyl->vy) + (rz * ptr->cyl->vz);
	p2 = (((ptr->posx - ptr->cyl->x) * ptr->cyl->vx) + ((ptr->posy - ptr->cyl->y) * ptr->cyl->vy) + ((ptr->posz - ptr->cyl->z) * ptr->cyl->vz));
	ptr->cyl->ax = (rx - (p1 * ptr->cyl->vx) * (rx - (p1 * ptr->cyl->vx)));
	ptr->cyl->bx = 2 * (((rx - (p1 * ptr->cyl->vx)) * ((ptr->posx - ptr->cyl->x) - (p2 * ptr->cyl->vx))) + ((ry - (p1 * ptr->cyl->vy)) * ((ptr->posy - ptr->cyl->y) - (p2 * ptr->cyl->vy))) + ((rz - (p1 * ptr->cyl->vz)) * ((ptr->posz - ptr->cyl->z) - (p2 * ptr->cyl->vz))));
	ptr->cyl->cx = ((ptr->posx - ptr->cyl->x) - (p2 * ptr->cyl->vx)) * ((ptr->posx - ptr->cyl->x) - (p2 * ptr->cyl->vx)) - (ptr->cyl->rayon * ptr->cyl->rayon);
		return (ft_solve_cyl(ptr));
}
