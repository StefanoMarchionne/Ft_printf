#include "libft.h"

/*!
 * @brief 
	Delete last n nodes.
 * @param head 
	The address of a pointer to the first link of a list.
 * @param n 
	Number of last nodes to be deleted.
 */
void	t_print_del_last(t_print **head, size_t n)
{
	t_print	*last;
	t_print	*tmp;

	while (n--)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = 0;
		free(last);
	}
}
