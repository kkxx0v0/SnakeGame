#ifndef __MAP_H__
#define __MAP_H__
#include<vector>
using namespace std;

//1����ͼԪ��
//���õ�ͼԪ��	ʹ��enumö��
//	0��	1ǽ	2��	3ʳ��
enum { �� = 0, ǽ = 1, �� = 2, ʳ�� = 3 };

//��ͼ��
struct Map
{
	vector<vector<int>> pMap;
	//2����ͼ��С�趨
	int ROW;	//��
	int COL;	//��
	int SIZE; //�����С

	//3����ͼ��ʼ��
	Map(int row, int col, int size);
	
};


#endif // !__MAP_H__