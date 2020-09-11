
#include <stdio.h>
#include "../cub3d.h"

void print_sets(t_sets sets)
{
	printf("%s\n", "-----------------------------");
	printf("R: |%d| |%d|\n", sets.r_x, sets.r_y);
	printf("NO: |%p|\n", sets.noth_texture);
	printf("SO: |%p|\n", sets.south_texture);
	printf("WE: |%p|\n", sets.west_texture);
	printf("EA: |%p|\n", sets.east_texture);
	printf("S: |%p|\n", sets.sprite_texture);
	printf("F: |%d| |%d| |%d|\n", sets.floor_r, sets.floor_g, sets.floor_b);
	printf("C: |%d| |%d| |%d|\n", sets.ceilling_r, sets.ceilling_g, sets.ceilling_b);
}
