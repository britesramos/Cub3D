/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/28 19:16:28 by sramos        #+#    #+#                 */
/*   Updated: 2023/10/28 19:45:49 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = ft_strlen(s);
	ch = c;
	if (ch == 0)
		return ((char *) &s[len]);
	while (len--)
	{
		if (s[len] == ch)
			return ((char *) &s[len]);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = NULL;
	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
		return (ft_substr(s, 0, 0));
	if (start + len < ft_strlen(s))
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (len-- && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *ns;
	int start;
	int end;

	start = 0;
	end = ft_strlen(s1);
	while(ft_strchr(set, s1[start]))
		start++;
	while(ft_strrchr(set, s1[end]))
		end--;
	ns = ft_substr(s1, start, end - start + 1);
	if (!ns)
		return (0);
	return(ns);
}

// int	main(void)
// {
// 	char *string = "0123456543210";
// 	char *set = "5216430";
// 	printf("This is ns: %s\n", ft_strtrim(string, set));
// 	return (0);
// }
