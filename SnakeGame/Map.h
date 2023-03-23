#ifndef __MAP_H__
#define __MAP_H__

//1、地图元素
//设置地图元素	使用enum枚举
//	0空	1墙	2蛇	3食物
enum { 空，墙，蛇，食物 };

//地图类
struct Map
{
	//2、地图大小设定
	int ROW;	//行
	int COL;	//列
	int SIZE; //方块大小

	//3、地图初始化
	void init();
};




#endif // !__MAP_H__