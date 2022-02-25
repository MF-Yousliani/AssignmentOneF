#include <iostream>
#include <stdlib.h>
#include <windows.h>


using namespace std;
int ScreenWidth = 12, ScreenHight = 5;

int WormPosX = 2, WormPosY = 2;

bool GamePlay = true;

int EndTest;




void ScreenRender() {


	for (int c = 0; c < ScreenHight; c++) {

		for (int a = 0; a < ScreenWidth; a++) {

			if (c == 0 || c == (ScreenHight - 1) || a == 0 || a == (ScreenWidth - 1))
			{
				printf("#");
			}
			else
			{

				if (WormPosX == a & WormPosY == c)
				{
					printf("O");
				}
				else
				{
					printf(" ");
				}

			}
		}
		printf("\n");
	}

}

int Mover(int Pos, bool hori, bool Stop,bool backward) {

	int NextPos = Pos;

	if (!Stop) {

		if (hori)
		{
			if (backward) {
				if (NextPos <=  1) {
					NextPos = ScreenWidth-2;
				}
				else {
					NextPos--;
				}
			}
			else {
				if (NextPos >= ScreenWidth - 2) {
					NextPos = 1;
				}
				else {
					NextPos++;
				}
			}
			
		}
		else {
			if (backward) {
				if (NextPos <=  1) {
					NextPos = ScreenHight-2;
				}
				else
				{
					NextPos--;
				}
			}
			else {
				if (NextPos >= ScreenHight - 2) {
					NextPos = 1;
				}
				else
				{
					NextPos++;
				}
			}
		}

	}
	else
	{
		NextPos = Pos;
	}


	return NextPos;

}



int main() {



	while (GamePlay)
	{
		WormPosX = Mover(WormPosX, true, false,false);
		WormPosY = Mover(WormPosY, false, true,false);

		ScreenRender();
		Sleep(1000.0f);
		system("CLS");
	}



	cin >> EndTest;
	return 0;
}