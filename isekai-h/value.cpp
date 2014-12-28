#include "../include/DxLib.h";
#include "math.h";
#define PI    3.1415926535897932384626433832795f

//�p�x�������苗���������肷����

double dicToRas(double angle){
	//�x�����W�A��
	return angle*PI/180;
}

//�قȂ�ʒu�ɂ���2�̓_AB�Ԃ̋������擾����
double getGapLength(double xA,double yA,double xB,double yB){
	return pow(pow(xB-xA,2.0)+pow(yB-yA,2.0),0.5);
}
//�_A����قȂ�ʒu�ɂ���_B�ւ̐�Ίp�x���擾����
double getGapAngle(double xA,double yA,double xB,double yB){
	return dicToRas(atan2( yB - yA, xB - xA));
}

//	�_A���炠�鋗���A��Ίp�x�ɂ���_B��x���W���擾����
double GetGapX(double xA,double gapLength,double gapAngle){
	double gA=dicToRas(gapAngle);
	return xA + gapLength * cos(gA);
}

//	�_A���炠�鋗���A��Ίp�x�ɂ���_B��y���W���擾����
double GetGapY(double yA,double gapLength,double gapAngle){
	double gA=dicToRas(gapAngle);
	return yA + gapLength * sin(gA);
}