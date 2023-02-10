/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:51:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/02/10 10:11:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 100
#define WINDOW_NAME "program"

int	handle_key(int keycode, void *mlx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	mlx_hook(win, DestroyNotify, NoEventMask, &mlx_loop_end, mlx);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &handle_key, mlx);
	mlx_hook(win, KeyPress, KeyPressMask, &handle_key, mlx);
	if (argc > 1)
		sleep(atoi(argv[1]));
	else
		mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
