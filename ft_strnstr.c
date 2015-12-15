/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:42:25 by owinckle          #+#    #+#             */
/*   Updated: 2015/12/15 11:51:25 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		lastresult;

	if (*s2 == '\0')
		return ((char*)s1);
	len = ft_strlen(s2);
	lastresult = 1;
	while (len <= n && *s1 != '\0'
			&& (lastresult = ft_strncmp(s1, s2, len)))
	{
		n--;
		s1++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)s1);
}
