#pragma once

#define D_APPLE_MAX 10
#define D_APPLE_WIDTH 40
#define D_APPLE_HEIGHT 40
#define D_APPLE_A 0
#define D_APPLE_B 1
#define D_APPLE_C 2
#define D_APPLE_D 3
#define D_APPLE_A_SPEED 2
#define D_APPLE_B_SPEED 5
#define D_APPLE_C_SPEED 10
#define D_APPLE_D_SPEED 1
#define D_APPLE_A_SCORE 150
#define D_APPLE_B_SCORE 300
#define D_APPLE_C_SCORE 500
#define D_APPLE_D_SCORE -1000 
#define D_PROPORTION_A 6
#define D_PROPORTION_B D_PROPORTION_A + 2
#define D_PROPORTION_C D_PROPORTION_B + 1
#define D_PROPORTION_D D_PROPORTION_C + 1
#define IMAGE_MAX 4

class CAppleManager;
class CApple {
private:
	int x;
	int y;
	int w;
	int h;
	int speed;
	int* image;
	int imgHandle;
	int score;
	bool isShow;
public:
	CApple();
	~CApple();
	void Update();
	void NewApple();
	void CreateAppleA();
	void CreateAppleB();
	void CreateAppleC();
	void CreateAppleD();
	void Render()const;
	void ToggleisShow() { isShow = !isShow; }
	int GetX() { return x; }
	int GetY() { return y; }
	int GetW() { return w; }
	int GetH() { return h; }
	bool GetisShow() { return isShow; };
};