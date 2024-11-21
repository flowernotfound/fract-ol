#include "../inc/fract-ol.h"

void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, X_EVENT, X_MASK, close_window, data);
	mlx_hook(data->win, EXPOSE_EVENT, EXPOSE_MASK, handle_expose, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (init_mlx(&data))
		return (1);
	if (parse_args(ac, av, &data))
	{
		clean_exit(&data);
		return (1);
	}
	if (init_window(&data))
		return (1);
	redraw(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
