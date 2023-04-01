#include "Snake.h"

Node::Node()
{
	this->row = -1;
	this->col = -1;
	next = nullptr;
}

Node::Node(int row, int col)
{
	this->row = row;
	this->col = col;
	this->next = nullptr;
}

Snake::Snake(int speed)
{
	dir = 上;			//初始方向为向上
	snakeNum = 2;		//初始长度为2
	SPEED = speed;
	head = new Node;
	Add(head->row, head->col);
}

void Snake::ChangeDir(char ch)
{
	switch (ch)
	{
	case 上:
		if(dir != 下)	
			dir = 上;
		break;
	case 下:
		if (dir != 上)	
			dir = 下;
		break;
	case 左:
		if (dir != 右)	
			dir = 左;
		break;
	case 右:
		if (dir != 左)	
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
		q->row = p->row;
		q->col = p->col;
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

void Snake::Add(int i,int j)
{
	Node* p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new Node(i,j);
}