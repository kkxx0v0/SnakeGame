#ifndef __GAME_H__
#define __GAME_H__
#include<ctime>

//��Ϸ��

struct Game
{
	//1����Ϸ��ʼ����
	//������ͼ��ʼ�� ��������
	void GameStart();

	//2������
	void run();

	//3���߳Ե�ʳ��
	void Eaten();

	//4��ʧ��
	void defeat();
};


#endif // !__GAME_H__