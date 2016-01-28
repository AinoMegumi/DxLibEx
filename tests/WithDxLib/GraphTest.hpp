//����e�X�g�Ƃ������T���v��
//��ŏ�������
#define DX_NON_USING_NAMESPACE_DXLIB
#include "dxlibex\Graph2D.h"
#include "dxlibex\basic_types.hpp"

int DrawGraph(const dxle::pointi& point, const dxle::texture_2d& Graph, bool TransFlag)
{
	return Graph.DrawGraph(point.x, point.y, TransFlag);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	using namespace dxle::graph2d;
	using dxle::sizei;
	DxLib::ChangeWindowMode(TRUE);
	if (DxLib::DxLib_Init() == -1)        // �c�w���C�u��������������
	{
		return -1;        // �G���[���N�����璼���ɏI��
	}

	{
		// test1.bmp�̓ǂݍ���
		auto GHandle = LoadGraph("test1.bmp");

		// �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
		DrawGraph({0, 0}, GHandle, TRUE);

		DxLib::WaitKey();
		DxLib::ClearDrawScreen();

		// �ǂ݂��񂾃O���t�B�b�N����ʒ����ɕ`��
		DrawGraph((sizei{640, 480} - GHandle.size()) / 2, GHandle, TRUE);

		DxLib::WaitKey();
		DxLib::ClearDrawScreen();
	}



	DxLib::DxLib_End();            // �c�w���C�u�����g�p�̏I������

	return 0;            // �\�t�g�̏I��
}