#include "raylib.h"
#include <iostream>

using namespace std;

int main()
{
	float posX = 0;
	float posY = 0;

	//This IS Screen Size 
	const int ScreenWidth = 800;
	const int ScreenHigth = 450;
	InitWindow(ScreenWidth, ScreenHigth, "Dallal Is King");

	SetTargetFPS(144);

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_D))
		{
			posX += GetFrameTime() * 200;
		}
		else if (IsKeyDown(KEY_A))
		{
			if (posX >= 0)
				posX -= GetFrameTime() * 200;
			else
				posX;
		}
		else if (IsKeyDown(KEY_W))
		{
			if (posY <= 4)
				posY;
			else
				posY -= GetFrameTime() * 200;
		}
		else if (IsKeyDown(KEY_S))
		{
			if (posY >= 390)
				posY;
			else
				posY += GetFrameTime() * 200;
		}

		BeginDrawing();

			ClearBackground(BLACK);
			DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHigth, RED); 
			DrawRectangle(posX, posY, 8, 60, BLUE);
			DrawCircle(ScreenWidth / 2, ScreenHigth / 2, 10, GREEN);
			DrawRectangle(posX, posY, 8, 60, BLUE);
		EndDrawing();
	}

	CloseWindow();

	return (0);
}
