﻿#ifndef DXLE_INC_CONFIG_LINK_H_
#define DXLE_INC_CONFIG_LINK_H_

//TOOLSET
#ifdef _MSC_VER
#if (_MSC_VER < 1800)
// Note: no compilers before 1800 are supported
#error no compilers before 1800 are supported
#elif (_MSC_VER < 1900)
// vc12:
#	define DXLE_LIB_TOOLSET "_v120"
#elif (_MSC_VER < 2000)
// vc14:
#	define DXLE_LIB_TOOLSET "_v140"
#elif
//other
#	define DXLE_LIB_TOOLSET ""
#endif

#ifdef _WIN64
#	define DXLE_PLATFORM_TARGET "_x64"
#else
#	define DXLE_PLATFORM_TARGET "_x86"
#endif

#if defined(_DEBUG) || !defined(NDEBUG)
#	define DXLE_CONFIGURATION "_d"
#else
#	define DXLE_CONFIGURATION "_r"
#endif
#ifdef UNICODE
#	define DXLE_CHARACTERSET "_Unicode"
#else
#	define DXLE_CHARACTERSET "_MultiByte"
#endif

#pragma comment(lib,"DXLIBEX" DXLE_LIB_TOOLSET DXLE_CHARACTERSET DXLE_PLATFORM_TARGET DXLE_CONFIGURATION ".lib")
#endif //ifdef _MSC_VER
#endif