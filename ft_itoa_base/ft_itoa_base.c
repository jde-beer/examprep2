/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-beer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:19:29 by jde-beer          #+#    #+#             */
/*   Updated: 2019/12/03 11:37:46 by jde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	long num;
	int len;
	char *str;
	char *ref_str = "0123456789ABCDEF";

	num = value;
	len = 0;
	if (value == 0)
		return ("0");
	while (num)
	{
		num = num / base;
		len++;
	}
	num = value;
	if (value < 0)
	{
		if (base == 10)
			len++;
		num = num * -1;
	}
	str = (char *)malloc(sizeof(char) * len);
	str[len] = '\0';
	while (num)
	{
		len--;
		str[len] = ref_str[num % base];
		num = num / base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return(str);
}
