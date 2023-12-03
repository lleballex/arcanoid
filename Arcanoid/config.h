#pragma once

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

//enum SCENE {
//	NONE = 0,
//	QUIT = 1,
//	HOME = 2,
//	GAME = 3,
//	RULES = 4,
//	ABOUT = 5,
//};

enum EVENT {
	QUIT = 0,
	GO_HOME = 1,
	GO_GAME = 2,
	GO_RULES = 3,
	GO_ABOUT = 4,
	CLICK = 5,
	HOVER = 6,
	UNHOVER = 7
};

enum COLOR {
    WHITE = 0xFEFCFFFF,
    BLACK = 0x000000FF,
    RED = 0xFF0000FF,
    BLUE = 0x0000FFFF,
    GREEN = 0x00FF00FF,
    PURPLE = 0x6A62DDFF,
    PURPLE_HOVER = 0xA888F9FF,
    BACKGROUND = 0x242132FF
};

enum DIRECTION {
	NO_DIRECTION = 0,
	TOP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4
};
