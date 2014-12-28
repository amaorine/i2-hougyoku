#include"Player.h";
#include"key.h";
#include "../include/DxLib.h";
#include "math.h";
#include "field.h";

//�R���g���N�^�g
Player::Player():Object(){
	LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
	//Object�ŏ���������B
}

Player::Player(double x,double y,double v):Object(x,y){
	Object::setV(v);
	
	LoadDivGraph( "../dat/img/char/player.png" ,12 , 4 , 3 , 73 , 73 ,playerImg) ;
}

//�֐��g
void Player::move(){
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
			Object::updateXY(Object::getX()+Object::getV()/vRateSlant*vRateX[i],Object::getY()+Object::getV()/vRateSlant*vRateY[i]);

			if(Object::getX()>xMoveMax[0]||Object::getX()<xMoveMax[1]){
				//���E�ɓ����̂�i=1��i=3�̎��Ȃ̂ŁAi/2
				Object::updateXY(xMoveMax[int(i/2)],Object::getY());
			}
			if(Object::getY()>yMoveMax[1]||Object::getY()<yMoveMax[0]){
				//���E�ɓ����̂�i=1��i=3�̎��Ȃ̂ŁAi/2
				Object::updateXY(Object::getX(),yMoveMax[int(i/2)]);
			}			
		}
	}

}
void Player::graph(){
	//�`�揈��
	//���@�����@���W�𒆐S�ɕ`��
	DrawRotaGraphF(Object::getX(),Object::getY(),1.0f,0.0f,playerImg[0],TRUE);
}

void Player::main(){
	move();
	graph();
}