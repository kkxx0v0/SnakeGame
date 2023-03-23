#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <conio.h>

//蛇的实现

//1、蛇类定义 食物类
//使用结构体
//由于“食物”的表示方式与单个“蛇”结点一样，可以使用node类表示“食物”
struct Node
{
	int row;//表示结点所在行数
	int col;//表示结点所在列数
	Node* next;

	Node()
	{
		this->next = nullptr;
	}
	Node(int row,int col)
	{
		this->row = row;
		this->col = col;
		this->next = nullptr;
	}
};

struct Snake
{
	int dir;		//当前前进方向 默认为0（上）
	int snakeNum;	//蛇的长度 包括头
	Node* head;		//蛇头

	Snake();
	void ChangeDir();//4、改变前进方向
	void Move();//5、蛇的前进

	void _HeadMove();
	void _BodyMove();
};

//2、蛇前进方向
//设置方向	使用enum枚举
//	0上	1下	2左	3右
enum { 上 = 'w',下 = 's',左 = 'a',右 = 'd' };

#endif // !__SNAKE_H__