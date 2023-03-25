#ifndef __GAME_H__
#define __GAME_H__
#include<ctime>
#include<stdlib.h>
#include "Map.h"
#include "Snake.h"

//食物类
struct Food
{
	Node pos;
	int FoodNum;
	Food();
};

//游戏类

struct Game
{
	int ROW, COL, SIZE, SPEED;
	Snake* GameSnake;
	Map* GameMap;
	Food* GameFood;
	Game(int row = 48, int col = 48, int size = 20, int speed = 10)
	{
		ROW = row, COL = col, SIZE = size, SPEED = speed;
		GameSnake = nullptr;
		GameMap = nullptr;
		GameFood = nullptr;
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

	//5、显示蛇、食物的位置
	void PrintSnake(int val);
	void PrintFood();

	//6、随机生成食物
	void CreatFood();

	//7、更新游戏
	void update();
};

#endif // !__GAME_H__