#include "Game.h"

Food::Food()
{
	FoodNum = 0;
}

void Game::GameStart()
{
	//ʱ��������
	srand((unsigned)time(NULL));

	//��ʼ����ͼ���ߡ�ʳ��
	
	GameMap = new Map(ROW, COL, SIZE);
	
	GameSnake = new Snake(SPEED);
	GameSnake->head->row = ROW / 2;
	GameSnake->head->col = COL / 2;
	GameSnake->head->next->row = ROW / 2;
	GameSnake->head->next->col = COL / 2 + 1;
	PrintSnake(��);

	GameFood = new Food;
	CreatFood();
	PrintFood();

	Sleep(1000);
}

int Game::run()
{
	initgraph(COL * SIZE, ROW * SIZE, EW_SHOWCONSOLE);//��ͼ�ν���
	SetWindowPos(GetHWnd(), 0, 0, 0, 0, 0, SWP_NOSIZE);
	GameStart();

	update();

	closegraph();//�ر�ͼ�δ���
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
	//��ײ��ǽ
	if (GameSnake->head->row == 0 || GameSnake->head->row == ROW || GameSnake->head->col == 0 || GameSnake->head->col == COL)
	{
		if (IDYES == MessageBox(GetHWnd(), L"��ײǽ�ˣ��Ƿ�Ҫ���¿�ʼ��Ϸ", L"��ʾ", MB_YESNO))
			//IDYES��ʾ���ǡ������ڵİ�ť�����µ�ֵ
			//MessageBox������������ GetHWnd���ھ��
			GameStart();
		else
			exit(0);
	}
	//��ײ���Լ�
	Node* s = GameSnake->head->next;
	while (s)
	{
		if (GameSnake->head->row == s->row && GameSnake->head->col == s->col)
		{
			if (IDYES == MessageBox(GetHWnd(), L"��ҧ�Լ��ˣ��Ƿ�Ҫ���¿�ʼ��Ϸ", L"��ʾ", MB_YESNO))
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
	GameMap->pMap[GameFood->pos.row][GameFood->pos.col] = ʳ��;
}

void Game::update()
{
	while (1)
	{
		PrintSnake(��);
		if ( _kbhit() )//�жϼ�����û�а������������û�оͷ��ؼ�0������Ϊ��1<conio.h>
		{
			GameSnake->ChangeDir();
		}
		GameSnake->Move();
		PrintSnake(��);
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