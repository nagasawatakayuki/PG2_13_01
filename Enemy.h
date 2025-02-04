#pragma once
#include "Bullet.h"

class Enemy
{
public:

	/// <summary>
	/// 弾丸の更新関数
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 弾丸の描画関数
	/// </summary>
	virtual void Draw();

	// 変数
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	static int isAlive_;

	int dx_;
	int dy_;
	int distance_;

public:

	//最大弾数の定数の定義
	static const int MAX_BULLETS = 100;

	//包含の変数
	Bullet* bullet_[MAX_BULLETS];

};
