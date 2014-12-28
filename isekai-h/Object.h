//とりま現在x,y所得はアイテムだろうが敵だろうが味方だろうが同じなのでまとめられる。
//クラス作るときに特に変更なしで使えそうな関数まとめ
//移動系統もこれでできるか？
#pragma once	//2重インクルード防止

class Object
{
	double x,y,v;	//自身の現在x,y位置と速度
	int flag,count;	//判定フラグと行動パターン用のカウンタ。絵の切り替えとかにも使う。
public:
	//コントラクタ群。
	Object();	//初期化
	Object(double x,double y);
	Object(double x,double y,double v);
	Object(double x,double y,int count);
	//関数組
	//取得組 上からx位置、y位置、速度
	double getX();
	double getY();
	double getV();
	//位置更新関数
	void updateXY(double x,double y);
};