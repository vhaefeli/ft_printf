/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:11:24 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
void	ft_putustr(char *s)
{	
	int i;

	i = 0;
	if (!s)
		return ((void) NULL);
	if (s[0] = "-")
		i++;
	while (i < ft_strlen(s))
		write (1, s[i], 1);
}

int ft_processargprintf(const char *input, va_list args, int j, const int nbflag)
{
	size_t	addsize;
	int		i;
	char	*str;
	char	*beforestr;

	i = j + nbflag;
	str = ft_processargtype(input[i], args);
	addsize = ft_strlen(str);
	beforestr = ft_processflagbefore(input, j, nbflag, str);
	ft_putstr_fd(beforestr, 1);
	ft_putustr(str);
	addsize += ft_strlen(beforestr) + ft_processflagafter(input, j, nbflag, str);
	free(str);
	free(beforestr);
	return (addsize);
}
