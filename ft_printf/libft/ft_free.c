#include "libft.h"

/*!
 * @brief 
	If the ptr is not NULL, it is freed and set to NULL.
 * @return
	NULL.
 */
void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}
