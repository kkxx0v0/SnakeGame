#ifndef __SNAKE_H__
#define __SNAKE_H__

//�ߵ�ʵ��

//1�����ඨ�� ʳ����
//ʹ�ýṹ��
//���ڡ�ʳ��ı�ʾ��ʽ�뵥�����ߡ����һ��������ʹ��node���ʾ��ʳ�
struct node
{
	int row;//��ʾ�����������
	int col;//��ʾ�����������
};

//2����ǰ������
//���÷���	ʹ��enumö��
//	0��	1��	2��	3��
enum { �ϣ��£����� };

//��ǰǰ������ Ĭ��Ϊ0���ϣ�
extern int dir;

//3���ߵĳ���
extern int snakeNum;

//4���ı�ǰ������
void ChangeDir();

//5���ߵ�ǰ��
void Move();

#endif // !__SNAKE_H__