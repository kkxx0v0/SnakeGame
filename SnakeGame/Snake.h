#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <conio.h>

//�ߵ�ʵ��

//1�����ඨ�� ʳ����
//ʹ�ýṹ��
//���ڡ�ʳ��ı�ʾ��ʽ�뵥�����ߡ����һ��������ʹ��node���ʾ��ʳ�
struct Node
{
	int row;//��ʾ�����������
	int col;//��ʾ�����������
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
	int dir;		//��ǰǰ������ Ĭ��Ϊ0���ϣ�
	int snakeNum;	//�ߵĳ��� ����ͷ
	Node* head;		//��ͷ

	Snake();
	void ChangeDir();//4���ı�ǰ������
	void Move();//5���ߵ�ǰ��

	void _HeadMove();
	void _BodyMove();
};

//2����ǰ������
//���÷���	ʹ��enumö��
//	0��	1��	2��	3��
enum { �� = 'w',�� = 's',�� = 'a',�� = 'd' };

#endif // !__SNAKE_H__