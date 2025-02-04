#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy
{
public:

	/// <summary>
	/// Enemy1のコンストラクト関数	
	/// </summary>
	Enemy1();

	/// <summary>
	/// Enemy1のデストラクタ関数
	/// </summary>
	~Enemy1();

	/// <summary>
	/// Enemy1の更新関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// Enemy1の描画関数
	/// </summary>
	void Draw() override;

protected:

};