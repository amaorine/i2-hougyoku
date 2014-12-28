#include "../include/DxLib.h";
#include "boss.h";
#include "shot.h";
#include "field.h";

//ボス攻撃のメイン
//難易度で角度とか数のフラグわけ？
//bossSpell_ステージ番号(01～08(06,07が６面分岐)スペル番号(通常含む、３面のサーカスコンビは分岐)
//全部戻り値はint 0=プレイヤーに破壊されただの時間切れだの　1=まだ大丈夫
//会話云々もここ？
//初期化系を繰り返されると面倒なので


int count=0;	//行動用カウント
int page=0;		//場面切り替え用
int live=1;


//タイマー


void bossSpellInitialize(int timeFrame,double iniX,double iniY,int iniMoveTimeFrame){
	//タイマーセットと初期位置へ移動
	//どのみち体力も追加
	bossSetTime(timeFrame);
	bossMovePosition02(iniX,iniY,iniMoveTimeFrame);
}

void bossSpellFinalize(){
	//スペル終わりの処理
	count=0;	//カウント初期化
	page++;	//次の場面に進める
}

void  bossTimer(){
	bossSetTime(bossGetTime()-1);
	if(bossGetTime()<0){
		//0切ったら終了処理
		bossSpellFinalize();
	}
	else{
	count++;
	}
}



//１面
//中ボス
void  bossSpell_0101(){
	double angleIni=GetRand(360/10);
	if(count==0){
	bossSpellInitialize(60*10,(getFieldMaxX()-getFieldMinX())/2,getFieldMinY()+50,60);	//0カウントの時だけ作動する初期化処理
	}
	else if(count%120==0){
		for(int i=0;i<100;i++){
			setBullet(getBossX(),getBossY(),3.0,i/10*360/10+GetRand(360/10));
		}
	bossMovePosition02(getBossX()+10,getBossY()+50,60);
	}
	bossTimer();
}

//ボス（ルビー）通常２、スペル２
void  bossSpell_0102(){
	if(count==0){
	bossSpellInitialize(60*10,(getFieldMaxX()-getFieldMinX())/2,getFieldMinY()+50,60);	//0カウントの時だけ作動する初期化処理
	}
	else if(count%120==0){
		for(int i=0;i<100;i++){
			setBullet(getBossX(),getBossY(),3.0,i/10*360/10+GetRand(360/10));
			
		}
	bossMovePosition02(getBossX()+10,getBossY()+50,60);
	}
	bossTimer();
}


int statege1(){
	DrawFormatString(50,200,GetColor(255, 255, 255),"BossTime:%d",bossGetTime());
	DrawFormatString(50,220,GetColor(255, 255, 255),"Count:%d",count);

	switch(page){
	case 0:
		bossSpell_0101();
		break;
	case 1:
		bossSpell_0102();
		break;
	case 2:
		//本来はボス通常が来るけど今回は戻す
		page=0;
		break;
	default:
		DrawFormatString(50,200,GetColor(255, 255, 255),"エラー");
		break;

	}

	return 1;
}