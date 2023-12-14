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

			ClearBackground(RAYWHITE);
			DrawRectangle(posX, posY, 8, 60, BLUE);
			DrawRectangle(400, 225, 15, 15, GREEN);

		EndDrawing();
	}

	CloseWindow();

	return (0);
}
