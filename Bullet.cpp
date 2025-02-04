#include "Novice.h"
#include "bullet.h"
#include "math.h"

/// <summary>
/// 弾丸コンストラクタ関数
/// </summary>
Bullet::Bullet() {

	posX_ = -100;
	posY_ = -100;
	speed_ = 15;
	radius_ = 5;
	isShot_ = false;

}

/// <summary>
/// 弾丸デストラクタ関数
/// </summary>
Bullet::~Bullet() {};

/// <summary>
/// 弾丸の生成関数
/// </summary>
/// <param name="startPosX">弾丸の発射X位置</param>
/// <param name="startPosY">弾丸の発射Y位置</param>
void Bullet::Fire(int& startPosX, int& startPosY) {

	posX_ = startPosX;
	posY_ = startPosY;
	isShot_ = true;

}

/// <summary>
/// 弾丸の更新関数
/// </summary>
void Bullet::Update() {

	if (isShot_) {
		posY_ -= speed_;
	}

}

/// <summary>
/// 弾丸の描画関数
/// </summary>
void Bullet::Draw() {

	if (isShot_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}

}

/// <summary>
/// 弾丸の当たり判定関数
/// </summary>
/// <param name="posX_">弾丸のX位置</param>
/// <param name="posY_">弾丸のY位置</param>
/// <param name="radius_">弾丸の半径</param>
/// <param name="isAlive">弾丸の生存フラグ</param>
void Bullet::Hit(int posX, int posY, int radius, int isAlive) {

	int dx = posX_ - posX;
	int dy = posY_ - posY;
	int r1 = radius_ + radius;

	if (sqrtf(float((dx * dx) + (dy * dy)) <= r1)) {

		isAlive = false;

	}

}