#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#define WINDOW_W 100
#define WINDOW_H 100
#define WINDOW_NAME "program"

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_W, WINDOW_H, WINDOW_NAME);
	// mlx_loop(mlx);
	sleep(2);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
