#include"Object.h";
#include "../include/DxLib.h";

//�R���X�g���N�^�Q
Object::Object(){
	double x=0.0;
	double y=0.0;
	double v=0.0;
	int flag=0;
	int count=0;
}

Object::Object(double x,double y){
	Object();
	Object.x=x;
	Object.y=y;
}

Object::Object(double x,double y,double v){
	Object();
	Object.x=x;
	Object.y=y;
	Object.v=v;
}

Object::Object(double x,double y,int count){
	Object();
	Object.x=x;
	Object.y=y;
	Object.count=count;
}

//�֐�
//�����g
double Object::getX(){
	return x;
}

double Object::getY(){
	return y;
}

double Object::getV(){
	return v;
}

//�ʒu�X�V�p
void Object::updateXY(double x,double y){
	Object.x=x;
	Object.y=y;
}
