#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(int ac, char **av)
{
	int	ret;

	(void)ac;
	(void)av;
	ret = ft_printf("%%500%% : [%500%]\n");
	ret = ft_printf("%%10.5d : [%10.5d]\n", 3543);
	ret = ft_printf("%%*5x : [%*5x]\n", 10, 6546);
	ret = ft_printf("%%6.8o : [%6.8o]\n", 6546);
	ret = ft_printf("%%*.*s : [%*.*s]\n", 20, 10, "qwertqwertasdfg");
	ret = ft_printf("%%.4s : [%.4s]\n", "Bonjour !");
	ret = ft_printf("%%06u %%c %%d : [%06u] [%3c] [%4d]\n", 6546, 0, 1);
	ret = ft_printf("%%06000d : %06000d\n", 6546);
	ret = ft_printf("%%06x : %06x\n", 6547);
	ret = ft_printf("[%s]", "abc");
	ft_printf("[%d]\n", ret);
	ret = ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_printf("[%d]\n", ret);
	ret = printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("[%d]\n", ret);
	ret = ft_printf("my %4.15S", L"我是一只猫。");
	ft_printf("[%d]\n", ret);
	ret = printf("%4.15S", L"我是一只猫。");
	printf("[%d]\n", ret);
	ret = ft_printf("my %15.4S", L"我是一只猫。");
	ft_printf("[%d]\n", ret);
	ret = printf("%15.4S", L"我是一只猫。");
	printf("[%d]\n", ret);
	ret = ft_printf("my %.4S", L"我是一只猫。");
	ft_printf("[%d]\n", ret);
	ret = printf("%.4S", L"我是一只猫。");
	printf("[%d]\n", ret);
	printf("\%#.o/\n", -42);
	ret = ft_printf("%#.0o", -42);
	return (0);
}
