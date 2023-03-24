#ifndef __GAME_H__
#define __GAME_H__
#include<ctime>
#include<stdlib.h>
#include "Map.h"
#include "Snake.h"

//��Ϸ��

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

	//1����Ϸ��ʼ����
	//������ͼ��ʼ�� ��������
	void GameStart();

	//2������
	int run();

	//3���߳Ե�ʳ��
	void Eaten();

	//4��ʧ��
	void defeat();

	//5����ʾ�ߵ�λ��
	void PrintSnake();
};


#endif // !__GAME_H__