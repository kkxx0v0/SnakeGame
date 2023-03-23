#include "Snake.h"

Snake::Snake()
{
	dir = 上;			//初始方向为向上
	snakeNum = 2;		//初始长度为2
	head = new Node;
}

void Snake::ChangeDir()
{
	switch (_getch())
	{
	case 上:
		dir = 上;
		break;
	case 下:
		dir = 下;
		break;
	case 左:
		dir = 左;
		break;
	case 右:
		dir = 右;
		break;
	default:
		break;
	}
}

void Snake::Move()
{
	_BodyMove();
	_HeadMove();
}

void Snake::_BodyMove()
{
	Node* p = head, * q = p->next;
	while (q != nullptr)
	{
		q->col = p->col;
		q->row = p->row;
		p = p->next;
		q = q->next;
	}
}

void Snake::_HeadMove()
{
	switch (dir)
	{
	case 上:
		head->col--;
		break;
	case 下:
		head->col++;
		break;
	case 左:
		head->row--;
		break;
	case 右:
		head->row++;
		break;
	default:
		break;
	}
}