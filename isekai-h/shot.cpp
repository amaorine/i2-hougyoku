#include "../include/DxLib.h";
#include "math.h";
#include "value.h";
#include "field.h";

typedef struct{
	int flag,knd,color;			//�e�����݂��Ă邩�ǂ���,��ށA�F
	double x,y,v,angle;	//xy�ʒu,���x�A�p�x

}shotSt;

#define SHOT_MAX 500
shotSt shot[SHOT_MAX];		//�e�̍\����
int shotImg[15][16*11];	//�e�i�[ ��ށ��F�̏�

void shotInitialize(){
	//���[�h�Ƃ��錾�Ƃ�
	LoadDivGraph( "../dat/img/shot/shot0-10.png",16*11,16,11,16,16,shotImg[0]) ;
	//�e�̏�����
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
		//�ǂ��������Ă�ԍ���������o�^���āAbreak
		if(shot[i].flag==0){
			shot[i].flag=1;
			shot[i].x=startX;
			shot[i].y=startY;
			shot[i].v=speed;
			shot[i].angle=angle;

			//�Z�b�g���I������甲����
			break;
		}
	}
}

void deleteBullet(){
	for(int i=0;i<SHOT_MAX;i++){
		//��ʊO�����яo�������
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
			//�����̍��W�𒆐S�Ƃ������ashot[i].v���shot[i].angle��x,y���W��moveX,moveY�ɑ����shot[i].x,y�ɑ��
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