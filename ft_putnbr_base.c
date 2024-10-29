/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:02:35 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/29 17:40:10 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static char	*get_base(char letter)
{
	if (letter == 'x' || letter == 'p')
		return ("0123456789abcdef");
	if (letter == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

int	ft_putnbr_base(unsigned int nbr, char letter)
{
	int		size_base;
	int		nbr_final[100];
	char	*base;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (letter == 'p')
		res += ft_putstr("0x");
	base = get_base(letter);
	size_base = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i++] = nbr % size_base;
			nbr = nbr / size_base;
		}
		while (--i >= 0)
			res += ft_putchar(base[nbr_final[i]]);
	}
	return (res);
}
