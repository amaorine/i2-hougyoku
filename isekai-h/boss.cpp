#include "../include/DxLib.h";
int bossImg[32];

typedef struct{
	double x,y;
	double pointX,pointY;
	double hp;
	int moveCount,moveTime;	//移動用カウントと移動制限時間
	int time;	//スペル時間

}bossSt;


//構造体宣言
bossSt boss;
void bossMove(){
	//指定先にmoveCountで移動
	if(boss.moveCount<boss.moveTime){
		boss.x+=(boss.pointX-boss.x)/(boss.moveTime-boss.moveCount);
		boss.y+=(boss.pointY-boss.y)/(boss.moveTime-boss.moveCount);
		boss.moveCount++;
	}
		DrawFormatString(50,50,GetColor(255, 255, 255),"moveCount:%d",boss.moveCount);
		DrawFormatString(50,70,GetColor(255, 255, 255),"moveTime:%d",boss.moveTime);
		DrawFormatString(200,50,GetColor(255, 255, 255),"bossX:%f",boss.x);
		DrawFormatString(200,70,GetColor(255, 255, 255),"bossY:%f",boss.y);
	
}


void bossMovePosition02(double x,double y,int moveCount){
	boss.pointX=x;
	boss.pointY=y;
	boss.moveCount=0;
	boss.moveTime=moveCount;
	
}

//ボスの座標トルコ達
double getBossX(){
	return boss.x;
}

double getBossY(){
	return boss.y;
}

//時間せっと
void bossSetTime(int time){
	boss.time=time;
}

//時間取得
int bossGetTime(){
	return boss.time;
}


//弾幕メインはbossShot.cppのなかのshot関数なので、ここでは使いそうな移動とかの処理を書く。
void bossInitialize(){
//	bossMovePosition02(boss.x+30,boss.y,100);
	//ロードとかの初期化処理
	LoadDivGraph( "../dat/img/boss/dot_ranmaru.png",32,8,4,128,128,bossImg) ;
}

void bossGraph(){
	//描画処理
	DrawRotaGraphF(boss.x,boss.y,1.0f,0.0f,bossImg[0],TRUE);
}		
void bossFinalize(){
	//終了処理
	for(int i=0;i<32;i++){
	DeleteGraph(bossImg[i]);
	}
}	