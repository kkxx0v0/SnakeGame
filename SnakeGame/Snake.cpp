#include "Snake.h"

Snake::Snake()
{
	dir = ��;			//��ʼ����Ϊ����
	snakeNum = 2;		//��ʼ����Ϊ2
	head = new Node;
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