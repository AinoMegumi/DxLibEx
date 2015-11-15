#ifndef DXLE_IMPL_H_2015_0930_0605_1596851632_
#define DXLE_IMPL_H_2015_0930_0605_1596851632_

//�����p�t�@�C���ł��B
//�J���҈ȊO�������̋@�\���g���̂͂����߂ł��܂���

#include "dxlibex/DxLibEx.h"
#include <type_traits>
#include <new>
//�e�֐��̒�`

namespace dxle
{
	//----------DxLibSys----------//
	namespace nDxLibSys
	{

		//!DxLib_Init���s���B<br>
		//!���s�����int�^�̗�O�𓊂���B<br>
		//!����̂ݗL���B<br>
		//!WinMain�����return��DxLibEnd���Ăяo���܂��B
		inline void DxLibSys::Init()
		{
			static DxLibSys initer;
		}
		//!DxLib_End���s��
		inline void DxLibSys::End()DXLE_NOEXCEPT
		{
			DxLib::DxLib_End();
		}
		//!DX���C�u�����̓����Ŏg�p���Ă���\���̂��[�����������āA
		//!DxLib_Init �̑O�ɍs�����ݒ�𖳌�������( DxLib_Init �̑O�ł̂ݗL�� )
		inline int DxLibSys::GlobalStructInitialize()DXLE_NOEXCEPT
		{
			return DxLib::DxLib_GlobalStructInitialize();
		}
		//!DX���C�u����������������Ă��邩�ǂ������擾����
		//!@return true:����������Ă���  false:����Ă��Ȃ�
		inline bool DxLibSys::IsInit()DXLE_NOEXCEPT
		{
			return DxLib::DxLib_IsInit() != FALSE;
		}
		//!�E�C���h�E�Y�̃��b�Z�[�W���[�v�ɑ��鏈�����s��
		inline int DxLibSys::ProcessMessage()
		{
			return DxLib::ProcessMessage();
		}
		DxLibSys::DxLibSys() {
			if (DxLib::DxLib_Init() == -1) {
				throw - 1;
			}
		}
		DxLibSys::~DxLibSys()DXLE_NOEXCEPT {
			DxLibSys::End();
		}
	}

	//----------Wait �E�G�C�g�n�֐�----------//


	//----------�J�E���^�n----------//
	namespace nCounter
	{

		//!�~���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
		inline Counter Counter::GetNowCount(bool UseRDTSCFlag)DXLE_NOEXCEPT {
			return Counter(DxLib::GetNowCount(UseRDTSCFlag));
		}
		//! 1000��������HiPerformanceCounter�Ƃ݂Ȃ��悤�ɂ���
		inline HiPerformanceCounter Counter::CastToHiPerformance()const DXLE_NOEXCEPT {
			return Cast<LONGLONG>::Do(static_cast<LONGLONG>(count()) * 1000);
		}
		//!�}�C�N���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
		inline HiPerformanceCounter HiPerformanceCounter::GetNowCount(bool UseRDTSCFlag)DXLE_NOEXCEPT {
			return HiPerformanceCounter(DxLib::GetNowHiPerformanceCount(UseRDTSCFlag));
		}
		//! 1000�Ŋ�����Counter�Ƃ݂Ȃ��悤�ɂ���
		inline Counter HiPerformanceCounter::CastToLowPerformance()const DXLE_NOEXCEPT {
			return Cast<int>::Do(static_cast<int>(count() / 1000));
		}
	}

	//----------�����n----------//


	//----------���O�n----------//


	//----------�񓯊��ǂݍ��݊֌W----------//


	//----------�n���h���֌W----------//


	//----------�}�E�X�֌W----------//
	namespace nMouse
	{
		inline MouseState::MouseState() DXLE_NOEXCEPT
			: LeftButton(ButtonState::Released)
			, MiddleButton(ButtonState::Released)
			, RightButton(ButtonState::Released)
			, ScrollWheelValue(0)
			, X(0)
			, XButton1(ButtonState::Released)
			, XButton2(ButtonState::Released)
			, Y(0)
		{}
		//!�Q�[���ł͒ʏ�AGetState ���g�p���Ď��ۂ̃}�E�X�̏�Ԃ��擾���܂��B
		//!���̃R���X�g���N�^�[�́A����ɃQ�[�����̂̓��̓T�u�V�X�e�����œn�����߂�
		//!�}�E�X���͂��V�~�����[�g���邽�߂Ɏg�p����܂��B
		//!@param[in] x              �}�E�X�̐����ʒu�B
		//!@param[in] y              �}�E�X�̐����ʒu�B
		//!@param[in] scrollWheel    �}�E�X �X�N���[�� �z�C�[���̒l�B
		//!@param[in] leftButton     ���}�E�X �{�^���̏�ԁB
		//!@param[in] middleButton   ���}�E�X �{�^���̏�ԁB
		//!@param[in] rightButton    �E�}�E�X �{�^���̏�ԁB
		//!@param[in] xButton1       XBUTTON1 �̏�ԁB
		//!@param[in] xButton2       XBUTTON2 �̏�ԁB
		inline MouseState::MouseState(int x, int y, int scrollWheel
			, ButtonState leftButton, ButtonState middleButton, ButtonState rightButton
			, ButtonState xButton1, ButtonState xButton2) DXLE_NOEXCEPT
			: LeftButton(leftButton)
			, MiddleButton(middleButton)
			, RightButton(rightButton)
			, ScrollWheelValue(scrollWheel)
			, X(x)
			, XButton1(xButton1)
			, XButton2(xButton2)
			, Y(y)
		{}
		inline bool MouseState::operator==(const MouseState& right)DXLE_NOEXCEPT
		{
			return (
				(LeftButton == right.LeftButton) &&
				(MiddleButton == right.MiddleButton) &&
				(RightButton == right.RightButton) &&
				(ScrollWheelValue == right.ScrollWheelValue) &&
				(X == right.X) &&
				(XButton1 == right.XButton1) &&
				(XButton2 == right.XButton2) &&
				(Y == right.Y)
				);
		}

		inline MouseInputInfo::MouseInputInfo()DXLE_NOEXCEPT
			: X(0)
			, Y(0)
			, Type(0)
		{}
		inline MouseInputInfo::MouseInputInfo(int x, int y, int type)DXLE_NOEXCEPT
			: X(x)
			, Y(y)
			, Type(type)
		{}

		//!�}�E�X�̌��݂̏�� (�}�E�X�̈ʒu�≟����Ă���{�^���Ȃ�) ���擾���܂��B
		//!@param ScrollWheelValueReset GetMouseWheelRotVol�̈���CounterReset�Ɠ���
		MouseState Mouse::GetState(bool ScrollWheelValueReset)DXLE_NOEXCEPT
		{
			int x, y;
			DxLib::GetMousePoint(&x, &y);

			int scrollWheel = DxLib::GetMouseWheelRotVol(ScrollWheelValueReset);

			int pushed_button = DxLib::GetMouseInput();
			ButtonState
				leftButton = ((pushed_button & MOUSE_INPUT_LEFT) ? ButtonState::Pressed : ButtonState::Released)
				, middleButton = ((pushed_button & MOUSE_INPUT_MIDDLE) ? ButtonState::Pressed : ButtonState::Released)
				, rightButton = ((pushed_button & MOUSE_INPUT_RIGHT) ? ButtonState::Pressed : ButtonState::Released)
				, xButton1 = ((pushed_button & MOUSE_INPUT_4) ? ButtonState::Pressed : ButtonState::Released)
				, xButton2 = ((pushed_button & MOUSE_INPUT_5) ? ButtonState::Pressed : ButtonState::Released)
				;
			return MouseState(x, y, scrollWheel, leftButton, middleButton, rightButton, xButton1, xButton2);
		}
		//!�}�E�X�̃N���b�N�������܂Ƃ߂Ď擾����
		//!�Q�ƁFDxLib::GetMouseInputLog http://homepage2.nifty.com/natupaji/DxLib/function/dxfunc_input.html#R5N36
		//!@attention ������GetMouseInputLog��LogDelete��TRUE��n���ČĂяo���܂�
		std::queue<MouseInputInfo> Mouse::GetMouseInputLog()
		{
			std::queue<MouseInputInfo> result;
			int x, y, pushed_button;
			while (DxLib::GetMouseInputLog(&pushed_button, &x, &y, TRUE) == 0)
			{
				result.push(MouseInputInfo(x, y, pushed_button));
			}
			return result;
		}
	}

	//----------�^�b�`�p�l�����͊֌W�֐�----------//


	//----------�������m�یn�֐�----------//
	namespace DxMemory
	{
#if 0
		template<typename... Args>
		//!�m�ۂɎ��s������new_handler���Ăяo�� or std::bad_alloc�𓊂���DxRealloc
		//!@param[in] Memory DxRealloc�̈���Memory�Ɠ���
		//!@param[in] size DxRealloc�̈���AllocSize�Ɠ���
		//!@param[in] File DxRealloc�̈���File�Ɠ���
		//!@param[in] Line DxRealloc�̈���Line�Ɠ���
		//!@return DxRealloc�̖߂�l�Ɠ���
		void* DxNewWithLog(void* Memory, size_t size, const char *File/*__FILE__*/, int Line/*__LINE__*/)
		{
			//�Q�Ɓ@http://cpplover.blogspot.jp/2010/07/operator-new.html

			// Executes a loop: Within the loop,
			for (;;)
			{
				// the function first attempts to allocate the requested storage.
				void* ptr = DxLib::DxRealloc(Memory, size, File, Line);

				// if the attempt is successful
				if (ptr != nullptr)
				{
					return ptr;
				}

				// Otherwise, 
				std::new_handler handler = std::set_new_handler(nullptr);
				std::set_new_handler(handler);

				// if the argument in the most recent call to set_new_handler() was a null pointer,
				if (handler == nullptr)
				{// throws bad_alloc.
					throw std::bad_alloc();
				}

				// Otherwise, the function calls the current new_handler function.
				handler();
				// If the called function returns, the loop repeats.
			}
		}
		template<typename T>
		template<typename... Args>
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		inline Dx_Unique_Ptr<T> Dx_Unique_Ptr<T>::NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args)
		{
			void* ptr = DxNewWithLog(nullptr, sizeof(T), File, Line);
			try {
				return Dx_Unique_Ptr<T>(new(ptr) T(std::forward<Args>(args)...));
			}
			catch (...) {
				//�R���X�g���N�^����O�𓊂���
				DxLib::DxFree(ptr);
				throw;
			}
		}
		template<typename T>
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		//!@param[in] n    �z��̗v�f��
		inline Dx_Unique_Ptr<T[]> Dx_Unique_Ptr<T[]>::NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n)
		{
			void* ptr = DxNewWithLog(nullptr, sizeof(T) * n, File, Line);
			try {
				return Dx_Unique_Ptr<T[]>(new(ptr) T[n]);
			}
			catch (...) {
				//�R���X�g���N�^����O�𓊂���
				DxLib::DxFree(ptr);
				throw;
			}
		}
#if 0
		template<typename T>
		//!�������̍Ċm�ۂ��s���i�z��ł̂݁j
		//!@attention �r���ŗ�O��������ꂽ�ꍇbace�͕K�������ɂȂ�܂�
		//!@param[in,out] bace ��ɂȂ�Dx_Unique_Ptr
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		//!@param[in] n    �V�����z��̗v�f��
		void Dx_Unique_Ptr<T[]>::NewWithLogRun(This_T&& bace, const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n)
		{
			void* ptr;
			try {
				ptr = DxNewWithLog(bace.ptr.get(), sizeof(T) * n, File, Line);
			}
			catch (...) {
				bace.reset();
				throw;
			}

			bace.ptr.release();
			try {
				bace.ptr.reset(new(ptr) T[n]);
			}
			catch (...) {
				//�R���X�g���N�^����O�𓊂���
				DxLib::DxFree(ptr);
				throw;
			}
		}
#endif
		template<typename T, typename... Args, typename>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�P��I�u�W�F�N�g�Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		inline Dx_Unique_Ptr<T> MakeUniqueDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args)
		{
			return Dx_Unique_Ptr<T>::NewWithLog(File, Line, std::forward<Args>(args)...);
		}
		template<typename T, typename>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�z��Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		inline Dx_Unique_Ptr<T> MakeUniqueDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n)
		{
			return Dx_Unique_Ptr<T>::NewWithLog(File, Line, n);
		}
#endif
	}



}//namespace dxle
//�C���N���[�h�K�[�h
#endif
