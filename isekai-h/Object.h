//�Ƃ�܌���x,y�����̓A�C�e�����낤���G���낤���������낤�������Ȃ̂ł܂Ƃ߂���B
//�N���X���Ƃ��ɓ��ɕύX�Ȃ��Ŏg�������Ȋ֐��܂Ƃ�
//�ړ��n��������łł��邩�H
#pragma once	//2�d�C���N���[�h�h�~

class Object
{
	double x,y,v;	//���g�̌���x,y�ʒu�Ƒ��x
	int flag,count;	//����t���O�ƍs���p�^�[���p�̃J�E���^�B�G�̐؂�ւ��Ƃ��ɂ��g���B
public:
	//�R���g���N�^�Q�B
	Object();	//������
	Object(double x,double y);
	Object(double x,double y,double v);
	Object(double x,double y,int count);
	//�֐��g
	//�擾�g �ォ��x�ʒu�Ay�ʒu�A���x
	double getX();
	double getY();
	double getV();
	//�ʒu�X�V�֐�
	void updateXY(double x,double y);
};