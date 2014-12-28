#include "../include/DxLib.h";
int bossImg[32];

typedef struct{
	double x,y;
	double pointX,pointY;
	double hp;
	int moveCount,moveTime;	//�ړ��p�J�E���g�ƈړ���������
	int time;	//�X�y������

}bossSt;


//�\���̐錾
bossSt boss;
void bossMove(){
	//�w����moveCount�ňړ�
	if(boss.moveCount<boss.moveTime){
		boss.x+=(boss.pointX-boss.x)/(boss.moveTime-boss.moveCount);
		boss.y+=(boss.pointY-boss.y)/(boss.moveTime-boss.moveCount);
		boss.moveCount++;
	}
		DrawFormatString(50,50,GetColor(255, 255, 255),"moveCount:%d",boss.moveCount);
		DrawFormatString(50,70,GetColor(255, 255, 255),"moveTime:%d",boss.moveTime);
		DrawFormatString(200,50,GetColor(255, 255, 255),"bossX:%f",boss.x);
		DrawFormatString(200,70,GetColor(255, 255, 255),"bossY:%f",boss.y);
	
}


void bossMovePosition02(double x,double y,int moveCount){
	boss.pointX=x;
	boss.pointY=y;
	boss.moveCount=0;
	boss.moveTime=moveCount;
	
}

//�{�X�̍��W�g���R�B
double getBossX(){
	return boss.x;
}

double getBossY(){
	return boss.y;
}

//���Ԃ�����
void bossSetTime(int time){
	boss.time=time;
}

//���Ԏ擾
int bossGetTime(){
	return boss.time;
}


//�e�����C����bossShot.cpp�̂Ȃ���shot�֐��Ȃ̂ŁA�����ł͎g�������Ȉړ��Ƃ��̏����������B
void bossInitialize(){
//	bossMovePosition02(boss.x+30,boss.y,100);
	//���[�h�Ƃ��̏���������
	LoadDivGraph( "../dat/img/boss/dot_ranmaru.png",32,8,4,128,128,bossImg) ;
}

void bossGraph(){
	//�`�揈��
	DrawRotaGraphF(boss.x,boss.y,1.0f,0.0f,bossImg[0],TRUE);
}		
void bossFinalize(){
	//�I������
	for(int i=0;i<32;i++){
	DeleteGraph(bossImg[i]);
	}
}	