/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:55:54 by dbouizem          #+#    #+#             */
/*   Updated: 2025/07/18 21:17:16 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str = "hello";
	char	*null_str = NULL;
	int		n = 2025;
	int		*ptr = &n;
    int     retft = 0;
    int     ret = 0;

	printf("---------- %%c ----------\n");
	ret = printf("[%c]\n", 'A');
    printf("%d\n", ret);
	retft = ft_printf("[%c]\n", 'A');
    printf("%d\n", retft);

	ret = printf("[%c]\n", 0);
     printf("%d\n", ret);
	retft = ft_printf("[%c]\n", 0);
     printf("%d\n", retft);

	printf("---------- %%s ----------\n");
	ret = printf("[%s]\n", str);
    printf("%d\n", ret);
	retft = ft_printf("[%s]\n", str);
    printf("%d\n", retft);


	ret = printf("[%s]\n", "");
    printf("%d\n", ret);
	retft = ft_printf("[%s]\n", "");
    printf("%d\n", retft);

	ret = printf("[%s]\n", null_str);
    printf("%d\n", ret);
	retft = ft_printf("[%s]\n", null_str);
    printf("%d\n", retft);

	printf("---------- %%d / %%i ----------\n");
	ret = printf("[%d]\n", 0);
    printf("%d\n", ret);
	retft = ft_printf("[%d]\n", 0);
    printf("%d\n", retft);

	ret = printf("[%d]\n", -123);
    printf("%d\n", ret);
	retft = ft_printf("[%d]\n", -123);
    printf("%d\n", retft);

	ret = printf("[%d]\n", INT_MIN);
    printf("%d\n", ret);
	retft = ft_printf("[%d]\n", INT_MIN);
    printf("%d\n", retft);

	ret = printf("[%d]\n", INT_MAX);
    printf("%d\n", ret);
	retft = ft_printf("[%d]\n", INT_MAX);
    printf("%d\n", retft);

	ret = printf("[%i]\n", 42);
    printf("%d\n", ret);
	retft = ft_printf("[%i]\n", 42);
    printf("%d\n", retft);

	printf("---------- %%u ----------\n");
	ret = printf("[%u]\n", 0);
    printf("%d\n", ret);
	retft = ft_printf("[%u]\n", 0);
    printf("%d\n", retft);

	ret = printf("[%u]\n", 42);
    printf("%d\n", ret);
	retft = ft_printf("[%u]\n", 42);
    printf("%d\n", retft);

	ret = printf("[%u]\n", UINT_MAX);
    printf("%d\n", ret);
	retft = ft_printf("[%u]\n", UINT_MAX);
    printf("%d\n", retft);

	ret = printf("[%u]\n", -1);
    printf("%d\n", ret);
	retft = ft_printf("[%u]\n", -1);
    printf("%d\n", retft);

	printf("---------- %%x / %%X ----------\n");
	ret = printf("[%x]\n", 0);
    printf("%d\n", ret);
	retft = ft_printf("[%x]\n", 0);
    printf("%d\n", retft);

	ret = printf("[%x]\n", 255);
    printf("%d\n", ret);
	retft = ft_printf("[%x]\n", 255);
    printf("%d\n", retft);

	ret = printf("[%x]\n", UINT_MAX);
    printf("%d\n", ret);
	retft = ft_printf("[%x]\n", UINT_MAX);
    printf("%d\n", retft);

	ret = printf("[%x]\n", -1);
    printf("%d\n", ret);
	retft = ft_printf("[%x]\n", -1);
    printf("%d\n", retft);

	ret = printf("[%X]\n", 255);
    printf("%d\n", ret);
	retft = ft_printf("[%X]\n", 255);
    printf("%d\n", retft);

	printf("---------- %%p ----------\n");
	ret = printf("[%p]\n", (void *)ptr);
    printf("%d\n", ret);
	retft = ft_printf("[%p]\n", (void *)ptr);
    printf("%d\n", retft);

	ret = printf("[%p]\n", NULL);
    printf("%d\n", ret);
	retft = ft_printf("[%p]\n", NULL);
    printf("%d\n", retft);

	printf("---------- %% ----------\n");
	ret = printf("[%%]\n");
    printf("%d\n", ret);
	retft = ft_printf("[%%]\n");
    printf("%d\n", retft);

	printf("---------- MIX ----------\n");
	ret = printf("[%s] [%d] [%u] [%x] [%p] [%c] [%%]\n", str, -42, 42u, 0xff, &n, 'Z');
    printf("%d\n", ret);
	retft = ft_printf("[%s] [%d] [%u] [%x] [%p] [%c] [%%]\n", str, -42, 42u, 0xff, &n, 'Z');
    printf("%d\n", retft);

	return(0);
}
