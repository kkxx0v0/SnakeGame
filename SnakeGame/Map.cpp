#include "Map.h"

Map::Map(int row, int col, int size)
{
	ROW = row;
	COL = col;
	SIZE = size;
	pMap = new int* [ROW];
	for (int i = 0; i < ROW; i++)
	{
		pMap[i] = new int[COL];
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
				pMap[i][j] = 墙;
			else
				pMap[i][j] = 空;
		}
	}
}

void Map::DrawMap()
{
	BeginBatchDraw();
	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COL; j++)
		{
			switch (pMap[i][j])
			{
			case 空:
				SetColor(i, j, WHITE);
				break;
			case 墙:
				SetColor(i, j, BLACK);
				break;
			case 蛇:
				SetColor(i, j, RED);
				break;
			case 食物:
				SetColor(i, j, BLUE);
				break;
			default:
				break;
			}
		}
	}
	EndBatchDraw();
}

void Map::SetColor(int i, int j,int color)
{
	//空为白色 墙为黑色 蛇为红色 食物为蓝色
	setfillcolor(color);
	fillrectangle(i * SIZE, j * SIZE, (i + 1) * SIZE, (j + 1) * SIZE);
}