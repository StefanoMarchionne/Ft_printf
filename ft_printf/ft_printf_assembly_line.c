#include "ft_printf.h"

static void	ft_assembly_line_5(t_print **lst, t_flags flags, char ph, int len)
{
	int	start;

	len = t_print_size(*lst);
	if (flags.zero > 0 && !flags.dot && flags.zero > t_print_size(*lst) \
		&& (ph == 'i' || ph == 'u' || ph == 'x' || ph == 'X'))
	{
		start = 0;
		if ((*lst)->content == '-')
			start = 1;
		t_print_add_inside(lst, start, flags.zero - len, '0');
	}
	len = t_print_size(*lst);
	if (!(*lst)->content && ph != 'c')
		len--;
	if (((flags.width > 0 && flags.width > len) || ((ph == 's' \
		|| ph == 'x' || ph == 'X' || ph == 'p') && flags.width > len)) \
		&& !flags.zero)
	{
		while (flags.width - len)
		{
			t_print_add_front(lst, t_print_new_char_node(' '));
			flags.width--;
		}
	}
}

static void	ft_assembly_line_4(t_print **lst, t_flags flags, char ph, int len)
{
	if (flags.dash > 0 && flags.dash >= len)
	{
		if ((ph == 's' || ph == 'i' || ph == 'u' || ph == 'x' || ph == 'X' \
			|| ph == 'p') && !(*lst)->content)
		{
			len--;
			while (flags.dash - len)
			{
				t_print_add_front(lst, t_print_new_char_node(' '));
				flags.dash--;
			}
		}
		else
		{
			while (flags.dash - len)
			{
				t_print_add_back(lst, t_print_new_char_node(' '));
				flags.dash--;
			}
		}
	}
	ft_assembly_line_5(lst, flags, ph, t_print_size(*lst));
}

static void	ft_assembly_line_3(t_print **lst, t_flags flags, char ph, int len)
{
	if (flags.dot == -1 || (!ph && flags.dot && flags.dot < len))
	{
		if ((ph == 's' || ((ph == 'i' || ph == 'u' || ph == 'x' || ph == 'X') \
			&& (*lst)->content == '0')) || !ph)
		{
			t_print_del_last(lst, len - 1);
			(*lst)->content = 0;
		}
	}
	len = t_print_size(*lst);
	if (flags.dot > 0 && ((flags.dot >= len && (ph == 'i' || ph == 'u' \
		|| ph == 'x' || ph == 'X')) || (flags.dot <= len && ph == 's')))
	{
		if (ph == 's')
			t_print_del_last(lst, len - flags.dot);
		else if (ph == 'i' || ph == 'u' || ph == 'x' || ph == 'X')
		{
			if ((*lst)->content == '-' && len--)
				t_print_add_inside(lst, 1, flags.dot - len, '0');
			else
				t_print_add_inside(lst, 0, flags.dot - len, '0');
		}
	}
	ft_assembly_line_4(lst, flags, ph, t_print_size(*lst));
}

static void	ft_assembly_line_2(t_print **lst, t_flags flags, char ph, int len)
{
	if (flags.space)
	{
		if (ph == 'i' && (*lst)->content != '-' && !flags.plus)
			t_print_add_front(lst, t_print_new_char_node(' '));
		else if (ph == 's' && (flags.space >= len || flags.space == -1))
		{
			if (flags.space == -1)
				flags.space = 0;
			else
				len--;
			while (flags.space && flags.space - len)
			{
				t_print_add_front(lst, t_print_new_char_node(' '));
				flags.space--;
			}
		}
	}
	ft_assembly_line_3(lst, flags, ph, t_print_size(*lst));
}

void	ft_printf_assembly_line(t_print **lst, t_flags flags, char ph)
{
	if (flags.zero && flags.dot)
	{
		flags.width = flags.zero;
		flags.zero = 0;
	}
	if (flags.sharp && (ph == 'x' || ph == 'X') && (*lst)->content != '0')
	{
		if (ph == 'x')
			t_print_add_front(lst, t_print_new_char_node('x'));
		else if (ph == 'X')
			t_print_add_front(lst, t_print_new_char_node('X'));
		t_print_add_front(lst, t_print_new_char_node('0'));
	}
	if (flags.plus > 0 && ph == 'i' && (*lst)->content != '-')
		t_print_add_front(lst, t_print_new_char_node('+'));
	ft_assembly_line_2(lst, flags, ph, t_print_size(*lst));
}
