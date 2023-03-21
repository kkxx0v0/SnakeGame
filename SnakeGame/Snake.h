#ifndef __SNAKE_H__
#define __SNAKE_H__

//蛇的实现

//1、蛇类定义 食物类
//使用结构体
//由于“食物”的表示方式与单个“蛇”结点一样，可以使用node类表示“食物”
struct node
{
	int row;//表示结点所在行数
	int col;//表示结点所在列数
};

//2、蛇前进方向
//设置方向	使用enum枚举
//	0上	1下	2左	3右
enum { 上，下，左，右 };

//当前前进方向 默认为0（上）
extern int dir;

//3、蛇的长度
extern int snakeNum;

//4、改变前进方向
void ChangeDir();

//5、蛇的前进
void Move();

#endif // !__SNAKE_H__