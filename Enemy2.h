#pragma once
#include "Enemy.h"

class Enemy2 :public Enemy
{
public:

	/// <summary>
	/// Enemy2のコンストラクト関数
	/// </summary>
	Enemy2();

	/// <summary>
	/// Enemy2のデストラクタ関数
	/// </summary>
	~Enemy2();

	/// <summary>
	/// Enemy2の更新関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// Enemy2の描画関数
	/// </summary>
	void Draw() override;

protected:

};
