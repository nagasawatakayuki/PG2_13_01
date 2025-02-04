#pragma once
#include "Vector2.h"

class Bullet {
public:

	//=====================
	//bulletの初期化
	//=====================
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	int isShot_;

	/// <summary>
	/// バレットの変数を初期化する関数
	/// </summary>
	Bullet();

	/// <summary>
	/// デストラクタをする関数
	/// </summary>
	~Bullet();

	/// <summary>
	/// 弾を動かす関数
	/// </summary>
	void Update();

	/// <summary>
	/// 弾を描画する関数
	/// </summary>
	void Draw();

	/// <summary>
	/// 発射管理の関数
	/// </summary>
	/// <param name="startPos"></param>
	/// <param name="startPosY"></param>
	void Fire(int& startPos, int& startPosY);

	/// <summary>
	/// 当たり判定
	/// </summary>
	/// <param name="posX">敵のX座標</param>
	/// <param name="posY">敵のY座標</param>
	void Hit(int posX, int posY, int radius, int isAlive);

};