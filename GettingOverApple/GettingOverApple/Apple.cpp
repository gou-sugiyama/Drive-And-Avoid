#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

CApple::CApple() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	score = 0;
	isShow = TRUE;
	image[0] = LoadGraph("images/Apple_2.png");
	image[1] = LoadGraph("images/BlueApple4.png");
	image[2] = LoadGraph("images/GoldApple.png");
	image[3] = LoadGraph("images/PoisonApple.png");
	type = GetRand(3);     
	col = GetRand(9)+1;   

	if (type == 0)speed = 2;
	if (type == 1)speed = 5;
	if (type == 2)speed = 10;
	if (type == 3)speed = 1;
	
	if (type < 4) {
		if (type == 0)col <= 6;
		if (type == 1)col <= 2;
		if (type == 2)col <= 1;
		if (type == 3)col <= 1;
	}
}

void CApple::Update() {
	y += speed;
}

void CApple::Render() {
	DrawGraph(x, y, image[type], TRUE);
}

void CApple::toggleisShow() {
	isShow = !isShow;
}
