#pragma once	//2重インクルード防止

//弾幕メインはbossShot.cppのなかのshot関数なので、ここでは使いそうな移動とかの処理を書く。
void bossInitialize();
void bossMove();
double getBossX();
double getBossY();
void bossSetTime(int time);
int bossGetTime();
void bossMovePosition02(double x,double y,int moveCount);				//弾幕風と一緒の移動方法 着地点とそこまでに行き着くカウント設定
void bossGraph();		//描画処理
void bossFinalize();	//終了処理