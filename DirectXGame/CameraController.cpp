#define NOMINMAX
#define NOMINMIN
#include "CameraController.h"
#include "Player.h"
#include "MathUtilityForText.h"


void CameraController::Initialize() {
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
}

void CameraController::Update() {
	// 追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	// 追従対象のオフセットから目標座標を計算
	targetCoordinates = targetWorldTransform.translation_ + targetOffset_;

	// 座標補間によりゆったり追従
	viewProjection_.translation_ = Lerp(viewProjection_.translation_, targetCoordinates, kInterpolationRate);

	//移動範囲制限
	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movaArea_.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movaArea_.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, movaArea_.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, movaArea_.top);

	// 行列を更新する
	viewProjection_.UpdateMatrix();
}

void CameraController::Reset() {
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	//追従対象とオフセットからカメラの座標を計算
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetOffset_;

}
