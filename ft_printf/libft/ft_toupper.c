#include "libft.h"

/*!
 * @brief 
		This function convert lowercase letters to uppercase.

	If c is a lowercase letter, toupper() returns its uppercase equivalent, if 
	an uppercase representation exists in the current locale, otherwise, it 
	returns c.

	If c is neither an unsigned char value nor EOF, the behavior of this 
	function is	undefined.
 * @return 
	The value returned is that of the converted letter, or c if the conversion 
	was not	possible.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
