#ifndef DX_LIB_EX_DEFINES_H_2015_10_11_1714_185961646566518
#define DX_LIB_EX_DEFINES_H_2015_10_11_1714_185961646566518

//�����p�t�@�C���ł�
//�J���҈ȊO�������̋@�\���g���̂͂����߂ł��܂���

//������define�͊��S�ł͂���܂���

#ifdef _MSC_VER
#if (_MSC_VER >= 1900)
	//VC2015
#	define DXLIBEX_NOEXCEPT noexcept
#	define DXLIBEX_CONSTEXPR constexpr
#	define DXLIBEX_SFINAE template<typename = void>
#
#elif (_MSC_VER >= 1700)
	//VC2013,VC2012
#	define DXLIBEX_NOEXCEPT throw()
#	define DXLIBEX_CONSTEXPR
#	define DXLIBEX_SFINAE
#
#endif
//#ifdef _MSC_VER
#else
#	define DXLIBEX_NOEXCEPT noexcept
#	define DXLIBEX_CONSTEXPR constexpr
#	define DXLIBEX_SFINAE template<typename = void>
#endif

//�C���N���[�h�K�[�h
#endif
