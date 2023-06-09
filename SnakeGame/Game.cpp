#include<ctime>
#include "Game.h"

Food::Food()
{
	FoodNum = 0;
}

void Game::GameStart()
{
	//初始化地图、蛇、食物
	GameMap = new Map(ROW, COL, SIZE);

	GameSnake = new Snake(SPEED);
	GameSnake->head->row = ROW / 2;
	GameSnake->head->col = COL / 2;
	GameSnake->head->next->row = ROW / 2;
	GameSnake->head->next->col = COL / 2 + 1;
	PrintSnake(蛇);

	GameFood = new Food;
	CreatFood();
	PrintFood();

	SleepEx(1000, false);
}

int Game::run()
{
	//打开图形界面
	initgraph(ROW * SIZE, COL * SIZE, EW_SHOWCONSOLE);
	SetWindowPos(GetHWnd(), 0, 0, 0, ROW * SIZE, COL * SIZE, SWP_NOSIZE);

	//时间数种子
	srand((unsigned)time(NULL));

	GameStart();
	update();

	//关闭图形窗口
	closegraph();
	return 0;
}

void Game::Eaten()
{
	//判断蛇头位置和食物位置
	if (GameSnake->head->row == GameFood->pos.row && GameSnake->head->col == GameFood->pos.col)
	{
		GameFood->FoodNum = 0;
		//蛇变长
		GameSnake->Add(GameFood->pos.row, GameFood->pos.col);
		GameSnake->snakeNum++;
	}
}

void Game::defeat()
{
	//蛇撞到墙
	if (GameSnake->head->row <= 0 || GameSnake->head->row >= ROW || GameSnake->head->col <= 0 || GameSnake->head->col >= COL)
	{
		if (IDYES == MessageBox(GetHWnd(), L"你撞墙了，是否要重新开始游戏", L"提示", MB_YESNO))
			//IDYES表示“是”，窗口的按钮被按下的值
			//MessageBox用来弹出窗口 GetHWnd窗口句柄
			GameStart();
		else
			exit(0);
	}
	//蛇撞到自己
	Node* s = GameSnake->head->next;
	while (s)
	{
		if (GameSnake->head->row == s->row && GameSnake->head->col == s->col)
		{
			if (IDYES == MessageBox(GetHWnd(), L"你咬自己了，是否要重新开始游戏", L"提示", MB_YESNO))
				GameStart();
			else
				exit(0);
		}
		s = s->next;
	}
}

void Game::PrintSnake(int val)
{
	Node* s = GameSnake->head;
	while (s)
	{
		GameMap->pMap[s->row][s->col] = val;
		s = s->next;
	}
}

void Game::CreatFood()
{
	//随机生成一个位置
	int RandRow = rand() % (ROW - 2) + 1;
	int RandCol = rand() % (COL - 2) + 1;

	Node* s = GameSnake->head;
	while (s)
	{
		if (s->row == RandRow && s->col == RandCol)
		{
			CreatFood();
		}
		s = s->next;
	}

	GameFood->pos = Node(RandRow, RandCol);
	GameFood->FoodNum = 1;
	GameMap->pMap[RandRow][RandCol] = 食物;
}

void Game::PrintFood()
{
	GameMap->pMap[GameFood->pos.row][GameFood->pos.col] = 食物;
}

bool IsKeyPressed(int vkey) 
{
	static bool keyPressed = false;
	bool pressed = (GetKeyState(vkey) & 0x8000) != 0;
	if (pressed && !keyPressed) 
	{
		keyPressed = true;
		return true;
	}
	if (!pressed && keyPressed) 
	{
		keyPressed = false;
	}
	return false;
}

void Game::update()
{
	while (1)
	{
		PrintSnake(空);

		//之前好用，可能是更新vs2022后无法使用
		// 
		//if ( _kbhit() )//判断键盘有没有按键操作，如果没有就返回假0，否则为真1 <conio.h>
		//{
		//	GameSnake->ChangeDir();
		//}

		if (IsKeyPressed('W'))
		{
			GameSnake->ChangeDir('w');
		}
		else if (IsKeyPressed('S'))
		{
			GameSnake->ChangeDir('s');
		}
		else if (IsKeyPressed('A'))
		{
			GameSnake->ChangeDir('a');
		}
		else if (IsKeyPressed('D'))
		{
			GameSnake->ChangeDir('d');
		}

		GameSnake->Move();
		PrintSnake(蛇);

		//判断状态
		defeat();
		Eaten();
		if (GameFood->FoodNum == 0)
		{
			CreatFood();
		}

		GameMap->DrawMap();

		SleepEx(GameSnake->SPEED * 20, false);
	}
}