#ifndef DX_LIB_EX_GRAPH_2D_H_201510241561
#define DX_LIB_EX_GRAPH_2D_H_201510241561

#include "DxLib.h"
#include <type_traits>
#include <utility>
#include <memory>
#include <string>
#include "DxLibEx_Helper.h"
#include "DxLibEx_Defines.h"
#include "DxLibEx_basic_types.hpp"

//----------2D�O���t�B�b�N----------//

namespace dxle
{
	//!\~japanese DxLibEx�̌��J�N���X���S�ē�����namespace�ł�
	namespace DxLibEx_Classes {}
	//! 2D�O���t�B�b�N
	namespace Graph2D
	{

		//!\~japanese �摜�N���X(�摜�n���h���N���X�ł͂Ȃ�)
		//!\~english  A image class (NOT a image handle class)
		class Texture2D : public impl::Unique_HandledObject_Bace<Texture2D>
		{
		public:
			//!\~japanese �摜���폜����
			//!\~english  Delete this image
			inline void Delete(bool LogOutFlag = false) { DeleteGraph(GetHandle(), LogOutFlag); }

			//�����pstatic�֐�
	
			// �O���t�B�b�N�쐬�֌W�֐�
	
			//!\~japanese �w��T�C�Y�̃O���t�B�b�N���쐬����
			//!\~english  Create image with sizes
			static inline Texture2D MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::MakeGraph(SizeX, SizeY, NotUse3DFlag), NotUse3DFlag); }
			//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
			static inline Texture2D DerivationGraph(int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle), false); }
	
			// �摜����O���t�B�b�N���쐬����֐�
	
			//! �摜�t�@�C������O���t�B�b�N���쐬����
			static inline Texture2D LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode), false); }
			//! �摜�t�@�C������O���t�B�b�N���쐬����
			static inline Texture2D LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::LoadGraph(FileName, NotUse3DFlag), NotUse3DFlag); }
			//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N���쐬����
			static inline Texture2D LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::LoadReverseGraph(FileName, NotUse3DFlag), NotUse3DFlag); }
			//! �摜�t�@�C������u�����h�p�O���t�B�b�N���쐬����
			static inline Texture2D LoadBlendGraph(const TCHAR *FileName)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::LoadBlendGraph(FileName), false); }
	
			//! ��������̉摜�C���[�W����O���t�B�b�N���쐬����
			static inline Texture2D CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag), false); }
			//! ��������̉摜�C���[�W��������̃O���t�B�b�N�Ƀf�[�^��]������
			static inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, Texture2D& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle.GetHandle(), AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
	
			//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N���쐬����
			static inline Texture2D CreateDXGraph(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag), false); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			static inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag), false); }
			//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			static inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag), false); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, Texture2D& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
			static inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, Texture2D& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }
	
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
			static inline Texture2D CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const Texture2D& GrHandle = Texture2D())DXLIBEX_NOEXCEPT { return Texture2D(DxLib::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle.GetHandle()), false); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
			static inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, Texture2D& GrHandle, const void *AlphaImage = nullptr)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle.GetHandle(), AlphaImage); }
	#ifndef DX_NON_SOFTIMAGE
			//extern	int			CreateBlendGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����u�����h�p�摜�O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�u�����h�p�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromSoftImage(int SIHandle);																													// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY);																				// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			ReCreateGraphFromSoftImage(int SIHandle, int GrHandle);																										// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			ReCreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle);																	// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			CreateDivGraphFromSoftImage(int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf);												// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
	#endif // DX_NON_SOFTIMAGE
			//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			static inline Texture2D CreateGraphFromBaseImage(const BASEIMAGE *BaseImage)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateGraphFromBaseImage(BaseImage), false); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
			static inline Texture2D CreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLIBEX_NOEXCEPT{ return Texture2D(DxLib::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY), false); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromBaseImage(const BASEIMAGE *BaseImage, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromBaseImage(BaseImage, GrHandle.GetHandle()); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle.GetHandle()); }
			//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
			static inline int ReloadGraph(const TCHAR *FileName, Texture2D& GrHandle, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return DxLib::ReloadGraph(FileName, GrHandle.GetHandle(), ReverseFlag); }
			//! ReloadGraph �̉摜���]�����ǉ���
			static inline int ReloadReverseGraph(const TCHAR *FileName, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return DxLib::ReloadReverseGraph(FileName, GrHandle.GetHandle()); }
	
	
			//�����o�֐�
	
			////! �w��̃O���t�B�b�N�̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )
			//inline const unsigned int* GetFullColorImage()const DXLIBEX_NOEXCEPT { return DxLib::GetFullColorImage(GetHandle()); }

			//! �O���t�B�b�N�������̈�̃��b�N
			inline int GraphLock(int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = nullptr, bool WriteOnly = false)DXLIBEX_NOEXCEPT { return DxLib::GraphLock(GetHandle(), PitchBuf, DataPointBuf, ColorDataPP, WriteOnly); }
			//! �O���t�B�b�N�������̈�̃��b�N����
			inline int GraphUnLock()DXLIBEX_NOEXCEPT { return DxLib::GraphUnLock(GetHandle()); }
			//! �O���t�B�b�N�X�f�o�C�X�̃f�o�C�X���X�g�������Ɏw��̃O���t�B�b�N���폜���邩�ǂ�����ݒ肷��( TRUE:�f�o�C�X���X�g���ɍ폜����  FALSE:�f�o�C�X���X�g���������Ă��폜���Ȃ� )
			inline int SetDeviceLostDeleteGraphFlag(bool DeleteFlag)DXLIBEX_NOEXCEPT { return DxLib::SetDeviceLostDeleteGraphFlag(GetHandle(), DeleteFlag); }
			//! �O���t�B�b�N�̃T�C�Y�𓾂�
			inline int GetGraphSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return DxLib::GetGraphSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline pointi GetGraphSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			inline int GetGraphTextureSize(int *SizeXBuf, int *SizeYBuf)const DXLIBEX_NOEXCEPT { return DxLib::GetGraphTextureSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			//!@return .first:SizeX .second:SizeY
			inline pointi GetGraphTextureSize()const DXLIBEX_NOEXCEPT { int x, y; GetGraphTextureSize(&x, &y); return std::make_pair(x, y); }
			//! �O���t�B�b�N�����e�N�X�`���̃~�b�v�}�b�v���x�������擾����
			inline int GetGraphMipmapCount()const DXLIBEX_NOEXCEPT { return DxLib::GetGraphMipmapCount(GetHandle()); }
			//! �O���t�B�b�N���摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline int GetGraphFilePath(TCHAR FilePathBuffer[])const DXLIBEX_NOEXCEPT { return DxLib::GetGraphFilePath(GetHandle(), FilePathBuffer); }
			//! �O���t�B�b�N���摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline std::basic_string<TCHAR> GetGraphFilePath()const DXLIBEX_NOEXCEPT { TCHAR FilePathBuffer[2048]; if (GetGraphFilePath(FilePathBuffer) == -1) { return std::basic_string<TCHAR>(); } return FilePathBuffer; }
	
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
			typedef Unique_HandledObject_Bace<Texture2D> Parent_T;
		public:
			Texture2D() : Unique_HandledObject_Bace() {}
			//! �R�s�[�֎~
			Texture2D(const Texture2D& other) = delete;
			//!���L���̏��n
			Texture2D(Texture2D&& other) : Unique_HandledObject_Bace(std::move(other)), NotUse3DFlag(std::move(other.NotUse3DFlag)) {}
			//! �R�s�[�֎~
			Texture2D& operator=(const Texture2D& other) = delete;
			//! ���L���̏��n
			Texture2D& operator=(Texture2D&& other) { Parent_T::operator=(std::move(other)); NotUse3DFlag = (std::move(other.NotUse3DFlag)); return *this; }

			virtual ~Texture2D()DXLIBEX_NOEXCEPT {}
		protected:
			Texture2D(int param_handle, bool param_NotUse3DFlag)DXLIBEX_NOEXCEPT : Unique_HandledObject_Bace(param_handle), NotUse3DFlag(param_NotUse3DFlag){}
			bool NotUse3DFlag;

			//Screen���̎q�N���X����GetHandle�ɃA�N�Z�X�ł���悤�ɂ����
			static int GetTexture2DHandle(const Texture2D& texture2d_obj) { return texture2d_obj.GetHandle(); }
		};
		//! �`��\�摜�N���X
		class Screen : public Texture2D
		{
		public:
			//!�摜�𕡐�����
			Screen clone()const;
			//!�摜�𕡐�����
			Texture2D cloneGr()const;

			//�����pstatic�֐�

			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
			static inline Screen MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLIBEX_NOEXCEPT { return Screen(DxLib::MakeScreen(SizeX, SizeY, UseAlphaChannel), UseAlphaChannel); }

			//�����o�֐�

			template<typename Func_T>
			void DrawnOn(Func_T&& draw_func) {
				auto old_draw_screen = DxLib::GetDrawScreen();
				this->SetDrawScreen();
				struct Finary_ { ~Finary_() {
					DxLib::SetDrawScreen(old_draw_screen);
				} }finally_;

				draw_func();
			}

			//! �O���t�B�b�N��p�̂y�o�b�t�@�������ǂ�����ݒ肷��
			//!@param UseFlag ��p�̂y�o�b�t�@�������ǂ���( true:����( �f�t�H���g )  false:�����Ȃ� )
			//!@param BitDepth �r�b�g�[�x( 16 or 24 or 32 ) )
			inline int SetUseGraphZBuffer(bool UseFlag, int BitDepth = -1)DXLIBEX_NOEXCEPT { return DxLib::SetUseGraphZBuffer(GetHandle(), UseFlag, BitDepth); }
			//! �O���t�B�b�N�̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�̂y�o�b�t�@�ɃR�s�[����
			//! *this�͂y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N
			//!@param ToGraph *this�ƃT�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�����A�y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N
			inline int CopyGraphZBufferImage(Screen& ToGraph)const DXLIBEX_NOEXCEPT { return DxLib::CopyGraphZBufferImage(GetHandle(), ToGraph.GetHandle()); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h������w��̈�̉摜����ʂ̃O���t�B�b�N�n���h���ɓ]������
			//!@param x1 �]�����̋�`�̍����W
			//!@param y1 �]�����̋�`�̏���W
			//!@param x2 �]�����̋�`�̉E���W
			//!@param y2 �]�����̋�`�̉����W
			//!@param DestX, DestY �]����̋�`�̍�����W
			//!@param DestGrHandle �]����̉摜
			inline int BltDrawValidGraph(int x1, int y1, int x2, int y2, int DestX, int DestY, Texture2D& DestGrHandle)const DXLIBEX_NOEXCEPT{ return DxLib::BltDrawValidGraph(GetHandle(), x1, y1, x2, y2, DestX, DestY, Texture2D::GetTexture2DHandle(DestGrHandle)); }

			//! �`����ʂ�ݒ肷��
			inline int SetDrawScreen()const DXLIBEX_NOEXCEPT { return DxLib::SetDrawScreen(GetHandle()); }

		public:
			Screen() : Texture2D() {}
			//! �R�s�[�֎~
			Screen(const Screen& other) = delete;
			//!���L���̏��n
			Screen(Screen&& other) : Texture2D(std::move(other)), UseAlphaChannel(std::move(other.UseAlphaChannel)) {}
			//! �R�s�[�֎~
			Screen& operator=(const Screen& other) = delete;
			//! ���L���̏��n
			Screen& operator=(Screen&& other) { Texture2D::operator=(std::move(other)); UseAlphaChannel = (std::move(other.UseAlphaChannel)); return *this; }

			virtual ~Screen()DXLIBEX_NOEXCEPT {}
		protected:
			Screen(int param_handle, bool param_UseAlphaChannel)DXLIBEX_NOEXCEPT : Texture2D(param_handle, false), UseAlphaChannel(param_UseAlphaChannel) {}
			bool UseAlphaChannel;
		};
		//! ����
		inline Screen Screen::clone()const
		{
			int graph_size_x, graph_size_y;
			GetGraphSize(&graph_size_x, &graph_size_y);

			Screen new_screen = Screen::MakeScreen(graph_size_x, graph_size_y, UseAlphaChannel);
			this->BltDrawValidGraph(0, 0, graph_size_x, graph_size_y, 0, 0, new_screen);
			return std::move(new_screen);
		}
		inline Texture2D Screen::cloneGr()const
		{
			int graph_size_x, graph_size_y;
			GetGraphSize(&graph_size_x, &graph_size_y);

			Texture2D new_graph = Texture2D::MakeGraph(graph_size_x, graph_size_y, NotUse3DFlag);
			this->BltDrawValidGraph(0, 0, graph_size_x, graph_size_y, 0, 0, new_graph);
			return std::move(new_graph);
		}
	
		//�����p�֐�
	
		// �O���t�B�b�N�쐬�֌W�֐�
	
		//! �w��T�C�Y�̃O���t�B�b�N���쐬����
		inline Texture2D MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::MakeGraph(SizeX, SizeY, NotUse3DFlag); }
		//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
		inline Screen MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLIBEX_NOEXCEPT { return Screen::MakeScreen(SizeX, SizeY, UseAlphaChannel); }
		//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
		inline Texture2D DerivationGraph(int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle)DXLIBEX_NOEXCEPT { return Texture2D::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle); }
	
		// �摜����O���t�B�b�N���쐬����֐�
	
		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline Texture2D LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLIBEX_NOEXCEPT { return Texture2D::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode); }
		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline Texture2D LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::LoadGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N���쐬����
		inline Texture2D LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::LoadReverseGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C������u�����h�p�O���t�B�b�N���쐬����
		inline Texture2D LoadBlendGraph(const TCHAR *FileName)DXLIBEX_NOEXCEPT { return Texture2D::LoadBlendGraph(FileName); }
	
		//! ��������̉摜�C���[�W����O���t�B�b�N���쐬����
		inline Texture2D CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
		//! ��������̉摜�C���[�W��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, Texture2D& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
	
		//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N���쐬����
		inline Texture2D CreateDXGraph(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLIBEX_NOEXCEPT { return Texture2D::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline Texture2D CreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, Texture2D& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const BASEIMAGE *RgbBaseImage, const BASEIMAGE *AlphaBaseImage, Texture2D& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle, TextureFlag, ReverseFlag); }
	
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
		inline Texture2D CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const Texture2D& GrHandle = Texture2D())DXLIBEX_NOEXCEPT { return Texture2D::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle); }
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
		inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, Texture2D& GrHandle, const void *AlphaImage = nullptr)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle, AlphaImage); }
	#ifndef DX_NON_SOFTIMAGE
	#endif // DX_NON_SOFTIMAGE
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline Texture2D CreateGraphFromBaseImage(const BASEIMAGE *BaseImage)DXLIBEX_NOEXCEPT { return Texture2D::CreateGraphFromBaseImage(BaseImage); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
		inline Texture2D CreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLIBEX_NOEXCEPT { return Texture2D::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromBaseImage(const BASEIMAGE *BaseImage, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraphFromBaseImage(BaseImage, GrHandle); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromRectBaseImage(const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle); }
		//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
		inline int ReloadGraph(const TCHAR *FileName, Texture2D& GrHandle, bool ReverseFlag = false)DXLIBEX_NOEXCEPT { return Texture2D::ReloadGraph(FileName, GrHandle, ReverseFlag); }
		//! ReloadGraph �̉摜���]�����ǉ���
		inline int ReloadReverseGraph(const TCHAR *FileName, Texture2D& GrHandle)DXLIBEX_NOEXCEPT { return Texture2D::ReloadReverseGraph(FileName, GrHandle); }
	
	}
	namespace DxLibEx_Classes {
		using Graph2D::Texture2D;
	}
}

#endif
