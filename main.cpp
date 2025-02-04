#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Hit.h"

//=================================
// ウィンドウタイトル
//=================================
const char kWindowTitle[] = "LC1B_17_ナガサワタカユキ_タイトル";

//=================================
// Enemyの生存フラグの宣言
//=================================
int Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//=================================
	// 動的メモリの確保とポインタ
	//=================================

	// ヒープにプレイヤーを作成
	Player* player = new Player;

	// ヒープに敵を作成
	Enemy* enemy[3];

	// 各種敵の作成
	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			enemy[i] = new Enemy1;
		} else {
			enemy[i] = new Enemy2;
		}
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//=================================
		// プレイヤーの更新処理
		//=================================

		// キー操作によるプレイヤーの更新
		player->Updata(keys);

		//=================================
		// 敵の更新処理
		//=================================

		// 敵のリセット
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive_ = true;
		}

		for (int i = 0; i < 2; i++) {
			enemy[i]->Update();
			// 当たり判定
			for (int j = 0; j < Player::MAX_BULLETS; j++) {
				// 弾が発射中かどうかを確認
				if (player->bullet_[j]->isShot_) {
					// 敵が生きているか確認
					if (enemy[i]->isAlive_) {
						// 当たり判定処理
						if (IsCircleHit(
							enemy[i]->posX_, enemy[i]->posY_, enemy[i]->radius_,
							player->bullet_[j]->posX_, player->bullet_[j]->posY_, player->bullet_[j]->radius_)) {
							enemy[i]->isAlive_ = false;             // 敵を倒す
							player->bullet_[j]->isShot_ = false;   // 弾を消す
							Enemy::isAlive_ = false;
						}
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 背景の描画
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

		// プレイヤーの描画
		player->Draw();

		// 敵の描画
		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}

		// デバック＆プレイヤーの操作説明
		Novice::ScreenPrintf(50, 50, "EnemyA isAlive = %d", enemy[0]->isAlive_);
		Novice::ScreenPrintf(50, 80, "EnemyB isAlive = %d", enemy[1]->isAlive_);
		Novice::ScreenPrintf(50, 140, "Shot           : SPACE");
		Novice::ScreenPrintf(50, 170, "Player Move    : WASD");
		Novice::ScreenPrintf(50, 230, "Enemy respawn  : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// メモリの解放
	delete player;
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
