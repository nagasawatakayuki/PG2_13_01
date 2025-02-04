#pragma once
#include "bullet.h"
#include "Novice.h"

class Player {
public:

	/// <summary>
	/// 初期化する関数
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタをする関数
	/// </summary>
	~Player();

	/// <summary>
	/// プレイヤーをキー入力で動かす関数
	/// </summary>
	/// <param name="keys">キー入力を受け付ける</param>
	/// <param name="preKeys">キーが押されているか判断</param>
	void Updata(char* keys);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	//==============
	//プレイヤーの変数
	//==============
	int playerPosX;
	int playerPosY;
	int playerRadius;
	int playerSpeed;
	int shotCoolTime;

public:

	//最大の弾数
	static const int MAX_BULLETS = 100;

	//包含をするための変数
	Bullet* bullet_[MAX_BULLETS];

};