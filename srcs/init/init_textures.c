/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:33:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/07/10 14:04:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*get_dir_path(t_data *data, int i)
{
	char	*path;

	path = NULL;
	if (i == 0)
		path = data->file.east;
	else if (i == 1)
		path = data->file.west;
	else if (i == 2)
		path = data->file.south;
	else
		path = data->file.north;
	return (path);
}

void	textures_error(t_data *data, int i)
{
	if (data->texture[i].img == NULL
		|| data->texture[i].img_width != TILE_SIZE
		|| data->texture[i].img_height != TILE_SIZE)
	{
		ft_putstr_fd("cub3D: Error\n", 2);
		ft_putstr_fd(ERR_TEXT, 2);
		exit_game(data);
	}
	data->texture[i].addr = mlx_get_data_addr(data->texture[i].img, \
		&data->texture[i].bits_per_pixel, &data->texture[i].line_size, \
		&data->texture[i].endian);
	if (!data->texture[i].addr)
	{
		ft_putstr_fd("cub3D: Error\n", 2);
		ft_putstr_fd(ERR_TEXT, 2);
		exit_game(data);
	}
}

void	init_texture(t_data *data)
{
	char	*path;
	int		i;

	i = 0;
	while (i < 4)
	{
		path = get_dir_path(data, i);
		if (!path)
			exit_game(data);
		data->texture[i].img = \
			mlx_xpm_file_to_image(data->mlx, path, &data->texture[i].img_width,
				&data->texture[i].img_height);
		textures_error(data, i);
		i++;
	}
}

void	init_textures(t_data *data)
{
	data->texture = (t_img *)malloc(sizeof(t_img) * 4);
	if (!data->texture)
		exit_game(data);
	init_texture(data);
}
