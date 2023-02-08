/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:51:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/02/08 20:51:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 100
#define WINDOW_NAME "program"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	sleep(1);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
