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
	this->x=x;
	this->y=y;
}

Object::Object(double x,double y,double v){
	Object();
	this->x=x;
	this->y=y;
	this->v=v;
}

Object::Object(double x,double y,int count){
	Object();
	this->x=x;
	this->y=y;
	this->count=count;
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
	this->x=x;
	this->y=y;
}

void Object::setV(double v){
	this->v=v;
}
