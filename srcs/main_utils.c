#include "fdf.h"

float	angle(float angle)
{
	if (angle > M_PI)
		angle = -1 * M_PI;
	else if (angle < -1 * M_PI)
		angle = -1 * M_PI;
	return (angle);
}

void	error(char *str, int x)
{
	int	i;

	i = write(2, str, ft_strlen(str));
	(void)i;
	exit(x);
}

long	get_time(void)
{
	long			curr_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	curr_time = time.tv_sec * THOUSAND + time.tv_usec / THOUSAND;
	return (curr_time);
}

int	uu_sleep(long ms)
{
	long	start_time;

	start_time = get_time();
	while (get_time() < start_time + ms)
		usleep (100);
	return (0);
}

int	animate(t_fdf *fdf)
{
	fdf->t1 = get_time();
	if (fdf->t1 >= (fdf->t2 + RATE) && fdf->t1 > (fdf->afk + THOUSAND))
	{
		fdf->t2 = fdf->t1;
		if (fdf->angle2 > SWEET_Y)
			fdf->angle2 -= ANGLERATE;
		if (fdf->angle2 < SWEET_Y)
			fdf->angle2 += ANGLERATE;
		if (fdf->angle3 > SWEET_Z)
			fdf->angle3 -= ANGLERATE;
		if (fdf->angle3 < SWEET_Z)
			fdf->angle3 += ANGLERATE;
		fdf->angle -= ANGLERATE;
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_map(fdf);
	}
	return (0);
}
