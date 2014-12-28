#include "../include/DxLib.h";
#include "math.h";
#include"key.h";
#include"field.h";

typedef struct{
	double x,y;	//座標
	double v;	//速度
	int point;	//得点
	int slow;	//低速かどうか
	int bomb;	//ボム数
	int pointJem;	//宝玉割断用エネルギー
}playerSt;

int playerImg[12];	//読み込んだ画像を格納するとこ
playerSt player;	//構造体宣言

void playerInitilaze(){
	//初期化処理
	//自機画像ロード
	 LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
	 //初期位置設定とかボム数決定とかの定義
	 player.v=4.0;
	 player.x=getFieldMinX()+(getFieldMaxX()-getFieldMinX())/2;
	 player.y=getFieldMaxY()-30;

}

void playerMove(){
	//上下左右のキーが押されてるかのフラグ立て
	int chekKey[4];
	double vRateX[4]={0.0,1.0,0.0,-1.0};
	double vRateY[4]={-1.0,0.0,1.0,0.0};
	double vRateSlant=1.0;	//ななめ移動フラグ
	double xMoveMax[2]={getFieldMaxX()-10,10};
	double yMoveMax[2]={5,getFieldMaxY()-5};
	chekKey[0]=CheckStateKey(KEY_INPUT_UP);	//上
	chekKey[1]=CheckStateKey(KEY_INPUT_RIGHT);	//→
	chekKey[2]=CheckStateKey(KEY_INPUT_DOWN);	//下
	chekKey[3]=CheckStateKey(KEY_INPUT_LEFT);	//左


	//移動後の自機位置設定
	if((chekKey[0]||chekKey[2])&&(chekKey[1]||chekKey[3])){
		//上下どちらかと左右どちらかがどっちも1ならななめ用にスピードを1√2に
		vRateSlant=sqrt(2.0);
	}
	for(int i=0;i<4;i++){
		if(chekKey[i]>0){
			if(CheckStateKey(KEY_INPUT_LSHIFT)||CheckStateKey(KEY_INPUT_RSHIFT)==1){
				vRateX[i]/=3;
				vRateY[i]/=3;
			}

			player.x+=player.v/vRateSlant*vRateX[i];
			player.y+=player.v/vRateSlant*vRateY[i];

			if(player.x>xMoveMax[0]||player.x<xMoveMax[1]){
				//左右に動くのはi=1とi=3の時なので、i/2
				player.x=xMoveMax[int(i/2)];
			}
			if(player.y>yMoveMax[1]||player.y<yMoveMax[0]){
				//左右に動くのはi=1とi=3の時なので、i/2
				player.y=yMoveMax[int(i/2)];
			}			
		}
	}



}	
void playerGraph(){
	//描画処理
	//自機を自機座標を中心に描画
	DrawRotaGraphF(player.x,player.y,1.0f,0.0f,playerImg[0],TRUE);
}

void playerMain(){
	//mainファイルにて呼び出す自機の動作まとめ
	playerMove();
	playerGraph();
}

void playerFinalize(){
	//終了処理
	for(int i=0;i<12;i++){
	DeleteGraph(playerImg[i]);
	}
}