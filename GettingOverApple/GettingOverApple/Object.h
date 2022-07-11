#pragma once
class CObject
{
protected:
	//画像
	int* image;
	//座標
	float x;
	float y;

	//当たり判定
	int width;
	int height;
	int rangeX;
	int rangeY;

public:
	virtual void HitAction() = 0;

};

void CheckHit(CObject* pObj1, CObject* pObj2);