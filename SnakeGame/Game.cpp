#include "Game.h"

void Game::GameStart()
{
	//ʱ��������
	srand((unsigned)time(NULL));

	//��ʼ���ߡ���ͼ
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
				GameMap->pMap[i][j] = ǽ;
			else
				GameMap->pMap[i][j] = ��;
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
		GameMap->pMap[pNode->row][pNode->col] = ��;
	}
}
