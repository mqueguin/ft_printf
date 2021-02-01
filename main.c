#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char c = 2147483647;
	char *str = "Hello World !";
	char	*test = NULL;
	printf("------------------ %%c -----------------\n\n");
	ft_printf("Test ft_printf\n");
	printf("Vrai : |%c|\n", c);
	ft_printf("|%c|\n", c);
	/*printf("Vrai : |%15c|\n", c);
	ft_printf("|%15c|\n", c);
	printf("Vrai : |%-15c|\n", c);
	ft_printf("|%-15c|\n", c);
	printf("Vrai : |%015c|\n", c); //undefined
	ft_printf("undefined : |%015c|\n", c);
	printf("Vrai : |%0-15c|\n", c); //undefined
	ft_printf("undefined : |%0-15c|\n", c);
	printf("Vrai : |%-*c|\n", 15, c);
	ft_printf("|%-*c|\n", 15, c);
	printf("Vrai : |%-*c|\n", -15, c);
	ft_printf("|%-*c|\n", -15, c);
	printf("Vrai : |%0*c|\n", 15, c); //undefined
	ft_printf("undefined : |%0*c|\n", 15, c);
	printf("Vrai : |%15.3c|\n", c); //undefined
	ft_printf("undefined : |%15.3c|\n", c);
	printf("Vrai : |%-2.5c|\n", c); //undefined
	ft_printf("undefined : |%-2.5c|\n", c);
	printf("Vrai : |%*.*c|\n", 10, 4, c); //undefined
	ft_printf("undefined : |%*.*c|\n", 10, 4, c);
	printf("Vrai : |%.4c|\n", c); //undefined
	ft_printf("undefined : |%.4c|\n", c);
	printf("Vrai : |%4.c|\n", c);
	ft_printf("|%4.c|\n", c);
	printf("Vrai : |%.c|\n", c);
	ft_printf("|%.c|\n", c);
	printf("Vrai : |%12c| |%4c|\n", c, c);
	ft_printf("|%12c| |%4c|\n", c, c);
	printf("\n---------------- %%s -----------------\n\n");
	printf("test vrai printf %%s sans flags : |%s|\n", str);
	ft_printf("Test %%s sans flags : |%s|\n", str);
	printf("Test vrai printf %%s avec width de 1 : |%1s|\n", str);
	ft_printf("Test %%s avec width de 1 : |%1s|\n", str);
	printf("Test vrai printf %%s avec width de 14 : |%14s|\n", str);
	ft_printf("Test %%s avec width de 14 : |%14s|\n", str);
	//printf("Test vrai printf %%s avec width de 0 : |%0s|\n", str);
	ft_printf("Test %%s avec width de 0 : |%0s|\n", str);
	printf("Test vrai printf %%s avec - et width de 18 : |%-18s|\n", str);
	ft_printf("test %%s avec - et width de 18 : |%-18s|\n", str);
	//printf("Test vrai printf %%s avec 0 * et width de 18 : |%0*s|\n", 18, str);
	ft_printf("test %%s avec 0 * et width de 18 : |%0*s|\n", 18, str);
	//printf("Test vrai printf %%s avec 0 * et width de 4 : |%0*s|\n", 4, str);
	ft_printf("test %%s avec 0 * et width de 4 : |%0*s|\n", 4, str);
	printf("test vrai printf %%s avec precision : |%.s|\n", str);
	ft_printf("test %%s avec precision : |%.s|\n", str);
	//printf("Test vrai printf %%s avec 0 * : |%0*s|\n", -15, str);
	ft_printf("Test %%s avec 0 * : |%0*s|\n", -15, str);
	//printf("Test %%s avec - et 2 * et precision : |%0-*.*s|\n", 0, 0, (null));
	//printf("Test vrai printf : |%0*s|\n", -15, str);
	printf("Test vrai printf : |%-.*s|\n", 0, str);
	ft_printf("Test %%s : |%-.*s|\n", 0, str);// Warning does NOT WORKING
	printf("Test avec vrai printf : |%-*.*s|\n", 15, 0, test);
	ft_printf("Test %%s avec width de 1 : %1s\n", str);
	ft_printf("Test %%s avec width de 14 : %14s\n", str);
	ft_printf("Test %%s avec width de 0 : %0s\n", str);
	ft_printf("test %%s avec - et width de 18 : %-18s\n", str);
	ft_printf("test %%s avec 0 * et width de 18 : %0*s\n", 18, str);
	ft_printf("test %%s avec 0* et width de 4 : %0*s\n", 4, str);
	printf("test vrai printf %%s avec precision 22.4 : %22.4s\n", str);
	ft_printf("test %%s avec precision de 22.4 : %22.4s\n", str);
	//printf("test vrai printf %%s avec precision de 22.4 et 0 : %022.4s\n", str);
	ft_printf("test %%s avec precision de 22.4 et 0 : %022.4s\n", str);*/
	return 0;
}