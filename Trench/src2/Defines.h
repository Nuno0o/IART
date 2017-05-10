#pragma once

#define BOARD_SIZE 8

#define COLOR_BLACK			0
#define COLOR_BLUE			1
#define COLOR_GREEN			2
#define COLOR_CYAN			3
#define COLOR_RED			4
#define COLOR_MAGENTA		5
#define COLOR_BROWN			6
#define COLOR_LIGHTGRAY		7
#define COLOR_DARKGRAY		8
#define COLOR_LIGHTBLUE		9
#define COLOR_LIGHTGREEN	10
#define COLOR_LIGHTCYAN		11
#define COLOR_LIGHTRED		12
#define COLOR_LIGHTMAGENTA	13
#define COLOR_YELLOW		14
#define COLOR_WHITE			15

//Coordinate
typedef char MCoord;
//Move angle
//1 -> (0,1) , 2 -> (1,1) , 3 -> (1,0)...(continues clockwise)
typedef unsigned char MAngle;
//Move length
typedef unsigned char MLength;
//Team
enum Team : char {
	White, Black
};