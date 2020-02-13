/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:44:36 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 07:51:04 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str_sub;
	unsigned int	count;

	if (!(str_sub = ft_strnew(len)) || !s)
		return (NULL);
	str = (char *)s;
	count = 0;
	while (count < len)
	{
		str_sub[count] = str[start];
		start++;
		count++;
	}
	return (str_sub);
}
