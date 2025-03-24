#include "libft.h"

/*!
 * @brief 
	Calculates the length of a hexadecimal number.
 * @param n 
	Number.
 * @return 
	Returns a size_t representing the length of a number in hexadecimal format.
 */
size_t	ft_hexlen(size_t n)
{
	size_t	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
