#ifndef __MAP_H__
#define __MAP_H__
#include<vector>
#include<easyx.h>
using namespace std;

//1����ͼԪ��
//���õ�ͼԪ��	ʹ��enumö��
//	0��	1ǽ	2��	3ʳ��
enum { �� = 0, ǽ = 1, �� = 2, ʳ�� = 3 };

//��ͼ��
struct Map
{
	int** pMap;
	//2����ͼ��С�趨
	int ROW;	//��
	int COL;	//��
	int SIZE; //�����С

	//3����ͼ��ʼ��
	Map(int row, int col, int size);
	~Map()
	{
		for (int i = 0; i < ROW; i++) {
			delete[] pMap[i];
		}
		delete[] pMap;
		if (pMap)
		{
			pMap = nullptr;
		}
	}

	//4���滭��ͼ
	void DrawMap();
	void SetColor(int i, int j, int color);
};


#endif // !__MAP_H__