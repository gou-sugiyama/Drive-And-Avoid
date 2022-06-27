#include"DxLib.h"
#include "UI.h"
#include"SceneManager.h"

CUI::CUI(CSceneManager* pManager) {
	manager = pManager;
	for (int i = 0; i < 4; i++) {
		AppleCount[i] = 0;
	}

	score = 0;
	TimeLimit = 60 * 10;			//60フレーム*30秒
	isPause = false;
}

bool CUI::Update() {
	if (isPause == false) {
		--TimeLimit;
	}

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_M) {		//スペースキーが押されたらPAUSE
		isPause = !isPause;
	}

	if (TimeLimit <= 0) {
		TimeLimit = 0;

		return false;
		//TODO　制限時間が0になったら3秒後に画面遷移
		//次のゲームステートを返すorゲームステートを変更する
	}

	return true;
}

void CUI::Render()const {
	int White = 0xFFFFFF;
	int Black = 0x000000;
	int const StrMargin = 20;

	if (isPause) {
		SetFontSize(50);
		DrawString(0, 240, "------PAUSE------", White);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "制限時間", Black);					//数値調整済み
	SetFontSize(50);
	DrawFormatString(545, StrMargin * 5, Black, "%02d", TimeLimit / 60);//数値調整済み
	SetFontSize(16);

	DrawFormatString(510, StrMargin * 12, White, "%03d", AppleCount[0]);
	DrawFormatString(560, StrMargin * 12, White, "%03d", AppleCount[1]);
	DrawFormatString(610, StrMargin * 12, White, "%03d", AppleCount[2]);

	DrawString(510, StrMargin * 14, "SCORE:", White);
	DrawFormatString(580, StrMargin * 14, White, "%06d", score);

	//デバッグ用数値 (500,300+20*n)


	/*
	DrawFormatString(510, 200, 0x000000, "走行距離");
	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
	DrawFormatString(510, 240, 0x000000, "スピード");
	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);*/


}