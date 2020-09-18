
#include <stdio.h>
#include "../includes/cub3d.h"

void	print_sets(t_sets sets)
{
	printf("%s\n", "-----------------------------");
	printf("R: |%d| |%d|\n", sets.wdw.r_x, sets.wdw.r_y);
	printf("NO: |%p|\n", sets.noth_texture);
	printf("SO: |%p|\n", sets.south_texture);
	printf("WE: |%p|\n", sets.west_texture);
	printf("EA: |%p|\n", sets.east_texture);
	printf("S: |%p|\n", sets.sprite_texture);
	printf("F: |%d| \n", sets.floor_col);
	printf("C: |%d| \n", sets.ceiling_col);
}

void	print_strstr(char **strstr)
{
	int i;

	i = 0;
	while (strstr[i])
	{
		ft_putendl_fd(strstr[i], 1);
		i++;
	}
}
