#include "Map.h"

Map::Map(int row, int col, int size)
{
	ROW = row;
	COL = col;
	SIZE = size;
	pMap = vector<vector<int>>(ROW, vector<int>(COL));
}
