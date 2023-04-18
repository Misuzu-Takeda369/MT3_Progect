#include <Novice.h>
#define _USE_MATH_DEFINE
#include <math.h>


const char kWindowTitle[] = "CG2A_15_タケダミスズ_";

struct Vector3 {
	float x;
	float y;
	float z;
};

static const int kColumnwidth = 60;
static const int kRowHeigth = 20;

#pragma region 関数宣言

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);
//内積
float Dot(const Vector3& v1, const Vector3& v2);
//長さ
float length(const Vector3& v);
//正規化
Vector3 Nomalaize(const Vector3& v);

void VectorScreenPrint(int x, int y, const Vector3& v, const char* label);

#pragma endregion


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//数値宣言
	Vector3 v1 = {
		1.0f,3.0f,-5.0f
	};
	Vector3 v2{
		4.0f,-1.0f,2.0f
	};
	float k = 4.0f;

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
		//加算
		Vector3 resultAdd = Add(v1,v2);
		//減算
		Vector3 resultSubtract = Subtract(v1,v2);

		//スカラー
		Vector3 resultMultiply = Multiply(k,v1);

		//内積
		float resultDot = Dot(v1,v2);

		//長さ
		float resultLength = length(v1);
		//正規化
		Vector3 resultNomalize = Nomalaize(v2);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		VectorScreenPrint(0,0, resultAdd,":Add");
		VectorScreenPrint(0, kRowHeigth, resultSubtract, ":Subtract");
		VectorScreenPrint(0, kRowHeigth*2, resultMultiply, ":Multiply");
		Novice::ScreenPrintf(0, kRowHeigth * 3,"%.02f:Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeigth * 4, "%.02f:Length", resultLength);
		VectorScreenPrint(0, kRowHeigth * 5, resultNomalize, ":Nomalaize");
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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

#pragma region 関数計算

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
};

//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
};
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 result;
	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;

	return result;
}
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float result;
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return result;
};
//長さ
float length(const Vector3& v) {
	float result;
	result = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return result;
}
//正規化
Vector3 Nomalaize(const Vector3& v) {
	Vector3 result;
	float le= sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	if (le != 0.0f) {
		result.x = v.x / le;
		result.y = v.y / le;
		result.z = v.z / le;
	}
	
	return result;

}

void VectorScreenPrint(int x,int y,const Vector3& v,const char* label) {
	Novice::ScreenPrintf(x,y,"%.02f",v.x);
	Novice::ScreenPrintf(x+ kColumnwidth, y, "%.02f", v.y);
	Novice::ScreenPrintf(x+ kColumnwidth*2, y, "%.02f", v.z);
	Novice::ScreenPrintf(x + kColumnwidth*3, y, "%s", label);
}
#pragma endregion
