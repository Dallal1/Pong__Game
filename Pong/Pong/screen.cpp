#include "raylib.h"
#include <iostream>

using namespace std;

class Wall
{
public:
	float pos_x, pos_y;
	int speed_x, speed_y;
	float width, higth;

	//const char* text;
	void Draw()
	{
		DrawRectangle(pos_x, pos_y, width, higth, WHITE);
	}

	void Update()
	{
		//Move The Wall
		/*if (IsKeyDown(KEY_D))
			pos_x += speed_x;
		if (IsKeyDown(KEY_A))
			pos_x -= speed_x;*/
		if (IsKeyDown(KEY_W))
			pos_y -= speed_y;
		if (IsKeyDown(KEY_S))
			pos_y += speed_y;

		//Screen Fizik
		if (pos_x <= 0)
			pos_x = 0;
		if (pos_x + width >= GetScreenWidth())
			pos_x = GetScreenWidth() - width;
		if (pos_y <= 0)
			pos_y = 0;
		if (pos_y + higth >= GetScreenHeight())
			pos_y = GetScreenHeight() - higth;
	}

};

class Cpu :public Wall
{
public:

	void Draw()
	{
		DrawRectangle(pos_x , pos_y, width, higth, WHITE);
	}

	void Update()
	{
		pos_y += speed_y;

		//Screen Fizik
		if (pos_y + higth >= 120)
			speed_y *= -1;
		if (pos_y + higth <= GetScreenHeight())
			speed_y *= -1;

	}
};

class Ball
{
public:
	int radius;
	float x, y;
	int speed_x, speed_y;

	//Score
	int min_wall = 1;
	int min_cpu = 1;
	const char* scoreText_wall;
	const char* scoreText_cpu;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE);
	}

	void Update()
	{
		x = x + speed_x;
		y = y + speed_y;


		//Screen Fizik
		if (x + radius >= GetScreenWidth())
		{
			speed_x *= -1;
			cout << "hello" << endl;
			scoreText_wall = TextFormat("Score: %i", min_wall++);
		}
		if (x - radius <= 0)
		{
			speed_x *= -1;
			cout << "dallal" << endl;
			scoreText_cpu = TextFormat("score: %i", min_cpu++);
		}
		if (y + radius >= GetScreenHeight() || y - radius <= 0)
			speed_y *= -1;

		DrawText(scoreText_wall, 560, 10, 20, BLUE);
		DrawText(scoreText_cpu, 150, 10, 20, BLUE);
	}
};

Ball ball;
Wall wall;
Cpu cpu;

int main()
{
	//This IS Screen Size 
	const int ScreenWidth = 800;
	const int ScreenHigth = 450;
	InitWindow(ScreenWidth, ScreenHigth, "Pong");

	//Move The Bull
	ball.radius = 10;
	ball.x = ScreenWidth / 2;
	ball.y = ScreenHigth / 2;
	ball.speed_x = 2;
	ball.speed_y = 2;

	//Move The Wall
	wall.width = 25;
	wall.higth = 120;
	wall.pos_x = ScreenWidth - wall.width - 2;
	wall.pos_y = ScreenHigth / 2 - wall.higth / 2;
	wall.speed_x = 2;
	wall.speed_y = 2;

	//CPU
	cpu.width = 25;
	cpu.higth = 120;
	cpu.pos_x = 2;
	cpu.pos_y = ScreenHigth / 2;
	cpu.speed_y = 2;

	SetTargetFPS(144);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			//Updateing
			ball.Update();
			wall.Update();
			cpu.Update();

			// Check collision between circle and rectangle
			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ wall.pos_x, wall.pos_y, wall.width, wall.higth }))
			{
				ball.speed_x *= -1;
				ball.speed_y *= -1;
			}
			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.pos_x, cpu.pos_y, cpu.width, cpu.higth }))
			{
				ball.speed_x *= -1;
				ball.speed_y *= -1;
			}

			// Set background color (framebuffer clear color)
			ClearBackground(BLACK);

			//Drawing 
			DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHigth, WHITE); 
			ball.Draw();
			wall.Draw();
			cpu.Draw();
		EndDrawing();
	}

	CloseWindow();

	return (0);
}
