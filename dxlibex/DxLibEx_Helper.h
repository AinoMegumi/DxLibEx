#ifndef DX_LIB_EX_HELPER_H_2015_0930_0626_256841632_
#define DX_LIB_EX_HELPER_H_2015_0930_0626_256841632_

//�����p�t�@�C���ł��B
//�J���҈ȊO�������̋@�\���g���̂͂����߂ł��܂���
#include <cassert>
#include "DxLibEx_Defines.h"

namespace DxLibEx{
//!�����p�̂��̂��W�܂閼�O��Ԃł��B�J���҈ȊO�������̋@�\���g���̂͂����߂ł��܂���B
namespace impl{

	template<typename T>
	//!�����p
	//!�J�E���^�n
	//!GetNowCount�̖߂�l������Đ��̂܂܎g�����Ƃ�h��
	class Counter_template
	{
	private:
		typedef Counter_template<T> This_T;
	public:
		//������public�֐���UI�ɒ�������̂Ŕj��I�ύX�͉\�Ȍ��������悤��

		Counter_template()DXLIBEX_NOEXCEPT : value(-1){}

		//! �����^�̒l���擾����
		inline const T& GetInt()const DXLIBEX_NOEXCEPT{ return count(); }
		//! �����^�̒l���擾����
		inline const T& count()const DXLIBEX_NOEXCEPT{ return value; }
		//! �����^�̒l���擾����
		explicit inline operator T()const DXLIBEX_NOEXCEPT{ return count(); }

		inline const This_T& operator+()const DXLIBEX_NOEXCEPT{ return *this; }
		inline This_T        operator-()const DXLIBEX_NOEXCEPT{ return This_T(-value); }

		inline This_T operator+(const T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return This_T(value + other); }
		inline This_T operator-(const T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return This_T(value - other); }
		inline friend This_T operator+(const T& other, const This_T& bace) DXLIBEX_NOEXCEPT{ assert(bace.value != -1); return This_T(other + bace.value); }
		inline friend This_T operator-(const T& other, const This_T& bace) DXLIBEX_NOEXCEPT{ assert(bace.value != -1); return This_T(other - bace.value); }
		inline This_T& operator+=(const T& other) DXLIBEX_NOEXCEPT{ assert(value != -1); value += other; return *this; }
		inline This_T& operator-=(const T& other) DXLIBEX_NOEXCEPT{ assert(value != -1); value -= other; return *this; }

		inline T operator-(const This_T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return value - other.value; }

		inline bool operator< (const This_T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return value <  other.value; }
		inline bool operator> (const This_T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return value >  other.value; }
		inline bool operator<=(const This_T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return value <= other.value; }
		inline bool operator>=(const This_T& other)const DXLIBEX_NOEXCEPT{ assert(value != -1); return value >= other.value; }

	protected:
		explicit Counter_template(T param)DXLIBEX_NOEXCEPT : value(param){}

		template<typename U>
		struct Cast : public Counter_template<U>{
			explicit Cast(const U& param) :Counter_template<U>(param){}
			//!Counter_template<T>����Counter_template<U>�ɃL���X�g����
			inline static Counter_template<U> Do(const U& value)DXLIBEX_NOEXCEPT
			{
				return Counter_template<U>(Cast<U>(value));
			}
		};
	private:
		T value;
	};


	template<typename Child>
	//!�����p
	class Unique_Handle_Bace
	{
	protected:
		typedef Unique_Handle_Bace<Child> Bace_T;
	private:
		//�R�s�[�֎~
		Unique_Handle_Bace(const Bace_T&);// = delete;
		Unique_Handle_Bace& operator=(const Bace_T&);// = delete;
	public:
		Unique_Handle_Bace()DXLIBEX_NOEXCEPT
			:handle(-1)
		{}

		//���L���̏��n
		Unique_Handle_Bace(Bace_T&& other)DXLIBEX_NOEXCEPT
			: handle(other.handle)
		{
			other.handle = -1;
			SetDeleteHandleFlag(handle, &handle);
		}
		//���L���̏��n
		Unique_Handle_Bace& operator=(Bace_T&& other)DXLIBEX_NOEXCEPT
		{
			if (this == &other) { return *this; }
			handle = other.handle;
			other.handle = -1;
			SetDeleteHandleFlag(handle, &handle);
			return *this;
		}

		~Unique_Handle_Bace() DXLIBEX_NOEXCEPT{
			//���\�[�X���
			static_cast<Child*>(this)->Delete();
		}
	protected:
		//�ԈႦ�đ��̎�ނ̃n���h���������Ȃ��悤��protected�ɂ��Ă���
		Unique_Handle_Bace(int param_handle)DXLIBEX_NOEXCEPT
			: handle(param_handle)
		{
			SetDeleteHandleFlag(handle, &handle);
		}

		//!���̃I�u�W�F�N�g�𖳌������A���܂Ŏg���Ă����n���h����Ԃ�
		//!�����폜�������������
		inline int ReleaseRun()DXLIBEX_NOEXCEPT{
			int temp = GetHandle();
			SetDeleteHandleFlag(handle, nullptr);
			handle = -1;
			return temp;
		}
		int GetHandle()const DXLIBEX_NOEXCEPT{ return handle; }
	private:
		int handle;
	};

}//namespace impl
}//namespace DxLibEx

#endif
