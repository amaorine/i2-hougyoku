#include "../include/DxLib.h";
#include "boss.h";
#include "shot.h";
#include "field.h";

//�{�X�U���̃��C��
//��Փx�Ŋp�x�Ƃ����̃t���O�킯�H
//bossSpell_�X�e�[�W�ԍ�(01�`08(06,07���U�ʕ���)�X�y���ԍ�(�ʏ�܂ށA�R�ʂ̃T�[�J�X�R���r�͕���)
//�S���߂�l��int 0=�v���C���[�ɔj�󂳂ꂽ���̎��Ԑ؂ꂾ�́@1=�܂����v
//��b�]�X�������H
//�������n���J��Ԃ����Ɩʓ|�Ȃ̂�


int count=0;	//�s���p�J�E���g
int page=0;		//��ʐ؂�ւ��p
int live=1;


//�^�C�}�[


void bossSpellInitialize(int timeFrame,double iniX,double iniY,int iniMoveTimeFrame){
	//�^�C�}�[�Z�b�g�Ə����ʒu�ֈړ�
	//�ǂ݂̂��̗͂��ǉ�
	bossSetTime(timeFrame);
	bossMovePosition02(iniX,iniY,iniMoveTimeFrame);
}

void bossSpellFinalize(){
	//�X�y���I���̏���
	count=0;	//�J�E���g������
	page++;	//���̏�ʂɐi�߂�
}

void  bossTimer(){
	bossSetTime(bossGetTime()-1);
	if(bossGetTime()<0){
		//0�؂�����I������
		bossSpellFinalize();
	}
	else{
	count++;
	}
}



//�P��
//���{�X
void  bossSpell_0101(){
	double angleIni=GetRand(360/10);
	if(count==0){
	bossSpellInitialize(60*10,(getFieldMaxX()-getFieldMinX())/2,getFieldMinY()+50,60);	//0�J�E���g�̎������쓮���鏉��������
	}
	else if(count%120==0){
		for(int i=0;i<100;i++){
			setBullet(getBossX(),getBossY(),3.0,i/10*360/10+GetRand(360/10));
		}
	bossMovePosition02(getBossX()+10,getBossY()+50,60);
	}
	bossTimer();
}

//�{�X�i���r�[�j�ʏ�Q�A�X�y���Q
void  bossSpell_0102(){
	if(count==0){
	bossSpellInitialize(60*10,(getFieldMaxX()-getFieldMinX())/2,getFieldMinY()+50,60);	//0�J�E���g�̎������쓮���鏉��������
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
		//�{���̓{�X�ʏ킪���邯�Ǎ���͖߂�
		page=0;
		break;
	default:
		DrawFormatString(50,200,GetColor(255, 255, 255),"�G���[");
		break;

	}

	return 1;
}