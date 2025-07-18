/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:55:54 by dbouizem          #+#    #+#             */
/*   Updated: 2025/07/18 21:11:27 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int main(void)
{
	int n = 42;

	ft_printf("%c", 'A');
 	printf("%c", 'A');

	ft_printf("%s", "hello");
 	printf("%s", "hello");

	ft_printf("%d", 42);
 	printf("%d", 42);

	ft_printf("%u", 42u);
 	printf("%u", 42u);

	ft_printf("%x", 255);
 	printf("%x", 255);

	ft_printf("%X", 255);
 	printf("%X", 255);

	ft_printf("%p", &n);
 	printf("%p", &n);

	ft_printf("%%");
	printf("%%");

printf("===== OK: =====\n");

 int n = 42;

    ft_printf("[%07i]\n", -54);
//"-000054"

    ft_printf("[%07d]\n", -54);
//"-000054"

    ft_printf("{%010d}\n", -42);
//"{-000000042}"

    ft_printf("[%020d]\n", -1024);
//"-0000000000000001024"

    ft_printf("[%020i]\n", -1024);
//"-0000000000000001024"

	printf("%.*s", 3, "Hello");
	printf(" Original : |%-+10.5d| |%#08x| |%.*s| |%20p| |%c|\n", x, 255, 3, "Test", &x, 'A');
	ft_printf("ft_printf : |%-+10.5d| |%#08x| |%.*s| |%20p| |%c|\n", x, 255, 3, "Test", &x, 'A');

	printf("===== SPECIFIER: %%c =====\n");
	ft_printf("Char simple       : [%c]\n", 'A');//[A]
	ft_printf("Char with width   : [%5c]\n", 'B');//[    B]
	ft_printf("Char left align   : [%-5c]\n", 'C');//[C    ]
	ft_printf("Char \\0           : [%c]\n", '\0');//[]
	ft_printf("Char \\0 padded    : [%5c]\n", '\0');//[    ]

	printf("\n===== SPECIFIER: %%s =====\n");
	ft_printf("String simple     : [%s]\n", "Hello");//[Hello]
	ft_printf("String width      : [%10s]\n", "World");//[     World]
	ft_printf("String precision  : [%.3s]\n", "Truncate");//[Tru]
	ft_printf("Left align + prec : [%-10.5s]\n", "Align");//[Align     ]
	ft_printf("NULL string       : [%s]\n", (char *)NULL);//[(null)]
	ft_printf("NULL str width    : [%10s]\n", (char *)NULL);//[    (null)]
	ft_printf("NULL str prec     : [%.3s]\n", (char *)NULL);//[]

	printf("\n===== SPECIFIER: %%p =====\n");
	ft_printf("Pointer address   : [%p]\n", &x);//[0x7ffce4c52e14]
	ft_printf("NULL pointer      : [%p]\n", NULL);//[(nil)]

	printf("\n===== SPECIFIER: %%d / %%i =====\n");
	ft_printf("Int simple        : [%d]\n", 42);//[42]
	ft_printf("Negative int      : [%i]\n", -42);//[-42]
	ft_printf("+ flag            : [%+d]\n", 42);//[+42]
	ft_printf("Space flag        : [% d]\n", 42);//[ 42]
	ft_printf("Zero padded       : [%05d]\n", 42);//[00042]
	ft_printf("Left align        : [%-5d]\n", 42);//[42   ]
	ft_printf("Precision         : [%.4d]\n", 42);//[0042]
	ft_printf("Width + prec      : [%8.4d]\n", 42);//[    0042]
	ft_printf("Int max           : [%d]\n", INT_MAX);//[2147483647]
	ft_printf("Int min           : [%d]\n", INT_MIN);//[-2147483648]
	ft_printf("Zero + .0         : [%.0d]\n", 0);//[]
	ft_printf("Zero + width .0   : [%5.0d]\n", 0);//[     ]

	printf("\n===== SPECIFIER: %%u =====\n");
	ft_printf("Unsigned          : [%u]\n", 123456);//[123456]
	ft_printf("Zero padded       : [%08u]\n", 123456);//[00123456]
	ft_printf("Precision         : [%.5u]\n", 123);//[00123]
	ft_printf("Width + prec      : [%10.5u]\n", 123);//[     00123]
	ft_printf("Zero with .0      : [%.0u]\n", 0);//[]

	printf("\n===== SPECIFIER: %%x / %%X =====\n");
	ft_printf("Hex lower         : [%x]\n", 255);//[ff]
	ft_printf("Hex upper         : [%X]\n", 255);//[FF]
	ft_printf("With # lower      : [%#x]\n", 255);//[0xff]
	ft_printf("With # upper      : [%#X]\n", 255);//[0XFF]
	ft_printf("Zero padded       : [%08x]\n", 255);//[000000ff]
	ft_printf("Precision         : [%.4x]\n", 255);//[00ff]
	ft_printf("Width + prec      : [%10.4x]\n", 255);//[      00ff]
	ft_printf("Zero hex          : [%x]\n", 0);//[0]
	ft_printf("Zero with .0      : [%.0x]\n", 0);//[]
	ft_printf("Zero with #       : [%#x]\n", 0);//[0]

	printf("\n===== SPECIFIER: %% =====\n");
	ft_printf("Percent literal   : [%%]\n");//[%]
	ft_printf("Width + %%         : [%5%]\n");//[%]
	ft_printf("Left align %%      : [%-5%]\n");//[%]

	printf("\n===== MODIFICATEURS DE LENGTH =====\n");

	short s = -32768;
	signed char sc = -128;
	long l = 2147483648;
	long long ll = 9223372036854775807LL;
	unsigned short us = 65535;
	unsigned char uc = 255;
	unsigned long ul = 4294967295UL;
	unsigned long long ull = 18446744073709551615ULL;

	ft_printf("%%lc  : [%lc]\n", L'你');//[你]
	ft_printf("%%lc  : [%5lc]\n", L'你');//[你]

	write(1, "write test : \xC3\xA9\n", 15 + ft_strlen("\xC3\xA9"));

	ft_printf("%%hd  : [%hd]\n", s);//[-32768]
	ft_printf("%%hhd : [%hhd]\n", sc);//[-128]
	ft_printf("%%ld  : [%ld]\n", l);//[-2147483648]
	ft_printf("%%lld : [%lld]\n", ll);//[-9223372036854775807]

	ft_printf("%%hu  : [%hu]\n", us);//[65535]
	ft_printf("%%hhu : [%hhu]\n", uc);//[255]
	ft_printf("%%lu  : [%lu]\n", ul);//[4294967295]
	ft_printf("%%llu : [%llu]\n", ull);//[18446744073709551615]

	ft_printf("%%lx  : [%lx]\n", ul);//[ffffffff]
	ft_printf("%%llx : [%llx]\n", ull);//[ffffffffffffffff]
	ft_printf("%%lX  : [%lX]\n", ul);//[FFFFFFFF]
	ft_printf("%%llX : [%llX]\n", ull);//[FFFFFFFFFFFFFFFF]

	return (0);
}
