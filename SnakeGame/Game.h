#ifndef __GAME_H__
#define __GAME_H__
#include<ctime>
#include<stdlib.h>
#include "Map.h"
#include "Snake.h"

//ʳ����
struct Food
{
	Node pos;
	int FoodNum;
	Food();
};

//��Ϸ��

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

	//1����Ϸ��ʼ����
	//������ͼ��ʼ�� ��������
	void GameStart();

	//2������
	int run();

	//3���߳Ե�ʳ��
	void Eaten();

	//4��ʧ��
	void defeat();

	//5����ʾ�ߡ�ʳ���λ��
	void PrintSnake(int val);
	void PrintFood();

	//6���������ʳ��
	void CreatFood();

	//7��������Ϸ
	void update();
};

#endif // !__GAME_H__