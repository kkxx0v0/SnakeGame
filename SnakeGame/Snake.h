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

	Node();
	Node(int row, int col);
};

struct Snake
{
	int dir;		//当前前进方向 默认为0（上）
	int snakeNum;	//蛇的长度 包括头
	Node* head;		//蛇头
	int SPEED;		//速度

	Snake(int SPEED);
	~Snake()
	{
		Node* curr = head;
		while (curr != nullptr) {
			Node* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}

	//4、改变前进方向
	void ChangeDir(char ch);
	//5、蛇的前进
	void Move();
	//头的前进
	void _HeadMove();
	//身体的前进
	void _BodyMove();
	//6、蛇变长
	void Add(int i,int j);
};

//2、蛇前进方向
//设置方向	使用enum枚举
//	w上	s下	a左	d右
enum { 上 = 'w',下 = 's',左 = 'a',右 = 'd' };

#endif // !__SNAKE_H__