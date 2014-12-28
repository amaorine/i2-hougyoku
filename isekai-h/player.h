#pragma once	//2重インクルード防止
#include "Object.h";


class Player:public Object
{
	//変数宣言
	int slow;	//低速判定
	int playerImg[12];	//画像

public:
	//コンストラクタ
	Player();
	Player(double x,double y,double v);
	//移動とか
	void move();
	void graph();
	void main();
};