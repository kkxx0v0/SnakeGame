#ifndef __MAP_H__
#define __MAP_H__

//地图的实现

//1、地图大小设定
#define ROW 20	//行
#define COL 20	//列
#define SIZE 20 //方块大小

//2、地图元素
//设置地图元素	使用enum枚举
//	0空	1墙	2蛇	3食物
enum {空，墙，蛇，食物};	

//3、地图初始化
void init();


#endif // !__MAP_H__