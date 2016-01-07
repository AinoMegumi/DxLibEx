/*=============================================================================
  Copyright (C) 2015-2016 DxLibEx project
  https://github.com/Nagarei/DxLibEx/

  Distributed under the Boost Software License, Version 1.0.
  (See http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef DXLE_INC_CONFIG_COMPILER_VISUALC_HPP_
#define DXLE_INC_CONFIG_COMPILER_VISUALC_HPP_

#define DXLE_NO_CXX11_CONSTEXPR_CLASS
#if _MSC_FULL_VER < 190023026
#	define DXLE_NO_CXX11_CONSTEXPR
#	define DXLE_NO_CXX11_NOEXCEPT_EXPRESSION
#	define DXLE_NO_CXX11_USER_DEFINED_LITERALS
#	define DXLE_NO_CXX11_UNICODE_LITERALS
#endif
#if _MSC_FULL_VER < 180031101
#	define DXLE_NO_CXX11_NOEXCEPT
#endif
#define DXLE_NO_CXX11_ATTRIBUTES

#if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#  define DXLE_NO_CXX14_CONSTEXPR
#endif
#if !defined(__cpp_variable_templates) || (__cpp_variable_templates < 201304)
#  define DXLE_NO_CXX14_VARIABLE_TEMPLATES
#endif

#endif	// #ifndef DXLE_INC_CONFIG_COMPILER_VISUALC_HPP_