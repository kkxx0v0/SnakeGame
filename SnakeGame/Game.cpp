#include "Game.h"

void Game::GameStart()
{
	//时间数种子
	srand((unsigned)time(NULL));

	//初始化蛇、地图
	GameSnake = &Snake(SPEED);
	GameSnake->head->row = ROW / 2;
	GameSnake->head->row = COL / 2;
	GameSnake->head->next->row = ROW / 2;
	GameSnake->head->next->row = COL / 2;

	GameMap = &Map(ROW,COL,SIZE);
	for (int i = 0; i< ROW - 1;i++)
	{
		for (int j = 0; j < COL - 1; j++)
		{
			if (i == 0 || i == ROW -1 || j == 0 || j == COL -1)
				GameMap->pMap[i][j] = 墙;
			else
				GameMap->pMap[i][j] = 空;
		}
	}
	PrintSnake();
}

int Game::run()
{
	return 0;
}

void Game::Eaten()
{
}

void Game::defeat()
{
}

void Game::PrintSnake()
{
	Snake* s = GameSnake;
	Node* pNode = s->head;
	while (s)
	{
		GameMap->pMap[pNode->row][pNode->col] = 蛇;
	}
}
