﻿/*=============================================================================
  Copyright (C) 2015-2016 DxLibEx project
  https://github.com/Nagarei/DxLibEx/

  Distributed under the Boost Software License, Version 1.0.
  (See http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef DXLE_INC_SOUND_HPP_
#define DXLE_INC_SOUND_HPP_

#include "dxlibex/config/no_min_max.h"
#include "DxLib.h"
#include <type_traits>
#include <utility>
#include <memory>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include "dxlibex/Helper.h"
#include "dxlibex/config/defines.h"
#include "dxlibex/thread.hpp"

//----------2Dグラフィック----------//

namespace dxle
{
	//! サウンド
	namespace sound
	{
		class sound final : public impl::Unique_HandledObject_Bace < sound >
		{
		public:
			DXLE_CONSTEXPR sound()DXLE_NOEXCEPT_OR_NOTHROW = default;
			sound(const sound& other) = delete;
			DXLE_CONSTEXPR sound(sound&& other)DXLE_NOEXCEPT_OR_NOTHROW : Unique_HandledObject_Bace(std::move(other)){}

			sound& operator=(const sound& other) = delete;
			sound& operator=(sound&& other) DXLE_NOEXCEPT_OR_NOTHROW{ Unique_HandledObject_Bace<sound>::operator=(std::move(other)); return *this; }
				
			//!\~japanese サウンドを削除する
			//!\~english  Delete this sound data
			inline void delete_this(bool LogOutFlag = false) { DxLib::DeleteSoundMem(GetHandle(), LogOutFlag); }
			
			//! 同じサウンドデータを使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS タイプのサウンドハンドルのみ可能 )
			sound DuplicateSoundMem(int BufferNum = 3)const DXLE_NOEXCEPT_OR_NOTHROW{ return DxLib::DuplicateSoundMem(GetHandle(), BufferNum); }


			//生成
			extern	int			LoadSoundMem2(const TCHAR *FileName1, const TCHAR *FileName2);											// 前奏部とループ部に分かれたサウンドファイルを読み込みサウンドハンドルを作成する
			extern	int			LoadBGM(const TCHAR *FileName);																	// 主にＢＧＭを読み込みサウンドハンドルを作成するのに適した関数

			extern	int			LoadSoundMemBase(const TCHAR *FileName, int BufferNum, int UnionHandle = -1);						// サウンドファイルからサウンドハンドルを作成する
			extern	int			LoadSoundMem(const TCHAR *FileName, int BufferNum = 3, int UnionHandle = -1);						// LoadSoundMemBase の別名関数
			extern	int			DuplicateSoundMem(int SrcSoundHandle, int BufferNum = 3);													// 同じサウンドデータを使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS タイプのサウンドハンドルのみ可能 )

			extern	int			LoadSoundMemByMemImageBase(const void *FileImage, int FileImageSize, int BufferNum, int UnionHandle = -1);			// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
			extern	int			LoadSoundMemByMemImage(const void *FileImage, int FileImageSize, int UnionHandle = -1);			// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する( バッファ数指定無し )
			extern	int			LoadSoundMemByMemImage2(const void *WaveImage, int WaveImageSize, const WAVEFORMATEX *WaveFormat, int WaveHeaderSize);	// メモリ上に展開されたＰＣＭデータからサウンドハンドルを作成する
			extern	int			LoadSoundMem2ByMemImage(const void *FileImage1, int FileImageSize1, const void *FileImage2, int FileImageSize2);	// 前奏部とループ部に分かれた二つのメモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
			extern	int			LoadSoundMemFromSoftSound(int SoftSoundHandle, int BufferNum = 3);													// ソフトウエアサウンドハンドルが持つサウンドデータからサウンドハンドルを作成する

			//削除

			//!\~japanese サウンドを削除する
			//!\~english  Delete this sound data
			int	DeleteSoundMem(int LogOutFlag = FALSE) { return DxLib::DeleteSoundMem(GetHandle(), LogOutFlag); }

			//操作
			extern	int			PlaySoundMem(int SoundHandle, int PlayType, int TopPositionFlag = TRUE);								// サウンドハンドルを再生する
			extern	int			StopSoundMem(int SoundHandle);						// サウンドハンドルの再生を停止する
			extern	int			CheckSoundMem(int SoundHandle);						// サウンドハンドルが再生中かどうかを取得する
			extern	int			SetPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルのパンを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangePanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルのパンを設定する( -255 ～ 255 )
			extern	int			GetPanSoundMem(int SoundHandle);						// サウンドハンドルのパンを取得する
			extern	int			SetVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangeVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルのボリュームを設定する( 0 ～ 255 )
			extern	int			GetVolumeSoundMem(int SoundHandle);						// サウンドハンドルのボリュームを取得する
			extern	int			SetChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangeChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを設定する( 0 ～ 255 )
			extern	int			GetChannelVolumeSoundMem(int Channel, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを取得する
			extern	int			SetFrequencySoundMem(int FrequencyPal, int SoundHandle);						// サウンドハンドルの再生周波数を設定する
			extern	int			GetFrequencySoundMem(int SoundHandle);						// サウンドハンドルの再生周波数を取得する
			extern	int			ResetFrequencySoundMem(int SoundHandle);						// サウンドハンドルの再生周波数を読み込み直後の状態に戻す

			extern	int			SetNextPlayPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するパンを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangeNextPlayPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するパンを設定する( -255 ～ 255 )
			extern	int			SetNextPlayVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangeNextPlayVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( 0 ～ 255 )
			extern	int			SetNextPlayChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するチャンネルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
			extern	int			ChangeNextPlayChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するチャンネルのボリュームを設定する( 0 ～ 255 )
			extern	int			SetNextPlayFrequencySoundMem(int FrequencyPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用する再生周波数を設定する

			extern	int			SetCurrentPositionSoundMem(int SamplePosition, int SoundHandle);						// サウンドハンドルの再生位置をサンプル単位で設定する(再生が止まっている時のみ有効)
			extern	int			GetCurrentPositionSoundMem(int SoundHandle);						// サウンドハンドルの再生位置をサンプル単位で取得する
			extern	int			SetSoundCurrentPosition(int Byte, int SoundHandle);						// サウンドハンドルの再生位置をバイト単位で設定する(再生が止まっている時のみ有効)
			extern	int			GetSoundCurrentPosition(int SoundHandle);						// サウンドハンドルの再生位置をバイト単位で取得する
			extern	int			SetSoundCurrentTime(int Time, int SoundHandle);						// サウンドハンドルの再生位置をミリ秒単位で設定する(圧縮形式の場合は正しく設定されない場合がある)
			extern	int			GetSoundCurrentTime(int SoundHandle);						// サウンドハンドルの再生位置をミリ秒単位で取得する(圧縮形式の場合は正しい値が返ってこない場合がある)
			extern	int			GetSoundTotalSample(int SoundHandle);						// サウンドハンドルの音の総時間をサンプル単位で取得する
			extern	int			GetSoundTotalTime(int SoundHandle);						// サウンドハンドルの音の総時間をミリ秒単位で取得する

			extern	int			SetLoopPosSoundMem(int LoopTime, int SoundHandle);						// SetLoopTimePosSoundMem の別名関数
			extern	int			SetLoopTimePosSoundMem(int LoopTime, int SoundHandle);						// サウンドハンドルにループ位置を設定する(ミリ秒単位)
			extern	int			SetLoopSamplePosSoundMem(int LoopSamplePosition, int SoundHandle);						// サウンドハンドルにループ位置を設定する(サンプル単位)

			extern	int			SetLoopStartTimePosSoundMem(int LoopStartTime, int SoundHandle);						// サウンドハンドルにループ開始位置を設定する(ミリ秒単位)
			extern	int			SetLoopStartSamplePosSoundMem(int LoopStartSamplePosition, int SoundHandle);						// サウンドハンドルにループ開始位置を設定する(サンプル単位)

			extern	int			SetPlayFinishDeleteSoundMem(int DeleteFlag, int SoundHandle);						// サウンドハンドルの再生が終了したら自動的にハンドルを削除するかどうかを設定する


		private:
			sound(int param_handle) DXLE_NOEXCEPT_OR_NOTHROW : Unique_HandledObject_Bace(param_handle){}
		};

		// 設定関係関数
		extern	int			SetCreateSoundDataType(int SoundDataType);																		// 作成するサウンドハンドルの再生タイプを設定する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
		extern	int			GetCreateSoundDataType(void);																					// 作成するサウンドハンドルの再生タイプを取得する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
		extern	int			SetCreateSoundPitchRate(float Cents);																			// 作成するサウンドハンドルのピッチ( 音の長さを変えずに音程を変更する )レートを設定する( 単位はセント( 100.0fで半音、1200.0fで１オクターヴ )、プラスの値で音程が高く、マイナスの値で音程が低くなります )
		extern	float		GetCreateSoundPitchRate(void);																					// 作成するサウンドハンドルのピッチ( 音の長さを変えずに音程を変更する )レートを取得する( 単位はセント( 100.0fで半音、1200.0fで１オクターヴ )、プラスの値で音程が高く、マイナスの値で音程が低くなります )
		extern	int			SetCreateSoundTimeStretchRate(float Rate);																				// 作成するサウンドハンドルのタイムストレッチ( 音程を変えずに音の長さを変更する )レートを設定する( 単位は倍率、2.0f で音の長さが２倍に、0.5f で音の長さが半分になります )
		extern	float		GetCreateSoundTimeStretchRate(void);																					// 作成するサウンドハンドルのタイムストレッチ( 音程を変えずに音の長さを変更する )レートを取得する( 単位は倍率、2.0f で音の長さが２倍に、0.5f で音の長さが半分になります )
		extern	int			SetDisableReadSoundFunctionMask(int Mask);																				// 使用しないサウンドデータ読み込み処理のマスクを設定する( DX_READSOUNDFUNCTION_PCM 等 )
		extern	int			GetDisableReadSoundFunctionMask(void);																					// 使用しないサウンドデータ読み込み処理のマスクを取得する( DX_READSOUNDFUNCTION_PCM 等 )
		extern	int			SetEnableSoundCaptureFlag(int Flag);																				// サウンドキャプチャを前提とした動作をするかどうかを設定する

		//extern	int			SetUseOldVolumeCalcFlag(int Flag);																				// ChangeVolumeSoundMem, ChangeNextPlayVolumeSoundMem, ChangeMovieVolumeToGraph の音量計算式を Ver3.10c以前のものを使用するかどうかを設定する( TRUE:Ver3.10c以前の計算式を使用  FALSE:3.10d以降の計算式を使用( デフォルト ) )


		//生成

		// 前奏部とループ部に分かれたサウンドファイルを読み込みサウンドハンドルを作成する
		sound	LoadSoundMem2(const TCHAR *FileName1, const TCHAR *FileName2)DXLE_NOEXCEPT_OR_NOTHROW{ return sound::LoadSoundMem2(FileName1, FileName2); }
		// 主にＢＧＭを読み込みサウンドハンドルを作成するのに適した関数
		sound	LoadBGM(const TCHAR *FileName)DXLE_NOEXCEPT_OR_NOTHROW{ return sound::LoadBGM(FileName); }
		// サウンドファイルからサウンドハンドルを作成する
		sound	LoadSoundMemBase(const TCHAR *FileName, int BufferNum, int UnionHandle = -1){ return sound::LoadSoundMemBase(FileName, BufferNum, UnionHandle); }
		// サウンドファイルからサウンドハンドルを作成する(LoadSoundMemBase の別名関数)
		sound	LoadSoundMem(const TCHAR *FileName, int BufferNum = 3, int UnionHandle = -1){ return sound::LoadSoundMem(FileName, BufferNum, UnionHandle); }
		// 同じサウンドデータを使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS タイプのサウンドハンドルのみ可能 )
		sound	DuplicateSoundMem(sound SrcSoundHandle, int BufferNum = 3){ return sound::DuplicateSoundMem(SrcSoundHandle, BufferNum); }
		// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
		sound	LoadSoundMemByMemImageBase(const void *FileImage, int FileImageSize, int BufferNum, int UnionHandle = -1){ return sound::LoadSoundMemByMemImageBase(FileImage, FileImageSize, BufferNum, UnionHandle); }
		sound	LoadSoundMemByMemImage(const void *FileImage, int FileImageSize, int UnionHandle = -1);			// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する( バッファ数指定無し )
		sound	LoadSoundMemByMemImage2(const void *WaveImage, int WaveImageSize, const WAVEFORMATEX *WaveFormat, int WaveHeaderSize);	// メモリ上に展開されたＰＣＭデータからサウンドハンドルを作成する
		sound	LoadSoundMem2ByMemImage(const void *FileImage1, int FileImageSize1, const void *FileImage2, int FileImageSize2);	// 前奏部とループ部に分かれた二つのメモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
		sound	LoadSoundMemFromSoftSound(int SoftSoundHandle, int BufferNum = 3);													// ソフトウエアサウンドハンドルが持つサウンドデータからサウンドハンドルを作成する

		//削除
		extern	int			DeleteSoundMem(int SoundHandle, int LogOutFlag = FALSE);												// サウンドハンドルを削除する

		//操作
		extern	int			PlaySoundMem(int SoundHandle, int PlayType, int TopPositionFlag = TRUE);								// サウンドハンドルを再生する
		extern	int			StopSoundMem(int SoundHandle);						// サウンドハンドルの再生を停止する
		extern	int			CheckSoundMem(int SoundHandle);						// サウンドハンドルが再生中かどうかを取得する
		extern	int			SetPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルのパンを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangePanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルのパンを設定する( -255 ～ 255 )
		extern	int			GetPanSoundMem(int SoundHandle);						// サウンドハンドルのパンを取得する
		extern	int			SetVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangeVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルのボリュームを設定する( 0 ～ 255 )
		extern	int			GetVolumeSoundMem(int SoundHandle);						// サウンドハンドルのボリュームを取得する
		extern	int			SetChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangeChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを設定する( 0 ～ 255 )
		extern	int			GetChannelVolumeSoundMem(int Channel, int SoundHandle);						// サウンドハンドルの指定のチャンネルのボリュームを取得する
		extern	int			SetFrequencySoundMem(int FrequencyPal, int SoundHandle);						// サウンドハンドルの再生周波数を設定する
		extern	int			GetFrequencySoundMem(int SoundHandle);						// サウンドハンドルの再生周波数を取得する
		extern	int			ResetFrequencySoundMem(int SoundHandle);						// サウンドハンドルの再生周波数を読み込み直後の状態に戻す

		extern	int			SetNextPlayPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するパンを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangeNextPlayPanSoundMem(int PanPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するパンを設定する( -255 ～ 255 )
		extern	int			SetNextPlayVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangeNextPlayVolumeSoundMem(int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( 0 ～ 255 )
		extern	int			SetNextPlayChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するチャンネルのボリュームを設定する( 100分の1デシベル単位 0 ～ 10000 )
		extern	int			ChangeNextPlayChannelVolumeSoundMem(int Channel, int VolumePal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用するチャンネルのボリュームを設定する( 0 ～ 255 )
		extern	int			SetNextPlayFrequencySoundMem(int FrequencyPal, int SoundHandle);						// サウンドハンドルの次の再生にのみ使用する再生周波数を設定する

		extern	int			SetCurrentPositionSoundMem(int SamplePosition, int SoundHandle);						// サウンドハンドルの再生位置をサンプル単位で設定する(再生が止まっている時のみ有効)
		extern	int			GetCurrentPositionSoundMem(int SoundHandle);						// サウンドハンドルの再生位置をサンプル単位で取得する
		extern	int			SetSoundCurrentPosition(int Byte, int SoundHandle);						// サウンドハンドルの再生位置をバイト単位で設定する(再生が止まっている時のみ有効)
		extern	int			GetSoundCurrentPosition(int SoundHandle);						// サウンドハンドルの再生位置をバイト単位で取得する
		extern	int			SetSoundCurrentTime(int Time, int SoundHandle);						// サウンドハンドルの再生位置をミリ秒単位で設定する(圧縮形式の場合は正しく設定されない場合がある)
		extern	int			GetSoundCurrentTime(int SoundHandle);						// サウンドハンドルの再生位置をミリ秒単位で取得する(圧縮形式の場合は正しい値が返ってこない場合がある)
		extern	int			GetSoundTotalSample(int SoundHandle);						// サウンドハンドルの音の総時間をサンプル単位で取得する
		extern	int			GetSoundTotalTime(int SoundHandle);						// サウンドハンドルの音の総時間をミリ秒単位で取得する

		extern	int			SetLoopPosSoundMem(int LoopTime, int SoundHandle);						// SetLoopTimePosSoundMem の別名関数
		extern	int			SetLoopTimePosSoundMem(int LoopTime, int SoundHandle);						// サウンドハンドルにループ位置を設定する(ミリ秒単位)
		extern	int			SetLoopSamplePosSoundMem(int LoopSamplePosition, int SoundHandle);						// サウンドハンドルにループ位置を設定する(サンプル単位)

		extern	int			SetLoopStartTimePosSoundMem(int LoopStartTime, int SoundHandle);						// サウンドハンドルにループ開始位置を設定する(ミリ秒単位)
		extern	int			SetLoopStartSamplePosSoundMem(int LoopStartSamplePosition, int SoundHandle);						// サウンドハンドルにループ開始位置を設定する(サンプル単位)

		extern	int			SetPlayFinishDeleteSoundMem(int DeleteFlag, int SoundHandle);						// サウンドハンドルの再生が終了したら自動的にハンドルを削除するかどうかを設定する



		//3D
#		if 0
		extern	int			Set3DReverbParamSoundMem(            const SOUND3D_REVERB_PARAM *Param,              int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用のリバーブパラメータを設定する
		extern	int			Set3DPresetReverbParamSoundMem(      int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */, int SoundHandle );						// サウンドハンドルの３Ｄサウンド用のリバーブパラメータをプリセットを使用して設定する
		extern	int			Set3DReverbParamSoundMemAll(const SOUND3D_REVERB_PARAM *Param, int PlaySoundOnly = FALSE);							// 全ての３Ｄサウンドのサウンドハンドルにリバーブパラメータを設定する( PlaySoundOnly TRUE:再生中のサウンドにのみ設定する  FALSE:再生していないサウンドにも設定する )
		extern	int			Set3DPresetReverbParamSoundMemAll(int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */, int PlaySoundOnly = FALSE);			// 全ての３Ｄサウンドのサウンドハンドルにリバーブパラメータをプリセットを使用して設定する( PlaySoundOnly TRUE:再生中のサウンドにのみ設定する  FALSE:再生していないサウンドにも設定する )
		extern	int			Get3DReverbParamSoundMem(SOUND3D_REVERB_PARAM *ParamBuffer, int SoundHandle);						// サウンドハンドルに設定されている３Ｄサウンド用のリバーブパラメータを取得する
		extern	int			Get3DPresetReverbParamSoundMem(SOUND3D_REVERB_PARAM *ParamBuffer, int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */);		// プリセットの３Ｄサウンド用のリバーブパラメータを取得する

		extern	int			Set3DPositionSoundMem(VECTOR Position, int SoundHandle);						// サウンドハンドルの３Ｄサウンド用の再生位置を設定する
		extern	int			Set3DRadiusSoundMem(float Radius, int SoundHandle);						// サウンドハンドルの３Ｄサウンド用の音が聞こえる距離を設定する
		extern	int			Set3DVelocitySoundMem(VECTOR Velocity, int SoundHandle);						// サウンドハンドルの３Ｄサウンド用の移動速度を設定する

		extern	int			SetNextPlay3DPositionSoundMem(VECTOR Position, int SoundHandle);						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の再生位置を設定する
		extern	int			SetNextPlay3DRadiusSoundMem(float Radius, int SoundHandle);						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の音が聞こえる距離を設定する
		extern	int			SetNextPlay3DVelocitySoundMem(VECTOR Velocity, int SoundHandle);						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の移動速度を設定する

		// 設定関係関数
		extern	int			SetCreate3DSoundFlag(int Flag);																			// 次に作成するサウンドハンドルを３Ｄサウンド用にするかどうかを設定する( TRUE:３Ｄサウンド用にする  FALSE:３Ｄサウンド用にしない( デフォルト ) )
		extern	int			Set3DSoundOneMetre(float Distance);																	// ３Ｄ空間の１メートルに相当する距離を設定する、DxLib_Init を呼び出す前でのみ呼び出し可能( デフォルト:1.0f )
		extern	int			Set3DSoundListenerPosAndFrontPos_UpVecY(VECTOR Position, VECTOR FrontPosition);												// ３Ｄサウンドのリスナーの位置とリスナーの前方位置を設定する( リスナーの上方向はＹ軸固定 )
		extern	int			Set3DSoundListenerPosAndFrontPosAndUpVec(VECTOR Position, VECTOR FrontPosition, VECTOR UpVector);							// ３Ｄサウンドのリスナーの位置とリスナーの前方位置とリスナーの上方向を設定する
		extern	int			Set3DSoundListenerVelocity(VECTOR Velocity);																	// ３Ｄサウンドのリスナーの移動速度を設定する
		extern	int			Set3DSoundListenerConeAngle(float InnerAngle, float OuterAngle);												// ３Ｄサウンドのリスナーの可聴角度範囲を設定する
		extern	int			Set3DSoundListenerConeVolume(float InnerAngleVolume, float OuterAngleVolume);									// ３Ｄサウンドのリスナーの可聴角度範囲の音量倍率を設定する

#		endif
	}
	using namespace sound;
}
//#ifndef DXLE_INC_SOUND_H_
#endif
