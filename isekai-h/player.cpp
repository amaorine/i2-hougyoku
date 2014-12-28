#include "../include/DxLib.h";
#include "math.h";
#include"key.h";
#include"field.h";

typedef struct{
	double x,y;	//���W
	double v;	//���x
	int point;	//���_
	int slow;	//�ᑬ���ǂ���
	int bomb;	//�{����
	int pointJem;	//��ʊ��f�p�G�l���M�[
}playerSt;

int playerImg[12];	//�ǂݍ��񂾉摜���i�[����Ƃ�
playerSt player;	//�\���̐錾

void playerInitilaze(){
	//����������
	//���@�摜���[�h
	 LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
	 //�����ʒu�ݒ�Ƃ��{��������Ƃ��̒�`
	 player.v=4.0;
	 player.x=getFieldMinX()+(getFieldMaxX()-getFieldMinX())/2;
	 player.y=getFieldMaxY()-30;

}

void playerMove(){
	//�㉺���E�̃L�[��������Ă邩�̃t���O����
	int chekKey[4];
	double vRateX[4]={0.0,1.0,0.0,-1.0};
	double vRateY[4]={-1.0,0.0,1.0,0.0};
	double vRateSlant=1.0;	//�ȂȂ߈ړ��t���O
	double xMoveMax[2]={getFieldMaxX()-10,10};
	double yMoveMax[2]={5,getFieldMaxY()-5};
	chekKey[0]=CheckStateKey(KEY_INPUT_UP);	//��
	chekKey[1]=CheckStateKey(KEY_INPUT_RIGHT);	//��
	chekKey[2]=CheckStateKey(KEY_INPUT_DOWN);	//��
	chekKey[3]=CheckStateKey(KEY_INPUT_LEFT);	//��


	//�ړ���̎��@�ʒu�ݒ�
	if((chekKey[0]||chekKey[2])&&(chekKey[1]||chekKey[3])){
		//�㉺�ǂ��炩�ƍ��E�ǂ��炩���ǂ�����1�Ȃ�ȂȂߗp�ɃX�s�[�h��1��2��
		vRateSlant=sqrt(2.0);
	}
	for(int i=0;i<4;i++){
		if(chekKey[i]>0){
			if(CheckStateKey(KEY_INPUT_LSHIFT)||CheckStateKey(KEY_INPUT_RSHIFT)==1){
				vRateX[i]/=3;
				vRateY[i]/=3;
			}

			player.x+=player.v/vRateSlant*vRateX[i];
			player.y+=player.v/vRateSlant*vRateY[i];

			if(player.x>xMoveMax[0]||player.x<xMoveMax[1]){
				//���E�ɓ����̂�i=1��i=3�̎��Ȃ̂ŁAi/2
				player.x=xMoveMax[int(i/2)];
			}
			if(player.y>yMoveMax[1]||player.y<yMoveMax[0]){
				//���E�ɓ����̂�i=1��i=3�̎��Ȃ̂ŁAi/2
				player.y=yMoveMax[int(i/2)];
			}			
		}
	}



}	
void playerGraph(){
	//�`�揈��
	//���@�����@���W�𒆐S�ɕ`��
	DrawRotaGraphF(player.x,player.y,1.0f,0.0f,playerImg[0],TRUE);
}

void playerMain(){
	//main�t�@�C���ɂČĂяo�����@�̓���܂Ƃ�
	playerMove();
	playerGraph();
}

void playerFinalize(){
	//�I������
	for(int i=0;i<12;i++){
	DeleteGraph(playerImg[i]);
	}
}