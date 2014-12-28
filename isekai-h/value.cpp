#include "../include/DxLib.h";
#include "math.h";
#define PI    3.1415926535897932384626433832795f

//角度測ったり距離測ったりするやつ

double dicToRas(double angle){
	//度→ラジアン
	return angle*PI/180;
}

//異なる位置にある2つの点AB間の距離を取得する
double getGapLength(double xA,double yA,double xB,double yB){
	return pow(pow(xB-xA,2.0)+pow(yB-yA,2.0),0.5);
}
//点Aから異なる位置にある点Bへの絶対角度を取得する
double getGapAngle(double xA,double yA,double xB,double yB){
	return dicToRas(atan2( yB - yA, xB - xA));
}

//	点Aからある距離、絶対角度にある点Bのx座標を取得する
double GetGapX(double xA,double gapLength,double gapAngle){
	double gA=dicToRas(gapAngle);
	return xA + gapLength * cos(gA);
}

//	点Aからある距離、絶対角度にある点Bのy座標を取得する
double GetGapY(double yA,double gapLength,double gapAngle){
	double gA=dicToRas(gapAngle);
	return yA + gapLength * sin(gA);
}