#ifndef __MAP_H__
#define __MAP_H__

//1����ͼԪ��
//���õ�ͼԪ��	ʹ��enumö��
//	0��	1ǽ	2��	3ʳ��
enum { �գ�ǽ���ߣ�ʳ�� };

//��ͼ��
struct Map
{
	//2����ͼ��С�趨
	int ROW;	//��
	int COL;	//��
	int SIZE; //�����С

	//3����ͼ��ʼ��
	void init();
};




#endif // !__MAP_H__