#include <stdlib.h>
#include <mlx.h>


/* gcc test.c -I/home/nuno/Desktop/42so_long/minilibx-linux -L/usr/local/lib /home/nuno/Desktop/42so_long/minilibx-linux/libmlx.a -lX11 -lXext -lm */
int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!");
	mlx_loop(mlx);
}