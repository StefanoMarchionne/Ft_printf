#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct flags
{
	int	width;
	int	dash;
	int	dot;
	int	zero;
	int	sharp;
	int	plus;
	int	space;
}	t_flags;

int		ft_printf(const char *s, ...);
int		ft_printf_format(va_list args, char ph, t_flags flags);
void	ft_printf_assembly_line(t_print **result, t_flags flags, char ph);

#endif
