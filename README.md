# cub3D
Raycasting 42 project using miniLibX.

## Config file
This file is given as first argument to a program and contains info about:
* Screen resolution
* Notrh, South, East, West textrures for walls and sprite in .xpm files
* Ceiling and floor color in RGB format
* Map where 1 - wall, 0 - empty space, N/W/E/S - initial direction of a player, 2 - sprite

## Config file validation
If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message. *Some of the following requirements are subjective, since the task is blurry.*
* File must exist and open 
* File extension must be ".cub"
* RGB diapason must in 0, 255 
* In param line must not be whitespaces in the beginning and ending
* Except for the map content, each type of element can be separated by one or more empty line
* Except for the map content which always has to be the last, each type of element can be set in any order in the file
* Except for the map, each type of information from an element can be separated by one or more space(s)
* Map must be closed
* All parameters are required and must exist only once
* In map must be one player and only symbols 1/2/0
* Resolution must be > 0
* If resolution > screen resolution, resolution = screen resolution
* After map it shouldn't be any lines
* Textures must be valid
* Except map and params shouldn't be any other lines
* 0/1/2 (empty space, player and sprite) in map should be closed by 1 (walls)

## --save
Program is saving the first rendered image in bmp format when its second argument is "--save".
	./cub3D configs/config.cub --save

## Example
![Cub3D](https://user-images.githubusercontent.com/51258482/94657936-d56a4580-030a-11eb-9e64-037950ae0a20.jpg)
