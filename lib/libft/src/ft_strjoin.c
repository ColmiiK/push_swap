/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:35:38 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/10 12:35:03 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(len);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined, s2, len);
	return (joined);
}

// int main()
// {
// 	char *s1 = "Hello";
// 	char *s2 = "World";
// 	char *joined = ft_strjoin(s1, s2);

// 	printf("%s\n", joined);
// 	free(joined);
// }