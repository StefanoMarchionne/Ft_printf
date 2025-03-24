#include "libft.h"

/*!
 * @brief 
	Outputs the string ’s’ to the given file descriptor followed by a newline.
 * @param s
	The string to output.
 * @param fd
	The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}
