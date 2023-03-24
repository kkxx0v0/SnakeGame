#ifndef __GAME_H__
#define __GAME_H__
#include<ctime>
#include<stdlib.h>
#include "Map.h"
#include "Snake.h"

//游戏类

struct Game
{
	int ROW, COL, SIZE, SPEED;
	Snake* GameSnake;
	Map* GameMap;
	Game(int row = 48, int col = 48, int size = 20, int speed = 10)
	{
		ROW = row, COL = col, SIZE = size, SPEED = speed;
		GameSnake = nullptr;
		GameMap = nullptr;
	}

	//1、游戏开始函数
	//包含地图初始化 变量设置
	void GameStart();

	//2、运行
	int run();

	//3、蛇吃到食物
	void Eaten();

	//4、失败
	void defeat();

	//5、显示蛇的位置
	void PrintSnake();
};


#endif // !__GAME_H__