/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:55:54 by dbouizem          #+#    #+#             */
/*   Updated: 2025/07/18 21:10:38 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str = "hello";
	char	*null_str = NULL;
	int		n = 2025;
	int		*ptr = &n;

	printf(NULL);
	ft_printf(NULL);

	printf("---------- %%c ----------\n");
	printf("printf: [%c]\n", 'A');
	ft_printf("ft_printf: [%c]\n\n", 'A');

	printf("printf: [%c]\n", 0);
	ft_printf("ft_printf: [%c]\n\n", 0);

	printf("---------- %%s ----------\n");
	printf("printf: [%s]\n", str);
	ft_printf("ft_printf: [%s]\n\n", str);

	printf("printf: [%s]\n", "");
	ft_printf("ft_printf: [%s]\n\n", "");

	printf("printf: [%s]\n", null_str);
	ft_printf("ft_printf: [%s]\n\n", null_str);

	printf("---------- %%d / %%i ----------\n");
	printf("printf: [%d]\n", 0);
	ft_printf("ft_printf: [%d]\n\n", 0);

	printf("printf: [%d]\n", -123);
	ft_printf("ft_printf: [%d]\n\n", -123);

	printf("printf: [%d]\n", INT_MIN);
	ft_printf("ft_printf: [%d]\n\n", INT_MIN);

	printf("printf: [%d]\n", INT_MAX);
	ft_printf("ft_printf: [%d]\n\n", INT_MAX);

	printf("printf: [%i]\n", 42);
	ft_printf("ft_printf: [%i]\n\n", 42);

	printf("---------- %%u ----------\n");
	printf("printf: [%u]\n", 0);
	ft_printf("ft_printf: [%u]\n\n", 0);

	printf("printf: [%u]\n", 42);
	ft_printf("ft_printf: [%u]\n\n", 42);

	printf("printf: [%u]\n", UINT_MAX);
	ft_printf("ft_printf: [%u]\n\n", UINT_MAX);

	printf("printf: [%u]\n", -1);
	ft_printf("ft_printf: [%u]\n\n", -1);

	printf("---------- %%x / %%X ----------\n");
	printf("printf: [%x]\n", 0);
	ft_printf("ft_printf: [%x]\n\n", 0);

	printf("printf: [%x]\n", 255);
	ft_printf("ft_printf: [%x]\n\n", 255);

	printf("printf: [%x]\n", UINT_MAX);
	ft_printf("ft_printf: [%x]\n\n", UINT_MAX);

	printf("printf: [%x]\n", -1);
	ft_printf("ft_printf: [%x]\n\n", -1);

	printf("printf: [%X]\n", 255);
	ft_printf("ft_printf: [%X]\n\n", 255);

	printf("---------- %%p ----------\n");
	printf("printf: [%p]\n", (void *)ptr);
	ft_printf("ft_printf: [%p]\n\n", (void *)ptr);

	printf("printf: [%p]\n", NULL);
	ft_printf("ft_printf: [%p]\n\n", NULL);

	printf("---------- %% ----------\n");
	printf("printf: [%%]\n");
	ft_printf("ft_printf: [%%]\n\n");

	printf("---------- MIX ----------\n");
	printf("printf: [%s] [%d] [%u] [%x] [%p] [%c] [%%]\n", str, -42, 42u, 0xff, &n, 'Z');
	ft_printf("ft_printf: [%s] [%d] [%u] [%x] [%p] [%c] [%%]\n\n", str, -42, 42u, 0xff, &n, 'Z');


	printf("----------- Overflow tests -----------\n");

	int overflow_plus = INT_MAX + 1;
	int overflow_minus = INT_MIN - 1;
	unsigned int u_overflow = -1;

	printf("INT_MAX        : %d\n", INT_MAX);
	printf("INT_MAX + 1    : %d\n", overflow_plus);
	ft_printf("ft INT_MAX + 1 : %d\n\n", overflow_plus);

	printf("INT_MIN        : %d\n", INT_MIN);
	printf("INT_MIN - 1    : %d\n", overflow_minus);
	ft_printf("ft INT_MIN - 1 : %d\n\n", overflow_minus);

	printf("UINT_MAX       : %u\n", UINT_MAX);
	printf("Unsigned -1    : %u\n", u_overflow);
	ft_printf("ft Unsigned -1 : %u\n\n", u_overflow);

	return(0);
}
