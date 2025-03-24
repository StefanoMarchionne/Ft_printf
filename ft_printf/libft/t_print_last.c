#include "libft.h"

/*!
 * @brief 
	Returns the last node of the list.
 * @param lst
	The beginning of the list.
 * @return
	Last node of the list.	
 */
t_print	*t_print_last(t_print *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
