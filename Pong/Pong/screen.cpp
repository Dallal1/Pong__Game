#include "raylib.h"
#include <iostream>

using namespace std;

class Wall
{
public:
	float pos_x, pos_y;
	int speed_x, speed_y;

	void Draw()
	{
		DrawRectangle(pos_x, pos_y, 15, 75, BLUE);
	}

	void Update()
	{
		if (IsKeyDown(KEY_D))
			pos_x += speed_x;
		else if (IsKeyDown(KEY_A))
			pos_x -= speed_x;
		else if (IsKeyDown(KEY_W))
			pos_y -= speed_y;
		else if (IsKeyDown(KEY_S))
			pos_y += speed_y;
	}

};

class Ball
{
public:
	int radius;
	float x, y;
	int speed_x, speed_y;


	void Draw()
	{
		DrawCircle(x, y, radius, GREEN);
	}

	void Update()
	{
		x = x + speed_x;
		y = y + speed_y;
	}
};

Ball ball;
Wall wall;

int main()
{
	//This IS Screen Size 
	const int ScreenWidth = 800;
	const int ScreenHigth = 450;
	InitWindow(ScreenWidth, ScreenHigth, "Dallal Is King");

	//Move The Bull
	ball.radius = 10;
	ball.x = ScreenWidth / 2;
	ball.y = ScreenHigth / 2;
	ball.speed_x = -2;
	ball.speed_y = -2;

	//Move The Wall
	wall.pos_x = 5;
	wall.pos_y = ScreenHigth / 2;
	wall.speed_x = 2;
	wall.speed_y = 2;

	SetTargetFPS(144);

	while (!WindowShouldClose())
	{
		ball.Update();
		wall.Update();

		BeginDrawing();

			ClearBackground(BLACK);
			DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHigth, RED); 
			ball.Draw();
			wall.Draw();
		EndDrawing();
	}

	CloseWindow();

	return (0);
}
