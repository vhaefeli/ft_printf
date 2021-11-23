/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/23 15:35:14 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putustr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ((void) NULL);
	if (s[0] == '-')
		i++;
	while (i < ft_strlen(s))
		write (1, &s[i++], 1);
}

static size_t ft_printarg(const char *input, char *str, int j, int nbflag)
{
	size_t	addsize;
	size_t	i;
	char	*beforestr;

	i = j + nbflag;
//	printf("printarg: input[i] %c \n", input[i]);
//	printf("printarg: str%s\n",str); 

	addsize = ft_strlen(str);
	if (str[0] == 0)
		addsize = 1;
	beforestr = ft_flbefore(input, j, nbflag, str);
	ft_putstr_fd(beforestr, 1);
	ft_putustr(str);
	if (str[0] == '-')
		addsize--;
	addsize += ft_strlen(beforestr);
	addsize += ft_flafter(input, j, nbflag, str);
	free(beforestr);
	free(str);
//	printf("addsize: %lu\n", addsize);
	return (addsize);
}

size_t ft_printstr(const char *input, char *str, int j, int nbflag)
{
	size_t	addsize;

	if (!str)
	{
		write(1,"(null)",6);
		addsize = 6;
	}
	else if (ft_checktype(input, ".-", j, nbflag))
		addsize = ft_flstring(input, j, nbflag, str);
	else
	{
		ft_putstr_fd(str, 1);
		addsize = ft_strlen(str);
	}

	return (addsize);
}

size_t ft_argprint(const char *input, va_list args, int j, int nbflag)
{
	size_t	addsize;
	size_t	i;
	char	*str;

	i = j + nbflag;
	str = ft_argtype(input[i], args);
//	printf("argprint str:%s\n",str);
//	printf("input[i] %c \n", input[i]);
	if (input[i] == 's')
	{
		addsize = ft_printstr(input, str, j,nbflag);
	}
	else
	{
		addsize = ft_printarg(input, str, j, nbflag);
	}
	return (addsize);
}
