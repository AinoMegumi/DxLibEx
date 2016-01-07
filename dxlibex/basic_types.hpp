﻿/*=============================================================================
  Copyright (C) 2015-2016 DxLibEx project
  https://github.com/Nagarei/DxLibEx/

  Distributed under the Boost Software License, Version 1.0.
  (See http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef DXLE_INC_BASIC_TYPES_HPP_
#define DXLE_INC_BASIC_TYPES_HPP_
#include "dxlibex/basic_types/point2d.hpp"
#include "dxlibex/basic_types/point3d.hpp"
#include "dxlibex/basic_types/size.hpp"
namespace dxle {

	//operators betwin point_c and size_c

	/**
	@relates point_c
	\~japanese	@brief	二項演算子+=のオーバーロード
	\~english	@brief	Overload of binary operator +=
	\~japanese	@param l	point_cクラスオブジェクトへのlvalue reference
	\~english	@param l	lvalue reference to point_c value
	\~japanese	@param r	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to size_c value
	\~japanese	@return	第一引数へのlvalue reference
	\~english	@return	lvalue reference to first argument
	*/
	template <typename T1, typename T2>
	point_c<T1>& operator +=(point_c<T1>& l, const size_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW
	{
	    l.x += r.width;
	    l.y += r.height;
	    return l;
	}

	/**
	@relates size_c
	\~japanese	@brief	二項演算子+=のオーバーロード
	\~english	@brief	Overload of binary operator +=
	\~japanese	@param l	size_cクラスオブジェクトへのlvalue reference
	\~english	@param l	lvalue reference to size_c value
	\~japanese	@param r	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to point_c value
	\~japanese	@return	第一引数へのlvalue reference
	\~english	@return	lvalue reference to first argument
	*/
	template <typename T1, typename T2>
	size_c<T1>& operator +=(size_c<T1>& l, const point_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW
	{
	    l.width += r.x;
	    l.height += r.y;
	    return l;
	}

	/**
	@relates point_c
	\~japanese	@brief	二項演算子+=のオーバーロード
	\~english	@brief	Overload of binary operator -=
	\~japanese	@param l	point_cクラスオブジェクトへのlvalue reference
	\~english	@param l	lvalue reference to point_c value
	\~japanese	@param r	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to size_c value
	\~japanese	@return	第一引数へのlvalue reference
	\~english	@return	lvalue reference to first argument
	*/
	template <typename T1, typename T2>
	point_c<T1>& operator -=(point_c<T1>& l, const size_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW
	{
	    l.x -= r.width;
	    l.y -= r.height;
	    return l;
	}

	/**
	@relates size_c
	\~japanese	@brief	二項演算子-=のオーバーロード
	\~english	@brief	Overload of binary operator -=
	\~japanese	@param l	size_cクラスオブジェクトへのlvalue reference
	\~english	@param l	lvalue reference to size_c value
	\~japanese	@param r	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to point_c value
	\~japanese	@return	第一引数へのlvalue reference
	\~english	@return	lvalue reference to first argument
	*/
	template <typename T1, typename T2>
	size_c<T1>& operator -=(size_c<T1>& l, const point_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW
	{
	    l.width -= r.x;
	    l.height -= r.y;
	    return l;
	}

	/**
	@relates point_c
	\~japanese	@brief	二項演算子+のオーバーロード
	\~english	@brief	Overload of binary operator +
	\~japanese	@param l	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param l	const-lvalue reference to point_c value
	\~japanese	@param r	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to size_c value
	\~japanese	@return	2つのpoint_cクラスオブジェクトの各メンバー同士の加算結果
	\~english	@return	Memberwise addition of both point_c value
	*/
	template <typename T1, typename T2>
	auto operator +(const point_c<T1>& l, const size_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW -> point_c<decltype(l.x + r.height)>
	{
		return {l.x + r.width, l.y + r.height};
	}

	/**
	@relates size_c
	\~japanese	@brief	二項演算子+のオーバーロード
	\~english	@brief	Overload of binary operator +
	\~japanese	@param l	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param l	const-lvalue reference to size_c value
	\~japanese	@param r	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to point_c value
	\~japanese	@return	2つのsize_cクラスオブジェクトの各メンバー同士の加算結果
	\~english	@return	Memberwise addition of both size_c value
	*/
	template <typename T1, typename T2>
	auto operator +(const size_c<T1>& l, const point_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW -> size_c<decltype(l.width + r.x)>
	{
		return {l.width + r.x, l.height + r.y};
	}

	/**
	@relates point_c
	\~japanese	@brief	二項演算子+のオーバーロード
	\~english	@brief	Overload of binary operator -
	\~japanese	@param l	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param l	const-lvalue reference to point_c value
	\~japanese	@param r	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to size_c value
	\~japanese	@return	2つのpoint_cクラスオブジェクトの各メンバー同士の加算結果
	\~english	@return	Memberwise addition of both point_c value
	*/
	template <typename T1, typename T2>
	auto operator -(const point_c<T1>& l, const size_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW -> point_c<decltype(l.x - r.height)>
	{
		return {l.x - r.width, l.y - r.height};
	}

	/**
	@relates size_c
	\~japanese	@brief	二項演算子-のオーバーロード
	\~english	@brief	Overload of binary operator -
	\~japanese	@param l	size_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param l	const-lvalue reference to size_c value
	\~japanese	@param r	point_cクラスオブジェクトへのconst-lvalue reference
	\~english	@param r	const-lvalue reference to point_c value
	\~japanese	@return	2つのsize_cクラスオブジェクトの各メンバー同士の加算結果
	\~english	@return	Memberwise addition of both size_c value
	*/
	template <typename T1, typename T2>
	auto operator -(const size_c<T1>& l, const point_c<T2>& r) DXLE_NOEXCEPT_OR_NOTHROW -> size_c<decltype(l.width + r.x)>
	{
		return {l.width - r.x, l.height - r.y};
	}
}
#endif
