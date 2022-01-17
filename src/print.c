#include "libunit.h"

void	print_header(const char *str)
{
	uint32_t	i;
	size_t		len;

	i = 0;
	len = ft_strlen(str) + 20;
	printf(MAG);
	while (i++ < len)
		printf("#");
	printf("\n");
	printf("#####     "CYN"%s"MAG"     #####\n", str);
	while (--i)
		printf("#");
	printf("\n");
	printf(RESET);
}