#pragma once	//2�d�C���N���[�h�h�~

//�e�����C����bossShot.cpp�̂Ȃ���shot�֐��Ȃ̂ŁA�����ł͎g�������Ȉړ��Ƃ��̏����������B
void bossInitialize();
void bossMove();
double getBossX();
double getBossY();
void bossSetTime(int time);
int bossGetTime();
void bossMovePosition02(double x,double y,int moveCount);				//�e�����ƈꏏ�̈ړ����@ ���n�_�Ƃ����܂łɍs�������J�E���g�ݒ�
void bossGraph();		//�`�揈��
void bossFinalize();	//�I������