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
				pMap[i][j] = ǽ;
			else
				pMap[i][j] = ��;
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
			case ��:
				SetColor(i, j, WHITE);
				break;
			case ǽ:
				SetColor(i, j, BLACK);
				break;
			case ��:
				SetColor(i, j, RED);
				break;
			case ʳ��:
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
	//��Ϊ��ɫ ǽΪ��ɫ ��Ϊ��ɫ ʳ��Ϊ��ɫ
	setfillcolor(color);
	fillrectangle(i * SIZE, j * SIZE, (i + 1) * SIZE, (j + 1) * SIZE);
}