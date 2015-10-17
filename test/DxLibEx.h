#ifndef DX_LIB_EX_H_
#define DX_LIB_EX_H_

#include "DxLib.h"
#include <type_traits>
#include <utility>
#include <memory>
#include <queue>
#include "DxLibEx_Helper.h"
#include "DxLibEx_Defines.h"

namespace DxLibEx
{
	//!DxLibEx�̌��J�N���X���S�ē�����namespace�ł�
	namespace DxLibEx_Classes{}

	//!DxLib_End�̂��Y���h���܂�
	namespace nDxLibSys
	{
		//!�������I���n�֐��A���b�Z�[�W�����֐�
		//!DxLib_End�̂��Y���h���܂�
		//!�i���Fexit��abort�ɂ͑Ή��ł��܂���j
		class DxLibSys
		{
		public:
			//----------�������I���n�֐�----------//

			//!DxLib_Init���s���B<br>
			//!���s�����int�^�̗�O�𓊂���B<br>
			//!����̂ݗL���B<br>
			//!WinMain�����return��DxLibEnd���Ăяo���܂��B
			static void Init();
			//!DxLib_End���s��
			static void End()DXLIBEX_NOEXCEPT;

			//!DX���C�u�����̓����Ŏg�p���Ă���\���̂��[�����������āA
			//!DxLib_Init �̑O�ɍs�����ݒ�𖳌�������( DxLib_Init �̑O�ł̂ݗL�� )
			static int GlobalStructInitialize()DXLIBEX_NOEXCEPT;
			//!DX���C�u����������������Ă��邩�ǂ������擾����
			//!@return true:����������Ă���  false:����Ă��Ȃ�
			static bool IsInit()DXLIBEX_NOEXCEPT;


			//----------���b�Z�[�W�����֐�----------//

			//!�E�C���h�E�Y�̃��b�Z�[�W���[�v�ɑ��鏈�����s��
			static int ProcessMessage();

		private:
			DxLibSys();
			~DxLibSys()DXLIBEX_NOEXCEPT;
		};
	}
	namespace DxLibEx_Classes { using nDxLibSys::DxLibSys; }


	//----------�E�G�C�g�n----------//

	//!�E�G�C�g�n
	namespace Wait
	{
		//! �w��̎��Ԃ����������Ƃ߂�
		int WaitTimer(int WaitTime)DXLIBEX_NOEXCEPT{ return DxLib::WaitTimer(WaitTime); }
#ifndef DX_NON_INPUT
		//! �L�[�̓��͑҂����s��
		int WaitKey(void)DXLIBEX_NOEXCEPT{ return DxLib::WaitKey(); }
#endif // DX_NON_INPUT
	}


	//----------�J�E���^�n----------//

	//!GetNowCount���̌�p��h���܂�
	namespace nCounter
	{
		//!�J�E���^�n
		//!GetNowCount�̖߂�l������Đ��̂܂܎g�����Ƃ�h��
		//!�����x�o�[�W����
		class HiPerformanceCounter;
		//!�J�E���^�n
		//!GetNowCount�̖߂�l������Đ��̂܂܎g�����Ƃ�h��
		class Counter : public impl::Counter_template<int>
		{
		public:
			//! �~���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
			static Counter GetNowCount(bool UseRDTSCFlag = false)DXLIBEX_NOEXCEPT;
			//! �~���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
			static inline Counter now(bool UseRDTSCFlag = false)DXLIBEX_NOEXCEPT { return GetNowCount(UseRDTSCFlag); }

			//! 1000��������HiPerformanceCounter�Ƃ݂Ȃ��悤�ɂ���
			HiPerformanceCounter CastToHiPerformance()const DXLIBEX_NOEXCEPT;

			Counter()DXLIBEX_NOEXCEPT {}
			Counter(const Counter_template<int>& param)DXLIBEX_NOEXCEPT :Counter_template(param) {}
		protected:
			explicit Counter(int param)DXLIBEX_NOEXCEPT : Counter_template(param) {}
		};
		//!�J�E���^�n
		//!GetNowCount�̖߂�l������Đ��̂܂܎g�����Ƃ�h��
		//!�����x�o�[�W����
		class HiPerformanceCounter : public impl::Counter_template<LONGLONG>
		{
		public:
			//! �}�C�N���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
			static HiPerformanceCounter GetNowCount(bool UseRDTSCFlag = false)DXLIBEX_NOEXCEPT;
			//! �}�C�N���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
			static inline HiPerformanceCounter now(bool UseRDTSCFlag = false)DXLIBEX_NOEXCEPT { return GetNowCount(UseRDTSCFlag); }

			//! 1000�Ŋ�����Counter�Ƃ݂Ȃ��悤�ɂ���
			Counter CastToLowPerformance()const DXLIBEX_NOEXCEPT;

			HiPerformanceCounter()DXLIBEX_NOEXCEPT {}
			HiPerformanceCounter(const Counter_template<LONGLONG>& param)DXLIBEX_NOEXCEPT :Counter_template(param) {}
		protected:
			explicit HiPerformanceCounter(LONGLONG param)DXLIBEX_NOEXCEPT : Counter_template(param) {}
		};
	}
	namespace DxLibEx_Classes { 
		using nCounter::Counter;
		using nCounter::HiPerformanceCounter;
	}


	//----------�����n----------//

	//!�����n
	namespace DxRand
	{
		//! �������擾����
		//!@param[in] RandMax �Ԃ��ė���l�̍ő�l
		inline int GetRand(int RandMax)DXLIBEX_NOEXCEPT{ return DxLib::GetRand(RandMax); }
		//! �����̏����l��ݒ肷��
		inline int SRand(int Seed)DXLIBEX_NOEXCEPT{ return DxLib::SRand(Seed); }
	};


	//----------���O�n----------//

	//!���O�n
	namespace DxLog
	{
#ifndef DX_NON_LOG
		// �G���[�����֐�

		//! ���O�t�@�C��( Log.txt ) �ɕ�������o�͂���
		inline int ErrorLogAdd(const TCHAR *ErrorStr)DXLIBEX_NOEXCEPT{ return DxLib::ErrorLogAdd(ErrorStr); }
		template<typename... Args>
		//! �����t���� ���O�t�@�C��( Log.txt ) �ɕ�������o�͂���( ������ printf �Ɠ��� )
		inline int ErrorLogFmtAdd(const TCHAR *FormatString, Args&&... args){ return DxLib::ErrorLogFmtAdd(FormatString, std::forward<Args>(args)...); }
		//! ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɕt����^�u�̐�������₷
		inline int ErrorLogTabAdd(void)DXLIBEX_NOEXCEPT{ return DxLib::ErrorLogTabAdd(); }
		//! ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɕt����^�u�̐�������炷
		inline int ErrorLogTabSub(void)DXLIBEX_NOEXCEPT{ return DxLib::ErrorLogTabSub(); }
		//! ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɋN�����Ă���̎��Ԃ�t���邩�ǂ�����ݒ肷��( TRUE:�t����( �f�t�H���g)  FALSE:�t���Ȃ� )
		inline int SetUseTimeStampFlag(bool UseFlag)DXLIBEX_NOEXCEPT{ return DxLib::SetUseTimeStampFlag(UseFlag); }
		template<typename... Args>
		//! ErrorLogFmtAdd �Ɠ����@�\�̊֐�
		inline int AppLogAdd(const TCHAR *String, Args&&... args){ return DxLib::AppLogAdd(String, std::forward<Args>(args)...); }

		//! ���O�t�@�C��( Log.txt ) ���쐬���邩�ǂ�����ݒ肷��( TRUE:�쐬����( �f�t�H���g )  FALSE:�쐬���Ȃ� )�ADxLib_Init �̑O�ł̂ݎg�p�\�@
		inline int SetOutApplicationLogValidFlag(bool Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetOutApplicationLogValidFlag(Flag); }
		//! ���O�t�@�C��( Log.txt ) ��ۑ�����f�B���N�g���p�X��ݒ肷��
		inline int SetApplicationLogSaveDirectory(const TCHAR *DirectoryPath)DXLIBEX_NOEXCEPT{ return DxLib::SetApplicationLogSaveDirectory(DirectoryPath); }
		//! ���O�t�@�C�����ɓ��t�����邩�ǂ������Z�b�g����( TRUE:�t����  FALSE:�t���Ȃ�( �f�t�H���g ) )
		inline int SetUseDateNameLogFile(bool Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetUseDateNameLogFile(Flag); }

#ifndef DX_NON_PRINTF_DX

		// ���O�o�͋@�\�֐�

		//! printfDx �̌��ʂ���ʂɏo�͂��邩�ǂ�����ݒ肷��ATRUE:�o�͂��s��  FALSE:�o�͂��s��Ȃ�( printfDx �����s����Ɠ����� SetLogDrawOutFlag( TRUE ) ; ���Ă΂�܂� )
		inline int SetLogDrawOutFlag(bool DrawFlag)DXLIBEX_NOEXCEPT{ return DxLib::SetLogDrawOutFlag(DrawFlag); }
		//! printfDx �̌��ʂ���ʂɏo�͂��邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�o�͂��s��  FALSE:�o�͂��s��Ȃ� )
		inline int GetLogDrawFlag(void)DXLIBEX_NOEXCEPT{ return DxLib::GetLogDrawFlag(); }
		//! printfDx �̌��ʂ���ʂɏo�͂���ۂɎg�p����t�H���g�̃T�C�Y��ݒ肷��
		inline int SetLogFontSize(int Size)DXLIBEX_NOEXCEPT{ return DxLib::SetLogFontSize(Size); }

		// �ȈՉ�ʏo�͊֐�

		template<typename... Args>
		//! printf �Ɠ��������ŉ�ʂɕ������\�����邽�߂̊֐�
		inline int printfDx(const TCHAR *FormatString, Args&&... args){ return DxLib::printfDx(FormatString, std::forward<Args>(args)...); }
		//! printfDx �̌��ʂ����Z�b�g���邽�߂̊֐�
		inline int clsDx(void)DXLIBEX_NOEXCEPT{ return DxLib::clsDx(); }
#endif // DX_NON_PRINTF_DX

#endif // DX_NON_LOG
	}


	//----------�񓯊��ǂݍ��݊֌W----------//

	//!�񓯊��ǂݍ��݊֌W
	namespace DxAsyncLoad
	{
#ifndef DX_NON_ASYNCLOAD
		//! �ǂݍ��ݏ����n�̊֐��Ŕ񓯊��ǂݍ��݂��s�����ǂ�����ݒ肷��( �񓯊��ǂݍ��݂ɑΉ����Ă���֐��̂ݗL�� )
		//!@param[in] Flag: TRUE:�񓯊��ǂݍ��݂��s��  FALSE:�񓯊��ǂݍ��݂��s��Ȃ�( �f�t�H���g )
		inline int SetUseASyncLoadFlag(bool Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetUseASyncLoadFlag(Flag); }
		//! �n���h���̔񓯊��ǂݍ��݂��������Ă��邩�ǂ������擾����
		//!@return TRUE:�܂��������Ă��Ȃ�  FALSE:�������Ă���  -1:�G���[
		inline int CheckHandleASyncLoad(int Handle)DXLIBEX_NOEXCEPT{ return DxLib::CheckHandleASyncLoad(Handle); }
		//! �n���h���̔񓯊��ǂݍ��ݏ����̖߂�l���擾����( �񓯊��ǂݍ��ݒ��̏ꍇ�͈�O�̔񓯊��ǂݍ��ݏ����̖߂�l���Ԃ��Ă��܂� )
		inline int GetHandleASyncLoadResult(int Handle)DXLIBEX_NOEXCEPT{ return DxLib::GetHandleASyncLoadResult(Handle); }
		//! �񓯊��ǂݍ��ݒ��̏����̐����擾����
		inline int GetASyncLoadNum(void)DXLIBEX_NOEXCEPT{ return DxLib::GetASyncLoadNum(); }
#endif // DX_NON_ASYNCLOAD
	}


	//----------�n���h���֌W----------//

	//!�n���h���֌W
	namespace DxHandle
	{
		//!�n���h�����폜���ꂽ�Ƃ��Ɂ|�P���ݒ肳���ϐ���o�^����
		//!@attention DxLibEx�ɂ���ĊǗ�����Ă���n���h���Ɏg�p���Ă͂����Ȃ�
		inline int SetDeleteHandleFlag(int Handle, int *DeleteFlag)DXLIBEX_NOEXCEPT{ return DxLib::SetDeleteHandleFlag(Handle, DeleteFlag); }
	}


	//----------�}�E�X�֌W----------//

	//!XNA�݊��̃}�E�X���͂Ȃ�
	namespace nMouse
	{
		//!XNA�݊�
		enum class ButtonState : bool
		{
			//!The button is released.�i�{�^���͕�����Ă���j
			Released = true,
			//!The button is pressed.�i�{�^���͉�����Ă���j
			Pressed = false,
		};
		//!XNA�݊�
		//!�}�E�X�̌��݂̏�� (�}�E�X�̈ʒu�≟����Ă���{�^���Ȃ�)
		struct MouseState
		{
			MouseState()DXLIBEX_NOEXCEPT;

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
			MouseState(int x, int y, int scrollWheel, ButtonState leftButton, ButtonState middleButton, ButtonState rightButton, ButtonState xButton1, ButtonState xButton2)DXLIBEX_NOEXCEPT;

			bool operator !=(const MouseState& right)DXLIBEX_NOEXCEPT { return !(*this == right); }
			bool operator ==(const MouseState& right)DXLIBEX_NOEXCEPT;
			//! �}�E�X�̍��{�^���̏��
			ButtonState LeftButton;
			//! �}�E�X�̒����{�^���̏�ԁB
			ButtonState MiddleButton;
			//! �}�E�X�̉E�{�^���̏��
			ButtonState RightButton;
			//! �}�E�X�̃X�N���[�� �z�C�[���̗ݐϒl (�Q�[���J�n���_or�Ō��GetState(true)���Ăяo����Ă���)
			int ScrollWheelValue;
			//! �}�E�X �J�[�\���̐����ʒu 
			int X;
			//! XBUTTON1 �̏��
			ButtonState XButton1;
			//! XBUTTON2 �̏��
			ButtonState XButton2;
			//! �}�E�X �J�[�\���̐����ʒu
			int Y;
		};
		//! �����ꂽ�{�^���̏��
		struct MouseInputInfo
		{
			//! �}�E�X �J�[�\���̐����ʒu
			int X;
			//! �}�E�X �J�[�\���̐����ʒu
			int Y;
			//!�����ꂽ�{�^��( MOUSE_INPUT_LEFT �� )
			int Type;

			MouseInputInfo()DXLIBEX_NOEXCEPT;
			MouseInputInfo(int x, int y, int type)DXLIBEX_NOEXCEPT;
		};
		//! �}�E�X�֌W
		//! XNA�݊�+��
		class Mouse
		{
		public:
			//!�}�E�X�̌��݂̏�� (�}�E�X�̈ʒu�≟����Ă���{�^���Ȃ�) ���擾���܂��B
			//!@param ScrollWheelValueReset GetMouseWheelRotVol�̈���CounterReset�Ɠ���
			static MouseState GetState(bool ScrollWheelValueReset = false)DXLIBEX_NOEXCEPT;
			//!�E�B���h�E�̍��������Ƃ����A�}�E�X �J�[�\���̈ʒu��ݒ肵�܂��B
			static inline void SetPosition(int x, int y)DXLIBEX_NOEXCEPT { SetMousePoint(x, y); }

			//!�}�E�X�̃N���b�N�������܂Ƃ߂Ď擾����
			//!�Q�ƁFDxLib::GetMouseInputLog http://homepage2.nifty.com/natupaji/DxLib/function/dxfunc_input.html#R5N36
			//!@attention ������GetMouseInputLog��LogDelete��TRUE��n���ČĂяo���܂�
			static std::queue<MouseInputInfo> GetMouseInputLog();
		};


		//--------�ȉ�DxLib�̋@�B�ϊ�

		//! �}�E�X�|�C���^�̕\����Ԃ�ݒ肷��
		//!@param[in] DispFlag:�}�E�X�|�C���^��\�����邩�ǂ���( TRUE:�\������  FALSE:�\�����Ȃ� )
		inline int SetMouseDispFlag(bool DispFlag) DXLIBEX_NOEXCEPT { return DxLib::SetMouseDispFlag(DispFlag); }
		//! �}�E�X�|�C���^�̈ʒu���擾����
		inline int GetMousePoint(int *XBuf, int *YBuf) DXLIBEX_NOEXCEPT{ return DxLib::GetMousePoint(XBuf, YBuf); }
		//! �}�E�X�|�C���^�̈ʒu��ݒ肷��
		inline int SetMousePoint(int PointX, int PointY) DXLIBEX_NOEXCEPT{ return DxLib::SetMousePoint(PointX, PointY); }
#ifndef DX_NON_INPUT
		//! �}�E�X�̃{�^���̉�����Ԃ��擾����
		inline int GetMouseInput(void) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseInput(); }
		//! �����}�E�X�z�C�[���̉�]�ʂ��擾����
		inline int GetMouseWheelRotVol(bool CounterReset = true) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseWheelRotVol(CounterReset); }
		//! �����}�E�X�z�C�[���̉�]�ʂ��擾����
		inline int GetMouseHWheelRotVol(bool CounterReset = true) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseHWheelRotVol(CounterReset); }
		//! �����}�E�X�z�C�[���̉�]�ʂ��擾����( �߂�l�� float �^ )
		inline float GetMouseWheelRotVolF(bool CounterReset = true) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseWheelRotVolF(CounterReset); }
		//! �����}�E�X�z�C�[���̉�]�ʂ��擾����( �߂�l�� float �^ )
		inline float GetMouseHWheelRotVolF(int CounterReset = true) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseHWheelRotVolF(CounterReset); }
		//! �}�E�X�̃N���b�N������擾����
		//!@param[out] Button:�N���b�N���ꂽ�{�^��( MOUSE_INPUT_LEFT �� )���i�[����ϐ��̃A�h���X
		//!@param[out] ClickX:�N���b�N���ꂽ���̂w���W���i�[����ϐ��̃A�h���X
		//!@param[out] ClickY:�N���b�N���ꂽ���̂x���W���i�[����ϐ��̃A�h���X
		//!@param[out] LogDelete:�擾�����N���b�N����������O����폜���邩�ǂ���( TRUE:�폜����  FALSE:�폜���Ȃ��A�܂莟�ɂ��̊֐����Ă΂ꂽ�Ƃ��ɓ����l���擾���邱�ƂɂȂ� )
		//!@return  0:�N���b�N���擾�ł����@-1:�N���b�N��񂪖��������A�܂�O��̌Ăяo��( �܂��͋N��������ŏ��̌Ăяo�� )�̊ԂɈ�x���}�E�X�̃{�^�����N���b�N����Ȃ����� )
		inline int GetMouseInputLog(int *Button, int *ClickX, int *ClickY, bool LogDelete = true) DXLIBEX_NOEXCEPT{ return DxLib::GetMouseInputLog(Button, ClickX, ClickY, LogDelete); }
#endif // DX_NON_INPUT

	}
	namespace DxLibEx_Classes { 
		using nMouse::ButtonState;
		using nMouse::MouseState;
		using nMouse::MouseInputInfo;
		using nMouse::Mouse;
	}


	//----------�^�b�`�p�l�����͊֌W�֐�----------//

	//!�^�b�`�p�l�����͊֌W
	namespace Touch
	{
		//! �^�b�`����Ă��鐔���擾����
		inline int GetTouchInputNum(void)DXLIBEX_NOEXCEPT{ return DxLib::GetTouchInputNum(); }

		//! �^�b�`�̏����擾����
		inline int GetTouchInput(int InputNo, int *PositionX, int *PositionY, int *ID = NULL, int *Device = NULL)DXLIBEX_NOEXCEPT{ return DxLib::GetTouchInput(InputNo, PositionX, PositionY, ID, Device); }

		//! �X�g�b�N����Ă���^�b�`���̐����擾����
		inline int GetTouchInputLogNum(void)DXLIBEX_NOEXCEPT{ return DxLib::GetTouchInputLogNum(); }

		//! �X�g�b�N����Ă���^�b�`��񂩂��ԌÂ������ЂƂ擾����
		inline TOUCHINPUTDATA GetTouchInputLogOne(int PeekFlag = FALSE)DXLIBEX_NOEXCEPT{ return DxLib::GetTouchInputLogOne(PeekFlag); }

		//! �X�g�b�N����Ă���^�b�`��񂩂�Â����Ɏw�萔�o�b�t�@�Ɏ擾����( �߂�l  -1:�G���[  0�ȏ�:�擾�������̐� )
		inline int GetTouchInputLog(TOUCHINPUTDATA *TouchData, int GetNum, int PeekFlag = FALSE)DXLIBEX_NOEXCEPT{ return DxLib::GetTouchInputLog(TouchData, GetNum, PeekFlag); }
	}

	//----------�������m�یn�֐�----------//

	//!DxLib�̓��I�m�یn�֐����X�}�[�g�|�C���^�Ŏg��(���ݎg�p�s��)
	namespace DxMemory
	{
#if 0
		//�f�X�g���N�^�Ăяo���R�[�h��g��łȂ��̂Ŏg���܂���

		//----------Dx_Unique_Ptr----------//

		template<typename T>
		class Dx_Unique_Ptr
		{
			typedef Dx_Unique_Ptr<T> This_T;
		public:
			typedef T* pointer;//!���L���郊�\�[�X�̃|�C���^�^T*
			typedef T element_type;//!�v�f�^T

			//----------�������m�یn�֐�(New)
			//�P��I�u�W�F�N�g��

			template<typename... Args>
			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			static This_T NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args);
			template<typename... Args>
			static This_T New(Args&&... args){ return NewWithLog(__FILE__, __LINE__, std::forward<Args>(args)...); }

			//----------�R���X�g���N�^
		public:
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Unique_Ptr() DXLIBEX_NOEXCEPT{}
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Unique_Ptr(std::nullptr_t) DXLIBEX_NOEXCEPT{}
			//!other����*this�ɁA���L�������n����B
			Dx_Unique_Ptr(This_T&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)){}
		private:
			//!�|�C���^����̍\�z�֎~(�����p�R���X�g���N�^)
			explicit Dx_Unique_Ptr(pointer param, void* resource) DXLIBEX_NOEXCEPT : ptr(param, Deleter(resource)){}
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Unique_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Unique_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Unique_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			Dx_Unique_Ptr(Dx_Unique_Ptr<U>&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)) {}

			//----------operator=
		public:
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			This_T& operator=(std::nullptr_t) DXLIBEX_NOEXCEPT{ ptr = nullptr; return *this; }
			//!other����*this�ɁA���L�������n����B
			This_T& operator=(This_T&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); return *this; }
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Unique_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Unique_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Unique_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			This_T& operator=(Dx_Unique_Ptr<U>&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); return *this; }

			//----------���̑��̃����o�֐�

			//! ���\�[�X�̏��L�����������B
			//! *this���ێ����Ă��郊�\�[�X�̏��L�����������B���\�[�X���������̂ł͂Ȃ��A�������ӔC���������B
			//! ���̊֐����Ăяo�������ƁA���̃N���X�̃f�X�g���N�^�ł́A���ݕێ����Ă��郊�\�[�X��������Ȃ��Ȃ�B
			//!@post ���̊֐����Ăяo�������ƁAget()�����o�֐���nullptr��Ԃ��B
			//!@return �����������\�[�X��Ԃ��B
			pointer release() DXLIBEX_NOEXCEPT{ return ptr.release(); }

			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			void reset() DXLIBEX_NOEXCEPT{ ptr.reset(); }
			//!other����*this�ɁA���L�������n����B
			void reset(This_T&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); }

			//!���\�[�X���擾����B�ێ����Ă���|�C���^��Ԃ��B
			//!@attention ���\�[�X�̏��L����*this�������Ă���̂ŁA���̊֐��ɂ���ĕԂ��ꂽ�|�C���^�ɑ΂��āA���\�[�X��������Ă͂Ȃ�Ȃ��B
			pointer get() const DXLIBEX_NOEXCEPT{ return ptr.get(); }

			//!�L���ȃ��\�[�X�����L���Ă��邩�𔻒肷��B
			explicit operator bool() const DXLIBEX_NOEXCEPT{ return ptr.operator bool(); }

			//----------�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�

			//!�|�C���^���ԐڎQ�Ƃ���B
			//!�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�
			typename std::add_lvalue_reference<T>::type operator*() const DXLIBEX_NOEXCEPT { return *ptr; }

			//!�|�C���^��ʂ��ăI�u�W�F�N�g�ɃA�N�Z�X����B
			//!�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�
			pointer operator->() const DXLIBEX_NOEXCEPT{ return ptr.get(); }

		private:
			struct Deleter{
				void operator()(T* param_ptr) const DXLIBEX_NOEXCEPT{
					param_ptr->~T();
					operator delete(param_ptr, resource);
					DxLib::DxFree(param_ptr);
				}
				DXLIBEX_CONSTEXPR Deleter() DXLIBEX_NOEXCEPT :resource(nullptr) {}
				DXLIBEX_CONSTEXPR Deleter(void* param) DXLIBEX_NOEXCEPT :resource(param) {}
				void* resource;
			};

			std::unique_ptr<T, Deleter> ptr;
		};
		template<>
		class Dx_Unique_Ptr<void>
		{
			template<typename>struct DUMY : std::true_type {};
			template<typename... Args>
			Dx_Unique_Ptr(Args&&...) {
				static_assert(DUMY<Args>::value, "can't use void in Dx_Unique_Ptr.");
			}
		};
		template<typename T>
		class Dx_Unique_Ptr<T[]>
		{
			typedef Dx_Unique_Ptr<T[]> This_T;
		public:
			typedef T* pointer;//!���L���郊�\�[�X�̃|�C���^�^T*
			typedef T element_type;//!�v�f�^T

			//----------�������m�یn�֐�(New)
			//�z���

			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			//!@param[in] n    �z��̗v�f��
			static This_T NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);
			//!@param[in] n    �z��̗v�f��
			static This_T New(size_t n) { return NewWithLog(__FILE__, __LINE__, n); }
	#if 0
			//!�������̍Ċm�ۂ��s���i�z��ł̂݁j
			//!@attention �r���ŗ�O��������ꂽ�ꍇbace�͕K�������ɂȂ�܂�
			//!@param[in,out] bace ��ɂȂ�Dx_Unique_Ptr
			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			//!@param[in] n    �V�����z��̗v�f��
			static This_T ReallocWithLog(This_T& bace, const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);
			//!�������̍Ċm�ۂ��s���i�z��ł̂݁j
			//!@attention �r���ŗ�O��������ꂽ�ꍇbace�͕K�������ɂȂ�܂�
			//!@param[in,out] bace ��ɂȂ�Dx_Unique_Ptr
			//!@param[in] n    �V�����z��̗v�f��
			static This_T Realloc(This_T& bace, size_t n) { return ReallocWithLog(bace, __FILE__, __LINE__, n); }
	#endif


			//----------�R���X�g���N�^
		public:
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Unique_Ptr() DXLIBEX_NOEXCEPT {}
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Unique_Ptr(std::nullptr_t) DXLIBEX_NOEXCEPT {}
			//!other����*this�ɁA���L�������n����B
			Dx_Unique_Ptr(This_T&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)) {}
		private:
			//!�R�s�[�\�z�֎~�B(delete)
			Dx_Unique_Ptr(const This_T& other) DXLIBEX_NOEXCEPT;// = delete
			//!�|�C���^����̍\�z�֎~(�����p�R���X�g���N�^)
			explicit Dx_Unique_Ptr(pointer param) DXLIBEX_NOEXCEPT : ptr(param) {}

			//----------operator=
		public:
			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			This_T& operator=(std::nullptr_t) DXLIBEX_NOEXCEPT { ptr = nullptr; return *this; }
			//!other����*this�ɁA���L�������n����B
			This_T& operator=(This_T&& other) DXLIBEX_NOEXCEPT { ptr = std::move(other.ptr); return *this; }
		private:
			//!�R�s�[�֎~�B(delete)
			This_T& operator=(const This_T& other) DXLIBEX_NOEXCEPT;// = delete

			//----------���̑��̃����o�֐�

			//! ���\�[�X�̏��L�����������B
			//! *this���ێ����Ă��郊�\�[�X�̏��L�����������B���\�[�X���������̂ł͂Ȃ��A�������ӔC���������B
			//! ���̊֐����Ăяo�������ƁA���̃N���X�̃f�X�g���N�^�ł́A���ݕێ����Ă��郊�\�[�X��������Ȃ��Ȃ�B
			//!@post ���̊֐����Ăяo�������ƁAget()�����o�֐���nullptr��Ԃ��B
			//!@return �����������\�[�X��Ԃ��B
			pointer release() DXLIBEX_NOEXCEPT { return ptr.release(); }

			//!���L���������Ȃ��A���Dx_Unique_Ptr�I�u�W�F�N�g���\�z����B
			void reset() DXLIBEX_NOEXCEPT { ptr.reset(); }
			//!other����*this�ɁA���L�������n����B
			void reset(This_T&& other) DXLIBEX_NOEXCEPT { ptr = std::move(other.ptr); }

			//!���\�[�X���擾����B�ێ����Ă���|�C���^��Ԃ��B
			//!@attention ���\�[�X�̏��L����*this�������Ă���̂ŁA���̊֐��ɂ���ĕԂ��ꂽ�|�C���^�ɑ΂��āA���\�[�X��������Ă͂Ȃ�Ȃ��B
			pointer get() const DXLIBEX_NOEXCEPT { return ptr.get(); }

			//!�L���ȃ��\�[�X�����L���Ă��邩�𔻒肷��B
			explicit operator bool() const DXLIBEX_NOEXCEPT { return ptr.operator bool(); }

			//----------�z��ŌŗL�̃����o�֐�

			//!�C�ӂ̈ʒu�̗v�f�ɃA�N�Z�X����B
			//!�z��ŌŗL�̃����o�֐�
			T& operator[](size_t i) const { return ptr[i]; }

		private:
			struct Deleter {
				void operator()(T* param_ptr) const DXLIBEX_NOEXCEPT { DxLib::DxFree(param_ptr); }
			private:
				template<typename U>
				void operator()(U* param_ptr) const DXLIBEX_NOEXCEPT;// = delete
			};

			std::unique_ptr<T, Deleter> ptr;
		};
		template<typename T, size_t N>
		class Dx_Unique_Ptr<T[N]>{
			static_assert(N && !N, "can't use fixed size arrays in Dx_Unique_Ptr. you can use std::array<T, N> instead.");
		};
		//----------�񃁃��o�֐�
		
		template <typename T1, typename T2>
		bool operator==(const Dx_Unique_Ptr<T1>& a, const Dx_Unique_Ptr<T2>& b){ return a.get() == b.get(); }
		template <typename T>
		bool operator==(const Dx_Unique_Ptr<T>& x, nullptr_t) DXLIBEX_NOEXCEPT{ return !x; }
		template <typename T>
		bool operator==(nullptr_t, const Dx_Unique_Ptr<T>& x) DXLIBEX_NOEXCEPT{ return !x; }
		template <typename T1, typename T2>
		bool operator!=(const Dx_Unique_Ptr<T1>& a, const Dx_Unique_Ptr<T2>& b){ return a.get() != b.get(); }
		template <typename T>
		bool operator!=(const Dx_Unique_Ptr<T>& x, nullptr_t) DXLIBEX_NOEXCEPT{ return static_cast<bool>(x); }
		template <typename T>
		bool operator!=(nullptr_t, const Dx_Unique_Ptr<T>& x) DXLIBEX_NOEXCEPT{ return static_cast<bool>(x); }

		template<typename T, typename... Args, typename = typename std::enable_if<!std::is_array<T>::value>::type>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�P��I�u�W�F�N�g�Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		Dx_Unique_Ptr<T> MakeUniqueDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args);
		template<typename T, typename = typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0>::type>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�z��Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		Dx_Unique_Ptr<T> MakeUniqueDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);

		template<typename T, typename... Args, typename = typename std::enable_if<!std::is_array<T>::value>::type>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�P��I�u�W�F�N�g�Łj
		Dx_Unique_Ptr<T> MakeUniqueDx(Args&&... args) { return MakeUniqueDxWithLog<T>(__FILE__, __LINE__ ,std::forward<Args>(args)...); }
		template<typename T, typename = typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0>::type>
		//!Dx_Unique_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�z��Łj
		Dx_Unique_Ptr<T> MakeUniqueDx(size_t n) { return MakeUniqueDxWithLog<T>(__FILE__, __LINE__, n); }

		//----------Dx_Shared_Ptr----------//

		template<typename T>
		class Dx_Shared_Ptr
		{
			typedef Dx_Shared_Ptr<T> This_T;
		public:
			typedef T* pointer;//!���L���郊�\�[�X�̃|�C���^�^T*
			typedef T element_type;//!�v�f�^T

			//----------�������m�یn�֐�(New)
			//�P��I�u�W�F�N�g��

			template<typename... Args>
			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			static This_T NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args);
			template<typename... Args>
			static This_T New(Args&&... args){ return NewWithLog(__FILE__, __LINE__, std::forward<Args>(args)...); }

			//----------�R���X�g���N�^
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr() DXLIBEX_NOEXCEPT{}
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr(std::nullptr_t) DXLIBEX_NOEXCEPT{}
			//!other����*this�ɁA���L�������n����B
			Dx_Shared_Ptr(This_T&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)){}
		private:
			//!�|�C���^����̍\�z�֎~(�����p�R���X�g���N�^)
			explicit Dx_Shared_Ptr(pointer param) DXLIBEX_NOEXCEPT : ptr(param){}
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Shared_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Shared_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Shared_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			Dx_Shared_Ptr(Dx_Shared_Ptr<U>&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)){}

			//----------operator=
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			This_T& operator=(std::nullptr_t) DXLIBEX_NOEXCEPT{ reset(); return *this; }
			//!other����*this�ɁA���L�������n����B
			This_T& operator=(This_T&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); return *this; }
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Shared_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Shared_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Shared_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			This_T& operator=(Dx_Shared_Ptr<U>&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); return *this; }

			//----------���̑��̃����o�֐�

			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			void reset() DXLIBEX_NOEXCEPT{ ptr.reset(); }
			//!other����*this�ɁA���L�������n����B
			void reset(This_T&& other) DXLIBEX_NOEXCEPT{ ptr = std::move(other.ptr); }

			//!���\�[�X���擾����B�ێ����Ă���|�C���^��Ԃ��B
			//!@attention ���\�[�X�̏��L����*this�������Ă���̂ŁA���̊֐��ɂ���ĕԂ��ꂽ�|�C���^�ɑ΂��āA���\�[�X��������Ă͂Ȃ�Ȃ��B
			pointer get() const DXLIBEX_NOEXCEPT{ return ptr.get(); }

			//!�L���ȃ��\�[�X�����L���Ă��邩�𔻒肷��B
			explicit operator bool() const DXLIBEX_NOEXCEPT{ return ptr.operator bool(); }

			//----------�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�

			//!�|�C���^���ԐڎQ�Ƃ���B
			//!�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�
			typename std::add_lvalue_reference<T>::type operator*() const DXLIBEX_NOEXCEPT { return *ptr; }

			//!�|�C���^��ʂ��ăI�u�W�F�N�g�ɃA�N�Z�X����B
			//!�P��I�u�W�F�N�g�ŌŗL�̃����o�֐�
			pointer operator->() const DXLIBEX_NOEXCEPT{ return ptr.get(); }

		private:
			struct Deleter{
				void operator()(T* param_ptr) const DXLIBEX_NOEXCEPT{ DxLib::DxFree(param_ptr); }
			};

			std::shared_ptr<T, Deleter> ptr;
		};
		template<>
		class Dx_Shared_Ptr<void>
		{
			typedef Dx_Shared_Ptr<void> This_T;
		public:
			typedef void* pointer;//!���L���郊�\�[�X�̃|�C���^�^T*
			typedef void element_type;//!�v�f�^T

			//----------�R���X�g���N�^
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr() DXLIBEX_NOEXCEPT : ptr(nullptr){}
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr(std::nullptr_t) DXLIBEX_NOEXCEPT : ptr(nullptr) {}
			//!other����*this�ɁA���L�������n����B
			Dx_Shared_Ptr(This_T&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)) {}
		private:
			//!�R�s�[�\�z�֎~�B(delete)
			Dx_Shared_Ptr(const This_T& other) DXLIBEX_NOEXCEPT;// = delete
			//!�|�C���^����̍\�z�֎~(�����p�R���X�g���N�^)
			explicit Dx_Shared_Ptr(pointer param) DXLIBEX_NOEXCEPT : ptr(param) {}
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Shared_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Shared_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Shared_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			Dx_Shared_Ptr(Dx_Shared_Ptr<U>&& other) DXLIBEX_NOEXCEPT : ptr(other.release()) {}

			//----------operator=
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			This_T& operator=(std::nullptr_t) DXLIBEX_NOEXCEPT { reset(); return *this; }
			//!other����*this�ɁA���L�������n����B
			This_T& operator=(This_T&& other) DXLIBEX_NOEXCEPT { reset(std::move(other)); return *this; }
		private:
			//!�R�s�[�֎~�B(delete)
			This_T& operator=(const This_T& other) DXLIBEX_NOEXCEPT;// = delete
		public:
			template <typename U, typename = typename std::enable_if<!std::is_array<U>::value && std::is_convertible<typename Dx_Shared_Ptr<U>::pointer, pointer>::value>::type>
			//!�ϊ��\�ȃ|�C���^�^������Dx_Shared_Ptr�I�u�W�F�N�g����̕ϊ��B
			//!�ȉ��̏����𖞂����Ȃ��ꍇ�A���̊֐��̓I�[�o�[���[�h�����̌�₩��O���F
			//!�@�EDx_Shared_Ptr<U>::pointer���Apointer�ɈÖٕϊ��\�Ȍ^�ł��邱�ƁB
			//!�@�EU���z��^�ł͂Ȃ����ƁB
			This_T& operator=(Dx_Shared_Ptr<U>&& other) DXLIBEX_NOEXCEPT { reset(); ptr = other.release(); return *this; }

			//----------���̑��̃����o�֐�

			//! ���\�[�X�̏��L�����������B
			//! *this���ێ����Ă��郊�\�[�X�̏��L�����������B���\�[�X���������̂ł͂Ȃ��A�������ӔC���������B
			//! ���̊֐����Ăяo�������ƁA���̃N���X�̃f�X�g���N�^�ł́A���ݕێ����Ă��郊�\�[�X��������Ȃ��Ȃ�B
			//!@post ���̊֐����Ăяo�������ƁAget()�����o�֐���nullptr��Ԃ��B
			//!@return �����������\�[�X��Ԃ��B
			pointer release() DXLIBEX_NOEXCEPT { auto temp = ptr; ptr = nullptr; return temp; }

			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			void reset() DXLIBEX_NOEXCEPT { DxLib::DxFree(ptr); ptr = nullptr; }
			//!other����*this�ɁA���L�������n����B
			void reset(This_T&& other) DXLIBEX_NOEXCEPT { if (this != &other) { reset(); ptr = other.release(); } }

			//!���\�[�X���擾����B�ێ����Ă���|�C���^��Ԃ��B
			//!@attention ���\�[�X�̏��L����*this�������Ă���̂ŁA���̊֐��ɂ���ĕԂ��ꂽ�|�C���^�ɑ΂��āA���\�[�X��������Ă͂Ȃ�Ȃ��B
			pointer get() const DXLIBEX_NOEXCEPT { return ptr; }

			//!�L���ȃ��\�[�X�����L���Ă��邩�𔻒肷��B
			explicit operator bool() const DXLIBEX_NOEXCEPT { return ptr != nullptr; }

			//----------�f�X�g���N�^

			~Dx_Shared_Ptr() DXLIBEX_NOEXCEPT { reset(); }
		private:
			void* ptr;
		};
		template<typename T>
		class Dx_Shared_Ptr<T[]>
		{
			typedef Dx_Shared_Ptr<T[]> This_T;
		public:
			typedef T* pointer;//!���L���郊�\�[�X�̃|�C���^�^T*
			typedef T element_type;//!�v�f�^T

			//----------�������m�یn�֐�(New)
			//�z���

			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			//!@param[in] n    �z��̗v�f��
			static This_T NewWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);
			//!@param[in] n    �z��̗v�f��
			static This_T New(size_t n) { return NewWithLog(__FILE__, __LINE__, n); }
	#if 0
			//!�������̍Ċm�ۂ��s���i�z��ł̂݁j
			//!@attention �r���ŗ�O��������ꂽ�ꍇbace�͕K�������ɂȂ�܂�
			//!@param[in,out] bace ��ɂȂ�Dx_Shared_Ptr
			//!@param[in] File DxAlloc�̈���File�Ɠ���
			//!@param[in] Line DxAlloc�̈���Line�Ɠ���
			//!@param[in] n    �V�����z��̗v�f��
			static This_T ReallocWithLog(This_T& bace, const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);
			//!�������̍Ċm�ۂ��s���i�z��ł̂݁j
			//!@attention �r���ŗ�O��������ꂽ�ꍇbace�͕K�������ɂȂ�܂�
			//!@param[in,out] bace ��ɂȂ�Dx_Shared_Ptr
			//!@param[in] n    �V�����z��̗v�f��
			static This_T Realloc(This_T& bace, size_t n) { return ReallocWithLog(bace, __FILE__, __LINE__, n); }
	#endif


			//----------�R���X�g���N�^
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr() DXLIBEX_NOEXCEPT {}
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			DXLIBEX_CONSTEXPR Dx_Shared_Ptr(std::nullptr_t) DXLIBEX_NOEXCEPT {}
			//!other����*this�ɁA���L�������n����B
			Dx_Shared_Ptr(This_T&& other) DXLIBEX_NOEXCEPT : ptr(std::move(other.ptr)) {}
		private:
			//!�R�s�[�\�z�֎~�B(delete)
			Dx_Shared_Ptr(const This_T& other) DXLIBEX_NOEXCEPT;// = delete
			//!�|�C���^����̍\�z�֎~(�����p�R���X�g���N�^)
			explicit Dx_Shared_Ptr(pointer param) DXLIBEX_NOEXCEPT : ptr(param) {}

			//----------operator=
		public:
			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			This_T& operator=(std::nullptr_t) DXLIBEX_NOEXCEPT { ptr = nullptr; return *this; }
			//!other����*this�ɁA���L�������n����B
			This_T& operator=(This_T&& other) DXLIBEX_NOEXCEPT { ptr = std::move(other.ptr); return *this; }
		private:
			//!�R�s�[�֎~�B(delete)
			This_T& operator=(const This_T& other) DXLIBEX_NOEXCEPT;// = delete

			//----------���̑��̃����o�֐�

			//! ���\�[�X�̏��L�����������B
			//! *this���ێ����Ă��郊�\�[�X�̏��L�����������B���\�[�X���������̂ł͂Ȃ��A�������ӔC���������B
			//! ���̊֐����Ăяo�������ƁA���̃N���X�̃f�X�g���N�^�ł́A���ݕێ����Ă��郊�\�[�X��������Ȃ��Ȃ�B
			//!@post ���̊֐����Ăяo�������ƁAget()�����o�֐���nullptr��Ԃ��B
			//!@return �����������\�[�X��Ԃ��B
			pointer release() DXLIBEX_NOEXCEPT { return ptr.release(); }

			//!���L���������Ȃ��A���Dx_Shared_Ptr�I�u�W�F�N�g���\�z����B
			void reset() DXLIBEX_NOEXCEPT { ptr.reset(); }
			//!other����*this�ɁA���L�������n����B
			void reset(This_T&& other) DXLIBEX_NOEXCEPT { ptr = std::move(other.ptr); }

			//!���\�[�X���擾����B�ێ����Ă���|�C���^��Ԃ��B
			//!@attention ���\�[�X�̏��L����*this�������Ă���̂ŁA���̊֐��ɂ���ĕԂ��ꂽ�|�C���^�ɑ΂��āA���\�[�X��������Ă͂Ȃ�Ȃ��B
			pointer get() const DXLIBEX_NOEXCEPT { return ptr.get(); }

			//!�L���ȃ��\�[�X�����L���Ă��邩�𔻒肷��B
			explicit operator bool() const DXLIBEX_NOEXCEPT { return ptr.operator bool(); }

			//----------�z��ŌŗL�̃����o�֐�

			//!�C�ӂ̈ʒu�̗v�f�ɃA�N�Z�X����B
			//!�z��ŌŗL�̃����o�֐�
			T& operator[](size_t i) const { return ptr[i]; }

		private:
			struct Deleter {
				void operator()(T* param_ptr) const DXLIBEX_NOEXCEPT { DxLib::DxFree(param_ptr); }
			private:
				template<typename U>
				void operator()(U* param_ptr) const DXLIBEX_NOEXCEPT;// = delete
			};

			std::shared_ptr<T, Deleter> ptr;
		};
		template<typename T, size_t N>
		class Dx_Shared_Ptr<T[N]>{
			static_assert(N && !N, "can't use fixed size arrays in Dx_Shared_Ptr. you can use std::array<T, N> instead.");
		};
		//----------�񃁃��o�֐�
		
		template <typename T1, typename T2>
		bool operator==(const Dx_Shared_Ptr<T1>& a, const Dx_Shared_Ptr<T2>& b){ return a.get() == b.get(); }
		template <typename T>
		bool operator==(const Dx_Shared_Ptr<T>& x, nullptr_t) DXLIBEX_NOEXCEPT{ return !x; }
		template <typename T>
		bool operator==(nullptr_t, const Dx_Shared_Ptr<T>& x) DXLIBEX_NOEXCEPT{ return !x; }
		template <typename T1, typename T2>
		bool operator!=(const Dx_Shared_Ptr<T1>& a, const Dx_Shared_Ptr<T2>& b){ return a.get() != b.get(); }
		template <typename T>
		bool operator!=(const Dx_Shared_Ptr<T>& x, nullptr_t) DXLIBEX_NOEXCEPT{ return static_cast<bool>(x); }
		template <typename T>
		bool operator!=(nullptr_t, const Dx_Shared_Ptr<T>& x) DXLIBEX_NOEXCEPT{ return static_cast<bool>(x); }

		template<typename T, typename... Args, typename = typename std::enable_if<!std::is_array<T>::value>::type>
		//!Dx_Shared_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�P��I�u�W�F�N�g�Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		Dx_Shared_Ptr<T> MakeSharedDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, Args&&... args);
		template<typename T, typename = typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0>::type>
		//!Dx_Shared_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�z��Łj
		//!@param[in] File DxAlloc�̈���File�Ɠ���
		//!@param[in] Line DxAlloc�̈���Line�Ɠ���
		Dx_Shared_Ptr<T> MakeSharedDxWithLog(const char *File/*__FILE__*/, int Line/*__LINE__*/, size_t n);

		template<typename T, typename... Args, typename = typename std::enable_if<!std::is_array<T>::value>::type>
		//!Dx_Shared_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�P��I�u�W�F�N�g�Łj
		Dx_Shared_Ptr<T> MakeSharedDx(Args&&... args) { return MakeSharedDxWithLog<T>(__FILE__, __LINE__ ,std::forward<Args>(args)...); }
		template<typename T, typename = typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0>::type>
		//!Dx_Shared_Ptr�I�u�W�F�N�g���\�z����w���p�֐��i�z��Łj
		Dx_Shared_Ptr<T> MakeSharedDx(size_t n) { return MakeSharedDxWithLog<T>(__FILE__, __LINE__, n); }

#endif
		//----------DxLib�̋@�B�ϊ�

		//! �w��̃T�C�Y�̃��������m�ۂ���
		//!@param[in] AllocSize �m�ۂ��郁�����̃T�C�Y( �P��:byte )
		//!@param[in] File DxAlloc���Ă񂾃\�[�X�t�@�C����( �f�o�b�O�p )
		//!@param[in] Line DxAlloc���Ă񂾃\�[�X�t�@�C�����̍s�ԍ�( �f�o�b�O�p )
		//!@return NULL:�������̊m�ێ��s   NULL�ȊO:�m�ۂ����������̈�̐擪�A�h���X )
		inline void* DxAlloc(size_t AllocSize, const char *File = NULL, int Line = -1)DXLIBEX_NOEXCEPT{ return DxLib::DxAlloc(AllocSize, File, Line); }
		//! �w��̃T�C�Y�̃��������m�ۂ��āA�O�Ŗ��߂�A��������ɂO�Ŗ��߂�ȊO�� DxAlloc �Ɠ���͓���
		inline void* DxCalloc(size_t AllocSize, const char *File = NULL, int Line = -1)DXLIBEX_NOEXCEPT{ return DxLib::DxCalloc(AllocSize, File, Line); }
		//! �������̍Ċm�ۂ��s��
		//!@param[in] Memory �Ċm�ۂ��s���������̈�̐擪�A�h���X( DxAlloc �̖߂�l )
		//!@param[in] File DxAlloc���Ă񂾃\�[�X�t�@�C����( �f�o�b�O�p )
		//!@param[in] Line DxAlloc���Ă񂾃\�[�X�t�@�C�����̍s�ԍ�( �f�o�b�O�p )
		//!@return NULL:�������̍Ċm�ێ��s�@NULL�ȊO:�Ċm�ۂ����V�����������̈�̐擪�A�h���X
		inline void* DxRealloc(void *Memory, size_t AllocSize, const char *File = NULL, int Line = -1)DXLIBEX_NOEXCEPT{ return DxLib::DxRealloc(Memory, AllocSize, File, Line); }
		//!@param[in] Memory ������郁�����̈�̐擪�A�h���X( DxAlloc �̖߂�l )
		inline void DxFree(void *Memory)DXLIBEX_NOEXCEPT{ return DxLib::DxFree(Memory); }
		//! �񋓑Ώۂɂ��郁�����̊m�ۗe�ʂ��Z�b�g����
		inline size_t DxSetAllocSizeTrap(size_t Size)DXLIBEX_NOEXCEPT{ return DxLib::DxSetAllocSizeTrap(Size); }
		//! �c�w���C�u�������Ń������m�ۂ��s���鎞�ɏ����o�͂��邩�ǂ������Z�b�g����
		inline int DxSetAllocPrintFlag(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::DxSetAllocPrintFlag(Flag); }
		//! DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����T�C�Y���擾����
		inline size_t DxGetAllocSize(void)DXLIBEX_NOEXCEPT{ return DxLib::DxGetAllocSize(); }
		//! DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����̐����擾����
		inline int DxGetAllocNum(void)DXLIBEX_NOEXCEPT{ return DxLib::DxGetAllocNum(); }
		//! DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁������񋓂���
		inline void DxDumpAlloc(void)DXLIBEX_NOEXCEPT{ return DxLib::DxDumpAlloc(); }
		//! DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����̏󋵂�`�悷��
		inline void DxDrawAlloc(int x, int y, int Width, int Height)DXLIBEX_NOEXCEPT{ return DxLib::DxDrawAlloc(x, y, Width, Height); }
		//! �m�ۂ�����������񂪔j�󂳂�Ă��Ȃ������ׂ�( -1:�j�󂠂�  0:�Ȃ� )
		inline int DxErrorCheckAlloc(void)DXLIBEX_NOEXCEPT{ return DxLib::DxErrorCheckAlloc(); }
		//! ���������m�ہA������s����x�Ɋm�ۂ��Ă��郁�����̗e�ʂ��o�͂��邩�ǂ����̃t���O���Z�b�g����
		inline int DxSetAllocSizeOutFlag(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::DxSetAllocSizeOutFlag(Flag); }
		//! �������̊m�ہA������s����x�Ɋm�ۂ��Ă��郁�����m�ۏ�񂪔j�����Ă��Ȃ������ׂ邩�ǂ����̃t���O���Z�b�g����
		inline int DxSetAllocMemoryErrorCheckFlag(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::DxSetAllocMemoryErrorCheckFlag(Flag); }

	}
#if 0
	namespace DxLibEx_Classes { 
		using DxMemory::Dx_Unique_Ptr;
		using DxMemory::MakeUniqueDx;
		using DxMemory::MakeUniqueDxWithLog;
		using DxMemory::Dx_Shared_Ptr;
		using DxMemory::MakeSharedDx;
		using DxMemory::MakeSharedDxWithLog;
	}
#endif


	//----------DxBaseFunc.cpp �֐��v���g�^�C�v�錾----------//

	//!�����R�[�h�֌W���[�e�B���e�B
	namespace DxChar
	{
		// �����R�[�h�֌W

		//! ������̕����R�[�h�`����ʂ̕����R�[�h�`���ɕϊ�����
		//!@param[in] SrcCharCodeFormat DX_CHARCODEFORMAT_SHIFTJIS ��
		//!@param[in] DestCharCodeFormat DX_CHARCODEFORMAT_SHIFTJIS ��
		inline int ConvertStringCharCodeFormat(int SrcCharCodeFormat, const void *SrcString, int DestCharCodeFormat, void *DestStringBuffer)DXLIBEX_NOEXCEPT{ return DxLib::ConvertStringCharCodeFormat(SrcCharCodeFormat, SrcString, DestCharCodeFormat, DestStringBuffer); }
		//! ������̈����̕����R�[�h�`����ݒ肷��( ������`��n�֐��Ƃ��̑��ꕔ�֐������� )( UNICODE�łł͖��� )
		//!@param[in] CharCodeFormat DX_CHARCODEFORMAT_SHIFTJIS ��
		inline int SetUseCharCodeFormat(int CharCodeFormat)DXLIBEX_NOEXCEPT{ return DxLib::SetUseCharCodeFormat(CharCodeFormat); }

		// ������֌W

		//! strcpy �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strcpyDx(TCHAR *Dest, const TCHAR *Src)DXLIBEX_NOEXCEPT{ return DxLib::strcpyDx(Dest, Src); }
		//! �ʒu�w��t�� strcpy�APos �̓R�s�[�J�n�ʒu�@( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strpcpyDx(TCHAR *Dest, const TCHAR *Src, int Pos)DXLIBEX_NOEXCEPT{ return DxLib::strpcpyDx(Dest, Src, Pos); }
		//! �ʒu�w��t�� strcpy�APos �̓R�s�[�J�n�ʒu( �S�p������ 1 ���� )�@( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strpcpy2Dx(TCHAR *Dest, const TCHAR *Src, int Pos)DXLIBEX_NOEXCEPT{ return DxLib::strpcpy2Dx(Dest, Src, Pos); }
		//! strncpy �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strncpyDx(TCHAR *Dest, const TCHAR *Src, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strncpyDx(Dest, Src, Num); }
		//! strncpy �� Num ��������( �S�p������ 1 ���� )�ɂȂ������́A�I�[�ɕK���k����������������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strncpy2Dx(TCHAR *Dest, const TCHAR *Src, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strncpy2Dx(Dest, Src, Num); }
		//! strncpy �̕�����̏I�[����̕������w���( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strrncpyDx(TCHAR *Dest, const TCHAR *Src, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strrncpyDx(Dest, Src, Num); }
		//! strncpy �̕�����̏I�[����̕�����( �S�p������ 1 ���� )�w��ŁA�I�[�ɕK���k����������������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strrncpy2Dx(TCHAR *Dest, const TCHAR *Src, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strrncpy2Dx(Dest, Src, Num); }
		//! strncpy �̃R�s�[�J�n�ʒu�w��ŁAPos �̓R�s�[�J�n�ʒu�ANum �͕�����( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strpncpyDx(TCHAR *Dest, const TCHAR *Src, int Pos, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strpncpyDx(Dest, Src, Pos, Num); }
		//! strncpy �̃R�s�[�J�n�ʒu�w��ŁAPos �̓R�s�[�J�n�ʒu( �S�p������ 1 ���� )�ANum �͕�����( �S�p������ 1 ���� )�A�I�[�ɕK���k����������������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strpncpy2Dx(TCHAR *Dest, const TCHAR *Src, int Pos, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strpncpy2Dx(Dest, Src, Pos, Num); }
		//! strcat �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline void strcatDx(TCHAR *Dest, const TCHAR *Src)DXLIBEX_NOEXCEPT{ return DxLib::strcatDx(Dest, Src); }
		//! strlen �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strlenDx(const TCHAR *Str)DXLIBEX_NOEXCEPT{ return DxLib::strlenDx(Str); }
		//! strlen �̖߂�l��������( �S�p������ 1 ���� )�ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strlen2Dx(const TCHAR *Str)DXLIBEX_NOEXCEPT{ return DxLib::strlen2Dx(Str); }
		//! strcmp �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strcmpDx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::strcmpDx(Str1, Str2); }
		//! stricmp �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int stricmpDx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::stricmpDx(Str1, Str2); }
		//! strncmp �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strncmpDx(const TCHAR *Str1, const TCHAR *Str2, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strncmpDx(Str1, Str2, Num); }
		//! strncmp �� Num ��������( �S�p������ 1 ���� )�ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strncmp2Dx(const TCHAR *Str1, const TCHAR *Str2, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strncmp2Dx(Str1, Str2, Num); }
		//! strncmp �̔�r�J�n�ʒu�w��ŁAPos �� Str1 �̔�r�J�n�ʒu�ANum ��������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strpncmpDx(const TCHAR *Str1, const TCHAR *Str2, int Pos, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strpncmpDx(Str1, Str2, Pos, Num); }
		//! strncmp �̔�r�J�n�ʒu�w��ŁAPos �� Str1 �̔�r�J�n�ʒu( �S�p������ 1 ���� )�ANum ��������( �S�p������ 1 ���� )( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strpncmp2Dx(const TCHAR *Str1, const TCHAR *Str2, int Pos, int Num)DXLIBEX_NOEXCEPT{ return DxLib::strpncmp2Dx(Str1, Str2, Pos, Num); }
		//! ������̎w��̈ʒu�̕����R�[�h���擾����APos �͎擾����ʒu�ACharNums �͕�������������ϐ��̃A�h���X�A�߂�l�͕����R�[�h( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline DWORD strgetchrDx(const TCHAR *Str, int Pos, int *CharNums = NULL)DXLIBEX_NOEXCEPT{ return DxLib::strgetchrDx(Str, Pos, CharNums); }
		//! ������̎w��̈ʒu�̕����R�[�h���擾����APos �͎擾����ʒu( �S�p������ 1 ���� )�ACharNums �͕�������������ϐ��̃A�h���X�A�߂�l�͕����R�[�h( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline DWORD strgetchr2Dx(const TCHAR *Str, int Pos, int *CharNums = NULL)DXLIBEX_NOEXCEPT{ return DxLib::strgetchr2Dx(Str, Pos, CharNums); }
		//! ������̎w��̈ʒu�ɕ����R�[�h���������ށAPos �͏������ވʒu�ACharCode �͕����R�[�h�A�߂�l�͏������񂾕�����( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strputchrDx(TCHAR *Str, int Pos, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strputchrDx(Str, Pos, CharCode); }
		//! ������̎w��̈ʒu�ɕ����R�[�h���������ށAPos �͏������ވʒu( �S�p������ 1 ���� )�ACharCode �͕����R�[�h�A�߂�l�͏������񂾕�����( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strputchr2Dx(TCHAR *Str, int Pos, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strputchr2Dx(Str, Pos, CharCode); }
		//! ������̎w��̈ʒu�̃A�h���X���擾����APos �͎擾����ʒu�@( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strposDx(const TCHAR *Str, int Pos)DXLIBEX_NOEXCEPT{ return DxLib::strposDx(Str, Pos); }
		//! ������̎w��̈ʒu�̃A�h���X���擾����APos �͎擾����ʒu( �S�p������ 1 ���� )�@( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strpos2Dx(const TCHAR *Str, int Pos)DXLIBEX_NOEXCEPT{ return DxLib::strpos2Dx(Str, Pos); }
		//! strstr �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strstrDx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::strstrDx(Str1, Str2); }
		//! strstr �̖߂�l��������擪����̕�����( �S�p������ 1 ���� ) �ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strstr2Dx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::strstr2Dx(Str1, Str2); }
		//! strrstr �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strrstrDx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::strrstrDx(Str1, Str2); }
		//! strrstr �̖߂�l��������擪����̕�����( �S�p������ 1 ���� ) �ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strrstr2Dx(const TCHAR *Str1, const TCHAR *Str2)DXLIBEX_NOEXCEPT{ return DxLib::strrstr2Dx(Str1, Str2); }
		//! strchr �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strchrDx(const TCHAR *Str, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strchrDx(Str, CharCode); }
		//! strchr �̖߂�l��������擪����̕�����( �S�p������ 1 ���� ) �ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strchr2Dx(const TCHAR *Str, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strchr2Dx(Str, CharCode); }
		//! strrchr �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline const TCHAR * strrchrDx(const TCHAR *Str, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strrchrDx(Str, CharCode); }
		//! strrchr �̖߂�l��������擪����̕�����( �S�p������ 1 ���� ) �ɂȂ�������( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int strrchr2Dx(const TCHAR *Str, DWORD CharCode)DXLIBEX_NOEXCEPT{ return DxLib::strrchr2Dx(Str, CharCode); }
		//! strupr �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline TCHAR * struprDx(TCHAR *Str)DXLIBEX_NOEXCEPT{ return DxLib::struprDx(Str); }
		//! vsprintf �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int vsprintfDx(TCHAR *Buffer, const TCHAR *FormatString, va_list Arg)DXLIBEX_NOEXCEPT{ return DxLib::vsprintfDx(Buffer, FormatString, Arg); }
		//! sprintf �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		template<typename... Args> inline int sprintfDx(TCHAR *Buffer, const TCHAR *FormatString, Args&&... args)DXLIBEX_NOEXCEPT{ return DxLib::sprfDx(Buffer, FormatString, std::forward<Args>(args)...); }
		//! itoa �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline TCHAR * itoaDx(int Value, TCHAR *Buffer, int Radix)DXLIBEX_NOEXCEPT{ return DxLib::itoaDx(Value, Buffer, Radix); }
		//! atoi �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int atoiDx(const TCHAR *Str)DXLIBEX_NOEXCEPT{ return DxLib::atoiDx(Str); }
		//! atof �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline double atofDx(const TCHAR *Str)DXLIBEX_NOEXCEPT{ return DxLib::atofDx(Str); }
		//! vsscanf �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		inline int vsscanfDx(const TCHAR *String, const TCHAR *FormatString, va_list Arg)DXLIBEX_NOEXCEPT{ return DxLib::vsscanfDx(String, FormatString, Arg); }
		//! sscanf �Ɠ����̋@�\( �}���`�o�C�g������łł͕����R�[�h�`���Ƃ��� SetUseCharCodeFormat �Őݒ肵���`�����g�p����܂� )
		template<typename... Args> inline int sscanfDx(const TCHAR *String, const TCHAR *FormatString, Args&&... args)DXLIBEX_NOEXCEPT{ return DxLib::sscanfDx(String, FormatString, std::forward<Args>(args)...); }

	}


	//----------�l�b�g���[�N----------//

	//!�l�b�g���[�N
	namespace Network
	{
#ifndef DX_NON_NETWORK
		// �ʐM�֌W

		//! �ʐM���b�Z�[�W�̏���������֐�
		inline int ProcessNetMessage(int RunReleaseProcess = FALSE)DXLIBEX_NOEXCEPT{ return DxLib::ProcessNetMessage(RunReleaseProcess); }

		//! �c�m�r�T�[�o�[���g���ăz�X�g������h�o�A�h���X���擾����( IPv4�� )
		inline int GetHostIPbyName(const TCHAR *HostName, IPDATA* IPDataBuf)DXLIBEX_NOEXCEPT{ return DxLib::GetHostIPbyName(HostName, IPDataBuf); }
		//! �c�m�r�T�[�o�[���g���ăz�X�g������h�o�A�h���X���擾����( IPv6�� )
		inline int GetHostIPbyName_IPv6(const TCHAR *HostName, IPDATA_IPv6 *IPDataBuf)DXLIBEX_NOEXCEPT{ return DxLib::GetHostIPbyName_IPv6(HostName, IPDataBuf); }
		//! ���}�V���ɐڑ�����( IPv4�� )
		inline int ConnectNetWork(IPDATA      IPData, int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::ConnectNetWork(IPData, Port); }
		//! ���}�V���ɐڑ�����( IPv6�� )
		inline int ConnectNetWork_IPv6(IPDATA_IPv6 IPData, int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::ConnectNetWork_IPv6(IPData, Port); }
		//! ���}�V���ɐڑ�����( IPv4�� )�A�񓯊���
		inline int ConnectNetWork_ASync(IPDATA      IPData, int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::ConnectNetWork_ASync(IPData, Port); }
		//! ���}�V���ɐڑ�����( IPv6�� )�A�񓯊���
		inline int ConnectNetWork_IPv6_ASync(IPDATA_IPv6 IPData, int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::ConnectNetWork_IPv6_ASync(IPData, Port); }
		//! �ڑ����󂯂����Ԃɂ���( IPv4�� )
		inline int PreparationListenNetWork(int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::PreparationListenNetWork(Port); }
		//! �ڑ����󂯂����Ԃɂ���( IPv6�� )
		inline int PreparationListenNetWork_IPv6(int Port = -1)DXLIBEX_NOEXCEPT{ return DxLib::PreparationListenNetWork_IPv6(Port); }
		//! �ڑ����󂯂���Ԃ̉���
		inline int StopListenNetWork(void)DXLIBEX_NOEXCEPT{ return DxLib::StopListenNetWork(); }
		//! �ڑ����I������
		inline int CloseNetWork(int NetHandle)DXLIBEX_NOEXCEPT{ return DxLib::CloseNetWork(NetHandle); }

		//! �ڑ���Ԃ��擾����
		inline int GetNetWorkAcceptState(int NetHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkAcceptState(NetHandle); }
		//! ��M�f�[�^�̗ʂ𓾂�
		inline int GetNetWorkDataLength(int NetHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkDataLength(NetHandle); }
		//! �����M�̃f�[�^�̗ʂ𓾂� 
		inline int GetNetWorkSendDataLength(int NetHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkSendDataLength(NetHandle); }
		//! �V���ɐڑ������ʐM����𓾂�
		inline int GetNewAcceptNetWork(void)DXLIBEX_NOEXCEPT{ return DxLib::GetNewAcceptNetWork(); }
		//! �ڑ���ؒf���ꂽ�ʐM����𓾂�
		inline int GetLostNetWork(void)DXLIBEX_NOEXCEPT{ return DxLib::GetLostNetWork(); }
		//! �ڑ���̂h�o�𓾂�( IPv4�� )
		inline int GetNetWorkIP(int NetHandle, IPDATA      *IpBuf)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkIP(NetHandle, IpBuf); }
		//! �ڑ���̂h�o�𓾂�( IPv6�� )
		inline int GetNetWorkIP_IPv6(int NetHandle, IPDATA_IPv6 *IpBuf)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkIP_IPv6(NetHandle, IpBuf); }
		//! �����̂h�o�𓾂�
		inline int GetMyIPAddress(IPDATA *IpBuf, int IpBufLength = 1, int *IpNum = NULL)DXLIBEX_NOEXCEPT{ return DxLib::GetMyIPAddress(IpBuf, IpBufLength, IpNum); }
		//! �ڑ��̃^�C���A�E�g�܂ł̎��Ԃ�ݒ肷��
		inline int SetConnectTimeOutWait(int Time)DXLIBEX_NOEXCEPT{ return DxLib::SetConnectTimeOutWait(Time); }
		//! �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������Z�b�g����
		inline int SetUseDXNetWorkProtocol(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetUseDXNetWorkProtocol(Flag); }
		//! �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������擾����
		inline int GetUseDXNetWorkProtocol(void)DXLIBEX_NOEXCEPT{ return DxLib::GetUseDXNetWorkProtocol(); }
		//! SetUseDXNetWorkProtocol �̕ʖ�
		inline int SetUseDXProtocol(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetUseDXProtocol(Flag); }
		//! GetUseDXNetWorkProtocol �̕ʖ�
		inline int GetUseDXProtocol(void)DXLIBEX_NOEXCEPT{ return DxLib::GetUseDXProtocol(); }
		//! �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���Z�b�g����
		inline int SetNetWorkCloseAfterLostFlag(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetNetWorkCloseAfterLostFlag(Flag); }
		//! �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���擾����
		inline int GetNetWorkCloseAfterLostFlag(void)DXLIBEX_NOEXCEPT{ return DxLib::GetNetWorkCloseAfterLostFlag(); }

		//! ��M�����f�[�^��ǂݍ���
		inline int NetWorkRecv(int NetHandle, void *Buffer, int Length)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkRecv(NetHandle, Buffer, Length); }
		//! ��M�����f�[�^��ǂݍ��ށA�ǂݍ��񂾃f�[�^�̓o�b�t�@����폜����Ȃ�
		inline int NetWorkRecvToPeek(int NetHandle, void *Buffer, int Length)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkRecvToPeek(NetHandle, Buffer, Length); }
		//! ��M�����f�[�^���N���A����
		inline int NetWorkRecvBufferClear(int NetHandle)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkRecvBufferClear(NetHandle); }
		//! �f�[�^�𑗐M����
		inline int NetWorkSend(int NetHandle, const void *Buffer, int Length)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkSend(NetHandle, Buffer, Length); }

		//! UDP���g�p�����ʐM���s���\�P�b�g�n���h�����쐬����( RecvPort �� -1 �ɂ���Ƒ��M��p�̃\�P�b�g�n���h���ɂȂ�܂� )
		inline int MakeUDPSocket(int RecvPort = -1)DXLIBEX_NOEXCEPT{ return DxLib::MakeUDPSocket(RecvPort); }
		//! UDP���g�p�����ʐM���s���\�P�b�g�n���h�����쐬����( RecvPort �� -1 �ɂ���Ƒ��M��p�̃\�P�b�g�n���h���ɂȂ�܂� )( IPv6�� )
		inline int MakeUDPSocket_IPv6(int RecvPort = -1)DXLIBEX_NOEXCEPT{ return DxLib::MakeUDPSocket_IPv6(RecvPort); }
		//! UDP���g�p�����ʐM���s���\�P�b�g�n���h�����폜����
		inline int DeleteUDPSocket(int NetUDPHandle)DXLIBEX_NOEXCEPT{ return DxLib::DeleteUDPSocket(NetUDPHandle); }
		//! UDP���g�p�����ʐM�Ŏw��̂h�o�Ƀf�[�^�𑗐M����ALength �͍ő�65507�ASendPort �� -1 �ɂ���� MakeUDPSocket �� RecvPort �œn�����|�[�g���g�p����܂�
		//!@preturn 0�ȏ�;���M�ł����f�[�^�T�C�Y  -1:�G���[  -2:���M�f�[�^���傫������  -3:���M�������ł��Ă��Ȃ�
		inline int NetWorkSendUDP(int NetUDPHandle, IPDATA SendIP, int SendPort, const void *Buffer, int Length)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkSendUDP(NetUDPHandle, SendIP, SendPort, Buffer, Length); }
		//! UDP���g�p�����ʐM�Ŏw��̂h�o�Ƀf�[�^�𑗐M����ALength �͍ő�65507�ASendPort �� -1 �ɂ���� MakeUDPSocket �� RecvPort �œn�����|�[�g���g�p����܂�( �߂�l  0�ȏ�;���M�ł����f�[�^�T�C�Y  -1:�G���[  -2:���M�f�[�^���傫������  -3:���M�������ł��Ă��Ȃ�  )( IPv6�� )
		inline int NetWorkSendUDP_IPv6(int NetUDPHandle, IPDATA_IPv6  SendIP, int SendPort, const void *Buffer, int Length)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkSendUDP_IPv6(NetUDPHandle, SendIP, SendPort, Buffer, Length); }
		//! UDP���g�p�����ʐM�Ńf�[�^����M����APeek �� TRUE ��n���Ǝ�M�ɐ������Ă��f�[�^����M�L���[����폜���܂���( �߂�l  0�ȏ�:��M�����f�[�^�̃T�C�Y  -1:�G���[  -2:�o�b�t�@�̃T�C�Y������Ȃ�  -3:��M�f�[�^���Ȃ� )
		inline int NetWorkRecvUDP(int NetUDPHandle, IPDATA* RecvIP, int *RecvPort, void *Buffer, int Length, int Peek)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkRecvUDP(NetUDPHandle, RecvIP, RecvPort, Buffer, Length, Peek); }
		//! UDP���g�p�����ʐM�Ńf�[�^����M����APeek �� TRUE ��n���Ǝ�M�ɐ������Ă��f�[�^����M�L���[����폜���܂���( �߂�l  0�ȏ�:��M�����f�[�^�̃T�C�Y  -1:�G���[  -2:�o�b�t�@�̃T�C�Y������Ȃ�  -3:��M�f�[�^���Ȃ� )( IPv6�� )
		inline int NetWorkRecvUDP_IPv6(int NetUDPHandle, IPDATA_IPv6 *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek)DXLIBEX_NOEXCEPT{ return DxLib::NetWorkRecvUDP_IPv6(NetUDPHandle, RecvIP, RecvPort, Buffer, Length, Peek); }
		//! UDP���g�p�����ʐM�ŐV���Ȏ�M�f�[�^�����݂��邩�ǂ����𒲂ׂ�( �߂�l  -1:�G���[  TRUE:��M�f�[�^����  FALSE:��M�f�[�^�Ȃ� )
		inline int CheckNetWorkRecvUDP(int NetUDPHandle)DXLIBEX_NOEXCEPT{ return DxLib::CheckNetWorkRecvUDP(NetUDPHandle); }
#endif
	}


	//----------�������͊֘A----------//

	//!�������͊֘A
	namespace InputString
	{
#ifndef DX_NON_INPUTSTRING
		// �����R�[�h�o�b�t�@����֌W

		//! �����R�[�h�o�b�t�@�ɕ����R�[�h���X�g�b�N����
		inline int StockInputChar(TCHAR CharCode )DXLIBEX_NOEXCEPT{ return DxLib::StockInputChar(CharCode); }
		//! �����R�[�h�o�b�t�@���N���A����
		inline int ClearInputCharBuf(void)DXLIBEX_NOEXCEPT{ return DxLib::ClearInputCharBuf(); }
		//! �����R�[�h�o�b�t�@�ɗ��܂����f�[�^���當���R�[�h����擾����
		inline TCHAR GetInputChar(int DeleteFlag )DXLIBEX_NOEXCEPT{ return DxLib::GetInputChar( DeleteFlag ); }
		//! �����R�[�h�o�b�t�@�ɗ��܂����f�[�^���當���R�[�h����擾����A�o�b�t�@�ɂȂɂ������R�[�h���Ȃ��ꍇ�͕����R�[�h���o�b�t�@�Ɉꕶ�������܂�܂ő҂�
		inline TCHAR GetInputCharWait(int DeleteFlag )DXLIBEX_NOEXCEPT{ return DxLib::GetInputCharWait( DeleteFlag ); }

		//! �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����
		inline int GetOneChar(TCHAR *CharBuffer, int DeleteFlag )DXLIBEX_NOEXCEPT{ return DxLib::GetOneChar(CharBuffer, DeleteFlag ); }
		//! �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����A�o�b�t�@�ɉ��������R�[�h���Ȃ��ꍇ�͕����R�[�h���o�b�t�@�Ɉꕶ�������܂�܂ő҂�
		inline int GetOneCharWait(TCHAR *CharBuffer, int DeleteFlag )DXLIBEX_NOEXCEPT{ return DxLib::GetOneCharWait(CharBuffer, DeleteFlag ); }
		//! �w��̕����R�[�h���A�X�L�[�R���g���[���R�[�h�����ׂ�
		inline int GetCtrlCodeCmp(TCHAR Char )DXLIBEX_NOEXCEPT{ return DxLib::GetCtrlCodeCmp( Char ); }
#endif // DX_NON_INPUTSTRING

#ifndef DX_NON_KEYEX
		//! ��ʏ�ɓ��͒��̕������`�悷��
		inline int DrawIMEInputString(int x, int y, int SelectStringNum )DXLIBEX_NOEXCEPT{ return DxLib::DrawIMEInputString(x, y, SelectStringNum ); }
		//! �h�l�d���g�p���邩�ǂ�����ݒ肷��
		inline int SetUseIMEFlag(int UseFlag )DXLIBEX_NOEXCEPT{ return DxLib::SetUseIMEFlag( UseFlag ); }
		//! �h�l�d�œ��͂ł���ő啶������ MakeKeyInput �̐ݒ�ɍ��킹�邩�ǂ������Z�b�g����( TRUE:���킹��  FALSE:���킹�Ȃ�(�f�t�H���g) )
		inline int SetInputStringMaxLengthIMESync(int Flag )DXLIBEX_NOEXCEPT{ return DxLib::SetInputStringMaxLengthIMESync( Flag ); }
		//! �h�l�d�ň�x�ɓ��͂ł���ő啶������ݒ肷��( 0:�����Ȃ�  1�ȏ�:�w��̕������Ő��� )
		inline int SetIMEInputStringMaxLength(int Length )DXLIBEX_NOEXCEPT{ return DxLib::SetIMEInputStringMaxLength( Length ); }
#endif // DX_NON_KEYEX

		//! �S�p�����A���p�������藐��钆����w��̕������ł̔��p�������𓾂�
		inline int GetStringPoint(const TCHAR *String, int Point )DXLIBEX_NOEXCEPT{ return DxLib::GetStringPoint( String, Point ); }
		//! �S�p�����A���p�������藐��钆����w��̔��p�������ł̕������𓾂�
		inline int GetStringPoint2(const TCHAR *String, int Point )DXLIBEX_NOEXCEPT{ return DxLib::GetStringPoint2( String, int Point ); }
		//! �S�p�����A���p�������藐��钆���當�������擾����
		inline int GetStringLength(const TCHAR *String )DXLIBEX_NOEXCEPT{ return DxLib::GetStringLength( String ); }

#ifndef DX_NON_FONT
		//! �`��\�̈�Ɏ��܂�悤�ɉ��s���Ȃ��當�����`��
		inline int DrawObtainsString(int x, int y, int AddY, const TCHAR *String, unsigned int StrColor, unsigned int StrEdgeColor = 0 , int FontHandle = -1 , unsigned int SelectBackColor = 0xffffffff , unsigned int SelectStrColor = 0 , unsigned int SelectStrEdgeColor = 0xffffffff , int SelectStart = -1 , int SelectEnd = -1 )DXLIBEX_NOEXCEPT{ return DxLib::DrawObtainsString(x, y, AddY, String, StrColor, StrEdgeColor, FontHandle , SelectBackColor, SelectStrColor, SelectStrEdgeColor, SelectStart, SelectEnd); }
		//! �`��\�̈�Ɏ��܂�悤�ɉ��s���Ȃ��當�����`��( �N���b�v�������P�� )
		inline int DrawObtainsString_CharClip(int x, int y, int AddY, const TCHAR *String, unsigned int StrColor, unsigned int StrEdgeColor = 0 , int FontHandle = -1 , unsigned int SelectBackColor = 0xffffffff , unsigned int SelectStrColor = 0 , unsigned int SelectStrEdgeColor = 0xffffffff , int SelectStart = -1 , int SelectEnd = -1 )DXLIBEX_NOEXCEPT{ return DxLib::DrawObtainsString_CharClip(x, y, AddY, String, StrColor, StrEdgeColor, FontHandl, SelectBackColor, SelectStrColor, SelectStrEdgeColor, SelectStart, SelectEnd); }
#endif // DX_NON_FONT
		//! �`��\�̈�Ɏ��܂�悤�ɕ␳�������Ȃ����`��`��
		inline int DrawObtainsBox(int x1, int y1, int x2, int y2, int AddY, unsigned int Color, int FillFlag )DXLIBEX_NOEXCEPT{ return DxLib::DrawObtainsBox(x1, y1, x2, y2, AddY, Color, FillFlag); }

#ifndef DX_NON_KEYEX

		//! ������̓��͎擾
		inline int InputStringToCustom(int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE )DXLIBEX_NOEXCEPT{ return DxLib::InputStringToCustom(x, y, BufLength, StrBuffer, CancelValidFlag, SingleCharOnlyFlag, NumCharOnlyFlag, DoubleCharOnlyFlag); }

		//! ������̓��͎擾
		inline int KeyInputString(int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag )DXLIBEX_NOEXCEPT{ return DxLib::KeyInputString(x, y, CharMaxLength, StrBuffer, CancelValidFlag ); }
		//! ���p������݂̂̓��͎擾
		inline int KeyInputSingleCharString(int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag )DXLIBEX_NOEXCEPT{ return DxLib::KeyInputSingleCharString(x, y, CharMaxLength, StrBuffer, CancelValidFlag ); }
		//! ���l�̓��͎擾
		inline int KeyInputNumber(int x, int y, int MaxNum, int MinNum, int CancelValidFlag )DXLIBEX_NOEXCEPT{ return DxLib::KeyInputNumber(x, y, MaxNum, MinNum, CancelValidFlag); }

		//! IME�̓��̓��[�h��������擾����
		inline int GetIMEInputModeStr(TCHAR *GetBuffer )DXLIBEX_NOEXCEPT{ return DxLib::GetIMEInputModeStr(GetBuffer); }
		//! IME�œ��͒��̕�����̏����擾����
		inline const IMEINPUTDATA* GetIMEInputData(	void )DXLIBEX_NOEXCEPT{ return DxLib::GetIMEInputData(); }
#if defined( DX_GCC_COMPILE ) || defined( __ANDROID )
		//! ( SetKeyInputStringColor2 �̋��֐� )InputString�֐��g�p���̕����̊e�F��ύX����
		inline int SetKeyInputStringColor(ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStrBack, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffffULL ,	ULONGLONG IMESelectWinF = 0xffffffffffffffffULL , ULONGLONG SelectStrBackColor = 0xffffffffffffffffULL , ULONGLONG SelectStrColor = 0xffffffffffffffffULL , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffffULL, ULONGLONG IMEStr = 0xffffffffffffffffULL, ULONGLONG IMEStrE = 0xffffffffffffffffULL  )DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputStringColor(NmlStr, NmlCur, IMEStrBack, IMECur, IMELine, IMESelectStr, IMEModeStr, NmlStrE, IMESelectStrE, IMEModeStrE, IMESelectWinE, IMESelectWinF, SelectStrBackColor, SelectStrColor, SelectStrEdgeColor, IMEStr, IMEStrE); }
#else // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
		//! ( SetKeyInputStringColor2 �̋��֐� )InputString�֐��g�p���̕����̊e�F��ύX���� 
		inline int SetKeyInputStringColor(ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStrBack, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff, ULONGLONG IMEStr = 0xffffffffffffffff, ULONGLONG IMEStrE = 0xffffffffffffffff )DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputStringColor(NmlStr, NmlCur, IMEStrBack, IMECur, IMELine, IMESelectStr, IMEModeStr, NmlStrE, IMESelectStrE, IMEModeStrE, IMESelectWinE, IMESelectWinF, SelectStrBackColor, SelectStrColor, SelectStrEdgeColor, IMEStr, IMEStrE); }
#endif // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
		//! InputString�֐��g�p���̕����̊e�F��ύX����
		//!@param[in] TargetColor DX_KEYINPSTRCOLOR_NORMAL_STR ��
		inline int SetKeyInputStringColor2(int TargetColor, unsigned int Color )DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputStringColor2(TargetColor, Color ); }
		//! SetKeyInputStringColor2 �Őݒ肵���F���f�t�H���g�ɖ߂�
		//!@param[in] TargetColor DX_KEYINPSTRCOLOR_NORMAL_STR ��
		inline int ResetKeyInputStringColor2(int TargetColor )DXLIBEX_NOEXCEPT{ return DxLib::ResetKeyInputStringColor2( TargetColor ); }
		//! �L�[���͕�����`��֘A�Ŏg�p����t�H���g�̃n���h����ύX����(-1�Ńf�t�H���g�̃t�H���g�n���h��)
		inline int SetKeyInputStringFont(int FontHandle )DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputStringFont( FontHandle ); }
		//! �L�[���͕����񏈗��̓��͕����������E�ɒB���Ă����ԂŁA������̖��[�����œ��͂��s��ꂽ�ꍇ�̏������[�h��ύX����
		//!@param[in] EndCharaMode DX_KEYINPSTR_ENDCHARAMODE_OVERWRITE ��
		inline int SetKeyInputStringEndCharaMode(int EndCharaMode )DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputStringEndCharaMode( EndCharaMode ); }
		//! ���̓��[�h�������`�悷��
		inline int DrawKeyInputModeString(int x, int y )DXLIBEX_NOEXCEPT{ return DxLib::DrawKeyInputModeString(x, y); }

		//! �L�[���̓f�[�^������
		inline int InitKeyInput(void)DXLIBEX_NOEXCEPT{ return DxLib::InitKeyInput(); }
		//! �V�����L�[���̓n���h���̍쐬
		inline int MakeKeyInput(int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE )DXLIBEX_NOEXCEPT{ return DxLib::MakeKeyInput(MaxStrLength, CancelValidFlag, SingleCharOnlyFlag, NumCharOnlyFlag, DoubleCharOnlyFlag); }
		//! �L�[���̓n���h���̍폜
		inline int DeleteKeyInput(int InputHandle )DXLIBEX_NOEXCEPT{ return DxLib::DeleteKeyInput(InputHandle ); }
		//! �w��̃L�[���̓n���h�����A�N�e�B�u�ɂ���( -1 ���w�肷��ƃA�N�e�B�u�ȃL�[���̓n���h����������ԂɂȂ�܂� )
		inline int SetActiveKeyInput(int InputHandle )DXLIBEX_NOEXCEPT{ return DxLib::SetActiveKeyInput(InputHandle ); }
		//! ���݃A�N�e�B�u�ɂȂ��Ă���L�[���̓n���h�����擾����
		inline int GetActiveKeyInput(void )DXLIBEX_NOEXCEPT{ return DxLib::GetActiveKeyInput(); }
		//! �L�[���̓n���h���̓��͂��I�����Ă��邩�擾����
		inline int CheckKeyInput(int InputHandle )DXLIBEX_NOEXCEPT{ return DxLib::CheckKeyInput(InputHandle ); }
		//! ���͂����������L�[���̓n���h�����ēx�ҏW��Ԃɖ߂�
		inline int ReStartKeyInput(int InputHandle )DXLIBEX_NOEXCEPT{ return DxLib::ReStartKeyInput(InputHandle ); }
		//! �L�[���̓n���h�������֐�
		inline int ProcessActKeyInput(void )DXLIBEX_NOEXCEPT{ return DxLib::ProcessActKeyInput(); }
		//! �L�[���̓n���h���̓��͒����̕`��
		inline int DrawKeyInputString(int x, int y, int InputHandle )DXLIBEX_NOEXCEPT{ return DxLib::DrawKeyInputString(x, y, InputHandle); }

		//! �L�[���̓n���h���̎w��̗̈��I����Ԃɂ���( SelectStart �� SelectEnd �� -1 ���w�肷��ƑI����Ԃ���������܂� )
		inline int SetKeyInputSelectArea(int  SelectStart, int  SelectEnd, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputSelectArea(SelectStart, SelectEnd, InputHandle); }
		//! �L�[���̓n���h���̑I��̈���擾����
		inline int GetKeyInputSelectArea(int *SelectStart, int *SelectEnd, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputSelectArea(SelectStart, SelectEnd, InputHandle); }
		//! �L�[���̓n���h���̕`��J�n�����ʒu��ݒ肷��
		inline int SetKeyInputDrawStartPos(int DrawStartPos, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputDrawStartPos(DrawStartPos, InputHandle); }
		//! �L�[���̓n���h���̕`��J�n�����ʒu���擾����
		inline int GetKeyInputDrawStartPos(int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputDrawStartPos(InputHandle); }
		//! �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
		inline int SetKeyInputCursorBrinkTime(int Time)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputCursorBrinkTime(Time); }
		//! �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
		inline int SetKeyInputCursorBrinkFlag(int Flag)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputCursorBrinkFlag(Flag); }
		//! �L�[���̓n���h���Ɏw��̕�������Z�b�g����
		inline int SetKeyInputString(const TCHAR *String, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputString(String, InputHandle); }
		//! �L�[���̓n���h���Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
		inline int SetKeyInputNumber(int Number, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputNumber(Number, InputHandle); }
		//! �L�[���̓n���h���Ɏw��̕��������_�l�𕶎��ɒu�������ăZ�b�g����
		inline int SetKeyInputNumberToFloat(float Number, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputNumberToFloat(Number, InputHandle); }
		//! �L�[���̓n���h���̓��͒��̕�������擾����
		inline int GetKeyInputString(TCHAR *StrBuffer, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputString(StrBuffer, InputHandle); }
		//! �L�[���̓n���h���̓��͒��̕�����𐮐��l�Ƃ��Ď擾����
		inline int GetKeyInputNumber(int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputNumber(InputHandle); }
		//! �L�[���̓n���h���̓��͒��̕�����𕂓������_�l�Ƃ��Ď擾����
		inline float GetKeyInputNumberToFloat(int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputNumberToFloat(InputHandle); }
		//! �L�[���̓n���h���̌��݂̃J�[�\���ʒu��ݒ肷��
		inline int SetKeyInputCursorPosition(int Position, int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::SetKeyInputCursorPosition(Position, InputHandle); }
		//! �L�[���̓n���h���̌��݂̃J�[�\���ʒu���擾����
		inline int GetKeyInputCursorPosition(int InputHandle)DXLIBEX_NOEXCEPT{ return DxLib::GetKeyInputCursorPosition(InputHandle); }

#endif // DX_NON_KEYEX
	}


	//----------�t�@�C������----------//

	//!�t�@�C������
	namespace DxFile
	{
		// �t�@�C���A�N�Z�X�֐�

		//! �t�@�C�����J��
		inline int FileRead_open(const TCHAR *FilePath, int ASync = FALSE)DXLIBEX_NOEXCEPT{ return DxLib::FileRead_open(FilePath, ASync); }
		//! �t�@�C���̃T�C�Y���擾����
		inline LONGLONG FileRead_size(const TCHAR *FilePath)DXLIBEX_NOEXCEPT{ return DxLib::FileRead_size(FilePath); }
		//! �t�@�C�������
		inline int FileRead_close(int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_close(FileHandle); }
		//! �t�@�C���|�C���^�̓ǂݍ��݈ʒu���擾����
		inline LONGLONG FileRead_tell(int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_tell(FileHandle); }
		//! �t�@�C���|�C���^�̓ǂݍ��݈ʒu��ύX����
		inline int FileRead_seek(int FileHandle, LONGLONG Offset, int Origin )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_seek(FileHandle , Offset , Origin); }
		//! �t�@�C������f�[�^��ǂݍ���
		inline int FileRead_read(void *Buffer, int ReadSize, int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_read(Buffer, ReadSize, FileHandle ); }
		//! �t�@�C���ǂݍ��݂��������Ă��邩�ǂ������擾����
		inline int FileRead_idle_chk(int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_idle_chk(FileHandle); }
		//! �t�@�C���̓ǂݍ��݈ʒu���I�[�ɒB���Ă��邩�ǂ������擾����
		inline int FileRead_eof(int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_eof(FileHandle); }
		//! �t�@�C�����當�����ǂݏo��
		inline int FileRead_gets(TCHAR *Buffer , int BufferSize , int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_gets(Buffer, BufferSize, FileHandle ); }
		//! �t�@�C������ꕶ���ǂݏo��
		inline TCHAR FileRead_getc(int FileHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_getc( FileHandle ); }
		//! �t�@�C�����珑�������ꂽ�f�[�^��ǂݏo��
		template<typename... Args> inline int FileRead_scanf(int FileHandle, const TCHAR *Format, Args&&... args)DXLIBEX_NOEXCEPT{ return DxLib::FileRead_scanf(FileHandle, Format, std::forward<Args>(args)...); }

#if 0
		static_assert(false, "�����܂�");
		//! �t�@�C�����n���h�����쐬����( �߂�l  -1:�G���[  -1�ȊO:�t�@�C�����n���h�� )
		inline DWORD_PTR FileRead_createInfo(		const TCHAR *ObjectPath )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_createInfo(		const TCHAR *ObjectPath ); }
		//! �t�@�C�����n���h�����̃t�@�C���̐����擾����
		inline int FileRead_getInfoNum(		DWORD_PTR FileInfoHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_getInfoNum(		DWORD_PTR FileInfoHandle ); }
		//! �t�@�C�����n���h�����̃t�@�C���̏����擾����
		inline int FileRead_getInfo(			int Index , FILEINFO *Buffer , DWORD_PTR FileInfoHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_getInfo(			int Index , FILEINFO *Buffer , DWORD_PTR FileInfoHandle ); }
		//! �t�@�C�����n���h�����폜����
		inline int FileRead_deleteInfo(		DWORD_PTR FileInfoHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_deleteInfo(		DWORD_PTR FileInfoHandle ); }

		//! �w��̃t�@�C�����̓t�H���_�̏����擾���A�t�@�C�������n���h�����쐬����( �߂�l: -1=�G���[  -1�ȊO=�t�@�C�������n���h�� )
		inline DWORD_PTR FileRead_findFirst(			const TCHAR *FilePath, FILEINFO *Buffer )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_findFirst(			const TCHAR *FilePath, FILEINFO *Buffer ); }
		//! �����̍��v���鎟�̃t�@�C���̏����擾����( �߂�l: -1=�G���[  0=���� )
		inline int FileRead_findNext(			DWORD_PTR FindHandle, FILEINFO *Buffer )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_findNext(			DWORD_PTR FindHandle, FILEINFO *Buffer ); }
		//! �t�@�C�������n���h�������( �߂�l: -1=�G���[  0=���� )
		inline int FileRead_findClose(			DWORD_PTR FindHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_findClose(			DWORD_PTR FindHandle ); }

		//! �w��̃t�@�C���̓��e��S�ă������ɓǂݍ��݁A���̏��̃A�N�Z�X�ɕK�v�ȃn���h����Ԃ�( �߂�l  -1:�G���[  -1�ȊO:�n���h�� )�A�g���I�������n���h���� FileRead_fullyLoad_delete �ō폜����K�v������܂�
		inline int FileRead_fullyLoad(			const TCHAR *FilePath )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_fullyLoad(			const TCHAR *FilePath ); }
		//! FileRead_fullyLoad �œǂݍ��񂾃t�@�C���̃n���h�����폜����
		inline int FileRead_fullyLoad_delete(	int FLoadHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_fullyLoad_delete(	int FLoadHandle ); }
		//! FileRead_fullyLoad �œǂݍ��񂾃t�@�C���̓��e���i�[�����������A�h���X���擾����
		inline const void* FileRead_fullyLoad_getImage( int FLoadHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_fullyLoad_getImage( int FLoadHandle ); }
		//! FileRead_fullyLoad �œǂݍ��񂾃t�@�C���̃T�C�Y���擾����
		inline LONGLONG FileRead_fullyLoad_getSize(	int FLoadHandle )DXLIBEX_NOEXCEPT{ return DxLib::FileRead_fullyLoad_getSize(	int FLoadHandle ); }

		// �ݒ�֌W�֐�

		//! �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐����f�t�H���g�̂��̂����ׂ�( TRUE:�f�t�H���g�̂���  FALSE:�f�t�H���g�ł͂Ȃ� )
		inline int GetStreamFunctionDefault(	void )DXLIBEX_NOEXCEPT{ return DxLib::GetStreamFunctionDefault(	void ); }
		//! �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐���ύX����
		inline int ChangeStreamFunction(		const STREAMDATASHREDTYPE2  *StreamThread  )DXLIBEX_NOEXCEPT{ return DxLib::ChangeStreamFunction(		const STREAMDATASHREDTYPE2  *StreamThread  ); }
		//! �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐���ύX����( wchar_t �g�p�� )
		inline int ChangeStreamFunctionW(		const STREAMDATASHREDTYPE2W *StreamThreadW )DXLIBEX_NOEXCEPT{ return DxLib::ChangeStreamFunctionW(		const STREAMDATASHREDTYPE2W *StreamThreadW ); }

		// �⏕�֌W�֐�

		//! �t���p�X�ł͂Ȃ��p�X��������t���p�X�ɕϊ�����( CurrentDir �̓t���p�X�ł���K�v������(����Ɂw\�x�������Ă������Ă��ǂ�) )( CurrentDir �� NULL �̏ꍇ�͌��݂̃J�����g�f�B���N�g�����g�p���� )
		inline int ConvertFullPath( const TCHAR *Src, TCHAR *Dest, const TCHAR *CurrentDir = NULL )DXLIBEX_NOEXCEPT{ return DxLib::ConvertFullPath( const TCHAR *Src, TCHAR *Dest, const TCHAR *CurrentDir = NULL ); }
#endif
	}

	//----------2D�O���t�B�b�N----------//
#if 0
	//�I�[�o�[�w�b�h�����Ȃ�Ver
	//�������R�s�[���ł��Ȃ�
	class Texture2D_Unique : public Unique_Handle_Bace<Texture2D_Unique>
	{
	public:
		void release() {
			DeleteSoundMem(GetHandle());
			//handle = -1;
		}

		static Texture2D_Unique LoadGraph(const TCHAR *FileName, int NotUse3DFlag = FALSE) {
			return DxLib::LoadGraph(FileName, NotUse3DFlag);
		}

	private:
		typedef Unique_Handle_Bace<Texture2D_Unique> Parent_T;
	public:
		Texture2D_Unique()
			: Unique_Handle_Bace()
		{}

		//���L���̏��n
		Texture2D_Unique(Texture2D_Unique&& other)
			: Unique_Handle_Bace(std::move(other))
		{}

		//���L���̏��n
		Texture2D_Unique& operator=(Texture2D_Unique&& other)
		{
			Parent_T::operator=(std::move(other));
			return *this;
		}

	private:
		//�ԈႦ�đ��̎�ނ̃n���h���������Ȃ��悤��private�ɂ��Ă���
		Texture2D_Unique(int param_handle)
			: Unique_Handle_Bace(param_handle)
		{}
	};
	class Texture2D
	{
	public:
		void release() {
			p_handle.reset();
		}

		static Texture2D LoadSoundMem(const TCHAR *FileName, int BufferNum = 3, int UnionHandle = -1) {
			return Texture2D_Unique::LoadSoundMem(FileName, BufferNum, UnionHandle);
		}

		static int PlaySoundMem(const Texture2D& SoundHandle, int PlayType, int TopPositionFlag = TRUE) {
			if (SoundHandle.p_handle == nullptr){ return -1; }
			return Texture2D_Unique::PlaySoundMem(*SoundHandle.p_handle, PlayType, TopPositionFlag);
		}

		Texture2D(Texture2D_Unique&& handle)
			: p_handle(std::make_shared<Texture2D_Unique>(std::move(handle)))
		{}
		Texture2D(){}
	private:
		std::shared_ptr<Texture2D_Unique> p_handle;
	};
#endif
	//----------�T�E���h�֌W----------//

	//!�T�E���h�֌W
	namespace Sound
	{
		//�I�[�o�[�w�b�h�����Ȃ�Ver
		//�������R�s�[���ł��Ȃ�
		class SoundEffect_Unique : public impl::Unique_Handle_Bace<SoundEffect_Unique>
		{
		public:
			//!�T�E���h�n���h�����폜����
			inline void Delete(bool LogOutFlag = false) {
				DeleteSoundMem(GetHandle(), LogOutFlag);
				//handle = -1;
			}
			//!���̃I�u�W�F�N�g�𖳌������A���܂Ŏg���Ă����n���h����Ԃ�
			//!�����폜�������������
			inline int release(){ return ReleaseRun(); }

			//----------static�֐�----------//

			static SoundEffect_Unique LoadSoundMem(const TCHAR *FileName, int BufferNum = 3, int UnionHandle = -1) {
				return DxLib::LoadSoundMem(FileName, BufferNum, UnionHandle);
			}

			static int PlaySoundMem(const SoundEffect_Unique& SoundHandle, int PlayType, int TopPositionFlag = TRUE) {
				return DxLib::PlaySoundMem(SoundHandle.GetHandle(), PlayType, TopPositionFlag);
			}

		private:
			typedef Unique_Handle_Bace<SoundEffect_Unique> Parent_T;
		public:
			SoundEffect_Unique()
				: Unique_Handle_Bace()
			{}

			//���L���̏��n
			SoundEffect_Unique(SoundEffect_Unique&& other)
				: Unique_Handle_Bace(std::move(other))
			{}

			//���L���̏��n
			SoundEffect_Unique& operator=(SoundEffect_Unique&& other)
			{
				Parent_T::operator=(std::move(other));
				return *this;
			}

		private:
			//�ԈႦ�đ��̎�ނ̃n���h���������Ȃ��悤��private�ɂ��Ă���
			SoundEffect_Unique(int param_handle)
				: Unique_Handle_Bace(param_handle)
			{}
		};
		class SoundEffect
		{
		public:
			void Delete(bool LogOutFlag = false) {
				p_handle->Delete(LogOutFlag);
			}
			//!���̃I�u�W�F�N�g�𖳌�������
			//!�Ō�̈�������ꍇ�n���h���͎����I�ɍ폜�����
			void release_this() {
				p_handle.reset();
			}
			//!���̃I�u�W�F�N�g����ѓ����h�����̃I�u�W�F�N�g�𖳌������A���܂Ŏg���Ă����n���h����Ԃ�
			//!�����폜�������������
			int release_all() {
				return p_handle->release();
			}

			//----------static�֐�----------//

			static SoundEffect LoadSoundMem(const TCHAR *FileName, int BufferNum = 3, int UnionHandle = -1) {
				return SoundEffect_Unique::LoadSoundMem(FileName, BufferNum, UnionHandle);
			}

			static int PlaySoundMem(const SoundEffect& SoundHandle, int PlayType, int TopPositionFlag = TRUE) {
				if (SoundHandle.p_handle == nullptr){ return -1; }
				return SoundEffect_Unique::PlaySoundMem(*SoundHandle.p_handle, PlayType, TopPositionFlag);
			}

			SoundEffect(SoundEffect_Unique&& handle)
				: p_handle(std::make_shared<SoundEffect_Unique>(std::move(handle)))
			{}
			SoundEffect(){}
		private:
			std::shared_ptr<SoundEffect_Unique> p_handle;
		};
	}
	namespace DxLibEx_Classes {
		using Sound::SoundEffect;
		using Sound::SoundEffect_Unique;
	}


}


//�֐��̒�`
#include "DxLibEx_impl.h"
#endif
