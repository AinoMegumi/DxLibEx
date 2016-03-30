/*=============================================================================
  Copyright (C) 2015-2016 DxLibEx project
  https://github.com/Nagarei/DxLibEx/

  Distributed under the Boost Software License, Version 1.0.
  (See http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef DXLE_INC_TEXTURE_TEXTURE2D_H_
#define DXLE_INC_TEXTURE_TEXTURE2D_H_

#include "dxlibex/config/no_min_max.h"
#include "DxLib.h"
#include <mutex>
#include <array>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstdint>
#include "dxlibex/config/defines.h"
#include "prototype2d.h"
#include "texture2d_handle_manager.hpp"
#include "dxlibex/basic_types.hpp"
#include "dxlibex/thread.h"


//----------2D�O���t�B�b�N----------//

namespace dxle
{
	//! 2D�O���t�B�b�N
	namespace graph2d
	{
		//!\~japanese DxLib�̕`���X�N���[�������̂��߂�mutex
		//!\~english  mutex for DxLib's draw screen
		class screen_mutex_c final
		{
		public:
#ifdef DX_THREAD_SAFE
			static std::recursive_mutex mtx;
#endif
		};

		/**
		@relates texture2d
		\~japanese	@brief	texture2d��screen_c��filter_bright_clip�����o�[�֐�������enum
		\~english	@brief	for filter_bright_clip(texture2d and screen_c )
		*/
		enum class bright_clip_mode : int {
			LESS,
			GREATER
		};

	//--------------------�N���X--------------------//
		
		class texture2d /*final*/
		{
		public:
			DXLE_CONSTEXPR texture2d()DXLE_NOEXCEPT_OR_NOTHROW{}
			//! �R�s�[�֎~
			texture2d(const texture2d& other) = delete;
			texture2d& operator=(const texture2d& other) = delete;
			//!���L���̏��n
			texture2d(texture2d&& other) DXLE_NOEXCEPT_OR_NOTHROW : handle_manager(std::move(other.handle_manager)){}
			texture2d& operator=(texture2d&& other) DXLE_NOEXCEPT_OR_NOTHROW { handle_manager = (std::move(other.handle_manager)); return *this; }

			//!\~japanese �摜���폜����
			//!\~english  Delete this image
			inline void delete_this(bool LogOutFlag = false) { DxLib::DeleteGraph(GetHandle(), LogOutFlag); }

			//! �O���t�B�b�N�̃T�C�Y�𓾂�
			inline sizei size()const DXLE_NOEXCEPT_OR_NOTHROW{ return GetGraphSize(); }

			//!�摜�𕡐�����
			virtual std::unique_ptr<texture2d> clone()const;

			virtual ~texture2d()DXLE_NOEXCEPT_OR_NOTHROW{}

		public:
			//�����p�R���X�g���N�^

			//!\~japanese �w��T�C�Y�̃O���t�B�b�N���쐬����
			//!\~english  Create an image with a specific size
			//inline texture2d(int SizeX, int SizeY, bool NotUse3DFlag = false): texture2d(DxLib::MakeGraph(SizeX, SizeY, NotUse3DFlag), NotUse3DFlag){}

			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image form an image file
			inline texture2d(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL) : texture2d(DxLib::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode), false){}
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image form an image file
			inline texture2d(const TCHAR *FileName, bool NotUse3DFlag = false) : texture2d(DxLib::LoadGraph(FileName, NotUse3DFlag), NotUse3DFlag){}


			//�����pstatic�֐�

			// �O���t�B�b�N�쐬�֌W�֐�

			//!\~japanese �w��T�C�Y�̃O���t�B�b�N���쐬����
			//!\~english  Create an image with a specific size
			static inline texture2d MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false){ return texture2d(DxLib::MakeGraph(SizeX, SizeY, NotUse3DFlag), NotUse3DFlag); }
			//!\~japanese �w��T�C�Y�̃O���t�B�b�N���쐬����
			//!\~english  Create an image with sizes
			static inline texture2d MakeGraph(const sizei& size, bool NotUse3DFlag = false){ return texture2d(DxLib::MakeGraph(size.width, size.height, NotUse3DFlag), NotUse3DFlag); }
			//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
			static inline texture2d DerivationGraph(int SrcX, int SrcY, int Width, int Height, const texture2d& SrcGraphHandle){ return texture2d(DxLib::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle.GetHandle()), false); }
			//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
			static inline texture2d DerivationGraph(const pointi& src, const sizei& size, const texture2d& SrcGraphHandle){ return texture2d(DxLib::DerivationGraph(src.x, src.y, size.width, size.height, SrcGraphHandle.GetHandle()), false); }

			// �摜����O���t�B�b�N���쐬����֐�

			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image from an image file
			static inline texture2d LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL){ return texture2d(DxLib::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode), false); }
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image from an image file
			static inline texture2d LoadBmpToGraph(const dxle::tstring& FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL){ return texture2d(DxLib::LoadBmpToGraph(FileName.c_str(), TextureFlag, ReverseFlag, SurfaceMode), false); }
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image from an image file
			static inline texture2d LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false){ return texture2d(DxLib::LoadGraph(FileName, NotUse3DFlag), NotUse3DFlag); }
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create an image from an image file
			static inline texture2d LoadGraph(const dxle::tstring& FileName, bool NotUse3DFlag = false){ return texture2d(DxLib::LoadGraph(FileName.c_str(), NotUse3DFlag), NotUse3DFlag); }
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create a reversed image from an image file
			static inline texture2d LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false){ return texture2d(DxLib::LoadReverseGraph(FileName, NotUse3DFlag), NotUse3DFlag); }
			//!\~japanese �摜�t�@�C������O���t�B�b�N���쐬����
			//!\~english  Create a reversed image from an image file
			static inline texture2d LoadReverseGraph(const dxle::tstring& FileName, bool NotUse3DFlag = false){ return texture2d(DxLib::LoadReverseGraph(FileName.c_str(), NotUse3DFlag), NotUse3DFlag); }


			//!\~japanese ��������̉摜�C���[�W����O���t�B�b�N���쐬����
			//!\~english  Create an graphic from an image stored in the computer memory
			static inline texture2d CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false){ return texture2d(DxLib::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag), false); }
			//!\~japanese ��������̉摜�C���[�W��������̃O���t�B�b�N�Ƀf�[�^��]������
			//!\~english  Recreate an graphic from an existing image stored in the computer memory
			static inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, texture2d& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false){ return DxLib::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle.GetHandle(), AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }

			//!\~japanese ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N���쐬����
			//!\~english  Determine the size of the basic image data and create a compatible graphics
			static inline texture2d CreateDXGraph(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, bool TextureFlag){ return texture2d(DxLib::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag), false); }
			//!\~japanese ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			//!\~english  Create a graphic from a basic image data
			static inline texture2d CreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false){ return texture2d(DxLib::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag), false); }
			//!\~japanese ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			//!\~english  Create a graphic from a basic image data
			static inline texture2d CreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false){ return texture2d(DxLib::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag), false); }
			//!\~japanese ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
			//!\~english  Recreate a graphic from an existing basic image data
			static inline int ReCreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, texture2d& GrHandle, bool TextureFlag = true, bool ReverseFlag = false){ return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }
			//!\~japanese ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
			//!\~english  Recreate a graphic from an existing basic image data
			static inline int ReCreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, texture2d& GrHandle, bool TextureFlag = true, bool ReverseFlag = false){ return DxLib::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle.GetHandle(), TextureFlag, ReverseFlag); }

			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
			//!\~english  Create a graphic from a bitmap image stored in the computer memory
			static inline texture2d CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const texture2d& GrHandle = texture2d()){ return texture2d(DxLib::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle.GetHandle()), false); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
			//!\~english  Create a graphic from a bitmap image stored in the computer memory
			static inline texture2d CreateGraph(const sizei& size, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const texture2d& GrHandle = texture2d()){ return texture2d(DxLib::CreateGraph(size.width, size.height, Pitch, RGBImage, AlphaImage, GrHandle.GetHandle()), false); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
			//!\~english  Recreate a graphic from a bitmap image stored in the computer memory
			static inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, texture2d& GrHandle, const void *AlphaImage = nullptr){ return DxLib::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle.GetHandle(), AlphaImage); }
			//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
			//!\~english  Recreate a graphic from a bitmap image stored in the computer memory
			static inline int ReCreateGraph(const sizei& size, int Pitch, const void *RGBImage, texture2d& GrHandle, const void *AlphaImage = nullptr){ return DxLib::ReCreateGraph(size.width, size.height, Pitch, RGBImage, GrHandle.GetHandle(), AlphaImage); }
#ifndef DX_NON_SOFTIMAGE
			//extern	int			CreateBlendGraphFromSoftImage(int SIHandle);																										// �\�t�g�E�G�A�ň����C���[�W����u�����h�p�摜�O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�u�����h�p�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromSoftImage(int SIHandle);																												// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			CreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY);																		// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
			//extern	int			ReCreateGraphFromSoftImage(int SIHandle, int GrHandle);																								// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			ReCreateGraphFromRectSoftImage(int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle);														// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
			//extern	int			CreateDivGraphFromSoftImage(int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf);									// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
#endif // DX_NON_SOFTIMAGE
			//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
			//!\~english  Create a graphic from a basic image data
			static inline texture2d CreateGraphFromBaseImage(const DxLib::BASEIMAGE *BaseImage){ return texture2d(DxLib::CreateGraphFromBaseImage(BaseImage), false); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
			//!\~english  Create a graphic from a degsinated area clipped from a basic image data 
			static inline texture2d CreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY){ return texture2d(DxLib::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY), false); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
			static inline texture2d CreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, const pointi& pos, const sizei& size){ return texture2d(DxLib::CreateGraphFromRectBaseImage(BaseImage, pos.x, pos.y, size.width, size.height), false); }
			//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromBaseImage(const DxLib::BASEIMAGE *BaseImage, texture2d& GrHandle){ return DxLib::ReCreateGraphFromBaseImage(BaseImage, GrHandle.GetHandle()); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, texture2d& GrHandle){ return DxLib::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle.GetHandle()); }
			//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
			static inline int ReCreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, const pointi& pos, const sizei& size, texture2d& GrHandle){ return DxLib::ReCreateGraphFromRectBaseImage(BaseImage, pos.x, pos.y, size.width, size.height, GrHandle.GetHandle()); }
			//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
			static inline int ReloadGraph(const TCHAR *FileName, texture2d& GrHandle, bool ReverseFlag = false){ return DxLib::ReloadGraph(FileName, GrHandle.GetHandle(), ReverseFlag); }
			//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
			static inline int ReloadGraph(const dxle::tstring& FileName, texture2d& GrHandle, bool ReverseFlag = false){ return DxLib::ReloadGraph(FileName.c_str(), GrHandle.GetHandle(), ReverseFlag); }
			//! ReloadGraph �̉摜���]�����ǉ���
			static inline int ReloadReverseGraph(const TCHAR *FileName, texture2d& GrHandle){ return DxLib::ReloadReverseGraph(FileName, GrHandle.GetHandle()); }
			//! ReloadGraph �̉摜���]�����ǉ���
			static inline int ReloadReverseGraph(const dxle::tstring& FileName, texture2d& GrHandle){ return DxLib::ReloadReverseGraph(FileName.c_str(), GrHandle.GetHandle()); }


				//�����o�֐�

			inline texture2d DerivationGraph(int SrcX, int SrcY, int Width, int Height)const  { return texture2d(DxLib::DerivationGraph(SrcX, SrcY, Width, Height, GetHandle()), false); }
			//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
			inline texture2d DerivationGraph(const pointi& src, const sizei& size)const  { return texture2d(DxLib::DerivationGraph(src.x, src.y, size.width, size.height, GetHandle()), false); }


			////! �w��̃O���t�B�b�N�̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )
			//inline const unsigned int* GetFullColorImage()const  { return DxLib::GetFullColorImage(GetHandle()); }

			//! �O���t�B�b�N�������̈�̃��b�N
			inline int GraphLock(int *PitchBuf, void **DataPointBuf, DxLib::COLORDATA **ColorDataPP = nullptr, bool WriteOnly = false){ return DxLib::GraphLock(GetHandle(), PitchBuf, DataPointBuf, ColorDataPP, WriteOnly); }
			//! �O���t�B�b�N�������̈�̃��b�N����
			inline int GraphUnLock(){ return DxLib::GraphUnLock(GetHandle()); }
			//! �O���t�B�b�N�X�f�o�C�X�̃f�o�C�X���X�g�������Ɏw��̃O���t�B�b�N���폜���邩�ǂ�����ݒ肷��( TRUE:�f�o�C�X���X�g���ɍ폜����  FALSE:�f�o�C�X���X�g���������Ă��폜���Ȃ� )
			inline int SetDeviceLostDeleteGraphFlag(bool DeleteFlag){ return DxLib::SetDeviceLostDeleteGraphFlag(GetHandle(), DeleteFlag); }
			//! �O���t�B�b�N�̃T�C�Y�𓾂�
			inline int GetGraphSize(int *SizeXBuf, int *SizeYBuf)const { return DxLib::GetGraphSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N�̃T�C�Y�𓾂�
			inline sizei GetGraphSize()const { int x, y; GetGraphSize(&x, &y); return{ x, y }; }
			//! �O���t�B�b�N������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			inline int GetGraphTextureSize(int *SizeXBuf, int *SizeYBuf)const { return DxLib::GetGraphTextureSize(GetHandle(), SizeXBuf, SizeYBuf); }
			//! �O���t�B�b�N������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
			inline sizei GetGraphTextureSize()const { int x, y; GetGraphTextureSize(&x, &y); return{ x, y }; }
			//! �O���t�B�b�N�����e�N�X�`���̃~�b�v�}�b�v���x�������擾����
			inline int GetGraphMipmapCount()const { return DxLib::GetGraphMipmapCount(GetHandle()); }
			//! �O���t�B�b�N���摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline int GetGraphFilePath(TCHAR FilePathBuffer[])const { return DxLib::GetGraphFilePath(GetHandle(), FilePathBuffer); }
			//! �O���t�B�b�N���摜�t�@�C������ǂݍ��܂�Ă����ꍇ�A���̉摜�̃t�@�C���p�X���擾����
			inline tstring GetGraphFilePath()const;

			//! �摜�̓��{�`��
			inline int DrawGraph(int x, int y, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawGraph(x, y, GetHandle(), TransFlag); }
			//! �摜�̓��{�`��
			inline int DrawGraph(const pointi& p, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawGraph(p.x, p.y, GetHandle(), TransFlag); }
			//! �摜�̊g��`��
			inline int DrawExtendGraph(int x1, int y1, int x2, int y2, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraph(x1, y1, x2, y2, GetHandle(), TransFlag); }
			//! �摜�̊g��`��
			inline int DrawExtendGraph(const pointi& lu, const pointi& rb, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraph(lu.x, lu.y, rb.x, rb.y, GetHandle(), TransFlag); }
			//! �摜�̉�]�`��
			inline int DrawRotaGraph(int x, int y, double ExRate, double Angle, bool TransFlag, bool TurnFlag = false)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph(x, y, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��
			inline int DrawRotaGraph(const pointi& p, double ExRate, double Angle, bool TransFlag, bool TurnFlag = false)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph(p.x, p.y, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )
			inline int DrawRotaGraph2(int x, int y, int cx, int cy, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = false)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph2(x, y, cx, cy, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )
			inline int DrawRotaGraph2(const pointi& p, const pointi& c, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = false)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph2(p.x, p.y, c.x, c.y, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
			inline int DrawRotaGraph3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph3(x, y, cx, cy, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
			inline int DrawRotaGraph3(const pointi& p, const pointi& c, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph3(p.x, p.y, c.x, c.y, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��
			inline int DrawModiGraph(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawModiGraph(x1, y1, x2, y2, x3, y3, x4, y4, GetHandle(), TransFlag); }
			//! �摜�̎��R�ό`�`��
			inline int DrawModiGraph(const std::array<pointi, 4>& ps, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawModiGraph(ps[0].x, ps[0].y, ps[1].x, ps[1].y, ps[2].x, ps[2].y, ps[3].x, ps[3].y, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��
			inline int DrawTurnGraph(int x, int y, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawTurnGraph(x, y, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��
			inline int DrawTurnGraph(const pointi& p, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawTurnGraph(p.x, p.y, GetHandle(), TransFlag); }
			//! �摜�̊g�卶�E���]�`��
			inline int DrawExtendTurnGraph(int x1, int y1, int x2, int y2, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraph(x2, y1, x1, y2, GetHandle(), TransFlag); }//x1��x2�͂���Ő�����
			//! �摜�̊g�卶�E���]�`��
			inline int DrawExtendTurnGraph(const pointi& lu, const pointi& rb, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraph(rb.x, lu.y, lu.x, rb.y, GetHandle(), TransFlag); }//lu.x��rb.x�͂���Ő�����

			//! �摜�̕`��( ���W�w�肪 float �� )
			inline int DrawGraphF(float xf, float yf, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawGraphF(xf, yf, GetHandle(), TransFlag); }
			//! �摜�̕`��( ���W�w�肪 float �� )
			inline int DrawGraphF(const pointf& p, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawGraphF(p.x, p.y, GetHandle(), TransFlag); }
			//! �摜�̊g��`��( ���W�w�肪 float �� )
			inline int DrawExtendGraphF(float x1f, float y1f, float x2f, float y2, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraphF(x1f, y1f, x2f, y2, GetHandle(), TransFlag); }
			//! �摜�̊g��`��( ���W�w�肪 float �� )
			inline int DrawExtendGraphF(const pointf& lu, const pointf& rb, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraphF(lu.x, lu.y, rb.x, rb.y, GetHandle(), TransFlag); }
			//! �摜�̉�]�`��( ���W�w�肪 float �� )
			inline int DrawRotaGraphF(float xf, float yf, double ExRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraphF(xf, yf, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��( ���W�w�肪 float �� )
			inline int DrawRotaGraphF(const pointf& p, double ExRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraphF(p.x, p.y, ExRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph2F(float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph2F(xf, yf, cxf, cyf, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph2F(const pointf& p, const pointf& c, double ExtRate, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph2F(p.x, p.y, c.x, c.y, ExtRate, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph3F(float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph3F(xf, yf, cxf, cyf, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
			inline int DrawRotaGraph3F(const pointf& p, const pointf& c, double ExtRateX, double ExtRateY, double Angle, bool TransFlag, bool TurnFlag = FALSE)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawRotaGraph3F(p.x, p.y, c.x, c.y, ExtRateX, ExtRateY, Angle, GetHandle(), TransFlag, TurnFlag); }
			//! �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
			inline int DrawModiGraphF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawModiGraphF(x1, y1, x2, y2, x3, y3, x4, y4, GetHandle(), TransFlag); }
			//! �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
			inline int DrawModiGraphF(const std::array<pointf, 4>& ps, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawModiGraphF(ps[0].x, ps[0].y, ps[1].x, ps[1].y, ps[2].x, ps[2].y, ps[3].x, ps[3].y, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��( ���W�w�肪 float �� )
			inline int DrawTurnGraphF(float xf, float yf, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawTurnGraphF(xf, yf, GetHandle(), TransFlag); }
			//! �摜�̍��E���]�`��( ���W�w�肪 float �� )
			inline int DrawTurnGraphF(const pointf& p, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawTurnGraphF(p.x, p.y, GetHandle(), TransFlag); }
			//! �摜�̊g�卶�E���]�`��( ���W�w�肪 float �� )
			inline int DrawExtendTurnGraphF(float x1f, float y1f, float x2f, float y2f, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraphF(x2f, y1f, x1f, y2f, GetHandle(), TransFlag); }//x1f��x2f�͂���Ő�����
			//! �摜�̊g�卶�E���]�`��( ���W�w�肪 float �� )
			inline int DrawExtendTurnGraphF(const pointf& lu, const pointf& rb, bool TransFlag)const { DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::DrawExtendGraphF(rb.x, lu.y, lu.x, rb.y, GetHandle(), TransFlag); }//x1f��x2f�͂���Ő�����

			int filter_mono			(int16_t Cb, int16_t Cr);
			int filter_gaussian		(uint16_t PixelWidth, int Param);
			int filter_down_scale	(uint8_t DivNum);
			int filter_bright_clip	(bright_clip_mode clipmode, uint8_t clip_pram, unsigned int fillcolor, uint8_t fillalpha);
			int filter_HSB			(bool HueType, int16_t Hue, int Saturation, int16_t Bright);
			int filter_invert		();
			int filter_level		(uint8_t min, uint8_t max, int Gamma, uint8_t Aftermin, uint8_t Aftermax);
			int filter_two_color	(uint8_t threshold, unsigned int LowColor, uint8_t LowAlpha, unsigned int HighColor, uint8_t HighAlpha);


		private:
			texture2d(int handle, bool NotUse3DFlag)
				: texture2d(gr_impl::simple_graph_handle_manager::get_unique(handle, NotUse3DFlag))
			{}
			texture2d(std::unique_ptr<gr_impl::texture2d_handle_manager>&& handle_manager_)
				: handle_manager(std::move(handle_manager_))
			{}
			std::unique_ptr<gr_impl::texture2d_handle_manager> handle_manager;

			int GetHandle()const{ if (!handle_manager){ return -1; } return handle_manager->get_handle(); }

			//���[�U�[���p������̂�h�~���邽��protected�ł͂Ȃ�friend���g��

			friend screen;

			//�����p

			 template<typename BuffT, typename OutFunc>
			 friend void gr_impl::LoadDivGraph_impl(OutFunc&& out_func, BuffT* HandleBuf, const TCHAR *FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag);
		};
		
		//! �`��\�摜�N���X
		class screen final : public texture2d
		{
		public:
			//!�摜�𕡐�����
			std::unique_ptr<texture2d> clone()const override{ return cloneSc(); }
			//!�摜�𕡐�����
			std::unique_ptr<screen> cloneSc()const;

			//�����pstatic�֐�

			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
			static inline screen MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLE_NOEXCEPT_OR_NOTHROW{ return screen(DxLib::MakeScreen(SizeX, SizeY, UseAlphaChannel), UseAlphaChannel); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
			static inline screen MakeScreen(const sizei& size, bool UseAlphaChannel = false)DXLE_NOEXCEPT_OR_NOTHROW{ return screen(DxLib::MakeScreen(size.width, size.height, UseAlphaChannel), UseAlphaChannel); }

			//�����o�֐�

			template<typename Func_T>
			screen& draw_on_this(Func_T&& draw_func);

			//! �O���t�B�b�N��p�̂y�o�b�t�@�������ǂ�����ݒ肷��
			//!@param UseFlag ��p�̂y�o�b�t�@�������ǂ���( true:����( �f�t�H���g )  false:�����Ȃ� )
			//!@param BitDepth �r�b�g�[�x( 16 or 24 or 32 ) )
			inline int SetUseGraphZBuffer(bool UseFlag, int BitDepth = -1)DXLE_NOEXCEPT_OR_NOTHROW{ return DxLib::SetUseGraphZBuffer(GetHandle(), UseFlag, BitDepth); }
			//! �O���t�B�b�N�̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�̂y�o�b�t�@�ɃR�s�[����
			//! *this�͂y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N
			//!@param ToGraph *this�ƃT�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�����A�y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N
			inline int CopyGraphZBufferImage(screen& ToGraph)const DXLE_NOEXCEPT_OR_NOTHROW{ return DxLib::CopyGraphZBufferImage(GetHandle(), ToGraph.GetHandle()); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h������w��̈�̉摜����ʂ̃O���t�B�b�N�n���h���ɓ]������
			//!@param x1 �]�����̋�`�̍����W
			//!@param y1 �]�����̋�`�̏���W
			//!@param x2 �]�����̋�`�̉E���W
			//!@param y2 �]�����̋�`�̉����W
			//!@param DestX, DestY �]����̋�`�̍�����W
			//!@param DestGrHandle �]����̉摜
			inline int BltDrawValidGraph(int x1, int y1, int x2, int y2, int DestX, int DestY, texture2d& DestGrHandle)const DXLE_NOEXCEPT_OR_NOTHROW{ return DxLib::BltDrawValidGraph(GetHandle(), x1, y1, x2, y2, DestX, DestY, DestGrHandle.GetHandle()); }
			//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h������w��̈�̉摜����ʂ̃O���t�B�b�N�n���h���ɓ]������
			//!@param lu �]�����̋�`�̍�����W
			//!@param rb �]�����̋�`�̉E�����W
			//!@param dest �]����̋�`�̍�����W
			//!@param DestGrHandle �]����̉摜
			inline int BltDrawValidGraph(const pointi& lu, const pointi& rb, const pointi& dest, texture2d& DestGrHandle)const DXLE_NOEXCEPT_OR_NOTHROW{ return DxLib::BltDrawValidGraph(GetHandle(), rb.x, lu.y, lu.x, rb.y, dest.x, dest.y, DestGrHandle.GetHandle()); }
			//! �`����ʂ�ݒ肷��
			inline int SetDrawScreen()const DXLE_NOEXCEPT_OR_NOTHROW_SINGLE{ DXLE_GET_LOCK(screen_mutex_c::mtx); return DxLib::SetDrawScreen(GetHandle()); }

		public:
			screen()DXLE_NOEXCEPT_OR_NOTHROW {}
			//! �R�s�[�֎~
			screen(const screen& other) = delete;
			//!���L���̏��n
			screen(screen&& other) DXLE_NOEXCEPT_OR_NOTHROW : texture2d(std::move(other)){}
			//! �R�s�[�֎~
			screen& operator=(const screen& other) = delete;
			//! ���L���̏��n
			screen& operator=(screen&& other) DXLE_NOEXCEPT_OR_NOTHROW{ texture2d::operator=(std::move(other)); return *this; }

		protected:
			screen(int handle, bool UseAlphaChannel)
				: texture2d(gr_impl::screen_handle_manager::get_unique(handle, UseAlphaChannel))
			{}
		};
		class shared_texture2d final
		{
		public:
			shared_texture2d()DXLE_NOEXCEPT_OR_NOTHROW{}
			template<typename texture2d_t> shared_texture2d(const texture2d_t& unique_tex) = delete;
			template<typename texture2d_t, enable_if_t<std::is_base_of<texture2d, texture2d_t>::value, nullptr_t> = nullptr>
			shared_texture2d(texture2d_t&& unique_tex)
				: impl(std::make_shared<texture2d_t>(std::forward<texture2d_t>(unique_tex)))
			{}

			shared_texture2d(const shared_texture2d& other)DXLE_NOEXCEPT_OR_NOTHROW : impl(other.impl){}
			shared_texture2d& operator=(const shared_texture2d& other)DXLE_NOEXCEPT_OR_NOTHROW { impl = (other.impl); return *this; }
			shared_texture2d(shared_texture2d&& other) DXLE_NOEXCEPT_OR_NOTHROW : impl(std::move(other.impl)){}
			shared_texture2d& operator=(shared_texture2d&& other) DXLE_NOEXCEPT_OR_NOTHROW{ impl = (std::move(other.impl)); return *this; }

#if 1
			texture2d& get()DXLE_NOEXCEPT_OR_NOTHROW{ return *impl; }
			const texture2d& get()const DXLE_NOEXCEPT_OR_NOTHROW{ return *impl; }
			operator texture2d&()DXLE_NOEXCEPT_OR_NOTHROW{ return *impl; }
			operator const texture2d&()const DXLE_NOEXCEPT_OR_NOTHROW{ return *impl; }
#else
			texture2d* operator->()DXLE_NOEXCEPT_OR_NOTHROW{ return impl.get(); }
			const texture2d* operator->()const DXLE_NOEXCEPT_OR_NOTHROW{ return impl.get(); }
			texture2d& operator*()DXLE_NOEXCEPT_OR_NOTHROW{ return impl.get(); }
			const texture2d& operator*()const DXLE_NOEXCEPT_OR_NOTHROW{ return impl.get(); }
#endif

		private:
			std::shared_ptr<texture2d> impl;
		};

		//!N = AllNum
		template<size_t N>
		//!�摜�t�@�C���𕪊������O���t�B�b�N
		//!DxLib::LoadDivGraph��dxle::texture�o�[�W����
		//!AllSize���萔�̏ꍇ
		//!move�ɐ��`���Ԃ������邱�Ƃɒ���
		class static_derivative_texture2d final
		{
		private:
			std::array<texture2d, N> textures;
			using cont_type = decltype(textures);
		public:

			DXLE_CONSTEXPR static_derivative_texture2d()DXLE_NOEXCEPT_OR_NOTHROW{}
			static_derivative_texture2d(const static_derivative_texture2d&) = delete;
			static_derivative_texture2d(static_derivative_texture2d&&)DXLE_NOEXCEPT_OR_NOTHROW;
			static_derivative_texture2d& operator=(const static_derivative_texture2d&) = delete;
			static_derivative_texture2d& operator=(static_derivative_texture2d&&)DXLE_NOEXCEPT_OR_NOTHROW;

		//----------�����֐�----------//

			static_derivative_texture2d(const TCHAR *FileName, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
			static_derivative_texture2d(const tstring& FileName, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

			void load(const TCHAR *FileName, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
			void load(const tstring& FileName, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

		//----------utility----------//

			void delete_all();

		//----------�R���e�i��----------//

			using reference              = typename cont_type::reference;
			using const_reference        = typename cont_type::const_reference;
			using iterator               = typename cont_type::iterator;
			using const_iterator         = typename cont_type::const_iterator;
			using reverse_iterator       = typename cont_type::reverse_iterator;
			using const_reverse_iterator = typename cont_type::const_reverse_iterator;
			using size_type              = typename cont_type::size_type;
			using difference_type        = typename cont_type::difference_type;
			using pointer                = typename cont_type::pointer;
			using const_pointer          = typename cont_type::const_pointer;
			using value_type             = typename cont_type::value_type;

			      reference at(size_t index)     { return textures.at(index); }
			const_reference at(size_t index)const{ return textures.at(index); }
			      reference operator[](size_t index)     { return textures[index]; }
			const_reference operator[](size_t index)const{ return textures[index]; }
			      reference front()     { return textures.front(); }
			const_reference front()const{ return textures.front(); }
			      reference back()     { return textures.back(); }
			const_reference back()const{ return textures.back(); }
			      pointer data()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.data(); }
			const_pointer data()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.data(); }

			      iterator begin ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.begin (); }
			const_iterator begin ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.begin (); }
			      iterator end   ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.end   (); }
			const_iterator end   ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.end   (); }
			const_iterator cbegin()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.cbegin(); }
			const_iterator cend  ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.cend  (); }
			      reverse_iterator rbegin ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rbegin (); }
			const_reverse_iterator rbegin ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rbegin (); }
			      reverse_iterator rend   ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rend   (); }
			const_reverse_iterator rend   ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rend   (); }
			const_reverse_iterator crbegin()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.crbegin(); }
			const_reverse_iterator crend  ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.crend  (); }

			DXLE_CONSTEXPR bool empty()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.empty(); }
			DXLE_CONSTEXPR size_type size()const DXLE_NOEXCEPT_OR_NOTHROW { return textures.size(); }
			DXLE_CONSTEXPR size_type max_size()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.max_size(); }

			void swap(static_derivative_texture2d& other){ textures.swap(other.textures); }
		};
		//!�摜�t�@�C���𕪊������O���t�B�b�N
		//!DxLib::LoadDivGraph��dxle::texture�o�[�W����
		//!move�͒萔����
		class derivative_texture2d final
		{
		private:
			std::vector<texture2d> textures;
			using cont_type = decltype(textures);
		public:

			derivative_texture2d()DXLE_NOEXCEPT_OR_NOTHROW{}
			derivative_texture2d(const derivative_texture2d&) = delete;
			derivative_texture2d(derivative_texture2d&&)DXLE_NOEXCEPT_IF((std::is_nothrow_move_constructible<cont_type>::value));
			derivative_texture2d& operator=(const derivative_texture2d&) = delete;
			derivative_texture2d& operator=(derivative_texture2d&&)DXLE_NOEXCEPT_IF((std::is_nothrow_move_assignable<cont_type>::value));

			//----------�����֐�----------//

			derivative_texture2d(const TCHAR *FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
			derivative_texture2d(const tstring& FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

			void load(const TCHAR *FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
			void load(const tstring& FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

			static inline derivative_texture2d LoadDivGraph(const TCHAR *FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
			static inline derivative_texture2d LoadDivGraph(const tstring& FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

			//----------utility----------//

			void delete_all();

			//----------�R���e�i��----------//

			using reference              = cont_type::reference;
			using const_reference        = cont_type::const_reference;
			using iterator               = cont_type::iterator;
			using const_iterator         = cont_type::const_iterator;
			using reverse_iterator       = cont_type::reverse_iterator;
			using const_reverse_iterator = cont_type::const_reverse_iterator;
			using size_type              = cont_type::size_type;
			using difference_type        = cont_type::difference_type;
			using pointer                = cont_type::pointer;
			using const_pointer          = cont_type::const_pointer;
			using value_type             = cont_type::value_type;

			      reference at(size_t index)     { return textures.at(index); }
			const_reference at(size_t index)const{ return textures.at(index); }
			      reference operator[](size_t index)     { return textures[index]; }
			const_reference operator[](size_t index)const{ return textures[index]; }
			      reference front()     { return textures.front(); }
			const_reference front()const{ return textures.front(); }
			      reference back()     { return textures.back(); }
			const_reference back()const{ return textures.back(); }
			      pointer data()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.data(); }
			const_pointer data()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.data(); }

			      iterator begin ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.begin (); }
			const_iterator begin ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.begin (); }
			      iterator end   ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.end   (); }
			const_iterator end   ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.end   (); }
			const_iterator cbegin()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.cbegin(); }
			const_iterator cend  ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.cend  (); }
			      reverse_iterator rbegin ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rbegin (); }
			const_reverse_iterator rbegin ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rbegin (); }
			      reverse_iterator rend   ()      DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rend   (); }
			const_reverse_iterator rend   ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.rend   (); }
			const_reverse_iterator crbegin()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.crbegin(); }
			const_reverse_iterator crend  ()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.crend  (); }

			bool empty()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.empty(); }
			size_type size()const DXLE_NOEXCEPT_OR_NOTHROW { return textures.size(); }
			size_type max_size()const DXLE_NOEXCEPT_OR_NOTHROW{ return textures.max_size(); }

			void swap(derivative_texture2d& other){ textures.swap(other.textures); }
		};

		
	//--------------------�����p�֐�--------------------//

		// �O���t�B�b�N�쐬�֌W�֐�

		//! �w��T�C�Y�̃O���t�B�b�N���쐬����
		inline texture2d MakeGraph(int SizeX, int SizeY, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::MakeGraph(SizeX, SizeY, NotUse3DFlag); }
		//! �w��T�C�Y�̃O���t�B�b�N���쐬����
		inline texture2d MakeGraph(const sizei& size, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::MakeGraph(size.width, size.height, NotUse3DFlag); }
		//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
		inline screen MakeScreen(int SizeX, int SizeY, bool UseAlphaChannel = false)DXLE_NOEXCEPT_OR_NOTHROW { return screen::MakeScreen(SizeX, SizeY, UseAlphaChannel); }
		//! SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N���쐬����
		inline screen MakeScreen(const sizei& size, bool UseAlphaChannel = false)DXLE_NOEXCEPT_OR_NOTHROW { return screen::MakeScreen(size.width, size.height, UseAlphaChannel); }
		//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
		inline texture2d DerivationGraph(int SrcX, int SrcY, int Width, int Height, const texture2d& SrcGraphHandle)DXLE_NOEXCEPT_OR_NOTHROW{ return texture2d::DerivationGraph(SrcX, SrcY, Width, Height, SrcGraphHandle); }
		//! �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N���쐬����
		inline texture2d DerivationGraph(const pointi& src, const sizei& size, const texture2d& SrcGraphHandle)DXLE_NOEXCEPT_OR_NOTHROW{ return texture2d::DerivationGraph(src.x, src.y, size.width, size.height, SrcGraphHandle); }

		// �摜����O���t�B�b�N���쐬����֐�

		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline texture2d LoadBmpToGraph(const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadBmpToGraph(FileName, TextureFlag, ReverseFlag, SurfaceMode); }
		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline texture2d LoadBmpToGraph(const tstring& FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadBmpToGraph(FileName.c_str(), TextureFlag, ReverseFlag, SurfaceMode); }
		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline texture2d LoadGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C������O���t�B�b�N���쐬����
		inline texture2d LoadGraph(const tstring& FileName, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadGraph(FileName.c_str(), NotUse3DFlag); }
		//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N���쐬����
		inline texture2d LoadReverseGraph(const TCHAR *FileName, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadReverseGraph(FileName, NotUse3DFlag); }
		//! �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N���쐬����
		inline texture2d LoadReverseGraph(const tstring& FileName, bool NotUse3DFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::LoadReverseGraph(FileName.c_str(), NotUse3DFlag); }

		//! �摜�t�@�C���𕪊����ăO���t�B�b�N�n���h�����쐬����
		inline derivative_texture2d LoadDivGraph(const TCHAR *FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);
		//! �摜�t�@�C���𕪊����ăO���t�B�b�N�n���h�����쐬����
		inline derivative_texture2d LoadDivGraph(const std::string& FileName, int AllNum, const dxle::sizei& Num, const dxle::sizei& Size, bool NotUse3DFlag = false);

		//! ��������̉摜�C���[�W����O���t�B�b�N���쐬����
		inline texture2d CreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromMem(RGBFileImage, RGBFileImageSize, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }
		//! ��������̉摜�C���[�W��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromMem(const void *RGBFileImage, int RGBFileImageSize, texture2d& GrHandle, const void *AlphaFileImage = nullptr, int AlphaFileImageSize = 0, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromMem(RGBFileImage, RGBFileImageSize, GrHandle, AlphaFileImage, AlphaFileImageSize, TextureFlag, ReverseFlag); }

		//! ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N���쐬����
		inline texture2d CreateDXGraph(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, bool TextureFlag)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateDXGraph(RgbBaseImage, AlphaBaseImage, TextureFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline texture2d CreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromGraphImage(RgbBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline texture2d CreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, texture2d& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromGraphImage(RgbBaseImage, GrHandle, TextureFlag, ReverseFlag); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�Ƀf�[�^��]������
		inline int ReCreateGraphFromGraphImage(const DxLib::BASEIMAGE *RgbBaseImage, const DxLib::BASEIMAGE *AlphaBaseImage, texture2d& GrHandle, bool TextureFlag = true, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromGraphImage(RgbBaseImage, AlphaBaseImage, GrHandle, TextureFlag, ReverseFlag); }

		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
		inline texture2d CreateGraph(int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const texture2d& GrHandle = texture2d())DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraph(Width, Height, Pitch, RGBImage, AlphaImage, GrHandle); }
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���쐬����
		inline texture2d CreateGraph(const sizei& size, int Pitch, const void *RGBImage, const void *AlphaImage = nullptr, const texture2d& GrHandle = texture2d())DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraph(size.width, size.height, Pitch, RGBImage, AlphaImage, GrHandle); }
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
		inline int ReCreateGraph(int Width, int Height, int Pitch, const void *RGBImage, texture2d& GrHandle, const void *AlphaImage = nullptr)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraph(Width, Height, Pitch, RGBImage, GrHandle, AlphaImage); }
		//! ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N���č쐬����
		inline int ReCreateGraph(const sizei& size, int Pitch, const void *RGBImage, texture2d& GrHandle, const void *AlphaImage = nullptr)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraph(size.width, size.height, Pitch, RGBImage, GrHandle, AlphaImage); }
#ifndef DX_NON_SOFTIMAGE
#endif // DX_NON_SOFTIMAGE
		//! ��{�C���[�W�f�[�^����O���t�B�b�N���쐬����
		inline texture2d CreateGraphFromBaseImage(const DxLib::BASEIMAGE *BaseImage)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromBaseImage(BaseImage); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
		inline texture2d CreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N���쐬����
		inline texture2d CreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, const pointi& p, const sizei& size)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::CreateGraphFromRectBaseImage(BaseImage, p.x, p.y, size.width, size.height); }
		//! ��{�C���[�W�f�[�^��������̃O���t�B�b�N�ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromBaseImage(const DxLib::BASEIMAGE *BaseImage, texture2d& GrHandle)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromBaseImage(BaseImage, GrHandle); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, texture2d& GrHandle)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromRectBaseImage(BaseImage, x, y, SizeX, SizeY, GrHandle); }
		//! ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�ɉ摜�f�[�^��]������
		inline int ReCreateGraphFromRectBaseImage(const DxLib::BASEIMAGE *BaseImage, const pointi& p, const sizei& size, texture2d& GrHandle)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReCreateGraphFromRectBaseImage(BaseImage, p.x, p.y, size.width, size.height, GrHandle); }
		//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
		inline int ReloadGraph(const TCHAR *FileName, texture2d& GrHandle, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReloadGraph(FileName, GrHandle, ReverseFlag); }
		//! �摜�t�@�C������O���t�B�b�N�։摜�f�[�^��]������
		inline int ReloadGraph(const tstring& FileName, texture2d& GrHandle, bool ReverseFlag = false)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReloadGraph(FileName.c_str(), GrHandle, ReverseFlag); }
		//! ReloadGraph �̉摜���]�����ǉ���
		inline int ReloadReverseGraph(const TCHAR *FileName, texture2d& GrHandle)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReloadReverseGraph(FileName, GrHandle); }
		//! ReloadGraph �̉摜���]�����ǉ���
		inline int ReloadReverseGraph(const tstring& FileName, texture2d& GrHandle)DXLE_NOEXCEPT_OR_NOTHROW { return texture2d::ReloadReverseGraph(FileName.c_str(), GrHandle); }


	}
	using namespace graph2d;
}

#include "texture2d.hpp"
#endif
