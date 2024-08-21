#include "TitleScene.h"
#include "Input.h"
#include <numbers>

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
	delete modelFont_;
	delete modelPlayer_;
}

void TitleScene::Initialize() {}

void TitleScene::Update() {
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
}

void TitleScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	// ここに3Dオブジェクトの描画処理を追加できる
	modelFont_->Draw(worldTransformFont_, viewProjection_);
	modelPlayer_->Draw(worldTransformPlayer_, viewProjection_);

	// 3Dオブジェクト描画処理後
	Model::PostDraw();
}
