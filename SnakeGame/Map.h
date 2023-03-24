#ifndef __MAP_H__
#define __MAP_H__
#include<vector>
using namespace std;

//1、地图元素
//设置地图元素	使用enum枚举
//	0空	1墙	2蛇	3食物
enum { 空 = 0, 墙 = 1, 蛇 = 2, 食物 = 3 };

//地图类
struct Map
{
	vector<vector<int>> pMap;
	//2、地图大小设定
	int ROW;	//行
	int COL;	//列
	int SIZE; //方块大小

	//3、地图初始化
	Map(int row, int col, int size);
	
};


#endif // !__MAP_H__