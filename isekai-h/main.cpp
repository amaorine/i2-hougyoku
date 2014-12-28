#include "include.h"

//ループで必ず行う３大処理
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//プロセス処理がエラーなら-1を返す
	if(ClearDrawScreen()!=0)return -1;//画面クリア処理がエラーなら-1を返す
	GetHitKeyStateAll_2();//現在のキー入力処理を行う
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);//ウィンドウモード
	
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化


	int page = 0;

	//初期化処理
	//playerInitilaze();	//プレイヤー初期化
	Player player(100.0,100.0,3.0);
	bossInitialize();	//ボス初期化
	shotInitialize();	//ボス初期化

	//bossMovePosition02(50,300,100);
	setBullet(0.0,0.0,3.0,90);



	while(ProcessLoop()==0&&CheckStateKey(KEY_INPUT_ESCAPE)==0){//メインループ
		//ここに処理
		statege1();








		//ほぼ毎回処理
		player.main();
		shotMove();
		shotGraph();
		deleteBullet();
		bossMove();
		bossGraph();


		//ここに処理

		ScreenFlip();//裏画面反映
	}

	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}



