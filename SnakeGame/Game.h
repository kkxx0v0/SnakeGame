#ifndef __GAME_H__
#define __GAME_H__

//游戏进行相关函数

//1、游戏开始函数
//包含地图初始化 变量设置
void GameStart();

//2、运行
void run();

//3、蛇吃到食物
void Eaten();

//4、失败
void defeat();

#endif // !__GAME_H__