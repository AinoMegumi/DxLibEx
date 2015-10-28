#ifndef DX_LIB_EX_STRUCTS_H_
#define DX_LIB_EX_STRUCTS_H_
#include "DxLib.h"

namespace DxLibEx{
namespace DxStructs//!DxLib��struct��using�錾���W�߂�namespace�ł�
{
	
	using DxLib::IMEINPUTCLAUSEDATA;//!�h�l�d���͕�����̕`��ɕK�v�ȏ��̓��̕��ߏ��
	using DxLib::LPIMEINPUTCLAUSEDATA;//!�h�l�d���͕�����̕`��ɕK�v�ȏ��̓��̕��ߏ��

	using DxLib::IMEINPUTDATA;//!�h�l�d���͕�����̕`��ɕK�v�ȏ��
	using DxLib::LPIMEINPUTDATA;//!�h�l�d���͕�����̕`��ɕK�v�ȏ��

	using DxLib::DISPLAYMODEDATA;//!��ʃ��[�h���f�[�^�^
	using DxLib::LPDISPLAYMODEDATA;//!��ʃ��[�h���f�[�^�^

	using DxLib::DATEDATA;//!�^�C���f�[�^�^
	using DxLib::LPDATEDATA;//!�^�C���f�[�^�^

	using DxLib::FILEINFO;//!�t�@�C�����\����
	using DxLib::LPFILEINFO;//!�t�@�C�����\����

	using DxLib::FILEINFOW;//!�t�@�C�����\���́i wchar_t �� �j
	using DxLib::LPFILEINFOW;//!�t�@�C�����\���́i wchar_t �� �j

	using DxLib::MATRIX;//!�s��\����
	using DxLib::LPMATRIX;//!�s��\����

	using DxLib::MATRIX_D;//!�s��\����
	using DxLib::LPMATRIX_D;//!�s��\����

	using DxLib::VECTOR;//!�x�N�g���f�[�^�^
	using DxLib::LPVECTOR;//!�x�N�g���f�[�^�^
	using DxLib::FLOAT3;//!�x�N�g���f�[�^�^
	using DxLib::LPFLOAT3;//!�x�N�g���f�[�^�^

	using DxLib::VECTOR_D;//!�x�N�g���f�[�^�^
	using DxLib::LPVECTOR_D;//!�x�N�g���f�[�^�^
	using DxLib::DOUBLE3;//!�x�N�g���f�[�^�^
	using DxLib::LPDOUBLE3;//!�x�N�g���f�[�^�^

	using DxLib::FLOAT2;//!FLOAT2�f�[�^�^

	using DxLib::COLOR_F;//!float �^�̃J���[�l
	using DxLib::LPCOLOR_F;//!float �^�̃J���[�l

	using DxLib::COLOR_U8;//!unsigned char �^�̃J���[�l

	using DxLib::FLOAT4;//!FLOAT4�f�[�^�^
	using DxLib::LPFLOAT4;//!FLOAT4�f�[�^�^

	using DxLib::DOUBLE4;//!DOUBLE4�f�[�^�^
	using DxLib::LPDOUBLE4;//!DOUBLE4�f�[�^�^

	using DxLib::INT4;//!INT4�f�[�^�^

#ifndef DX_NOTUSE_DRAWFUNCTION

	using DxLib::VERTEX2D;//!�Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2D�p)
	using DxLib::LPVERTEX2D;//!�Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2D�p)

	using DxLib::VERTEX2DSHADER;//!�Q�c�`��Ɏg�p���钸�_�f�[�^�^(���J�p)
	using DxLib::LPVERTEX2DSHADER;//!�Q�c�`��Ɏg�p���钸�_�f�[�^�^(���J�p)

	using DxLib::VERTEX_3D;//!�R�c�`��Ɏg�p���钸�_�f�[�^�^( ���o�[�W�����̂��� )
	using DxLib::LPVERTEX_3D;//!�R�c�`��Ɏg�p���钸�_�f�[�^�^( ���o�[�W�����̂��� )

	using DxLib::VERTEX3D;//!�R�c�`��Ɏg�p���钸�_�f�[�^�^
	using DxLib::LPVERTEX3D;//!�R�c�`��Ɏg�p���钸�_�f�[�^�^

	//!�R�c�`��Ɏg�p���钸�_�f�[�^�^( DrawPrimitive3DToShader�p )
	//!���Ӂc�����o�ϐ��ɒǉ������邩������܂���̂ŁA�錾���̏�����( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... �Ƃ����悤�Ȃ��� )�͂��Ȃ������ǂ��ł�
	using DxLib::VERTEX3DSHADER;
	//!�R�c�`��Ɏg�p���钸�_�f�[�^�^( DrawPrimitive3DToShader�p )
	//!���Ӂc�����o�ϐ��ɒǉ������邩������܂���̂ŁA�錾���̏�����( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... �Ƃ����悤�Ȃ��� )�͂��Ȃ������ǂ��ł�
	using DxLib::LPVERTEX3DSHADER;

	using DxLib::LIGHTPARAM;//!���C�g�p�����[�^

	using DxLib::MATERIALPARAM;//!�}�e���A���p�����[�^

#endif//#ifndef DX_NOTUSE_DRAWFUNCTION

	using DxLib::HITRESULT_LINE;//!���C���q�b�g�`�F�b�N���ʊi�[�p�\����
	using DxLib::HITRESULT_LINE_D;//!���C���q�b�g�`�F�b�N���ʊi�[�p�\����

	using DxLib::SEGMENT_SEGMENT_RESULT;//!�֐� Segment_Segment_Analyse �̌��ʂ��󂯎��ׂ̍\����
	using DxLib::SEGMENT_SEGMENT_RESULT_D;//!�֐� Segment_Segment_Analyse �̌��ʂ��󂯎��ׂ̍\����

	using DxLib::SEGMENT_POINT_RESULT;//!�֐� Segment_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����
	using DxLib::SEGMENT_POINT_RESULT_D;//!�֐� Segment_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����

	using DxLib::SEGMENT_TRIANGLE_RESULT;//!�֐� Segment_Triangle_Analyse �̌��ʂ��󂯎��ׂ̍\����
	using DxLib::SEGMENT_TRIANGLE_RESULT_D;//!�֐� Segment_Triangle_Analyse �̌��ʂ��󂯎��ׂ̍\����

	using DxLib::TRIANGLE_POINT_RESULT;//!�֐� Triangle_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����
	using DxLib::TRIANGLE_POINT_RESULT_D;//!�֐� Triangle_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����

	using DxLib::PLANE_POINT_RESULT;//!�֐� Plane_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����
	using DxLib::PLANE_POINT_RESULT_D;//!�֐� Plane_Point_Analyse �̌��ʂ��󂯎��ׂ̍\����

#ifndef DX_NOTUSE_DRAWFUNCTION

	using DxLib::MV1_COLL_RESULT_POLY;//!�R���W�������ʑ���p�|���S��

	using DxLib::MV1_COLL_RESULT_POLY_DIM;//!�R���W�������ʑ���p�|���S���z��

	using DxLib::MV1_REF_VERTEX;//!�Q�Ɨp���_�\����

	using DxLib::MV1_REF_POLYGON;//!�Q�Ɨp�|���S���\����

	using DxLib::MV1_REF_POLYGONLIST;//!�Q�Ɨp�|���S���f�[�^�\����

#endif //#ifndef DX_NOTUSE_DRAWFUNCTION

	

	using DxLib::SOUND3D_REVERB_PARAM;//!�R�c�T�E���h���o�[�u�G�t�F�N�g�p�����[�^�\����

	using DxLib::STREAMDATASHREDTYPE2;//!�X�g���[���f�[�^����p�֐��|�C���^�\���̃^�C�v�Q
	using DxLib::STREAMDATASHREDTYPE2W;//!�X�g���[���f�[�^����p�֐��|�C���^�\���̃^�C�v�Q�� wchar_t �g�p��

	using DxLib::STREAMDATASHRED;//!�X�g���[���f�[�^����p�֐��|�C���^�\����
	using DxLib::LPSTREAMDATASHRED;//!�X�g���[���f�[�^����p�֐��|�C���^�\����

	using DxLib::STREAMDATA;//!�X�g���[���f�[�^����p�f�[�^�\����



	using DxLib::STREAMDATA;//!�p���b�g���\����

	using DxLib::COLORDATA;//!�J���[�\�����\����

	using DxLib::BASEIMAGE;//!��{�C���[�W�f�[�^�\����
	using DxLib::GRAPHIMAGE;//!��{�C���[�W�f�[�^�\����
	using DxLib::LPGRAPHIMAGE;//!��{�C���[�W�f�[�^�\����

	using DxLib::LINEDATA;//!���C���f�[�^�^
	using DxLib::LPLINEDATA;//!���C���f�[�^�^

	using DxLib::POINTDATA;//!���W�f�[�^�^
	using DxLib::LPPOINTDATA;//!���W�f�[�^�^

#ifndef DX_NOTUSE_DRAWFUNCTION

	using DxLib::IMAGEFORMATDESC;//!�C���[�W�t�H�[�}�b�g�f�[�^

#endif //#ifndef DX_NOTUSE_DRAWFUNCTION

	using DxLib::DINPUT_JOYSTATE;//!DirectInput �̃W���C�p�b�h���͏��

	using DxLib::XINPUT_STATE;//!XInput �̃W���C�p�b�h���͏��

	using DxLib::TOUCHINPUTPOINT;//!�^�b�`�p�l���̂P�ӏ����̃^�b�`�̏��

	using DxLib::TOUCHINPUTDATA;//!�^�b�`�p�l���̃^�b�`�̏��



	using DxLib::IPDATA;//!WinSockets�g�p���̃A�h���X�w��p�\����
	using DxLib::LPIPDATA;//!WinSockets�g�p���̃A�h���X�w��p�\����

	using DxLib::IPDATA_IPv6;

}
using namespace DxStructs;
}//namespace end

#endif
