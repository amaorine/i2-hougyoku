#include "../include/DxLib.h";
#include "math.h";
#include "value.h";
#include "field.h";

typedef struct{
	int flag,knd,color;			//弾が存在してるかどうか,種類、色
	double x,y,v,angle;	//xy位置,速度、角度

}shotSt;

#define SHOT_MAX 500
shotSt shot[SHOT_MAX];		//弾の構造体
int shotImg[15][16*11];	//弾格納 種類→色の順

void shotInitialize(){
	//ロードとか宣言とか
	LoadDivGraph( "../dat/img/shot/shot0-10.png",16*11,16,11,16,16,shotImg[0]) ;
	//弾の初期化
	for(int i=0;i<SHOT_MAX;i++){
	shot[i].x=0.0;
	shot[i].y=0.0;
	shot[i].v=0.0;
	shot[i].flag=0;
	shot[i].angle=0.0;
	}
}

void setBullet(double startX,double startY,double speed,double angle){
	for(int i=0;i<SHOT_MAX;i++){
		//どっかあいてる番号あったら登録して、break
		if(shot[i].flag==0){
			shot[i].flag=1;
			shot[i].x=startX;
			shot[i].y=startY;
			shot[i].v=speed;
			shot[i].angle=angle;

			//セットし終わったら抜ける
			break;
		}
	}
}

void deleteBullet(){
	for(int i=0;i<SHOT_MAX;i++){
		//画面外から飛び出たら消去
		if(shot[i].x<getFieldMinX()||shot[i].x>getFieldMaxX()||shot[i].y<getFieldMinY()||shot[i].y>getFieldMaxY()){
	shot[i].x=0.0;
	shot[i].y=0.0;
	shot[i].v=0.0;
	shot[i].flag=0;
	shot[i].angle=0.0;

		}
	}
}


void shotMove(){

	for(int i=0;i<SHOT_MAX;i++){
		if(shot[i].flag==1){
			//自分の座標を中心とした半径shot[i].v先のshot[i].angleのx,y座標をmoveX,moveYに代入→shot[i].x,yに代入
			shot[i].x=GetGapX(shot[i].x,shot[i].v,shot[i].angle);
			shot[i].y=GetGapY(shot[i].y,shot[i].v,shot[i].angle);
		}
	}
}

void shotGraph(){
	for(int i=0;i<SHOT_MAX;i++){
		if(shot[i].flag==1){
			DrawRotaGraph(shot[i].x,shot[i].y,1.0,dicToRas(shot[i].angle+90),shotImg[0][16], TRUE );
		}
	}

}

void shotFinalize(){
}