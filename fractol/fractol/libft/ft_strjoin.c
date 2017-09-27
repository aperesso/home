/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 21:54:05 by alexia            #+#    #+#             */
/*   Updated: 2017/04/18 22:55:16 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	h;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		k = -1;
		h = -1;
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (s1[++k] != '\0')
			str[k] = s1[k];
		while (s2[++h] != '\0')
			str[k++] = s2[h];
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
