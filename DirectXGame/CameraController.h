#pragma once
#include "ViewProjection.h"

/// <summary>
/// カメラコントローラー
/// </summary>

//前方宣言
class Player;

class CameraController {
public:
	/// <summary>
	///	初期化
	/// </summary>
	void Initialize();

	/// <summary>
	///	更新
	/// </summary>
	void Update();

	void SetTarget(Player* target) { target_ = target; }

	const ViewProjection& GetViewProjection() { return viewProjection_; }
	

	void Reset();


private:
	// ビュープロジェクション
	ViewProjection viewProjection_;
	Player* target_ = nullptr;

	//追従対象とカメラの座標の差(オフセット)
	Vector3 targetOffset_ = {0, 0, -15.0f};
};
