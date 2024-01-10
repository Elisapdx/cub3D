/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:19:57 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/09 18:17:48 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

int	main(int ac, char **av)
{
	int			err_type;
	t_config	*conf;

	if (ac < 2 || check_extension(av[1]) < 0)
		return (-1);
	err_type = parse_data(&conf, av);
	if (err_type == MAP_ERR)
		return (ft_putendl_fd(GET_SKETCH_ERR, STDERR_FILENO));
	else if (err_type == DATA_ERR)
		return (ft_putendl_fd(GET_DATA_ERR, STDERR_FILENO));
	if (initialize_mlx_win(&conf) < 0 || stock_image(&conf) < 0)
		return (free_table_err(&conf, NULL, -1));
	if (init_cub(&conf) < 0)
		return (free_table_err(&conf, NULL, -1));
	init_game(&conf);
	return (SUCCESS);
}
