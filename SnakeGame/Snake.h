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

	//4���ı�ǰ������
	void ChangeDir(char ch);
	//5���ߵ�ǰ��
	void Move();
	//ͷ��ǰ��
	void _HeadMove();
	//�����ǰ��
	void _BodyMove();
	//6���߱䳤
	void Add(int i,int j);
};

//2����ǰ������
//���÷���	ʹ��enumö��
//	w��	s��	a��	d��
enum { �� = 'w',�� = 's',�� = 'a',�� = 'd' };

#endif // !__SNAKE_H__