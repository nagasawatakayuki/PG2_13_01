#include "Novice.h"
#include "Enemy1.h"
#include "math.h"

//=================================
// 定数の定義
//=================================
const int rightWall = 1280;
const int Dirt = 720;
const int minusNum = -1;

/// <summary>
/// Enemy1のコンストラクタ関数
/// </summary>
Enemy1::Enemy1() {

	posX_ = 500;
	posY_ = 200;
	radius_ = 20;
	speed_ = 5;
	isAlive_ = true;

	dx_ = 0;
	dy_ = 0;
	distance_ = 0;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet();
	}
}

/// <summary>
/// Enemy1の更新関数
/// </summary>
void Enemy1::Update() {

	posX_ += speed_;

	if (posX_ > rightWall - radius_ || posX_ < radius_) {

		speed_ *= minusNum;

	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		dx_ = (posX_ - bullet_[i]->posX_) * (posX_ - bullet_[i]->posX_);
		dy_ = (posY_ - bullet_[i]->posY_) * (posY_ - bullet_[i]->posY_);
		distance_ = dx_ + dy_;
	}

	if (isAlive_) {

		for (int i = 0; i < MAX_BULLETS; i++) {
			if (sqrtf(float((posX_ - bullet_[i]->posX_) * (posX_ - bullet_[i]->posX_) +
				(posY_ - bullet_[i]->posY_) * (posY_ - bullet_[i]->posY_)
				<= radius_ + bullet_[i]->radius_))) {

				isAlive_ = false;

			}
		}
	}
}

/// <summary>
/// Enemy1の描画関数
/// </summary>
void Enemy1::Draw() {

	if (isAlive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}