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
	dir = ��;			//��ʼ����Ϊ����
	snakeNum = 2;		//��ʼ����Ϊ2
	SPEED = speed;
	head = new Node();
	Add(head->row, head->col);
}

void Snake::ChangeDir()
{
	switch (_getch())
	{
	case ��:
		dir = ��;
		break;
	case ��:
		dir = ��;
		break;
	case ��:
		dir = ��;
		break;
	case ��:
		dir = ��;
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
	case ��:
		head->col--;
		break;
	case ��:
		head->col++;
		break;
	case ��:
		head->row--;
		break;
	case ��:
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