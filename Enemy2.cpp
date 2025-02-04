#include "Novice.h"
#include "Enemy2.h"
#include "math.h"

//=================================
// 定数の定義
//=================================
const int rightWall = 1280;
const int Dirt = 720;
const int minusNum = -1;

/// <summary>
/// Enemy2のコンストラクタ関数
/// </summary>
Enemy2::Enemy2() {

	posX_ = 500;
	posY_ = 200;
	radius_ = 50;
	speed_ = -5;
	isAlive_ = true;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet();
	}
}

/// <summary>
/// Enemy2の更新関数
/// </summary>
void Enemy2::Update() {

	posY_ += speed_;

	if (posY_ > Dirt - radius_ || posY_ < radius_) {

		speed_ *= minusNum;

	}

	if (isAlive_) {

		for (int i = 0; i < MAX_BULLETS; i++) {
			if (sqrtf(float((posX_ - bullet_[i]->posX_) * (posX_ - bullet_[i]->posX_) +
				(posY_ - bullet_[i]->posY_) * (posY_ - bullet_[i]->posY_))) <= radius_ / 2 + bullet_[i]->radius_ / 2) {
				isAlive_ = false;

			}
		}
	}
}

/// <summary>
/// Enemy2の描画関数
/// </summary>
void Enemy2::Draw() {

	if (isAlive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);

	}
}