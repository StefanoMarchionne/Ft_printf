#include "libft.h"

/*!
 * @brief 
	Adds the node ’new’ at the beginning of the list.
 * @param lst 
	The address of a pointer to the first link of a list.
 * @param new 
	The address of a pointer to the node to be added to the list.
 */
void	t_print_add_front(t_print **lst, t_print *new)
{
	new->next = *lst;
	*lst = new;
}
