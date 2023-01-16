#ifndef FRACT_OL
# define FRACT_OL

#include "../lib/libft/inc/libft.h"
#include "../lib/mlx/mlx.h"

#define WIDTH  (1920)
#define HEIGHT (1080)
#define IMAX   (30)

typedef struct	s_data {
	char	*type;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	void	*mlx;
	void	*win;
	void	*ptr;
	char	*adr;
	int		bpp;
	int		len;
	int		edn;
}			t_data;

#endif
