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

	Node();
	Node(int row, int col);
};

struct Snake
{
	int dir;		//��ǰǰ������ Ĭ��Ϊ0���ϣ�
	int snakeNum;	//�ߵĳ��� ����ͷ
	Node* head;		//��ͷ
	int SPEED;		//�ٶ�

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

	void ChangeDir(char ch);//4���ı�ǰ������
	void Move();//5���ߵ�ǰ��
	void _HeadMove();
	void _BodyMove();
	void Add(int i,int j);//6���߱䳤
};

//2����ǰ������
//���÷���	ʹ��enumö��
//	w��	s��	a��	d��
enum { �� = 'w',�� = 's',�� = 'a',�� = 'd' };

#endif // !__SNAKE_H__