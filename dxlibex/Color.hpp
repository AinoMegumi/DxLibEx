/*=============================================================================
  Copyright (C) 2015 DxLibEx project
  https://github.com/Nagarei/DxLibEx/

  Distributed under the Boost Software License, Version 1.0.
  (See http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef DXLE_INC_COLOR_HPP_
#define DXLE_INC_COLOR_HPP_

#include "dxlibex/config/no_min_max.h"
#include "DxLib.h"
#include "config/defines.h"

namespace dxle
{
	//! utility for Color
	//! based on X11
	struct Color
	{
		typedef decltype(DxLib::GetColor(0, 0, 0)) value_type;

		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(0, 0, 0); } } static const black;//!< ��
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(0, 0, 255); } } static const blue;//!< ��
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(0, 255, 255); } } static const cyan;//!< �V�A�� 
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(169, 169, 169); } } static const darkgray;//!< �_�[�N�O���[(X11)
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(190, 190, 190); } } static const gray;//!< �O���[
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(0, 255, 0); } } static const green;//!< ��(X11)
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(211, 211, 211); } } static const lightgray;//!< ���C�g�O���[
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 0, 255); } } static const magenta;//!< �}�[���^
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 165, 0); } } static const orange;//!< �I�����W
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 192, 203); } } static const pink;//!< �s���N
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 0, 0); } } static const red;//!< ��
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 255, 255); } } static const white;//!< ��
		struct { inline operator Color()const DXLE_NOEXCEPT { return DxLib::GetColor(255, 255, 0); } } static const yellow;//!< ���F

		//! DrawPixel ���̕`��֐��Ŏg�p����J���[�l���擾����
		static Color GetColor(int Red, int Green, int Blue)DXLE_NOEXCEPT { return DxLib::GetColor(Red, Green, Blue); }
		//! �w��̃s�N�Z���t�H�[�}�b�g�ɑΉ������J���[�l�𓾂�
		static Color GetColor3(const COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255)DXLE_NOEXCEPT { return DxLib::GetColor3(ColorData, Red, Green, Blue, Alpha); }
		//! �w��̃J���[�t�H�[�}�b�g�̃J���[�l��ʂ̃J���[�t�H�[�}�b�g�̃J���[�l�ɕϊ�����
		static Color GetColor4(const COLORDATA *DestColorData, const COLORDATA* SrcColorData, const Color& SrcColor)DXLE_NOEXCEPT { return DxLib::GetColor4(DestColorData, SrcColorData, SrcColor.value); }

		//�����o�֐�

		//! �J���[�l����ԁA�΁A�̒l���擾����
		int GetColor2(int *Red, int *Green, int *Blue)const DXLE_NOEXCEPT { return DxLib::GetColor2(value, Red, Green, Blue); }
		//! �w��̃J���[�t�H�[�}�b�g�̃J���[�l��ԁA�΁A�A�A���t�@�̒l���擾����
		int GetColor5(const COLORDATA *ColorData, int *Red, int *Green, int *Blue, int *Alpha = NULL)const DXLE_NOEXCEPT { return DxLib::GetColor5(ColorData, value, Red, Green, Blue, Alpha); }

		value_type get()const DXLE_NOEXCEPT { return value; }

		/*
		extern	COLOR_F			GetColorF(float Red, float Green, float Blue, float Alpha);												// ���������_�^�̃J���[�l���쐬����
		extern	COLOR_U8		GetColorU8(int Red, int Green, int Blue, int Alpha);														// �����Ȃ������W�r�b�g�̃J���[�l���쐬����
		extern	int				CreatePaletteColorData(COLORDATA *ColorDataBuf);																		// �p���b�g�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateARGBF32ColorData(COLORDATA *ColorDataBuf);																		// �`�q�f�a�e�`�����l�� 32bit ���������_�^�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateARGBF16ColorData(COLORDATA *ColorDataBuf);																		// �`�q�f�a�e�`�����l�� 16bit ���������_�^�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateXRGB8ColorData(COLORDATA *ColorDataBuf);																		// �w�q�f�a�W�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateARGB8ColorData(COLORDATA *ColorDataBuf);																		// �`�q�f�a�W�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateARGB4ColorData(COLORDATA *ColorDataBuf);																		// �`�q�f�a�S�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateFullColorData(COLORDATA *ColorDataBuf);																		// �Q�S�r�b�g�J���[�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateGrayColorData(COLORDATA *ColorDataBuf);																		// �O���[�X�P�[���̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreatePal8ColorData(COLORDATA *ColorDataBuf);																		// �p���b�g�Q�T�U�F�̃J���[�t�H�[�}�b�g���\�z����
		extern	int				CreateColorData(COLORDATA *ColorDataBuf, int ColorBitDepth,
			DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask,
			int ChannelNum = 0, int ChannelBitDepth = 0, int FloatTypeFlag = FALSE);						// �J���[�t�H�[�}�b�g���쐬����
		extern	void			SetColorDataNoneMask(COLORDATA *ColorData);																		// NoneMask �ȊO�̗v�f�𖄂߂� COLORDATA �\���̂̏������� NoneMask ���Z�b�g����
		extern	int				CmpColorData(const COLORDATA *ColorData1, const COLORDATA *ColorData2);									// ��̃J���[�t�H�[�}�b�g�����������ǂ������ׂ�( �߂�l�@TRUE:������  FALSE:�������Ȃ� )
		*/

	private:
		value_type value;
		Color(value_type param)DXLE_NOEXCEPT
			: value(param)
		{}
	};

}//namespace dxle
#endif
