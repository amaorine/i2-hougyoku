#include"Player.h";
#include"key.h";
#include "../include/DxLib.h";
#include "math.h";
#include "field.h";

//コントラクタ組
Player::Player():Object(){
	LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
	//Objectで初期化する。
}

Player::Player(double x,double y,double v):Object(x,y){
	Object::setV(v);
	
	LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
}

//関数組
void Player::move(){
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
			Object::updateXY(Object::getX()+Object::getV()/vRateSlant*vRateX[i],Object::getY()+Object::getV()/vRateSlant*vRateY[i]);

			if(Object::getX()>xMoveMax[0]||Object::getX()<xMoveMax[1]){
				//左右に動くのはi=1とi=3の時なので、i/2
				Object::updateXY(xMoveMax[int(i/2)],Object::getY());
			}
			if(Object::getY()>yMoveMax[1]||Object::getY()<yMoveMax[0]){
				//左右に動くのはi=1とi=3の時なので、i/2
				Object::updateXY(Object::getX(),yMoveMax[int(i/2)]);
			}			
		}
	}

}
void Player::graph(){
	//描画処理
	//自機を自機座標を中心に描画
	DrawRotaGraphF(Object::getX(),Object::getY(),1.0f,0.0f,playerImg[0],TRUE);
}

void Player::main(){
	move();
	graph();
}