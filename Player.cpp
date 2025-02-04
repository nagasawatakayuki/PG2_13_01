#include "Novice.h"
#include "player.h"

/// <summary>
/// プレイヤーのコンストラクタ関数
/// </summary>
Player::Player() {

	playerPosX = 640;
	playerPosY = 360;
	playerRadius = 30;
	playerSpeed = 10;
	shotCoolTime = 5;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet();
	}

}

/// <summary>
/// プレイヤーのデストラクタ関数
/// </summary>
Player::~Player() {

	for (int i = 0; i < MAX_BULLETS; i++) {
		delete bullet_[i];
	}

}

/// <summary>
/// プレイヤーの更新関数
/// </summary>
void Player::Updata(char* keys) {

	if (keys[DIK_D]) {
		playerPosX += playerSpeed;
	}

	if (keys[DIK_A]) {
		playerPosX -= playerSpeed;
	}

	if (keys[DIK_W]) {
		playerPosY -= playerSpeed;
	}

	if (keys[DIK_S]) {
		playerPosY += playerSpeed;
	}


	if (shotCoolTime > 0) {
		shotCoolTime--;
	}

	if (keys[DIK_SPACE]) {
		if (shotCoolTime <= 0) {

			for (int i = 0; i < MAX_BULLETS; i++) {
				if (!bullet_[i]->isShot_) {

					bullet_[i]->Fire(playerPosX, playerPosY);
					shotCoolTime = 4;
					break;

				}
			}

		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullet_[i]->isShot_) {

			bullet_[i]->Update();

		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullet_[i]->posY_ < 0) {

			bullet_[i]->isShot_ = false;

		}
	}

}

/// <summary>
/// プレイヤーの描画関数
/// </summary>
void Player::Draw() {

	Novice::DrawEllipse(playerPosX, playerPosY, playerRadius, playerRadius, 0.0f, WHITE, kFillModeSolid);

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i]->Draw();
	}

}
