#include "include.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen()!=0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�


	int page = 0;

	//����������
	//playerInitilaze();	//�v���C���[������
	Player player(100.0,100.0,3.0);
	bossInitialize();	//�{�X������
	shotInitialize();	//�{�X������

	//bossMovePosition02(50,300,100);
	setBullet(0.0,0.0,3.0,90);



	while(ProcessLoop()==0&&CheckStateKey(KEY_INPUT_ESCAPE)==0){//���C�����[�v
		//�����ɏ���
		statege1();








		//�قږ��񏈗�
		player.main();
		shotMove();
		shotGraph();
		deleteBullet();
		bossMove();
		bossGraph();


		//�����ɏ���

		ScreenFlip();//����ʔ��f
	}

	DxLib_End();//�c�w���C�u�����I������
	return 0;
}



