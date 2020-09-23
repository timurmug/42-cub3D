
#include <stdio.h>
#include "../includes/cub3d.h"

void	print_sets(t_sets sets)
{
	printf("%s\n", "-----------------------------");
	printf("%map size: %d\n", sets.map_size_y);
	printf("R: |%d| |%d|\n", sets.wdw.r_x, sets.wdw.r_y);

	printf("NO: |%p| height: |%d| width: |%d| addr: |%p| size_line: |%d|\n", sets.n_txtr.img_data.img, \
	sets.n_txtr.img_data.height, sets.n_txtr.img_data.width, sets.n_txtr.img_data.addr, sets.n_txtr.img_data.size_line);

	printf("SO: |%p| height: |%d| width: |%d| addr: |%p| size_line: |%d|\n\n", sets.s_txtr.img_data.img, \
	sets.s_txtr.img_data.height, sets.s_txtr.img_data.width, sets.s_txtr.img_data.addr, sets.s_txtr.img_data.size_line);

	printf("WE: |%p| height: |%d| width: |%d| addr: |%p| size_line: |%d|\n\n", sets.w_txtr.img_data.img, \
	sets.w_txtr.img_data.height, sets.w_txtr.img_data.width, sets.w_txtr.img_data.addr, sets.w_txtr.img_data.size_line);

	printf("EA: |%p| height: |%d| width: |%d| addr: |%p| size_line: |%d|\n\n", sets.e_txtr.img_data.img, \
	sets.e_txtr.img_data.height, sets.e_txtr.img_data.width, sets.e_txtr.img_data.addr, sets.e_txtr.img_data.size_line);

	printf("S: |%p| height: |%d| width: |%d| addr: |%p| size_line: |%d|\n\n", sets.sprt_txtr.img_data.img, \
	sets.sprt_txtr.img_data.height, sets.sprt_txtr.img_data.width, sets.sprt_txtr.img_data.addr, sets.sprt_txtr.img_data.size_line);
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
