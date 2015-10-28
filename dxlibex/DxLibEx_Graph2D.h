#ifndef DX_LIB_EX_GRAPH_2D_H_201510241561
#define DX_LIB_EX_GRAPH_2D_H_201510241561

#include "DxLib.h"
#include <type_traits>
#include <utility>
#include <memory>
#include <string>
#include "DxLibEx_Helper.h"
#include "DxLibEx_Defines.h"

//----------2D�O���t�B�b�N----------//

namespace DxLibEx
{
	//!DxLibEx�̌��J�N���X���S�ē�����namespace�ł�
	namespace DxLibEx_Classes {}
	//! 2D�O���t�B�b�N
	namespace Graph2D
	{
	
		//! class Texture2D�̃I�[�o�[�w�b�h�����Ȃ�Ver
		//! �������R�s�[���ł��Ȃ�
		class Texture2D_Unique : public impl::Unique_Handle_Bace<Texture2D_Unique>
		{
		public:
			//!�n���h�����폜����
			inline void Delete(bool LogOutFlag = false) { DeleteGraph(GetHandle(), LogOutFlag); }
			//!���̃I�u�W�F�N�g�𖳌������A���܂Ŏg���Ă����n���h����Ԃ�
			//!�����폜�������������
			inline int release() { return ReleaseRun(); }
	
			//�����pstatic�֐�
	
			// �O���t�B�b�N�n���h���쐬�֌W�֐�
	
			//! �w��T�C�Y�̃O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return DxLib::MakeGraph(SizeX, SizeY, NotUse3DFlag); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLIBEX_NOEXCEPT { return DxLib::MakeScreen(SizeX, SizeY, UseAlphaChannel); }
			//! �w��̃O���t�B�b�N�n���h���̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique DerivationGraph(int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle)DXLIBEX_NOEXCEPT { return DxLib::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle); }
	
			// �摜����O���t�B�b�N�n���h�����쐬����֐�
	
			//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLIBEX_NOEXCEPT { return DxLib::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode); }
			//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return DxLib::LoadGraph(FileName, NotUse3DFlag); }
			//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return DxLib::LoadReverseGraph(FileName, NotUse3DFlag); }
			//! �摜�t�@�C������u�����h�p�O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique LoadBlendGraph(const TCHAR *FileName)DXLIBEX_NOEXCEPT { return DxLib::LoadBlendGraph(FileName); }
	
			//! ��������̉摜�C���[�W����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
			//! ��������̉摜�C���[�W��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, Texture2D_Unique& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle.GetHandle(), AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
	
			//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateDXGraph(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLIBEX_NOEXCEPT { return DxLib::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }
	
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const Texture2D_Unique& GrHandle = Texture2D_Unique())DXLIBEX_NOEXCEPT { return DxLib::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle.GetHandle()); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����č쐬����
			static inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, Texture2D_Unique& GrHandle, const void *AlphaImage = nullptr)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle.GetHandle(), AlphaImage); }
	#ifndef DX_NON_SOFTIMAGE
			//extern	int			CreateBlendGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����u�����h�p�摜�O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�u�����h�p�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY);																				// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			ReCreateGraphFromSoftImage(int SIHandle, int GrHandle);																										// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			ReCreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle);																	// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			CreateDivGraphFromSoftImage(int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf);												// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
	#endif // DX_NON_SOFTIMAGE
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraphFromBaseImage(const BASEIMAGE *BaseImage)DXLIBEX_NOEXCEPT { return DxLib::CreateGraphFromBaseImage(BaseImage); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����
			static inline Texture2D_Unique CreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLIBEX_NOEXCEPT { return DxLib::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromBaseImage(const BASEIMAGE *BaseImage, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromBaseImage(BaseImage, GrHandle.GetHandle()); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle.GetHandle()); }
			//! �摜�t�@�C������O���t�B�b�N�n���h���։摜�f�[�^��]������
			static inline int ReloadGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReloadGraph(FileName, GrHandle.GetHandle(), ReverseFlag); }
			//! ReloadGraph �̉摜���]�����ǉ���
			static inline int ReloadReverseGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReloadReverseGraph(FileName, GrHandle.GetHandle()); }
	
	
			//�����o�֐�
	
			//! �w��̃O���t�B�b�N�n���h���̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )
			inline const unsigned int* GetFullColorImage()const DXLIBEX_NOEXCEPT { return DxLib::GetFullColorImage(GetHandle()); }
			//! �O���t�B�b�N�������̈�̃��b�N
			inline int GraphLock(int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = nullptr, bool WriteOnly = false)DXLIBEX_NOEXCEPT { return DxLib::GraphLock(GetHandle(), PitchBuf, DataPointBuf, ColorDataPP, WriteOnly); }
			//! �O���t�B�b�N�������̈�̃��b�N����
			inline int GraphUnLock()DXLIBEX_NOEXCEPT { return DxLib::GraphUnLock(GetHandle()); }
			//! �O���t�B�b�N�n���h����p�̂y�o�b�t�@�������ǂ�����ݒ肷��( GrHandle:�ΏۂƂȂ�O���t�B�b�N�n���h��( �`��ΏۂƂ��Ďg�p�\�ȃO���t�B�b�N�n���h���̂ݗL�� )  UseFlag:��p�̂y�o�b�t�@�������ǂ���( TRUE:����( �f�t�H���g )  FALSE:�����Ȃ� )  BitDepth:�r�b�g�[�x( 16 or 24 or 32 ) )
			inline int SetUseGraphZBuffer(int UseFlag, int BitDepth = -1)DXLIBEX_NOEXCEPT { return DxLib::SetUseGraphZBuffer(GetHandle(), UseFlag, BitDepth); }
			//! �O���t�B�b�N�n���h���̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�n���h���̂y�o�b�t�@�ɃR�s�[����( DestGrHandle �� SrcGrHandle ���y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N�n���h���ŁA�T�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�������Ƃ����� )
			inline int CopyGraphZBufferImage(Texture2D_Unique& ToGrHandle)const DXLIBEX_NOEXCEPT { return DxLib::CopyGraphZBufferImage(GetHandle(), ToGrHandle.GetHandle()); }
			//! �O���t�B�b�N�X�f�o�C�X�̃f�o�C�X���X�g�������Ɏw��̃O���t�B�b�N�n���h�����폜���邩�ǂ�����ݒ肷��( TRUE:�f�o�C�X���X�g���ɍ폜����  FALSE:�f�o�C�X���X�g���������Ă��폜���Ȃ� )
			inline int SetDeviceLostDeleteGraphFlag(bool DeleteFlag)DXLIBEX_NOEXCEPT { return DxLib::SetDeviceLostDeleteGraphFlag(GetHandle(), DeleteFlag); }
			//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
			inline int GetGraphSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return DxLib::GetGraphSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline std::pair<int, int> GetGraphSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			inline int GetGraphTextureSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return DxLib::GetGraphTextureSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline std::pair<int, int> GetGraphTextureSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphTextureSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N�n���h�������e�N�X�`���̃~�b�v�}�b�v���x�������擾����
			inline int GetGraphMipmapCount()const DXLIBEX_NOEXCEPT { return DxLib::GetGraphMipmapCount(GetHandle()); }
			//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline int GetGraphFilePath(TCHAR FilePathBuffer[])const DXLIBEX_NOEXCEPT { return DxLib::GetGraphFilePath(GetHandle(), FilePathBuffer); }
			//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline std::basic_string<TCHAR> GetGraphFilePath()const DXLIBEX_NOEXCEPT { TCHAR FilePathBuffer[1024]; if (GetGraphFilePath(FilePathBuffer) == -1) { return std::basic_string<TCHAR>(); } return FilePathBuffer; }
	
			//! �摜�̓��{�`��
			inline int DrawGraph(int x, int y, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawGraph(x, y, GetHandle(), TransFlag); }
			//! �摜�̊g��`��
			inline int DrawExtendGraph(int x1, int y1, int x2, int y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawExtendGraph(x1, y1, x2, y2, GetHandle(), TransFlag); }
			//! �摜�̉�]�`��
			inline int DrawRotaGraph(int x, int y, double ExRate, double Angle, bool TransFlag, bool TurnFlag = false)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraph(x, y, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )
			inline int DrawRotaGraph2(int x, int y, int cx, int cy, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = false)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraph2(x, y, cx, cy, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
			inline int DrawRotaGraph3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraph3(x, y, cx, cy, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��
			inline int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawModiGraph(x1, y1, x2, y2, x3, y3, x4, y4, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��
			inline int DrawTurnGraph(int x, int y, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawTurnGraph(x, y, GetHandle(), TransFlag); }
			//! �摜�̊g�卶�E���]�`��
			inline int DrawExtendTurnGraph(int x1, int y1, int x2, int y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawExtendGraph(x2, y1, x1, y2, GetHandle(), TransFlag); }
	
			//! �摜�̕`��( ���W�w�肪 float �� )
			inline int DrawGraphF(float xf, float yf, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawGraphF(xf, yf, GetHandle(), TransFlag); }
			//! �摜�̊g��`��( ���W�w�肪 float �� )
			inline int DrawExtendGraphF(float x1f, float y1f, float x2f, float y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawExtendGraphF(x1f, y1f, x2f, y2, GetHandle(), TransFlag); }
			//! �摜�̉�]�`��( ���W�w�肪 float �� )
			inline int DrawRotaGraphF(float xf, float yf, double ExRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraphF(xf, yf, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph2F(float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraph2F(xf, yf, cxf, cyf, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph3F(float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return DxLib::DrawRotaGraph3F(xf, yf, cxf, cyf, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
			inline int DrawModiGraphF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawModiGraphF(x1, y1, x2, y2, x3, y3, x4, y4, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��( ���W�w�肪 float �� )
			inline int DrawTurnGraphF(float xf, float yf, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawTurnGraphF(xf, yf, GetHandle(), TransFlag); }
			//! �摜�̊g�卶�E���]�`��( ���W�w�肪 float �� )
			inline int DrawExtendTurnGraphF(float x1f, float y1f, float x2f, float y2f, bool TransFlag)const DXLIBEX_NOEXCEPT { return DxLib::DrawExtendGraphF(x2f, y1f, x1f, y2f, GetHandle(), TransFlag); }
	
		private:
			typedef Unique_Handle_Bace<Texture2D_Unique> Parent_T;
		public:
			Texture2D_Unique() : Unique_Handle_Bace() {}
			//!���L���̏��n
			Texture2D_Unique(Texture2D_Unique&& other) : Unique_Handle_Bace(std::move(other)) {}
			//! ���L���̏��n
			Texture2D_Unique& operator=(Texture2D_Unique&& other) { Parent_T::operator=(std::move(other)); return *this; }
		private:
			Texture2D_Unique(int param_handle) : Unique_Handle_Bace(param_handle) {}//�ԈႦ�đ��̎�ނ̃n���h���������Ȃ��悤��private�ɂ��Ă���
		};
	
		//! �摜�n���h���N���X
		//! �N���Q�Ƃ��Ȃ��Ȃ�����n���h���������폜����
		class Texture2D
		{
		public:
			//!�T�E���h�n���h�����폜����
			inline void Delete(bool LogOutFlag = false) { p_handle->Delete(LogOutFlag); }
			//!���̃I�u�W�F�N�g�𖳌�������
			//!�Ō�̈�������ꍇ�n���h���͎����I�ɍ폜�����
			inline void release_this() { p_handle.reset(); }
			//!���̃I�u�W�F�N�g����ѓ����h�����̃I�u�W�F�N�g�𖳌������A���܂Ŏg���Ă����n���h����Ԃ�
			//!�����폜�������������
			inline int release_all() { return p_handle->release(); }
	
	
			//�����pstatic�֐�
	
			// �O���t�B�b�N�n���h���쐬�֌W�֐�
	
			//! �w��T�C�Y�̃O���t�B�b�N�n���h�����쐬����
			static inline Texture2D MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::MakeGraph(SizeX, SizeY, NotUse3DFlag); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h�����쐬����
			static inline Texture2D MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::MakeScreen(SizeX, SizeY, UseAlphaChannel); }
			//! �w��̃O���t�B�b�N�n���h���̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N�n���h�����쐬����
			static inline Texture2D DerivationGraph(int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle); }
	
			// �摜����O���t�B�b�N�n���h�����쐬����֐�
	
			//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode); }
			//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadGraph(FileName, NotUse3DFlag); }
			//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N�n���h�����쐬����
			static inline Texture2D LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadReverseGraph(FileName, NotUse3DFlag); }
			//! �摜�t�@�C������u�����h�p�O���t�B�b�N�n���h�����쐬����
			static inline Texture2D LoadBlendGraph(const TCHAR *FileName)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadBlendGraph(FileName); }
	
			//! ��������̉摜�C���[�W����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
			//! ��������̉摜�C���[�W��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, Texture2D_Unique& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
	
			//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateDXGraph(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle, TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle, TextureFlag, ReverseFlag); }
	
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const Texture2D_Unique& GrHandle = Texture2D_Unique())DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����č쐬����
			static inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, Texture2D_Unique& GrHandle, const void *AlphaImage = nullptr)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle, AlphaImage); }
	#ifndef DX_NON_SOFTIMAGE
			//extern	int			CreateBlendGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����u�����h�p�摜�O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�u�����h�p�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY);																				// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			ReCreateGraphFromSoftImage(int SIHandle, int GrHandle);																										// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			ReCreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle);																	// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			CreateDivGraphFromSoftImage(int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf);												// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
	#endif // DX_NON_SOFTIMAGE
			//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraphFromBaseImage(const BASEIMAGE *BaseImage)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromBaseImage(BaseImage); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����
			static inline Texture2D CreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromBaseImage(const BASEIMAGE *BaseImage, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromBaseImage(BaseImage, GrHandle); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle); }
			//! �摜�t�@�C������O���t�B�b�N�n���h���։摜�f�[�^��]������
			static inline int ReloadGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReloadGraph(FileName, GrHandle, ReverseFlag); }
			//! ReloadGraph �̉摜���]�����ǉ���
			static inline int ReloadReverseGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReloadReverseGraph(FileName, GrHandle); }
	
	
			//�����o�֐�
	
			//! �w��̃O���t�B�b�N�n���h���̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )
			inline const unsigned int* GetFullColorImage()const DXLIBEX_NOEXCEPT { return p_handle->GetFullColorImage(); }
			//! �O���t�B�b�N�������̈�̃��b�N
			inline int GraphLock(int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = nullptr, bool WriteOnly = false)DXLIBEX_NOEXCEPT { return p_handle->GraphLock(PitchBuf, DataPointBuf, ColorDataPP, WriteOnly); }
			//! �O���t�B�b�N�������̈�̃��b�N����
			inline int GraphUnLock()DXLIBEX_NOEXCEPT { return p_handle->GraphUnLock(); }
			//! �O���t�B�b�N�n���h����p�̂y�o�b�t�@�������ǂ�����ݒ肷��( GrHandle:�ΏۂƂȂ�O���t�B�b�N�n���h��( �`��ΏۂƂ��Ďg�p�\�ȃO���t�B�b�N�n���h���̂ݗL�� )  UseFlag:��p�̂y�o�b�t�@�������ǂ���( TRUE:����( �f�t�H���g )  FALSE:�����Ȃ� )  BitDepth:�r�b�g�[�x( 16 or 24 or 32 ) )
			inline int SetUseGraphZBuffer(int UseFlag, int BitDepth = -1)DXLIBEX_NOEXCEPT { return p_handle->SetUseGraphZBuffer(UseFlag, BitDepth); }
			//! �O���t�B�b�N�n���h���̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�n���h���̂y�o�b�t�@�ɃR�s�[����( DestGrHandle �� SrcGrHandle ���y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N�n���h���ŁA�T�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�������Ƃ����� )
			inline int CopyGraphZBufferImage(Texture2D_Unique& ToGrHandle)const DXLIBEX_NOEXCEPT { return p_handle->CopyGraphZBufferImage(ToGrHandle); }
			//! �O���t�B�b�N�X�f�o�C�X�̃f�o�C�X���X�g�������Ɏw��̃O���t�B�b�N�n���h�����폜���邩�ǂ�����ݒ肷��( TRUE:�f�o�C�X���X�g���ɍ폜����  FALSE:�f�o�C�X���X�g���������Ă��폜���Ȃ� )
			inline int SetDeviceLostDeleteGraphFlag(bool DeleteFlag)DXLIBEX_NOEXCEPT { return p_handle->SetDeviceLostDeleteGraphFlag(DeleteFlag); }
			//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
			inline int GetGraphSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return p_handle->GetGraphSize(SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline std::pair<int, int> GetGraphSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			inline int GetGraphTextureSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return p_handle->GetGraphTextureSize(SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline std::pair<int, int> GetGraphTextureSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphTextureSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N�n���h�������e�N�X�`���̃~�b�v�}�b�v���x�������擾����
			inline int GetGraphMipmapCount()const DXLIBEX_NOEXCEPT { return p_handle->GetGraphMipmapCount(); }
			//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline int GetGraphFilePath(TCHAR FilePathBuffer[])const DXLIBEX_NOEXCEPT { return p_handle->GetGraphFilePath(FilePathBuffer); }
			//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline std::basic_string<TCHAR> GetGraphFilePath()const DXLIBEX_NOEXCEPT { TCHAR FilePathBuffer[1024]; if (GetGraphFilePath(FilePathBuffer) == -1) { return std::basic_string<TCHAR>(); } return FilePathBuffer; }
	
			//! �摜�̓��{�`��
			inline int DrawGraph(int x, int y, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawGraph(x, y, TransFlag); }
			//! �摜�̊g��`��
			inline int DrawExtendGraph(int x1, int y1, int x2, int y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawExtendGraph(x1, y1, x2, y2, TransFlag); }
			//! �摜�̉�]�`��
			inline int DrawRotaGraph(int x, int y, double ExRate, double Angle, bool TransFlag, bool TurnFlag = false)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraph(x, y, ExRate, Angle, TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )
			inline int DrawRotaGraph2(int x, int y, int cx, int cy, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = false)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraph2(x, y, cx, cy, ExtRate, Angle, TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
			inline int DrawRotaGraph3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraph3(x, y, cx, cy, ExtRateX, ExtRateY, Angle, TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��
			inline int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawModiGraph(x1, y1, x2, y2, x3, y3, x4, y4, TransFlag); }
			//! �摜�̍��E���]�`��
			inline int DrawTurnGraph(int x, int y, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawTurnGraph(x, y, TransFlag); }
			//! �摜�̊g�卶�E���]�`��
			inline int DrawExtendTurnGraph(int x1, int y1, int x2, int y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawExtendGraph(x2, y1, x1, y2, TransFlag); }
	
			//! �摜�̕`��( ���W�w�肪 float �� )
			inline int DrawGraphF(float xf, float yf, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawGraphF(xf, yf, TransFlag); }
			//! �摜�̊g��`��( ���W�w�肪 float �� )
			inline int DrawExtendGraphF(float x1f, float y1f, float x2f, float y2, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawExtendGraphF(x1f, y1f, x2f, y2, TransFlag); }
			//! �摜�̉�]�`��( ���W�w�肪 float �� )
			inline int DrawRotaGraphF(float xf, float yf, double ExRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraphF(xf, yf, ExRate, Angle, TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph2F(float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraph2F(xf, yf, cxf, cyf, ExtRate, Angle, TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph3F(float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const DXLIBEX_NOEXCEPT { return p_handle->DrawRotaGraph3F(xf, yf, cxf, cyf, ExtRateX, ExtRateY, Angle, TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
			inline int DrawModiGraphF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawModiGraphF(x1, y1, x2, y2, x3, y3, x4, y4, TransFlag); }
			//! �摜�̍��E���]�`��( ���W�w�肪 float �� )
			inline int DrawTurnGraphF(float xf, float yf, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawTurnGraphF(xf, yf, TransFlag); }
			//! �摜�̊g�卶�E���]�`��( ���W�w�肪 float �� )
			inline int DrawExtendTurnGraphF(float x1f, float y1f, float x2f, float y2f, bool TransFlag)const DXLIBEX_NOEXCEPT { return p_handle->DrawExtendGraphF(x2f, y1f, x1f, y2f, TransFlag); }
	
			//�R���X�g���N�^
	
			inline Texture2D(Texture2D_Unique&& handle) : p_handle(std::make_shared<Texture2D_Unique>(std::move(handle))) {}
			Texture2D() {}
		private:
			std::shared_ptr<Texture2D_Unique> p_handle;
		};
	
		//�����p�֐�
	
		// �O���t�B�b�N�n���h���쐬�֌W�֐�
	
		//! �w��T�C�Y�̃O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::MakeGraph(SizeX, SizeY, NotUse3DFlag); }
		//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::MakeScreen(SizeX, SizeY, UseAlphaChannel); }
		//! �w��̃O���t�B�b�N�n���h���̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique DerivationGraph(int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle); }
	
		// �摜����O���t�B�b�N�n���h�����쐬����֐�
	
		//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode); }
		//! �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadReverseGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C������u�����h�p�O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique LoadBlendGraph(const TCHAR *FileName)DXLIBEX_NOEXCEPT { return Texture2D_Unique::LoadBlendGraph(FileName); }
	
		//! ��������̉摜�C���[�W����O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
		//! ��������̉摜�C���[�W��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
		inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, Texture2D_Unique& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
	
		//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateDXGraph(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, Texture2D_Unique& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle, TextureFlag, ReverseFlag); }
	
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const Texture2D_Unique& GrHandle = Texture2D_Unique())DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle); }
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����č쐬����
		inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, Texture2D_Unique& GrHandle, const void *AlphaImage = nullptr)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle, AlphaImage); }
	#ifndef DX_NON_SOFTIMAGE
	#endif // DX_NON_SOFTIMAGE
		//! ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraphFromBaseImage(const BASEIMAGE *BaseImage)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromBaseImage(BaseImage); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����
		inline Texture2D_Unique CreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLIBEX_NOEXCEPT { return Texture2D_Unique::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromBaseImage(const BASEIMAGE *BaseImage, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromBaseImage(BaseImage, GrHandle); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle); }
		//! �摜�t�@�C������O���t�B�b�N�n���h���։摜�f�[�^��]������
		inline int ReloadGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReloadGraph(FileName, GrHandle, ReverseFlag); }
		//! ReloadGraph �̉摜���]�����ǉ���
		inline int ReloadReverseGraph(const TCHAR *FileName, Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D_Unique::ReloadReverseGraph(FileName, GrHandle); }
	
	
		//�g�p�p�֐�
	
		//! �w��̃O���t�B�b�N�n���h���̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )
		inline const unsigned int* GetFullColorImage(const Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return GrHandle.GetFullColorImage(); }
		//! �O���t�B�b�N�������̈�̃��b�N
		inline int GraphLock(Texture2D_Unique& GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = nullptr, bool WriteOnly = false)DXLIBEX_NOEXCEPT { return GrHandle.GraphLock(PitchBuf, DataPointBuf, ColorDataPP, WriteOnly); }
		//! �O���t�B�b�N�������̈�̃��b�N����
		inline int GraphUnLock(Texture2D_Unique& GrHandle)DXLIBEX_NOEXCEPT { return GrHandle.GraphUnLock(); }
		//! �O���t�B�b�N�n���h����p�̂y�o�b�t�@�������ǂ�����ݒ肷��( GrHandle:�ΏۂƂȂ�O���t�B�b�N�n���h��( �`��ΏۂƂ��Ďg�p�\�ȃO���t�B�b�N�n���h���̂ݗL�� )  UseFlag:��p�̂y�o�b�t�@�������ǂ���( TRUE:����( �f�t�H���g )  FALSE:�����Ȃ� )  BitDepth:�r�b�g�[�x( 16 or 24 or 32 ) )
		inline int SetUseGraphZBuffer(Texture2D_Unique& GrHandle, int UseFlag, int BitDepth = -1)DXLIBEX_NOEXCEPT { return GrHandle.SetUseGraphZBuffer(UseFlag, BitDepth); }
		//! �O���t�B�b�N�n���h���̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�n���h���̂y�o�b�t�@�ɃR�s�[����( DestGrHandle �� SrcGrHandle ���y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N�n���h���ŁA�T�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�������Ƃ����� )
		inline int CopyGraphZBufferImage(const Texture2D_Unique& GrHandle, Texture2D_Unique& ToGrHandle)DXLIBEX_NOEXCEPT { return GrHandle.CopyGraphZBufferImage(ToGrHandle); }
		//! �O���t�B�b�N�X�f�o�C�X�̃f�o�C�X���X�g�������Ɏw��̃O���t�B�b�N�n���h�����폜���邩�ǂ�����ݒ肷��( TRUE:�f�o�C�X���X�g���ɍ폜����  FALSE:�f�o�C�X���X�g���������Ă��폜���Ȃ� )
		inline int SetDeviceLostDeleteGraphFlag(Texture2D_Unique& GrHandle, bool DeleteFlag)DXLIBEX_NOEXCEPT { return GrHandle.SetDeviceLostDeleteGraphFlag(DeleteFlag); }
		//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
		inline int GetGraphSize(const Texture2D_Unique& GrHandle, int *SizeXBuf, int *SizeYBuf)DXLIBEX_NOEXCEPT { return GrHandle.GetGraphSize(SizeXBuf, SizeYBuf); }
		//! �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
		//!@return .first:SizeX .second:SizeY
		inline std::pair<int, int> GetGraphSize(const Texture2D_Unique& GrHandle) DXLIBEX_NOEXCEPT { return GrHandle.GetGraphSize(); }
		//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
		inline int GetGraphTextureSize(const Texture2D_Unique& GrHandle, int *SizeXBuf, int *SizeYBuf)DXLIBEX_NOEXCEPT { return GrHandle.GetGraphTextureSize(SizeXBuf, SizeYBuf); }
		//! �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
		//!@return .first:SizeX .second:SizeY
		inline std::pair<int, int> GetGraphTextureSize(const Texture2D_Unique& GrHandle) DXLIBEX_NOEXCEPT { return GrHandle.GetGraphTextureSize(); }
		//! �O���t�B�b�N�n���h�������e�N�X�`���̃~�b�v�}�b�v���x�������擾����
		inline int GetGraphMipmapCount(const Texture2D_Unique& GrHandle) DXLIBEX_NOEXCEPT { return GrHandle.GetGraphMipmapCount(); }
		//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
		inline int GetGraphFilePath(const Texture2D_Unique& GrHandle, TCHAR FilePathBuffer[])DXLIBEX_NOEXCEPT { return GrHandle.GetGraphFilePath(FilePathBuffer); }
		//! �O���t�B�b�N�n���h�����摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
		inline std::basic_string<TCHAR> GetGraphFilePath(const Texture2D_Unique& GrHandle) DXLIBEX_NOEXCEPT { return GrHandle.GetGraphFilePath(); }
	
		//! �摜�̓��{�`��
		inline int DrawGraph(int x, int y, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawGraph(x, y, TransFlag); }
		//! �摜�̊g��`��
		inline int DrawExtendGraph(int x1, int y1, int x2, int y2, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawExtendGraph(x1, y1, x2, y2, TransFlag); }
		//! �摜�̉�]�`��
		inline int DrawRotaGraph(int x, int y, double ExRate, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = false)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraph(x, y, ExRate, Angle, TransFlag, TurnFlag); }
		//! �摜�̉�]�`��Q( ��]���S�w��t�� )
		inline int DrawRotaGraph2(int x, int y, int cx, int cy, double ExtRate, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = false)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraph2(x, y, cx, cy, ExtRate, Angle, TransFlag, TurnFlag); }
		//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
		inline int DrawRotaGraph3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = FALSE)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraph3(x, y, cx, cy, ExtRateX, ExtRateY, Angle, TransFlag, TurnFlag); }
		//! �摜�̎��R�ό`�`��
		inline int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawModiGraph(x1, y1, x2, y2, x3, y3, x4, y4, TransFlag); }
		//! �摜�̍��E���]�`��
		inline int DrawTurnGraph(int x, int y, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawTurnGraph(x, y, TransFlag); }
		//! �摜�̊g�卶�E���]�`��
		inline int DrawExtendTurnGraph(int x1, int y1, int x2, int y2, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawExtendGraph(x2, y1, x1, y2, TransFlag); }
	
		//! �摜�̕`��( ���W�w�肪 float �� )
		inline int DrawGraphF(float xf, float yf, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawGraphF(xf, yf, TransFlag); }
		//! �摜�̊g��`��( ���W�w�肪 float �� )
		inline int DrawExtendGraphF(float x1f, float y1f, float x2f, float y2, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawExtendGraphF(x1f, y1f, x2f, y2, TransFlag); }
		//! �摜�̉�]�`��( ���W�w�肪 float �� )
		inline int DrawRotaGraphF(float xf, float yf, double ExRate, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = FALSE)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraphF(xf, yf, ExRate, Angle, TransFlag, TurnFlag); }
		//! �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
		inline int DrawRotaGraph2F(float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = FALSE)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraph2F(xf, yf, cxf, cyf, ExtRate, Angle, TransFlag, TurnFlag); }
		//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
		inline int DrawRotaGraph3F(float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, const Texture2D_Unique& GrHandle, bool TransFlag, bool TurnFlag = FALSE)DXLIBEX_NOEXCEPT { return GrHandle.DrawRotaGraph3F(xf, yf, cxf, cyf, ExtRateX, ExtRateY, Angle, TransFlag, TurnFlag); }
		//! �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
		inline int DrawModiGraphF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawModiGraphF(x1, y1, x2, y2, x3, y3, x4, y4, TransFlag); }
		//! �摜�̍��E���]�`��( ���W�w�肪 float �� )
		inline int DrawTurnGraphF(float xf, float yf, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawTurnGraphF(xf, yf, TransFlag); }
		//! �摜�̊g�卶�E���]�`��( ���W�w�肪 float �� )
		inline int DrawExtendTurnGraphF(float x1f, float y1f, float x2f, float y2f, const Texture2D_Unique& GrHandle, bool TransFlag)DXLIBEX_NOEXCEPT { return GrHandle.DrawExtendGraphF(x2f, y1f, x1f, y2f, TransFlag); }
	
	}
	namespace DxLibEx_Classes {
		using Graph2D::Texture2D_Unique;
		using Graph2D::Texture2D;
	}
}

#endif
