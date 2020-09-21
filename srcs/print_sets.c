
#include <stdio.h>
#include "../includes/cub3d.h"

void	print_sets(t_sets sets)
{
	printf("%s\n", "-----------------------------");
	printf("R: |%d| |%d|\n", sets.wdw.r_x, sets.wdw.r_y);
	printf("NO: |%p|\n", sets.n_txtr.img_data.img);
	printf("SO: |%p|\n", sets.s_txtr.img_data.img);
	printf("WE: |%p|\n", sets.w_txtr.img_data.img);
	printf("EA: |%p|\n", sets.e_txtr.img_data.img);
	printf("S: |%p|\n", sets.sprt_txtr.img_data.img);
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
