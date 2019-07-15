#include <stdio.h>
#include <windows.h>

/* 키보드 값 */
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SELECT 13

/* 함수 선언 */
void dice();
int keyControl();
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void drawMap();
void gotoxy(int, int);
char map[25][104] = {
	{"000003222222222222222b222222222222222b222222222222222b222222222222222b222222222222222b22222222222222240 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"00000a2222222222222227222222222222222d222222222222222d222222222222222d2222222222222227222222222222222c0 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"00000a222222222222222c000000000000000000000000000000000000000000000000000000000000000a222222222222222c0 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000000000000000000000000000000000000000000000000000100000000000000010 "},
	{"00000a2222222222222227222222222222222b222222222222222b222222222222222b2222222222222227222222222222222c0 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"0000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010 "},
	{"000006222222222222222d222222222222222d222222222222222d222222222222222d222222222222222d22222222222222250 "}
};

int main()
{
	init();
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0)
		{
			drawMap();
			dice();
		}
		else if (menuCode == 1)
		{
			infoDraw();
		}
		else if (menuCode == 2)
		{
			return 0;
		}
		system("cls");
	}
	return 0;
}

/* 함수 구현 */
void dice()
{
	int key;
	int i = 0;
	system("cls");
	while (1)
	{
		if (kbhit())
		{
			key = getch();
			if (key == '1')
			{
				srand(time(NULL));
				int random = (rand() % 3) + 1;

				if (random == 1)
				{
					printf("┎━━━━━━━━━━━━┓ \n");
					printf("┃            ┃ \n");
					printf("┃            ┃ \n");
					printf("┃     ●     ┃ \n");
					printf("┃            ┃ \n");
					printf("┃            ┃ \n");
					printf("┖━━━━━━━━━━━━┚ \n");
					break;
				}
				else if (random == 2)
				{
					printf("┎━━━━━━━━━━━━┓ \n");
					printf("┃            ┃ \n");
					printf("┃     ●     ┃ \n");
					printf("┃            ┃ \n");
					printf("┃     ●     ┃ \n");
					printf("┃            ┃ \n");
					printf("┖━━━━━━━━━━━━┚ \n");
					break;
				}
				else if (random == 3)
				{
					printf("┎━━━━━━━━━━━━┓ \n");
					printf("┃       ●   ┃ \n");
					printf("┃            ┃ \n");
					printf("┃     ●     ┃ \n");
					printf("┃            ┃ \n");
					printf("┃   ●       ┃ \n");
					printf("┖━━━━━━━━━━━━┚ \n");
					break;
				}

			}
		}


	}
	while (1)
	{
		if (keyControl() == SELECT)
		{
			break;
		}
	}
}

void drawMap()
{
	system("cls");
	int h, w;

	for (h = 0; h < 25; h++)
	{
		for (w = 0; w < 103; w++)
		{
			char temp = map[h][w];
			if (temp == '0')
			{
				printf(" ");
			}
			else if (temp == '1')
			{
				printf("┃");
			}
			else if (temp == '2')
			{
				printf("━");
			}
			else if (temp == '3')
			{
				printf("┏");
			}
			else if (temp == '4')
			{
				printf("┓");
			}
			else if (temp == '5')
			{
				printf("┛");
			}
			else if (temp == '6')
			{
				printf("┗");
			}
			else if (temp == '7')
			{
				printf("╋");
			}
			else if (temp == 'a')
			{
				printf("┣");
			}
			else if (temp == 'b')
			{
				printf("┳");
			}
			else if (temp == 'c')
			{
				printf("┫");
			}
			else if (temp == 'd')
			{
				printf("┻");
			}
		}
		printf("\n");
	}
	//나라
	gotoxy(19, 14); printf("필");
	gotoxy(19, 15); printf("리");
	gotoxy(19, 16); printf("핀");
	//필리핀
	gotoxy(19, 8); printf("베");
	gotoxy(19, 9); printf("트");
	gotoxy(19, 10); printf("남");
	//베트남
	gotoxy(28, 5); printf("인 도");
	//인도
	gotoxy(44, 5); printf("태 국");
	//태국
	gotoxy(60, 5); printf("중 국");
	//중국
	gotoxy(76, 5); printf("일 본");
	//일본
	gotoxy(87, 8); printf("터");
	gotoxy(87, 10); printf("키");
	//터키
	gotoxy(87, 14); printf("프");
	gotoxy(87, 15); printf("랑");
	gotoxy(87, 16); printf("스");
	//프랑스
	gotoxy(75, 19); printf("독 일");
	//독일
	gotoxy(59, 19); printf("호 주");
	//호주
	gotoxy(43, 19); printf("미 국");
	//미국
	gotoxy(27, 19); printf("한 국");
	//한국


	while (1)
	{
		if (keyControl() == SELECT)
		{
			break;
		}
	}
}
int keyControl()
{
	char temp = getch();

	if (temp == '↑')
	{
		return UP;
	}
	else if (temp == '←')
	{
		return LEFT;
	}
	else if (temp == '↓')
	{
		return DOWN;
	}
	else if (temp == '→')
	{
		return RIGHT;
	}
	else if (temp == '\n')
	{
		return SELECT;
	}
}

void init()
{
	system("mode con cols=110 lines=40");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw()
{
	printf("\n\n\n\n");
	printf("       QQQQQQQQQ \n");
	printf("     QQ:::::::::QQ \n");
	printf("   QQ:::::::::::::QQ \n");
	printf("  Q:::::::QQQ:::::::Q \n");
	printf("  Q::::::O   Q::::::Q \n");
	printf("  Q:::::O     Q:::::Q                  ::::    ::::      :::     :::::::::  :::::::::  :::        ::::::::::  \n");
	printf("  Q:::::O     Q:::::Q                  +:+:+: :+:+:+   :+: :+:   :+:    :+: :+:    :+: :+:        :+:         \n");
	printf("  Q:::::O     Q:::::Q                  +:+ +:+:+ +:+  +:+   +:+  +:+    +:+ +:+    +:+ +:+        +:+         \n");
	printf("  Q:::::O     Q:::::Q  +#++:++#++:++   +#+  +:+  +#+ +#++:++#++: +#++:++#:  +#++:++#+  +#+        +#++:++#    \n");
	printf("  Q:::::O     Q:::::Q                  +#+       +#+ +#+     +#+ +#+    +#+ +#+    +#+ +#+        +#+         \n");
	printf("  Q:::::O  QQQQ:::::Q                  #+#       #+# #+#     #+# #+#    #+# #+#    #+# #+#        #+#         \n");
	printf("  Q::::::O Q::::::::Q                  ###       ### ###     ### ###    ### #########  ########## ##########  \n");
	printf("  Q:::::::QQ::::::::Q \n");
	printf("   QQ::::::::::::::Q \n");
	printf("     QQ:::::::::::Q  \n");
	printf("       QQQQQQQQ::::QQ \n");
	printf("               Q:::::Q \n");
	printf("                QQQQQQ \n");
	printf("\n\n\n\n");
}

int menuDraw()
{
	int x = 50;
	int y = 27;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작");
	gotoxy(x, y + 1);
	printf("게 임 정 보");
	gotoxy(x, y + 2);
	printf("   종 료   ");

	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 27)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 29)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SELECT:
		{
			return y - 27;
		}
		}
	}
}

void infoDraw()
{
	system("cls");
	printf("■■■■■■■■■■■■■■■Q-marble 규칙 설명■■■■■■■■■■■■■■■■■■■■ \n");
	printf("■                                                                                    ■ \n");
	printf("■ 1. 주사위를 던져서 나온 수(1~3) 만큼 칸을 이동한다.                                ■ \n");
	printf("■ 2. 각 칸에서 퀴즈를 풀어야 한다.                                                   ■ \n");
	printf("■          -나라 퀴즈 칸: 12개                                                       ■ \n");
	printf("■          -프로그래밍 퀴즈 칸: 3개                                                  ■ \n");
	printf("■ 3. 나라 퀴즈 칸에 도착하면 상중하 난이도를 선택한다.                               ■ \n");
	printf("■          - 문제를 맞췄을 시                                                        ■ \n");
	printf("■            상 : +20000                                                             ■ \n");
	printf("■            중 : +10000                                                             ■ \n");
	printf("■            하 : +5000                                                              ■ \n");
	printf("■          - 문제를 틀렸을 시                                                        ■ \n");
	printf("■            상 : -20000                                                             ■ \n");
	printf("■            중 : -10000                                                             ■ \n");
	printf("■            하 : -5000                                                              ■ \n");
	printf("■ 4. 프로그래밍 퀴즈 칸에 도착하면 프로그래밍 문제 12개 중 랜덤으로 문제가 주어진다. ■ \n");
	printf("■          - 문제를 맞췄을 시  +30000                                                ■ \n");
	printf("■          - 문제를 틀렸을 시  -30000                                                ■ \n");
	printf("■ 5. 시작 칸에 도착할 시 +20000이 부여된다.                                          ■ \n");
	printf("■ 6. 게임 엔딩 조건                                                                  ■ \n");
	printf("■          - 한 명이 파산하거나 한 명이 먼저 250,000을 넘기면 승리하게 된다.         ■ \n");
	printf("■                                                                                    ■ \n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");

	while (1)
	{
		if (keyControl() == SELECT)
		{
			break;
		}
	}
}
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}