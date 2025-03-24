#include "libft.h"

/*!
 * @brief 
	Checks for a digit (0 through 9).
 * @return 
	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
