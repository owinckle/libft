/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:40:37 by owinckle          #+#    #+#             */
/*   Updated: 2015/12/15 16:17:12 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*static int		numcheck(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	else
	{
		while (n > 10)
		{
			i++;
			n /=10;
		}
	}	
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*buf;
	unsigned int 	x;
	int 			sign;

	buf = ft_strnew(numcheck(n));
	if (buf == NULL)
		return (NULL);
	x = n;
	if ((sign = n) < 0)
		x = -n;
	i = 0;
	if (x == 0)
		buf[i++] = '0';
	while (x > 0)
	{
		buf[i++] = x % 10 + '0';
		x /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}*/

static void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char*ft_itoa(int n)
{
	int		tmpn;
	int 	len;
	int		negative;
	char	*str;

	if (n == -2147483648)					
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
