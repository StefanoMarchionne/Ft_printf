#include "libft.h"

/*!
 * @brief 
	Checks for any printable character including space.
 * @return 
	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
