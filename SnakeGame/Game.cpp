#include "Game.h"

Food::Food()
{
	FoodNum = 0;
}

void Game::GameStart()
{
	//时间数种子
	srand((unsigned)time(NULL));

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

	Sleep(1000);
}

int Game::run()
{
	initgraph(COL * SIZE, ROW * SIZE, EW_SHOWCONSOLE);//打开图形界面
	SetWindowPos(GetHWnd(), 0, 0, 0, 0, 0, SWP_NOSIZE);
	GameStart();

	update();

	closegraph();//关闭图形窗口
	return 0;
}

void Game::Eaten()
{
	if (GameSnake->head->row == GameFood->pos.row && GameSnake->head->col == GameFood->pos.col)
	{
		GameFood->FoodNum = 0;
		GameSnake->Add(GameFood->pos.row, GameFood->pos.col);
		GameSnake->snakeNum++;
	}
}

void Game::defeat()
{
	//蛇撞到墙
	if (GameSnake->head->row == 0 || GameSnake->head->row == ROW || GameSnake->head->col == 0 || GameSnake->head->col == COL)
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
	int RandRow = rand() % (ROW - 2) + 1;
	int RandCol = rand() % (COL - 2) + 1;
	Node* s = GameSnake->head;
	while (s)
	{
		if (s->row == RandRow && s->row == RandCol)
		{
			CreatFood();
		}
		s = s->next;
	}
	GameFood->pos = Node(RandRow, RandCol);
	GameFood->FoodNum = 1;
}

void Game::PrintFood()
{
	GameMap->pMap[GameFood->pos.row][GameFood->pos.col] = 食物;
}

void Game::update()
{
	while (1)
	{
		PrintSnake(空);
		if ( _kbhit() )//判断键盘有没有按键操作，如果没有就返回假0，否则为真1<conio.h>
		{
			GameSnake->ChangeDir();
		}
		GameSnake->Move();
		PrintSnake(蛇);
		defeat();
		Eaten();
		if (GameFood->FoodNum == 0)
		{
			CreatFood();
		}
		GameMap->DrawMap();
		Sleep(GameSnake->SPEED*20);
		//cleardevice();
	}
}