#pragma once	//2�d�C���N���[�h�h�~
#include "Object.h";


class Player:public Object
{
	//�ϐ��錾
	int slow;	//�ᑬ����
	int playerImg[12];	//�摜

public:
	//�R���X�g���N�^
	Player();
	Player(double x,double y,double v);
	//�ړ��Ƃ�
	void move();
	void graph();
	void main();
};