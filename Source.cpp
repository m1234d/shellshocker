#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;

HDC const dc = GetDC(0);

float A = -0.0033390266;
float B = 0.97565742f;
float C = 14.520011f;
float D1 = 0.18f;
float D2 = 0.3f;
class Vector3 {
public:
	float x, y, z;
	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}
	~Vector3() {

	}
	Vector3(float xxx, float yyy, float zzz) {
		x = xxx;
		y = yyy;
		z = zzz;
	}
};
class Vector2 {
public:
	float x, y;
	Vector2() {
		x = 0;
		y = 0;
	}
	~Vector2() {

	}
	Vector2(float xxx, float yyy) {
		x = xxx;
		y = yyy;
	}
};
Vector2 VectorSubtract(Vector2 a, Vector2 b) {
	float row1 = a.x - b.x;
	float row2 = a.y - b.y;

	Vector2 v;
	v.x = row1;
	v.y = row2;

	return v;
}
void ShellShock() {
	bool checking = true;
	cout << "Press E to Activate...\n";
	while (checking) {
		if ((GetKeyState('E') & 0x100) != 0) {
			checking = false;
		}
	}
	cout << "Player Location...\n";
	POINT p;
	checking = true;
	while (checking) {
		if ((GetKeyState(VK_LBUTTON) & 0x80) != 0){
			GetCursorPos(&p);
			checking = false;
		}
	}
	Sleep(300);
	cout << "Enemy location...\n";
	POINT e;
	checking = true;
	while (checking) {
		if ((GetKeyState(VK_LBUTTON) & 0x80) != 0){
			GetCursorPos(&e);
			checking = false;
		}
	}
	Vector2 player;
	Vector2 enemy;
	player.x = p.x/10;
	player.y = p.y/10;
	enemy.x = e.x/10;
	enemy.y = e.y/10;

	Vector2 distance = VectorSubtract(enemy, player);
	//int strength = (A * distance.x) + (B*distance.y) + C;
	float strength1 = (A*pow(abs(distance.x), 2)) + B*abs(distance.x) + C;
	if (distance.y > 0)  {
		strength1 -= D1*distance.y;
	}
	else {
		strength1 -= D2*distance.y;
	}
	/*if (strength1 > 80) {
		strength1 = strength1*1.06f;
	}*/
	int strength = strength1;
	cout << "Distance : ";
	cout << distance.y;
	cout << "\n";
	cout << strength;
	cout << "\n";
	ShellShock();
}
int main() {
	ShellShock();
}
