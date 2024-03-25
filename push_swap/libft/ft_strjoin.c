/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 17:31:23 by kchahmi       #+#    #+#                 */
/*   Updated: 2023/11/04 20:32:21 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s1 == NULL || s2 == NULL || s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}
