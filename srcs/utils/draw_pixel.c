/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:44 by pmaimait          #+#    #+#             */
/*   Updated: 2023/05/26 15:47:15 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


/* void	draw_circle(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 360)
	{
		draw_arrow(data, i * PI / 180, data->player.pos_x, data->player.pos_y, 5);
		i++;
	}
} */
void	draw_line(t_data *data, double angle, double x, double y)
{
	int i = 0;

	angle = angle - PI;
	
	while (i < INT_MAX)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, MMAP_COLOR_PLAYER);
		x = x + cos(angle);
		y = y + sin(angle);
		if (hasWallAt(data, x, y))
			break;
		i++;
	}
}
void	draw_ray(t_data *data)
{
	double	ray_angle;
	double	distance;
	
	distance = 0;
	ray_angle = data->player.rotationAngle - 30 / PI;
	while (ray_angle <= (data->player.rotationAngle + 30 / PI))
	{
		draw_line(data, ray_angle, data->player.pos_x, data->player.pos_y);
		ray_angle += PI / 2;
	}
}